#include "opengl_math/math/numbers.h"

#include "suite.h"

START_TEST(test_float_equals)
{
  ck_assert(opengl_math::float_equals(1.0f, 1.0f, 1e-006f));
  ck_assert(opengl_math::float_equals(1.0, 1.0, 1e-012));
  ck_assert(opengl_math::float_equals(1.0L, 1.0L, 1e-012L));
}
END_TEST

int
main(int argc, char *argv[])
{
  Suite *s;
  SRunner *sr;
  TCase *tc;
  int result;

  s = suite_create("Unit Tests");
  tc = tcase_create(__FILE__);

  tcase_add_test(tc, test_float_equals);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
