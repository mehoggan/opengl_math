#ifndef OPERATIONS_TESTS
#define OPERATIONS_TESTS

#include "test_base.h"

#include "math/clamp.h"
#include "math/numbers.h"

#include <iostream>
#include <vector>
#include <cassert>

// TODO: Test sqrt
// TODO: Test sin, asin, cos, acos, tan, cot

static float eps = 1e-006f;

class test_operations : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_operations"; }
};
#endif
