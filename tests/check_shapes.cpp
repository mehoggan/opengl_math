#include "opengl_math/math/trig.h"
#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/shapes/line.h"
#include "opengl_math/shapes/sphere.h"
#include "opengl_math/shapes/triangle.h"

#include "suite.h"

#include <check.h>

#include <iterator>

START_TEST(test_default_line_ctor)
{
  { // Construct point
    opengl_math::point_3d<float> p;
    opengl_math::line<float> line(p, p);

    ck_assert(line.p0() == p);
    ck_assert(line.p1() == p);
  }

  { // Construct random line.
    opengl_math::point_3d<float> p0(
      static_cast<float>(std::rand()), static_cast<float>(std::rand()),
      static_cast<float>(std::rand()));
    opengl_math::point_3d<float> p1(
      static_cast<float>(std::rand()), static_cast<float>(std::rand()),
      static_cast<float>(std::rand()));

    opengl_math::line<float> line(p0, p1);
    ck_assert(line.p0() == p0);
    ck_assert(line.p1() == p1);
  }
}
END_TEST

START_TEST(test_default_sphere_ctor)
{
  {
    float radius = 0.0f;
    opengl_math::octahedron_generator<float, std::uint32_t> generator(
      radius, 8);
    opengl_math::sphere<float, std::uint32_t> sphere(generator);
    ck_assert(generator.radius() == sphere.radius());
  }
}
END_TEST

START_TEST(test_generator_sphere_ctor)
{
  {
    float radius = 0.0f;
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 1.0, 1.0, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    ck_assert(generator.radius() == sphere.radius());
  }
}
END_TEST

START_TEST(test_generator_sphere_generate_octahedron)
{
  { // Fill
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::octahedron_generator<float, std::uint32_t> generator(radius,
      0u);
    opengl_math::sphere<float, std::uint32_t> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 6u);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 24u);
  }

  { // Wireframe
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output(opengl_math::wireframe);
    opengl_math::octahedron_generator<float, std::uint32_t> generator(radius,
      0u);
    opengl_math::sphere<float, std::uint32_t> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 6u);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 48u);
  }
}
END_TEST

START_TEST(test_generator_sphere_generate_spherical)
{
  { // Fill degenerate sphere.
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 360.0f, 180.0f, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 2u);
    opengl_math::vec3f pos1(output.points()[0].x(), output.points()[0].y(),
      output.points()[0].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, -1.0f, +0.0f), pos1, 1e-7f));
    opengl_math::vec3f pos2(output.points()[1].x(), output.points()[1].y(),
      output.points()[1].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, +1.0f, +0.0f), pos2, 1e-7f));
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 2u);
    ck_assert_int_eq(0u, output.indices()[0]);
    ck_assert_int_eq(1u, output.indices()[1]);
  }

  { // Wireframe degenerate sphere.
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output(opengl_math::wireframe);
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 360.0f, 180.0f, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 2u);
    opengl_math::vec3f pos1(output.points()[0].x(), output.points()[0].y(),
      output.points()[0].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, -1.0f, +0.0f), pos1, 1e-7f));
    opengl_math::vec3f pos2(output.points()[1].x(), output.points()[1].y(),
      output.points()[1].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, +1.0f, +0.0f), pos2, 1e-7f));
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 2u);
    ck_assert_int_eq(0u, output.indices()[0]);
    ck_assert_int_eq(1u, output.indices()[1]);
  }

  { // Fill sphere 2 steps horizontal and degenerate in z.
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 180.0f, 180.0f, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 2u);
    opengl_math::vec3f pos1(output.points()[0].x(), output.points()[0].y(),
      output.points()[0].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, -1.0f, +0.0f), pos1, 1e-7f));
    opengl_math::vec3f pos2(output.points()[1].x(), output.points()[1].y(),
      output.points()[1].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, +1.0f, +0.0f), pos2, 1e-7f));
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 2u);
    ck_assert_int_eq(0u, output.indices()[0]);
    ck_assert_int_eq(1u, output.indices()[1]);
  }

  { // Wireframe sphere 2 steps horizontal and degenerate in z.
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output(opengl_math::wireframe);
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 180.0f, 180.0f, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 2u);
    opengl_math::vec3f pos1(output.points()[0].x(), output.points()[0].y(),
      output.points()[0].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, -1.0f, +0.0f), pos1, 1e-7f));
    opengl_math::vec3f pos2(output.points()[1].x(), output.points()[1].y(),
      output.points()[1].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, +1.0f, +0.0f), pos2, 1e-7f));
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 2u);
    ck_assert_int_eq(0u, output.indices()[0]);
    ck_assert_int_eq(1u, output.indices()[1]);
  }

  { // Fill sphere 2 steps horizontal and degenerate in z.
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 180.0f, 180.0f, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 2u);
    opengl_math::vec3f pos1(output.points()[0].x(), output.points()[0].y(),
      output.points()[0].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, -1.0f, +0.0f), pos1, 1e-7f));
    opengl_math::vec3f pos2(output.points()[1].x(), output.points()[1].y(),
      output.points()[1].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, +1.0f, +0.0f), pos2, 1e-7f));
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 2u);
    ck_assert_int_eq(0u, output.indices()[0]);
    ck_assert_int_eq(1u, output.indices()[1]);
  }

  { // Wireframe sphere 2 steps horizontal and degenerate in z.
    float radius = 1.0f;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output(opengl_math::wireframe);
    opengl_math::spherical_coordinate_generator<float, std::uint32_t>
      generator(radius, 180.0f, 180.0f, opengl_math::degrees);
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(generator);
    sphere.generate(output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 2u);
    opengl_math::vec3f pos1(output.points()[0].x(), output.points()[0].y(),
      output.points()[0].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, -1.0f, +0.0f), pos1, 1e-7f));
    opengl_math::vec3f pos2(output.points()[1].x(), output.points()[1].y(),
      output.points()[1].z());
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vec3f(+0.0f, +1.0f, +0.0f), pos2, 1e-7f));
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 2u);
    ck_assert_int_eq(0u, output.indices()[0]);
    ck_assert_int_eq(1u, output.indices()[1]);
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

  tcase_add_test(tc, test_default_line_ctor);
  tcase_add_test(tc, test_default_sphere_ctor);
  tcase_add_test(tc, test_generator_sphere_ctor);
  tcase_add_test(tc, test_generator_sphere_generate_octahedron);
  tcase_add_test(tc, test_generator_sphere_generate_spherical);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
