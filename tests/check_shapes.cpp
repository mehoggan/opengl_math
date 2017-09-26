#include "opengl_math/primitives/points/type_point_3d.h"

#include "opengl_math/shapes/line.h"
#include "opengl_math/shapes/sphere.h"
#include "opengl_math/shapes/triangle.h"

#include "suite.h"

#include <check.h>

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
    opengl_math::sphere<float, std::uint32_t> sphere(radius);
    ck_assert(sphere.radius() == radius);
  }
}
END_TEST

START_TEST(test_generator_sphere_ctor)
{
  {
    float radius = 0.0f;
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(radius);
    ck_assert(sphere.radius() == radius);
  }
}
END_TEST

START_TEST(test_generator_sphere_generate_octahedron)
{
  {
    float radius = 0.0f;
    opengl_math::subdivided_tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::octahedron_generator> sphere(radius);
    sphere.generate(output);
    // TODO: Validate output
  }
}
END_TEST

START_TEST(test_generator_sphere_generate_spherical)
{
  {
    float radius = 0.0f;
    opengl_math::subdivided_tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::sphere<float, std::uint32_t,
      opengl_math::spherical_coordinate_generator> sphere(radius);
    sphere.generate(output);
    // TODO: Validate output.
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
