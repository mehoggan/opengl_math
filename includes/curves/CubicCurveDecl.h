#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CubicCurveImpl;

typedef CubicCurveImpl<float> CubicCurveF;
typedef CubicCurveImpl<double> CubicCurveD;

} // namespace curve
