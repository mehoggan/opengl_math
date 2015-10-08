#ifndef CURVE_TESTS
#define CURVE_TESTS

#include "test_base.h"

#include "curves/cubic_curve.h"
#include "math/numbers.h"
#include "primitives/conversions.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class test_curves : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_curves"; }
};
#endif
