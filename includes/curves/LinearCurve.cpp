#include "curve/linear/LinearCurve.h"
#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Vector3.h>

namespace curve
{

template<typename RealT>
LinearCurveImpl<RealT>::LinearCurveImpl()
    : m_point0(NavCore::Math::Vector3Impl<RealType>::cZero)
    , m_point1(NavCore::Math::Vector3Impl<RealType>::cZero)
{}


template<typename RealT>
LinearCurveImpl<RealT>::LinearCurveImpl(const NavCore::Math::Vector3Impl<RealType>& point0,
    const NavCore::Math::Vector3Impl<RealType>& point1)
    : m_point0(point0)
    , m_point1(point1)
{
}


template<typename RealT>
void LinearCurveImpl<RealT>::setPoints(const NavCore::Math::Vector3Impl<RealType>& point0,
    const NavCore::Math::Vector3Impl<RealType>& point1)
{
    m_point0 = point0;
    m_point1 = point1;
}


template<typename RealT>
const NavCore::Math::Vector3Impl<RealT>& LinearCurveImpl<RealT>::getPoint0() const
{
    return m_point0;
}


template<typename RealT>
const NavCore::Math::Vector3Impl<RealT>& LinearCurveImpl<RealT>::getPoint1() const
{
    return m_point1;
}


template<typename RealT>
NavCore::Math::Vector3Impl<RealT> LinearCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    return NavCore::Math::Lerp(t, m_point0, m_point1);
}


template<typename RealT>
NavCore::Math::Vector3Impl<RealT> LinearCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    return (m_point1 - m_point0);
}


template<typename RealT>
CurveSampleImpl<RealT> LinearCurveImpl<RealT>::evaluate(RealType t) const
{
    return CurveImpl<RealType>::evaluate(t);
}


template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> LinearCurveImpl<RealT>::computeBoundingBox() const
{
    NavCore::Math::AlignedBox3Impl<RealType> outBox;
    outBox.min = outBox.max = m_point0;
    outBox.GrowToContain(m_point1);
    return outBox;
}


template<typename RealT>
std::vector<RealT> LinearCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    return CurveImpl<RealType>::computeSampleValues(sampleCount);
}


template<typename RealT>
std::vector<CurveSampleImpl<RealT>> LinearCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    std::vector<CurveSampleImpl<RealType>> outSamples;
    CurveSampleImpl<RealType> sample0 = evaluate(0);
    CurveSampleImpl<RealType> sample1 = evaluate(1);

    outSamples.push_back(sample0);
    outSamples.push_back(sample1);

    return outSamples;
}

template class LinearCurveImpl<float>;
template class LinearCurveImpl<double>;

} // namespace curve
