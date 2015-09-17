#pragma once

#include <vector>
#include "curve/core/Curve.h"
#include "curve/linear/LinearCurveDecl.h"

namespace curve
{

/**
 * @brief Represents a straight line segment that runs between two points.
 */
template<typename RealT>
class CURVE_API LinearCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;

    LinearCurveImpl();
    LinearCurveImpl(const NavCore::Math::Vector3Impl<RealType>& point0,
        const NavCore::Math::Vector3Impl<RealType>& point1);

    void setPoints(const NavCore::Math::Vector3Impl<RealType>& point0,
        const NavCore::Math::Vector3Impl<RealType>& point1);

    const NavCore::Math::Vector3Impl<RealType>& getPoint0() const;
    const NavCore::Math::Vector3Impl<RealType>& getPoint1() const;

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    NavCore::Math::Vector3Impl<RealType> m_point0;
    NavCore::Math::Vector3Impl<RealType> m_point1;
};

} // namespace curve
