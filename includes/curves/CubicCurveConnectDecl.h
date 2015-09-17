#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CubicCurveConnectImpl;

typedef CubicCurveConnectImpl<float> CubicCurveConnectF;
typedef CubicCurveConnectImpl<double> CubicCurveConnectD;

} // namespace curve
