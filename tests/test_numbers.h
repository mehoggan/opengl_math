#ifndef NUMBER_TESTS
#define NUMBER_TESTS

#include "test_base.h"

#include "math/numbers.h"

#include <iostream>
#include <vector>
#include <cassert>

// TODO: Test squared
// TODO: Test min
// TODO: Test max
// TODO: Test abs
// TODO: Test vector_2d_float_equals
// TODO: Test vector_3d_float_equals
// TODO: Test vector_4d_float_equals

class test_numbers : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_numbers"; }
};

#endif
