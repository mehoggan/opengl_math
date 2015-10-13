#include "test_curves.h"

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
    opengl_math::catmulrom<float, opengl_math::column>();

  opengl_math::matrix_4X4<float, opengl_math::row> catmul_rom_row =
    opengl_math::catmulrom<float, opengl_math::row>();

  for (unsigned short col = 0; col < 4u; ++col) {
    for (unsigned short row = 0; row < 4u; ++row) {
      OPENGL_MATH_ASSERT(opengl_math::float_equals<float>(
        catmul_rom_row[col][row], catmul_rom_col[col][row],
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
  {
    opengl_math::point_3d<float> p0(+0.00f, +0.00f, +0.00f);
    opengl_math::point_3d<float> p3(+2.00f, -2.00f, +3.20f);
    opengl_math::vector_3d<float> t0(+1.00f, +0.50f, +1.00f);
    opengl_math::vector_3d<float> t3(-2.00f, +0.70f, +1.50f);

    opengl_math::cubic_curve<float, opengl_math::column> hermite;
    hermite.set_hermite(p0, p3, t0, t3);

    opengl_math::curve_sample_3d<float> start_sample =
      hermite.evaluate(0.0f);
    opengl_math::curve_sample_3d<float> end_sample =
      hermite.evaluate(1.0f);

    float epsilon = 1e-6f;
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p0, start_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(+1.00f, +0.50f, +1.00f),
      start_sample._tangent, epsilon));
    OPENGL_MATH_ASSERT_EQ(0.0, start_sample._parameter);

    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p3, end_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(-2.00f, +0.70f, +1.50f),
      end_sample._tangent, epsilon));
    OPENGL_MATH_ASSERT_EQ(1.0, end_sample._parameter)
  }

  {
    opengl_math::point_3d<float> p0(+0.00f, +0.00f, +0.00f);
    opengl_math::point_3d<float> p3(+2.00f, -2.00f, +3.20f);
    opengl_math::vector_3d<float> t0(+1.00f, +0.50f, +1.00f);
    opengl_math::vector_3d<float> t3(-2.00f, +0.70f, +1.50f);

    opengl_math::cubic_curve<float, opengl_math::row> hermite;
    hermite.set_hermite(p0, p3, t0, t3);

    opengl_math::curve_sample_3d<float> start_sample =
      hermite.evaluate(0.0f);
    opengl_math::curve_sample_3d<float> end_sample =
      hermite.evaluate(1.0f);

    float epsilon = 1e-6f;
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p0, start_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(+1.00f, +0.50f, +1.00f),
      start_sample._tangent, epsilon));
    OPENGL_MATH_ASSERT_EQ(0.0, start_sample._parameter);

    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p3, end_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(-2.00f, +0.70f, +1.50f),
      end_sample._tangent, epsilon));
    OPENGL_MATH_ASSERT_EQ(1.0, end_sample._parameter)
  }
}

void test_cubic_curve_set_bezier()
{
  {
    opengl_math::point_3d<float> p0(+0.00f, +0.00f, +0.00f);
    opengl_math::point_3d<float> p1(-2.00f, +1.00f, +0.00f);
    opengl_math::point_3d<float> p2(+2.00f, +3.00f, +1.00f);
    opengl_math::point_3d<float> p3(+2.50f, +5.67f, +3.40f);

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
    opengl_math::point_3d<float> p0(+0.00f, +0.00f, +0.00f);
    opengl_math::point_3d<float> p1(-2.00f, +1.00f, +0.00f);
    opengl_math::point_3d<float> p2(+2.00f, +3.00f, +1.00f);
    opengl_math::point_3d<float> p3(+2.50f, +5.67f, +3.40f);

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

  {
    opengl_math::point_3d<float> p0(+0.0f, -1.0f, +0.0f);
    opengl_math::point_3d<float> p1(+0.0f, +0.0f, +0.0f);
    opengl_math::point_3d<float> p2(+0.0f, +0.0f, +0.0f);
    opengl_math::point_3d<float> p3(+0.0f, +1.0f, +0.0f);

    opengl_math::cubic_curve<float, opengl_math::column> bezier;
    bezier.set_bezier(p0, p1, p2, p3);

    opengl_math::curve_sample_3d<float> start_sample =
      bezier.evaluate(0.0f);
    start_sample.normalize_tangent();
    opengl_math::curve_sample_3d<float> end_sample =
      bezier.evaluate(1.0f);
    end_sample.normalize_tangent();

    float epsilon = 1e-6f;
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p0, start_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), start_sample._tangent,
      epsilon));
    OPENGL_MATH_ASSERT_EQ(0.0, start_sample._parameter);

    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p3, end_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), end_sample._tangent,
      epsilon));
    OPENGL_MATH_ASSERT_EQ(1.0, end_sample._parameter);
  }

  {
    opengl_math::point_3d<float> p0(+0.0f, -1.0f, +0.0f);
    opengl_math::point_3d<float> p1(+0.0f, +0.0f, +0.0f);
    opengl_math::point_3d<float> p2(+0.0f, +0.0f, +0.0f);
    opengl_math::point_3d<float> p3(+0.0f, +1.0f, +0.0f);

    opengl_math::cubic_curve<float, opengl_math::row> bezier;
    bezier.set_bezier(p0, p1, p2, p3);

    opengl_math::curve_sample_3d<float> start_sample =
      bezier.evaluate(0.0f);
    start_sample.normalize_tangent();
    opengl_math::curve_sample_3d<float> end_sample =
      bezier.evaluate(1.0f);
    end_sample.normalize_tangent();

    float epsilon = std::numeric_limits<float>::epsilon();
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p0, start_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), start_sample._tangent,
      epsilon));
    OPENGL_MATH_ASSERT_EQ(0.0, start_sample._parameter);

    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals<float>(
      p3, end_sample._position, epsilon));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals<float>(
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), end_sample._tangent,
      epsilon));
    OPENGL_MATH_ASSERT_EQ(1.0, end_sample._parameter);
  }
}

void test_curve3d_compute_sample_values()
{
  opengl_math::cubic_curve<float, opengl_math::row> bezier;
  std::vector<float> params;
  params = bezier.compute_sample_values(11);

  OPENGL_MATH_ASSERT_EQ(11u, params.size());
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.0f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.1f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.2f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.3f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.4f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.5f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.6f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.7f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.8f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 0.9f) !=
    params.end()));
  OPENGL_MATH_ASSERT((std::find(params.begin(), params.end(), 1.0f) !=
    params.end()));
}

void test_curve3d_compute_samples_uniform()
{
}

void test_curve3d_compute_samples_adaptive()
{
  {
    opengl_math::point_3d<float> p0(-3.00f, -6.00f, +0.00f);
    opengl_math::point_3d<float> p1(-3.00f, -1.50f, +0.00f);
    opengl_math::point_3d<float> p2(+3.00f, +1.50f, +0.00f);
    opengl_math::point_3d<float> p3(+3.00f, +6.00f, +0.00f);

    opengl_math::cubic_curve<float, opengl_math::column> bezier;
    bezier.set_bezier(p0, p1, p2, p3);

    std::vector<opengl_math::curve_sample_3d<float>> samples =
      bezier.compute_samples_adaptive(0.0011f);
    OPENGL_MATH_ASSERT_EQ(53u, samples.size());
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals(p0,
      samples.front()._position, std::numeric_limits<float>::epsilon()));
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals(p3,
      samples.back()._position, std::numeric_limits<float>::epsilon()));
  }

  {
    opengl_math::point_3d<float> p0(-3.00f, -6.00f, +0.00f);
    opengl_math::point_3d<float> p1(-3.00f, -1.50f, +0.00f);
    opengl_math::point_3d<float> p2(+3.00f, +1.50f, +0.00f);
    opengl_math::point_3d<float> p3(+3.00f, +6.00f, +0.00f);

    opengl_math::cubic_curve<float, opengl_math::row> bezier;
    bezier.set_bezier(p0, p1, p2, p3);

    std::vector<opengl_math::curve_sample_3d<float>> samples =
      bezier.compute_samples_adaptive(0.0011f);
    OPENGL_MATH_ASSERT_EQ(53u, samples.size());
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals(p0,
      samples.front()._position, std::numeric_limits<float>::epsilon()));
    OPENGL_MATH_ASSERT(opengl_math::point_3d_float_equals(p3,
      samples.back()._position, std::numeric_limits<float>::epsilon()));
  }
}

bool test_curves::run()
{
  test_curve_samples();
  test_cubic_curve_catmul_rom();
  test_cubic_curve_bezier();
  test_cubic_curve_hermite();
  test_cubic_curve_default_ctor();
  test_cubic_curve_set_hermite();
  test_cubic_curve_set_bezier();
  test_curve3d_compute_sample_values();
  test_curve3d_compute_samples_uniform();
  test_curve3d_compute_samples_adaptive();

  return true;
}
