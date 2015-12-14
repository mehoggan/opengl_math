#include "test_planes.h"

void test_default_ctor()
{
  opengl_math::plane_3d<float> plane;
  OPENGL_MATH_ASSERT(!plane.is_valid());
}

void test_ctor()
{
  {
    opengl_math::plane_3d<float> plane(+3.0f, +4.0f, -6.0f, +1.0f);
    OPENGL_MATH_ASSERT(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(+0.0f, +4.0f, -0.0f, +1.0f);
    OPENGL_MATH_ASSERT(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(+0.0f, +4.0f, -1.0f, +0.0f);
    OPENGL_MATH_ASSERT(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(+0.1f, +4.0f, +0.0f, +4.0f);
    OPENGL_MATH_ASSERT(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    OPENGL_MATH_ASSERT(plane.is_valid());
  }

  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.0f, +0.0f, +0.0f, +4.0f));
    OPENGL_MATH_ASSERT(!plane.is_valid());
  }
}

void test_copy_ctor()
{
  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    OPENGL_MATH_ASSERT(plane.is_valid());
    opengl_math::plane_3d<float> plane_copy = plane;
    OPENGL_MATH_ASSERT_EQ(plane, plane_copy);
  }
}

void test_assignment_operator()
{
  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    OPENGL_MATH_ASSERT(plane.is_valid());
    opengl_math::plane_3d<float> plane_copy;
    plane_copy = plane;
    OPENGL_MATH_ASSERT_EQ(plane, plane_copy);
  }
}

void test_setters_getters()
{
  {
    opengl_math::plane_3d<float> plane(opengl_math::vector_4d<float>(
      +0.1f, +4.0f, +0.0f, +4.0f));
    OPENGL_MATH_ASSERT(plane.is_valid());
    plane.a(+5.0f);
    plane.b(+4.0f);
    plane.c(+2.0f);
    plane.d(+1.0f);
    OPENGL_MATH_ASSERT_EQ(plane, opengl_math::plane_3d<float>(
      opengl_math::vector_4d<float>(+5.0f, +4.0f, +2.0f, +1.0f)));
    OPENGL_MATH_ASSERT_EQ(+5.0f, plane.a());
    OPENGL_MATH_ASSERT_EQ(+4.0f, plane.b());
    OPENGL_MATH_ASSERT_EQ(+2.0f, plane.c());
    OPENGL_MATH_ASSERT_EQ(+1.0f, plane.d());
  }
}

bool test_planes::run()
{
  test_default_ctor();
  test_ctor();
  test_copy_ctor();
  test_assignment_operator();
  test_setters_getters();

  return true;
}