#ifndef CURVE_TESTS
#define CURVE_TESTS

#include "test_base.h"

#include "curves/cubic_curve.h"
#include "math/numbers.h"
#include "primitives/conversions.h"

#include <iostream>
#include <vector>
#include <cassert>

class test_curves : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_curves"; }
};
#endif