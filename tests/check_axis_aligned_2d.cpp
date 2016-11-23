#include "opengl_math/bounds/axis_aligned_2d.h"
#include "opengl_math/primitives/points/type_point_2d.h"
#include "opengl_math/primitives/points/type_point_3d.h"

#include "suite.h"

#include <check.h>

START_TEST(test_axis_aligned_default_ctor)
{
  opengl_math::axis_aligned_2d<float> invalid;
  ck_assert(!invalid.is_valid());
}
END_TEST

START_TEST(test_axis_aligned_ctor_1)
{
  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(-0.1f, -0.1f),
      opengl_math::point_2d<float>(+0.1f, +0.1f));

    ck_assert(valid.is_valid());
    ck_assert(valid.r_ll() ==
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    ck_assert(valid.r_ur() ==
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(+0.1f, -0.1f),
      opengl_math::point_2d<float>(-0.1f, +0.1f));

    ck_assert(valid.is_valid());
    ck_assert(valid.r_ll() ==
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    ck_assert(valid.r_ur() ==
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(-0.1f, +0.1f),
      opengl_math::point_2d<float>(+0.1f, -0.1f));

    ck_assert(valid.is_valid());
    ck_assert(valid.r_ll() ==
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    ck_assert(valid.r_ur() ==
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(+0.1f, +0.1f),
      opengl_math::point_2d<float>(-0.1f, -0.1f));

    ck_assert(valid.is_valid());
    ck_assert(valid.r_ll() ==
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    ck_assert(valid.r_ur() ==
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> aab(
        opengl_math::point_2d<float>(-0.0f, -0.0f),
        opengl_math::point_2d<float>(+0.0f, +0.0f));

    ck_assert(!aab.is_valid());
    ck_assert(aab.r_ll() ==
      opengl_math::point_2d<float>(-0.0f, -0.0f));
    ck_assert(aab.r_ur() ==
      opengl_math::point_2d<float>(+0.0f, +0.0f));
  }
}
END_TEST

START_TEST(test_axis_aligned_ctor_2)
{
  {
    opengl_math::axis_aligned_2d<float> aab(
      opengl_math::point_2d<float>(-100.0f, +100.0f), +50.0f, +25.0f);

    ck_assert(aab.is_valid());
    ck_assert(aab.r_ll() ==
      opengl_math::point_2d<float>(-100.0f, +100.0f));
    ck_assert(aab.r_ur() ==
      opengl_math::point_2d<float>(-50.0f, +125.0f));
  }

  {
    opengl_math::axis_aligned_2d<float> aab(
      opengl_math::point_2d<float>(-100.0f, +100.0f), -50.0f, -125.0f);

    ck_assert(aab.is_valid());
    ck_assert(aab.r_ll() ==
      opengl_math::point_2d<float>(-150.0f, -25.0f));
    ck_assert(aab.r_ur() ==
      opengl_math::point_2d<float>(-100.0f, +100.0f));
  }
}
END_TEST

START_TEST(test_axis_aligned_2d_copy_ctor)
{
  opengl_math::axis_aligned_2d<float> aab;
  opengl_math::axis_aligned_2d<float> aab_copy(aab);

  ck_assert(aab == aab_copy);
}
END_TEST

START_TEST(test_axis_aligned_2d_assignment_operator)
{
  opengl_math::axis_aligned_2d<float> aab;
  opengl_math::axis_aligned_2d<float> aab_copy;
  aab_copy = aab;

  ck_assert(aab == aab_copy);
}
END_TEST

START_TEST(test_axis_aligned_grow_to_contain)
{
  opengl_math::axis_aligned_2d<float> aab;
  aab.grow_to_contain(opengl_math::point_2d<float>(-1.0f, +1.0f));
  aab.grow_to_contain(opengl_math::point_2d<float>(+1.0f, +2.0f));
  ck_assert(aab.contains(opengl_math::point_2d<float>(-1.0, +1.0)));
  ck_assert(aab.contains(opengl_math::point_2d<float>(-1.0, +2.0)));
  ck_assert(aab.contains(opengl_math::point_2d<float>(+1.0, +2.0)));
  ck_assert(aab.contains(opengl_math::point_2d<float>(+1.0, +1.0)));
  ck_assert(!aab.contains(opengl_math::point_2d<float>(+0.0, +0.0)));
  ck_assert(aab.contains(opengl_math::point_2d<float>(+0.0, +1.5)));
  ck_assert(opengl_math::point_2d<float>(+0.0, +1.5) == aab.center());
  ck_assert(2.0f == aab.width());
  ck_assert(1.0f == aab.height());
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
  tcase_add_test(tc, test_axis_aligned_default_ctor);
  tcase_add_test(tc, test_axis_aligned_ctor_1);
  tcase_add_test(tc, test_axis_aligned_ctor_2);
  tcase_add_test(tc, test_axis_aligned_2d_copy_ctor);
  tcase_add_test(tc, test_axis_aligned_2d_assignment_operator);
  tcase_add_test(tc, test_axis_aligned_grow_to_contain);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}

