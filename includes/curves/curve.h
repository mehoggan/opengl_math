#pragma once

#include <vector>
#include <NavCore/Math/Geometry/AlignedBox3Decl.h>
#include <NavCore/Math/Vector/Vector3Decl.h>
#include "curve/CurveApi.h"
#include "curve/core/CurveDecl.h"
#include "curve/core/CurveSample.h"
#include "curve/core/TessellationQuality.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveImpl
{
public:
    using RealType = RealT;

    CurveImpl() {}
    virtual ~CurveImpl() {}

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const = 0;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const = 0;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const = 0;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const = 0;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const = 0;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const = 0;

    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesUniform(size_t sampleCount = 2) const;
};

} // namespace curve
