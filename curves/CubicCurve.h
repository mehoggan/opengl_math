#pragma once

#include <vector>
#include <NavCore/Math/Geometry/AlignedBox3Decl.h>
#include <NavCore/Math/Vector/Matrix34.h>
#include <NavCore/Math/Vector/Vector3Decl.h>
#include "curve/core/Curve.h"
#include "curve/core/CurveSampleDecl.h"
#include "curve/core/TessellationQualityDecl.h"
#include "curve/cubic/CubicCurveDecl.h"

namespace curve
{

template<typename RealT>
class CURVE_API CubicCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;

    CubicCurveImpl();

    /**
     * @brief Sets cubic curve using Hermite parameters.
     * @param p0 The start position.
     * @param p1 The end position.
     * @param t0 The start tangent.
     * @param t1 The end tangent.
     */
    void setHermite(
        const NavCore::Math::Vector3Impl<RealType>& p0, const NavCore::Math::Vector3Impl<RealType>& p1,
        const NavCore::Math::Vector3Impl<RealType>& t0, const NavCore::Math::Vector3Impl<RealType>& t1);

    /**
    * @brief Sets cubic curve using Bezier parameters.
    * @param p0 The start position.
    * @param p1 The first control point.
    * @param p2 The second control point.
    * @param p3 The end position.
    */
    void setBezier(
        const NavCore::Math::Vector3Impl<RealType>& p0, const NavCore::Math::Vector3Impl<RealType>& p1,
        const NavCore::Math::Vector3Impl<RealType>& p2, const NavCore::Math::Vector3Impl<RealType>& p3);

    /**
    * @brief Sets cubic curve using Catmull-Rom parameters.
    * @param p0 The start control point.
    * @param p1 The start position.
    * @param p2 The end position.
    * @param p3 The end control point.
    */
    void setCatmullRom(
        const NavCore::Math::Vector3Impl<RealType>& p0, const NavCore::Math::Vector3Impl<RealType>& p1,
        const NavCore::Math::Vector3Impl<RealType>& p2, const NavCore::Math::Vector3Impl<RealType>& p3);

    /**
     * @brief Gets the underlying matrix representing this cubic curve.
     */
    const NavCore::Math::Matrix34Impl<RealType>& getMatrix() const { return m_cubic; }

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    void ComputeRangeForDimension(RealType& outMin, RealType& outMax, int dimension) const;

    NavCore::Math::Matrix34Impl<RealType> m_cubic;
};

} // namespace curve
