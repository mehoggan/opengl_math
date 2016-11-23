#include "opengl_math/planes/plane_3d.h"

#include "suite.h"

#include <check.h>

START_TEST(test_default_ctor)
{
  opengl_math::plane_3d<float> plane;
  ck_assert(!plane.is_valid());
}
END_TEST

START_TEST(test_ctor)
{
  {
    opengl_math::plane_3d<float> plane(+3.0f, +4.0f, -6.0f, +1.0f);
    ck_assert(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(+0.0f, +4.0f, -0.0f, +1.0f);
    ck_assert(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(+0.0f, +4.0f, -1.0f, +0.0f);
    ck_assert(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(+0.1f, +4.0f, +0.0f, +4.0f);
    ck_assert(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    ck_assert(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.0f, +0.0f, +0.0f, +4.0f));
    ck_assert(!plane.is_valid());
  }
}
END_TEST

START_TEST(test_copy_ctor)
{
  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    ck_assert(plane.is_valid());
    opengl_math::plane_3d<float> plane_copy = plane;
    ck_assert(plane == plane_copy);
  }
}
END_TEST

START_TEST(test_assignment_operator)
{
  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    ck_assert(plane.is_valid());
    opengl_math::plane_3d<float> plane_copy;
    plane_copy = plane;
    ck_assert(plane == plane_copy);
  }
}
END_TEST

START_TEST(test_setters_getters)
{
  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    ck_assert(plane.is_valid());
    plane.a(+5.0f);
    plane.b(+4.0f);
    plane.c(+2.0f);
    plane.d(+1.0f);
    ck_assert(plane == opengl_math::plane_3d<float>(
      opengl_math::vector_4d<float>(+5.0f, +4.0f, +2.0f, +1.0f)));
    ck_assert(+5.0f == plane.a());
    ck_assert(+4.0f == plane.b());
    ck_assert(+2.0f == plane.c());
    ck_assert(+1.0f == plane.d());
  }
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

  tcase_add_test(tc, test_default_ctor);
  tcase_add_test(tc, test_ctor);
  tcase_add_test(tc, test_copy_ctor);
  tcase_add_test(tc, test_assignment_operator);
  tcase_add_test(tc, test_setters_getters);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
