#include "test_numbers.h"

void test_float_equals()
{
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0f, 1.0f, 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0, 1.0, 1e-012));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0L, 1.0L, 1e-012L));
}

bool test_numbers::run()
{
  test_float_equals();

  return true;
}
