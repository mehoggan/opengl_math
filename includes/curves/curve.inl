#include "curve/core/Curve.h"

#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Vector3.h>

#include "curve/core/CurveNumeric.h"
#include "curve/core/Tessellator.h"


namespace curve
{

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> CurveImpl<RealT>::evaluateTangent(RealType t) const
{
    return CurveNumericImpl<RealType>::evaluateTangent(*this, t);
}

template<typename RealT>
CurveSampleImpl<RealT> CurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealType> outSample;
    outSample.m_position = evaluatePosition(t);
    outSample.m_tangent = evaluateTangent(t);
    outSample.m_parameter = t;
    return outSample;
}

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> CurveImpl<RealT>::computeBoundingBox() const
{
    return CurveNumericImpl<RealType>::computeBoundingBox(*this);
}

template<typename RealT>
std::vector<RealT> CurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    return CurveNumericImpl<RealType>::computeSampleValues(*this, sampleCount);
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> CurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    return TessellatorImpl<RealType>::adaptive(*this, quality);
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> CurveImpl<RealT>::computeSamplesUniform(size_t sampleCount) const
{
    return TessellatorImpl<RealType>::uniform(*this, sampleCount);
}

template class CurveImpl<float>;
template class CurveImpl<double>;

} // namespace curve
