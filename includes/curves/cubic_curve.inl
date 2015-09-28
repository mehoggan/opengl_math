#include "curve/cubic/CubicCurve.h"

#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Interpolate/CubicInterpolate.h>
#include <NavCore/Math/Vector/Matrix33.h>
#include <NavCore/Math/Vector/Matrix34.h>
#include <NavCore/Math/Vector/Matrix44.h>
#include <NavCore/Math/Vector/Vector3.h>

namespace curve
{

template<typename RealT>
CubicCurveImpl<RealT>::CubicCurveImpl()
    : m_cubic(NavCore::Math::Matrix34Impl<RealType>::cIdentity)
{}

template<typename RealT>
void CubicCurveImpl<RealT>::setHermite(
    const NavCore::Math::Vector3Impl<RealType>& p0, const NavCore::Math::Vector3Impl<RealType>& p1,
    const NavCore::Math::Vector3Impl<RealType>& t0, const NavCore::Math::Vector3Impl<RealType>& t1)
{
    // Build geometry matrix
    NavCore::Math::Matrix44Impl<RealType> geom;
    geom.a.Set(p0, 0.0f);
    geom.b.Set(p1, 0.0f);
    geom.c.Set(t0, 0.0f);
    geom.d.Set(t1, 0.0f);

    // Compute cubic coefficients
    NavCore::Math::Matrix44Impl<RealType> cube;
    cube.Dot(NavCore::Math::Matrix44Impl<RealType>::cHermite, geom);

    // Copy coefficients to 3x4 matrix
    m_cubic.a.Set(cube.a.x, cube.a.y, cube.a.z);
    m_cubic.b.Set(cube.b.x, cube.b.y, cube.b.z);
    m_cubic.c.Set(cube.c.x, cube.c.y, cube.c.z);
    m_cubic.d.Set(cube.d.x, cube.d.y, cube.d.z);
}

template<typename RealT>
void CubicCurveImpl<RealT>::setBezier(
    const NavCore::Math::Vector3Impl<RealType>& p0, const NavCore::Math::Vector3Impl<RealType>& p1,
    const NavCore::Math::Vector3Impl<RealType>& p2, const NavCore::Math::Vector3Impl<RealType>& p3)
{
    // Build geometry matrix
    NavCore::Math::Matrix44Impl<RealType> geom;
    geom.a.Set(p0, 0.0);
    geom.b.Set(p1, 0.0);
    geom.c.Set(p2, 0.0);
    geom.d.Set(p3, 0.0);

    // Compute cubic coefficients
    NavCore::Math::Matrix44Impl<RealType> cube;
    cube.Dot(NavCore::Math::Matrix44Impl<RealType>::cBezier, geom);

    // Copy coefficients to 3x4 matrix
    m_cubic.a.Set(cube.a.x, cube.a.y, cube.a.z);
    m_cubic.b.Set(cube.b.x, cube.b.y, cube.b.z);
    m_cubic.c.Set(cube.c.x, cube.c.y, cube.c.z);
    m_cubic.d.Set(cube.d.x, cube.d.y, cube.d.z);
}

template<typename RealT>
void CubicCurveImpl<RealT>::setCatmullRom(
    const NavCore::Math::Vector3Impl<RealType>& p0, const NavCore::Math::Vector3Impl<RealType>& p1,
    const NavCore::Math::Vector3Impl<RealType>& p2, const NavCore::Math::Vector3Impl<RealType>& p3)
{
    // Build geometry matrix
    NavCore::Math::Matrix44Impl<RealType> geom;
    geom.a.Set(p0, 0.0);
    geom.b.Set(p1, 0.0);
    geom.c.Set(p2, 0.0);
    geom.d.Set(p3, 0.0);

    // Compute cubic coefficients
    NavCore::Math::Matrix44Impl<RealType> cube;
    cube.Dot(NavCore::Math::Matrix44Impl<RealType>::cCatmulRom, geom);

    // Create cubic with coefficients to 3x4 matrix
    m_cubic.a.Set(cube.a.x, cube.a.y, cube.a.z);
    m_cubic.b.Set(cube.b.x, cube.b.y, cube.b.z);
    m_cubic.c.Set(cube.c.x, cube.c.y, cube.c.z);
    m_cubic.d.Set(cube.d.x, cube.d.y, cube.d.z);
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> CubicCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    NavCore::Math::Vector3Impl<RealType> vs(t * t * t, t * t, t);
    return m_cubic.Transform(vs);
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> CubicCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    NavCore::Math::Vector3Impl<RealType> vs(3.0f * t * t, 2.0f * t, 1.0f);
    return m_cubic.Transform3x3(vs);
}

template<typename RealT>
CurveSampleImpl<RealT> CubicCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealType> outSample;
    outSample.m_position = evaluatePosition(t);
    outSample.m_tangent = evaluateTangent(t);
    outSample.m_parameter = t;

    return outSample;
}

namespace
{
template<typename RealT>
struct MinMax
{
    MinMax(RealT min, RealT max)
        : m_min(min)
        , m_max(max)
    {}

    RealT m_min;
    RealT m_max;
};

enum class ComponentEnum
{
    eX, eY, eZ
};

template <typename RealT>
RealT getComponent(ComponentEnum component, const NavCore::Math::Vector3Impl<RealT>& v)
{
    switch (component)
    {
    case(ComponentEnum::eX): return v.x;
    case(ComponentEnum::eY): return v.y;
    case(ComponentEnum::eZ): return v.z;
    default: NT_ASSERT(false && "Invalid Component");
    }

    // MSVC Warning.
    return v.x;
}

template<typename RealT>
MinMax<RealT> getQuadraticMinimaMaxima(const CubicCurveImpl<RealT>& curve,
    const NavCore::Math::Vector3Impl<RealT>& coeff, const RealT min, const RealT max,
    ComponentEnum component, std::vector<RealT>& tvals)
{
    RealT a = coeff.x;
    RealT b = coeff.y;
    RealT c = coeff.z;

    RealT sqrtParam = b * b - RealT(4) * a * c;
    RealT t0 = RealT(-1);
    RealT t1 = RealT(-1);

    RealT local_min = min;
    RealT local_max = max;

    if (sqrtParam > 0) // Don't want imaginary numbers in sqrt
    {
        t0 = (-b + std::sqrt(sqrtParam)) / (2 * a);
        if (t0 > 0 && t0 < 1)
        {
            CurveSampleImpl<RealT> Ci = curve.evaluate(t0);
            local_min = std::min(local_min, getComponent(component, Ci.m_position));
            local_max = std::max(local_max, getComponent(component, Ci.m_position));
            tvals.push_back(t0);
        }

        t1 = (-b - std::sqrt(sqrtParam)) / (2 * a);
        if (t1 > 0 && t1 < 1)
        {
            CurveSampleImpl<RealT> Cj = curve.evaluate(t1);
            local_min = std::min(local_min, getComponent(component, Cj.m_position));
            local_max = std::max(local_max, getComponent(component, Cj.m_position));
            tvals.push_back(t1);
        }
    }

    return MinMax<RealT>(local_min, local_max);
}


template<typename RealT>
NavCore::Math::Matrix33Impl<RealT> computeTangentCoefficients(
    const NavCore::Math::Vector3Impl<RealT>& p0,
    const NavCore::Math::Vector3Impl<RealT>& p1,
    const NavCore::Math::Vector3Impl<RealT>& p2,
    const NavCore::Math::Vector3Impl<RealT>& p3)
{
    RealT ax = RealT( -3) * p0.x + RealT( +9) * p1.x + RealT( -9) * p2.x + RealT( +3) * p3.x;
    RealT bx = RealT( +6) * p0.x + RealT(-12) * p1.x + RealT( +6) * p2.x;
    RealT cx = RealT( -3) * p0.x + RealT( +3) * p1.x;

    RealT ay = RealT( -3) * p0.y + RealT( +9) * p1.y + RealT( -9) * p2.y + RealT( +3) * p3.y;
    RealT by = RealT( +6) * p0.y + RealT(-12) * p1.y + RealT( +6) * p2.y;
    RealT cy = RealT( -3) * p0.y + RealT( +3) * p1.y;

    RealT az = RealT( -3) * p0.z + RealT( +9) * p1.z + RealT( -9) * p2.z + RealT( +3) * p3.z;
    RealT bz = RealT( +6) * p0.z + RealT(-12) * p1.z + RealT( +6) * p2.z;
    RealT cz = RealT( -3) * p0.z + RealT( +3) * p1.z;

    return NavCore::Math::Matrix33Impl<RealT>(
        ax, bx, cx,
        ay, by, cy,
        az, bz, cz);
}

} // End namespace

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> CubicCurveImpl<RealT>::computeBoundingBox() const
{
    NavCore::Math::Matrix44Impl<RealT> cp;
    cp.Dot(NavCore::Math::Matrix44Impl<RealT>::cBezierInverse, m_cubic);
    NavCore::Math::Vector3Impl<RealT> p0(cp.a.x, cp.a.y, cp.a.z);
    NavCore::Math::Vector3Impl<RealT> p1(cp.b.x, cp.b.y, cp.b.z);
    NavCore::Math::Vector3Impl<RealT> p2(cp.c.x, cp.c.y, cp.c.z);
    NavCore::Math::Vector3Impl<RealT> p3(cp.d.x, cp.d.y, cp.d.z);

    NavCore::Math::AlignedBox3Impl<RealType> outBox;
    outBox.Invalidate();

    NavCore::Math::Matrix33Impl<RealT> coeff = computeTangentCoefficients(p0, p1, p2, p3);
    std::vector<RealT> tvals;

    RealT xmin = std::min(p0.x, p3.x);
    RealT xmax = std::max(p0.x, p3.x);
    MinMax<RealT> xMinMax = getQuadraticMinimaMaxima((*this), coeff.a, xmin, xmax,
        ComponentEnum::eX, tvals);

    RealT ymin = std::min(p0.y, p3.y);
    RealT ymax = std::max(p0.y, p3.y);
    MinMax<RealT> yMinMax = getQuadraticMinimaMaxima((*this), coeff.b, ymin, ymax,
        ComponentEnum::eY, tvals);

    RealT zmin = std::min(p0.z, p3.z);
    RealT zmax = std::max(p0.z, p3.z);
    MinMax<RealT> zMinMax = getQuadraticMinimaMaxima((*this), coeff.c, zmin, zmax,
        ComponentEnum::eZ, tvals);

    outBox = NavCore::Math::AlignedBox3Impl<RealT>(
        xMinMax.m_min, yMinMax.m_min, zMinMax.m_min,
        xMinMax.m_max, yMinMax.m_max, zMinMax.m_max);

    return outBox;
}

template<typename RealT>
std::vector<RealT> CubicCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    return CurveImpl<RealType>::computeSampleValues(sampleCount);
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> CubicCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    return CurveImpl<RealType>::computeSamplesAdaptive(quality);
}

template<typename RealT>
void CubicCurveImpl<RealT>::ComputeRangeForDimension(RealType& outMin, RealType& outMax,
    int dimension) const
{
    RealType a = m_cubic.a[dimension];
    RealType b = m_cubic.b[dimension];
    RealType c = m_cubic.c[dimension];
    RealType d = m_cubic.d[dimension];

    NavCore::Math::CubicInterpolateImpl<RealType>::ComputeCubicBox(outMin, outMax, a, b, c, d);
}

template class CubicCurveImpl<float>;
template class CubicCurveImpl<double>;

} // namespace curve
