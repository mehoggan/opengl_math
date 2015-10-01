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
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(),
      opengl_math::vector3d_from_point3d(sample._position), 0.0f));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(),
      sample._tangent, 0.0f));
    OPENGL_MATH_ASSERT_EQ(0.0f, sample._parameter);
  }

  {
    opengl_math::curve_sample_3d<float> sample(
      opengl_math::point_3d<float>(1.0f, 1.0f, 0.0f),
      opengl_math::vector_3d<float>(1.0f, 0.0f, 1.0f), 0.1f);
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(1.0f, 1.0f, 0.0f),
      opengl_math::vector3d_from_point3d(sample._position), 0.0f));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 1.0f),
      sample._tangent, 0.0f));
    OPENGL_MATH_ASSERT_EQ(0.1f, sample._parameter);
  }

  {
    opengl_math::curve_sample_3d<float> sample(
      opengl_math::point_3d<float>(1.0f, 1.0f, 0.0f),
      opengl_math::vector_3d<float>(1.0f, 1.0f, 0.0f), 0.1f);
    sample.normalize_tangent();
    float mag = 1.0f / opengl_math::sqrt<float>(2.0f);
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(mag, mag, 0.0f),
      sample._tangent, 1e-6f));
  }
}

void test_cubic_curve_catmul_rom()
{
  opengl_math::matrix_4X4<float, opengl_math::column> catmul_rom_col =
    opengl_math::catmul_rom<float, opengl_math::column>();

  opengl_math::matrix_4X4<float, opengl_math::row> catmul_rom_row =
    opengl_math::catmul_rom<float, opengl_math::row>();

  opengl_math::matrix_4X4<float, opengl_math::row> transposed =
    catmul_rom_row.transposed();

  for (unsigned short col = 0; col < 4u; ++col) {
    for (unsigned short row = 0; row < 4u; ++row) {
      OPENGL_MATH_ASSERT(opengl_math::float_equals<float>(
        transposed[col][row], catmul_rom_col[col][row],
        std::numeric_limits<float>::epsilon()));
    }
  }
}

void test_cubic_curve_bezier()
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> bezier =
      opengl_math::bezier<float, opengl_math::column>();
    opengl_math::matrix_4X4<float, opengl_math::column> bezier_inv =
      opengl_math::bezier_inverse<float, opengl_math::column>();
    opengl_math::matrix_4X4<float, opengl_math::column> identity(
      opengl_math::identity);

    auto expected = bezier * bezier_inv;

    for (unsigned short col = 0; col < 4u; ++col) {
      for (unsigned short row = 0; row < 4u; ++row) {
        OPENGL_MATH_ASSERT(opengl_math::float_equals<float>(
          expected[col][row], identity[col][row],
          std::numeric_limits<float>::epsilon()));
      }
    }
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> bezier =
      opengl_math::bezier<float, opengl_math::row>();
    opengl_math::matrix_4X4<float, opengl_math::row> bezier_inv =
      opengl_math::bezier_inverse<float, opengl_math::row>();
    opengl_math::matrix_4X4<float, opengl_math::row> identity(
      opengl_math::identity);

    auto expected = bezier * bezier_inv;

    for (unsigned short row = 0; row < 4u; ++row) {
      for (unsigned short col = 0; col < 4u; ++col) {
        OPENGL_MATH_ASSERT(opengl_math::float_equals<float>(
          expected[row][col], identity[row][col],
          std::numeric_limits<float>::epsilon()));
      }
    }
  }
}

void test_cubic_curve_hermite()
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> hermite =
      opengl_math::hermite<float, opengl_math::column>();
    opengl_math::matrix_4X4<float, opengl_math::column> hermite_inv =
      opengl_math::hermite_inverse<float, opengl_math::column>();
    opengl_math::matrix_4X4<float, opengl_math::column> identity(
      opengl_math::identity);

    auto expected = hermite * hermite_inv;

    for (unsigned short col = 0; col < 4u; ++col) {
      for (unsigned short row = 0; row < 4u; ++row) {
        OPENGL_MATH_ASSERT(opengl_math::float_equals<float>(
          expected[col][row], identity[col][row],
          std::numeric_limits<float>::epsilon()));
      }
    }
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> hermite =
      opengl_math::hermite<float, opengl_math::row>();
    opengl_math::matrix_4X4<float, opengl_math::row> hermite_inv =
      opengl_math::hermite_inverse<float, opengl_math::row>();
    opengl_math::matrix_4X4<float, opengl_math::row> identity(
      opengl_math::identity);

    auto expected = hermite * hermite_inv;

    for (unsigned short row = 0; row < 4u; ++row) {
      for (unsigned short col = 0; col < 4u; ++col) {
        OPENGL_MATH_ASSERT(opengl_math::float_equals<float>(
          expected[row][col], identity[row][col],
          std::numeric_limits<float>::epsilon()));
      }
    }
  }
}

void test_cubic_curve_default_ctor()
{
  using mat44 = opengl_math::matrix_4X4<float, opengl_math::column>;
  opengl_math::cubic_curve<float, opengl_math::column> cubic;
  OPENGL_MATH_ASSERT_EQ(mat44(opengl_math::identity), cubic.get_matrix());
}

void test_cubic_curve_set_hermite()
{

}

void test_cubic_curve_set_bezier()
{
  {
    opengl_math::point_3d<float> p0(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p1(-2.0f, 1.0f, 0.0f);
    opengl_math::point_3d<float> p2(2.0f, 3.0f, 1.0f);
    opengl_math::point_3d<float> p3(2.5f, 5.67f, 3.4f);

    opengl_math::cubic_curve<float, opengl_math::column> bezier;
    bezier.set_bezier(p0, p1, p2, p3);

    opengl_math::point_3d<float> start =
      bezier.evaluate_position(0.0f);
    opengl_math::point_3d<float> end =
      bezier.evaluate_position(1.0f);

    float epsilon = std::numeric_limits<float>::epsilon();
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p0, start, epsilon));

    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p3, end, epsilon));
  }

  {
    opengl_math::point_3d<float> p0(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p1(-2.0f, 1.0f, 0.0f);
    opengl_math::point_3d<float> p2(2.0f, 3.0f, 1.0f);
    opengl_math::point_3d<float> p3(2.5f, 5.67f, 3.4f);

    opengl_math::cubic_curve<float, opengl_math::row> bezier;
    bezier.set_bezier(p0, p1, p2, p3);

    opengl_math::point_3d<float> start =
      bezier.evaluate_position(0.0f);
    opengl_math::point_3d<float> end =
      bezier.evaluate_position(1.0f);

    float epsilon = std::numeric_limits<float>::epsilon();
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p0, start, epsilon));

    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p3, end, epsilon));
  }
}

bool test_curves::run()
{
  test_tessellation_quality();
  test_curve_samples();
  test_cubic_curve_catmul_rom();
  test_cubic_curve_bezier();
  test_cubic_curve_hermite();
  test_cubic_curve_default_ctor();
  test_cubic_curve_set_hermite();
  test_cubic_curve_set_bezier();

  return true;
}