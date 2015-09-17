#pragma once

#include <stdlib.h>
#include <vector>
#include "curve/core/CurveDecl.h"
#include "curve/core/CurveSampleDecl.h"
#include "curve/core/TessellationQualityDecl.h"
#include "curve/core/TessellatorDecl.h"

namespace curve
{

template<typename RealT>
class CURVE_API TessellatorImpl
{
public:
    using RealType = RealT;

    /**
     * @brief Tessellates a curve using a uniform parameter evaluation. Sample tangents are NOT
     * normalized.
     */
    static std::vector<CurveSampleImpl<RealType>> uniform(const CurveImpl<RealType>& curve,
        size_t sampleCount = 2);

    /**
     * @brief Tessellates a curve using a top-down adaptive tessellation
     */
    static std::vector<CurveSampleImpl<RealType>> adaptive(const CurveImpl<RealType>& curve,
        TessellationQualityImpl<RealType> quality = TessellationQualityImpl<RealType>::cDefault);
};

} // namespace curve
