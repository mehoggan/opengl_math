#ifndef COLOR_TESTS
#define COLOR_TESTS

#include <cxxtest/TestSuite.h>

#include <core/math/numbers.h>

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

class number_tests : public CxxTest::TestSuite
{
public:
  void test_float_equals()
  {
    TS_ASSERT(gl_wrapper::core::math::float_equals(1.0f, 1.0f, 1e-006f));
    TS_ASSERT(gl_wrapper::core::math::float_equals(1.0, 1.0, 1e-012));
    TS_ASSERT(gl_wrapper::core::math::float_equals(1.0L, 1.0L, 1e-012L));
  }
};

#endif
