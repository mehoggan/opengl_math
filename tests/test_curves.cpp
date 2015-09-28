#include "test_curves.h"

void test_tessellation_quality()
{
  opengl_math::tessellation_quality<float> blank;
  OPENGL_MATH_ASSERT_EQ(0.01f, blank._chordal_tol)

  opengl_math::tessellation_quality<float> default =
    opengl_math::tessellation_quality<float>::default_quality;
  OPENGL_MATH_ASSERT_EQ(0.01f, default._chordal_tol);

  opengl_math::tessellation_quality<float> precise =
    opengl_math::tessellation_quality<float>::precise_quality;
  OPENGL_MATH_ASSERT_EQ(0.0005f, precise._chordal_tol);
}

void test_curve_samples()
{
  {
    opengl_math::curve_sample_3d<float> sample;
    // TODO: Add conversions between vector and point
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(),
      opengl_math::vector3d_from_point3d(sample._position), 0.0f));
  }
}

bool test_curves::run()
{
  test_tessellation_quality();
  test_curve_samples();

  return true;
}