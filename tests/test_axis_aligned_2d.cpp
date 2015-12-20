#include "test_axis_aligned_2d.h"

void test_axis_aligned_default_ctor()
{
  opengl_math::axis_aligned_2d<float> invalid;
  OPENGL_MATH_ASSERT(!invalid.is_valid());
}

void test_axis_aligned_ctor_1()
{
  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(-0.1f, -0.1f),
      opengl_math::point_2d<float>(+0.1f, +0.1f));

    OPENGL_MATH_ASSERT(valid.is_valid());
    OPENGL_MATH_ASSERT_EQ(valid.r_ll(),
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    OPENGL_MATH_ASSERT_EQ(valid.r_ur(),
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(+0.1f, -0.1f),
      opengl_math::point_2d<float>(-0.1f, +0.1f));

    OPENGL_MATH_ASSERT(valid.is_valid());
    OPENGL_MATH_ASSERT_EQ(valid.r_ll(),
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    OPENGL_MATH_ASSERT_EQ(valid.r_ur(),
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(-0.1f, +0.1f),
      opengl_math::point_2d<float>(+0.1f, -0.1f));

    OPENGL_MATH_ASSERT(valid.is_valid());
    OPENGL_MATH_ASSERT_EQ(valid.r_ll(),
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    OPENGL_MATH_ASSERT_EQ(valid.r_ur(),
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> valid(
      opengl_math::point_2d<float>(+0.1f, +0.1f),
      opengl_math::point_2d<float>(-0.1f, -0.1f));

    OPENGL_MATH_ASSERT(valid.is_valid());
    OPENGL_MATH_ASSERT_EQ(valid.r_ll(),
      opengl_math::point_2d<float>(-0.1f, -0.1f));
    OPENGL_MATH_ASSERT_EQ(valid.r_ur(),
      opengl_math::point_2d<float>(+0.1f, +0.1f));
  }

  {
    opengl_math::axis_aligned_2d<float> aab(
        opengl_math::point_2d<float>(-0.0f, -0.0f),
        opengl_math::point_2d<float>(+0.0f, +0.0f));

    OPENGL_MATH_ASSERT(!aab.is_valid());
    OPENGL_MATH_ASSERT_EQ(aab.r_ll(),
      opengl_math::point_2d<float>(-0.0f, -0.0f));
    OPENGL_MATH_ASSERT_EQ(aab.r_ur(),
      opengl_math::point_2d<float>(+0.0f, +0.0f));
  }
}

void test_axis_aligned_ctor_2()
{
  {
    opengl_math::axis_aligned_2d<float> aab(
      opengl_math::point_2d<float>(-100.0f, +100.0f), +50.0f, +25.0f);

    OPENGL_MATH_ASSERT(aab.is_valid());
    OPENGL_MATH_ASSERT_EQ(aab.r_ll(),
      opengl_math::point_2d<float>(-100.0f, +100.0f));
    OPENGL_MATH_ASSERT_EQ(aab.r_ur(),
      opengl_math::point_2d<float>(-50.0f, +125.0f));
  }

  {
    opengl_math::axis_aligned_2d<float> aab(
      opengl_math::point_2d<float>(-100.0f, +100.0f), -50.0f, -125.0f);

    OPENGL_MATH_ASSERT(aab.is_valid());
    OPENGL_MATH_ASSERT_EQ(aab.r_ll(),
      opengl_math::point_2d<float>(-150.0f, -25.0f));
    OPENGL_MATH_ASSERT_EQ(aab.r_ur(),
      opengl_math::point_2d<float>(-100.0f, +100.0f));
  }
}

void test_axis_aligned_2d_copy_ctor()
{
  opengl_math::axis_aligned_2d<float> aab;
  opengl_math::axis_aligned_2d<float> aab_copy(aab);

  OPENGL_MATH_ASSERT_EQ(aab, aab_copy);
}

void test_axis_aligned_2d_assignment_operator()
{
  opengl_math::axis_aligned_2d<float> aab;
  opengl_math::axis_aligned_2d<float> aab_copy;
  aab_copy = aab;

  OPENGL_MATH_ASSERT_EQ(aab, aab_copy);
}

void test_axis_aligned_grow_to_contain()
{
  opengl_math::axis_aligned_2d<float> aab;
  aab.grow_to_contain(opengl_math::point_2d<float>(-1.0f, +1.0f));
  aab.grow_to_contain(opengl_math::point_2d<float>(+1.0f, +2.0f));
  OPENGL_MATH_ASSERT(aab.contains(opengl_math::point_2d<float>(-1.0, +1.0)));
  OPENGL_MATH_ASSERT(aab.contains(opengl_math::point_2d<float>(-1.0, +2.0)));
  OPENGL_MATH_ASSERT(aab.contains(opengl_math::point_2d<float>(+1.0, +2.0)));
  OPENGL_MATH_ASSERT(aab.contains(opengl_math::point_2d<float>(+1.0, +1.0)));
  OPENGL_MATH_ASSERT(!aab.contains(opengl_math::point_2d<float>(+0.0, +0.0)));
  OPENGL_MATH_ASSERT(aab.contains(opengl_math::point_2d<float>(+0.0, +1.5)));
  OPENGL_MATH_ASSERT_EQ(opengl_math::point_2d<float>(+0.0, +1.5), aab.center());
  OPENGL_MATH_ASSERT_EQ(2.0f, aab.width());
  OPENGL_MATH_ASSERT_EQ(1.0f, aab.height());
}

bool test_axis_aligned_2d::run()
{
  test_axis_aligned_default_ctor();
  test_axis_aligned_ctor_1();
  test_axis_aligned_ctor_2();
  test_axis_aligned_2d_copy_ctor();
  test_axis_aligned_2d_assignment_operator();
  test_axis_aligned_grow_to_contain();

  return true;
}
