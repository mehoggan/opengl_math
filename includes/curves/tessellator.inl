#include "curve/core/Tessellator.h"
#include "curve/core/Curve.h"
#include "curve/core/CurveOps.h"
#include "curve/core/TessellationQuality.h"
#include "curve/core/Tessellator.h"

#include <NavCore/Math/Geometry/AlignedBox3.h>

#include <cstring>

namespace curve
{

template<typename RealT>
bool operator<(const CurveSampleImpl<RealT>& lhs, const CurveSampleImpl<RealT>& rhs)
{
    return lhs.m_parameter < rhs.m_parameter;
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> TessellatorImpl<RealT>::uniform(const CurveImpl<RealT>& curve,
    size_t sampleCount)
{
    std::vector<CurveSampleImpl<RealT>> outSamples;
    outSamples.reserve(sampleCount);

    for (size_t i = 0; i < sampleCount; ++i)
    {
        RealType t = static_cast<RealType>(i) / static_cast<RealType>(sampleCount - 1);
        CurveSampleImpl<RealType> sample = curve.evaluate(t);
        outSamples.push_back(sample);
    }

    return outSamples;
}

namespace
{

template<typename RealT>
RealT solveForMaxChordalDistanceBetween(RealT ti, RealT tj,
    const CurveImpl<RealT>& curve, RealT& maxChordal)
{
    CurveSampleImpl<RealT> Co = curve.evaluate(ti);
    CurveSampleImpl<RealT> Cn = curve.evaluate(tj);
    RealT step_size = 0.0001;
    RealT max_height = std::numeric_limits<RealT>::min();
    RealT max_t = std::numeric_limits<RealT>::min();

    for (RealT t = Co.m_parameter; t <= Cn.m_parameter; t += step_size)
    {
        CurveSampleImpl<RealT> Ct = curve.evaluate(t);
        NavCore::Math::Vector3Impl<RealT> u(
            Ct.m_position.x - Co.m_position.x,
            Ct.m_position.y - Co.m_position.y,
            Ct.m_position.z - Co.m_position.z);
        NavCore::Math::Vector3Impl<RealT> s(
            Cn.m_position.x - Co.m_position.x,
            Cn.m_position.y - Co.m_position.y,
            Cn.m_position.z - Co.m_position.z);
        if (s != NavCore::Math::Vector3Impl<RealT>(RealT(0), RealT(0), RealT(0)))
            s.Normalize();
        NavCore::Math::Vector3Impl<RealT> v = u.Dot(s) * s;
        RealT height = u.DistanceSquared(v);
        if (height > max_height)
        {
            maxChordal = height;
            max_height = height;
            max_t = t;
        }
    }

    if ((!NavCore::Math::FloatEquals(max_t, ti) &&
        !NavCore::Math::FloatEquals(max_t, tj)) &&
        max_t > 0 && max_t < 1)
    {
        return max_t;
    }
    else
    {
        return ti + 0.5;
    }
}

template<typename RealT>
RealT chordalDistanceSquaredFromSecant(
    const CurveImpl<RealT>& curve,
    const CurveSampleImpl<RealT>& point0,
    const CurveSampleImpl<RealT>& point1,
    RealT percent)
{
    NavCore::Math::Vector3Impl<RealT> secPos =
        NavCore::Math::Lerp(RealT(percent), point0.m_position, point1.m_position);

    CurveSampleImpl<RealT> pos = curve.evaluate(point0.m_parameter +
        (percent * (point1.m_parameter - point0.m_parameter)));

    return pos.m_position.DistanceSquared(secPos);
}

const unsigned short cMaxDepth = 10;

template<typename RealT>
bool isOfGoodQuality(
    const CurveImpl<RealT>& curve,
    const CurveSampleImpl<RealT>& point0,
    const RealT mid_t,
    const CurveSampleImpl<RealT>& point1,
    const TessellationQualityImpl<RealT>& quality,
    const unsigned short depth)
{
    // First Proposed Parameter
    bool isGood = false;
    RealT chordalToleranceCalc = chordalDistanceSquaredFromSecant(curve, point0, point1, mid_t);
    RealT chordalToleranceExpe = quality.m_chordalTolerance * quality.m_chordalTolerance;
    bool chordalToleranceGood = (chordalToleranceCalc <= chordalToleranceExpe);
    isGood = chordalToleranceGood;

    if (depth > cMaxDepth)
    {
        isGood = true;
    }
    else if (isGood)// Second Proposed Parameter this should not be run every check. We are only
    {               // worried about false positives. One such case is the standard cubic in xy.
        NavCore::Math::Vector3Impl<RealT> secant = point1.m_position - point0.m_position;
        if (secant.IsNearZero() || point0.m_tangent.IsNearZero())
        {
            isGood = true;
        }
        else
        {
            NavCore::Math::Vector3Impl<RealT> tangent = point0.m_tangent;
            secant.Normalize();
            tangent.Normalize();

            RealT tangentDeviation = secant.Distance(tangent);
            if (isGood && tangentDeviation > RealT(0.10))
            {
                isGood = false;
            }
        }
    }

    return isGood;
}

template<typename RealT>
void subdivide(
    std::vector<CurveSampleImpl<RealT>>& outSamples,
    const CurveImpl<RealT>& curve,
    const CurveSampleImpl<RealT> point0,
    const CurveSampleImpl<RealT> point1,
    const TessellationQualityImpl<RealT>& quality,
    unsigned short depth = 0)
{
    const RealT t = NavCore::Math::Lerp(RealT(0.5), point0.m_parameter, point1.m_parameter);
    const CurveSampleImpl<RealT> breakPoint = curve.evaluate(t);

    if (isOfGoodQuality(curve, point0, t, point1, quality, depth))
    {
        return;
    }
    else
    {
        ++depth;
        subdivide(outSamples, curve, point0, breakPoint, quality, depth);

        outSamples.push_back(breakPoint);

        subdivide(outSamples, curve, breakPoint, point1, quality, depth);
        --depth;
    }
}

} // End namespace

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> TessellatorImpl<RealT>::adaptive(
    const CurveImpl<RealT>& curve, TessellationQualityImpl<RealType> quality)
{
    std::vector<CurveSampleImpl<RealT>> outSamples;

    std::vector<RealT> tvals = curve.computeSampleValues();
    CurveSampleImpl<RealT> begin = curve.evaluate(tvals[0]);
    CurveSampleImpl<RealT> end = curve.evaluate(tvals[1]);

    outSamples.push_back(begin);
    subdivide(outSamples, curve, outSamples[0], end, quality);
    outSamples.push_back(end);

    return outSamples;
}

template class TessellatorImpl<float>;
template class TessellatorImpl<double>;

}
