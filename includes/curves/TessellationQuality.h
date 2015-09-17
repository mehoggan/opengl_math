#pragma once

#include <stdlib.h>
#include "curve/CurveApi.h"
#include "curve/core/TessellationQualityDecl.h"

namespace curve
{

/**
 * @brief Contains a set of quality parameters used to tessellate a curve.
 */
template<typename RealT>
class CURVE_API TessellationQualityImpl
{
public:
    using RealType = RealT;

    TessellationQualityImpl();

    /**
     * @brief The desired maximum distance between the resulting polyline and the original curve.
     * The adaptive tessellation process is not guaranteed to achieve this tolerance, as other
     * parameters, such as m_maxDepth, can terminate recursive subdivision before the tolerance is
     * met.
     */
    RealType m_chordalTolerance;

    static const TessellationQualityImpl cDefault;
    static const TessellationQualityImpl cPrecise;
};

} // namespace curve
