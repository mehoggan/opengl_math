#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/shapes/triangle.h"
#include "opengl_math/tessellation/tessellated_triangle_data.h"
#include "opengl_math/tessellation/tessellation_ops.h"

#include "suite.h"

#include <limits>

#include <check.h>

/*! \brief Unit tests for translate to and from functions
*/

START_TEST(test_tessellate_triangle_by_subdivision)
{
  { // zero tessellation
    opengl_math::point_3d<float> p1;
    opengl_math::point_3d<float> p2;
    opengl_math::point_3d<float> p3;
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangle_by_subdivision<float>(
      opengl_math::triangle<float>(p1, p2, p3), 0, current_index, output);
    ck_assert(output.points().empty());
    ck_assert(output.indices().empty());
    ck_assert(current_index == 0);
  }

  { // equilateral triangle subdivide zero times.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangle_by_subdivision<float>(
      opengl_math::triangle<float>(p1, p2, p3), 0, current_index, output);
    ck_assert(output.points().size() == 3);
    ck_assert(output.points()[0] == p1);
    ck_assert(output.points()[1] == p2);
    ck_assert(output.points()[2] == p3);
    ck_assert(output.indices().size() == 3);
    ck_assert(output.indices()[0] == 0u);
    ck_assert(output.indices()[1] == 1u);
    ck_assert(output.indices()[2] == 2u);
  }

  { // equilateral triangle subdivide once.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::triangle<float> tri(p1, p2, p3);
    opengl_math::tessellate_triangle_by_subdivision<float>(
      tri, 1, current_index, output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 4u);
    ck_assert(output.points()[0] == p1);
    ck_assert(output.points()[1] == opengl_math::centroid_of_triangle(tri));
    ck_assert(output.points()[2] == p3);
    ck_assert(output.points()[3] == p2);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 9u);
    ck_assert(output.indices()[0] == 0u);
    ck_assert(output.indices()[1] == 1u);
    ck_assert(output.indices()[2] == 2u);
    ck_assert(output.indices()[3] == 0u);
    ck_assert(output.indices()[4] == 3u);
    ck_assert(output.indices()[5] == 1u);
    ck_assert(output.indices()[6] == 3u);
    ck_assert(output.indices()[7] == 2u);
    ck_assert(output.indices()[8] == 1u);
  }

  { // equilateral triangle subdivide twice.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::triangle<float> tri(p1, p2, p3);
    opengl_math::tessellate_triangle_by_subdivision<float>(
      tri, 2, current_index, output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 7u);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 27u);
  }
}
END_TEST

START_TEST(test_tessellate_triangles_by_subdivision)
{
  opengl_math::point_3d<float> points[6] = {
    opengl_math::point_3d<float>(+0.0f, -1.0f, +0.0f),
    opengl_math::point_3d<float>(+0.0f, +0.0f, +1.0f),
    opengl_math::point_3d<float>(+1.0f, +0.0f, +0.0f),
    opengl_math::point_3d<float>(+0.0f, +0.0f, -1.0f),
    opengl_math::point_3d<float>(-1.0f, +0.0f, +0.0f),
    opengl_math::point_3d<float>(+0.0f, +1.0f, +0.0f)
  };
  std::vector<opengl_math::triangle<float>> dodecahedron_tris = {
    opengl_math::triangle<float>(points[0], points[1], points[2]),
    opengl_math::triangle<float>(points[5], points[1], points[2]),
    opengl_math::triangle<float>(points[0], points[3], points[2]),
    opengl_math::triangle<float>(points[5], points[2], points[3]),
    opengl_math::triangle<float>(points[0], points[3], points[4]),
    opengl_math::triangle<float>(points[5], points[3], points[4]),
    opengl_math::triangle<float>(points[0], points[4], points[1]),
    opengl_math::triangle<float>(points[5], points[4], points[1])
  };
  {
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangles_by_subdivision<float>(
      dodecahedron_tris, 0, current_index, output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 6u);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 24u);
  }
}
END_TEST

START_TEST(test_tessellate_triangle_by_midpoint_subdivision)
{
  { // zero tessellation
    opengl_math::point_3d<float> p1;
    opengl_math::point_3d<float> p2;
    opengl_math::point_3d<float> p3;
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangle_by_midpoint_subdivision<float>(
      opengl_math::triangle<float>(p1, p2, p3), 0, current_index, output);
    ck_assert(output.points().empty());
    ck_assert(output.indices().empty());
    ck_assert(current_index == 0);
  }

  { // equilateral triangle subdivide zero times.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangle_by_midpoint_subdivision<float>(
      opengl_math::triangle<float>(p1, p2, p3), 0, current_index, output);
    ck_assert(output.points().size() == 3);
    ck_assert(output.points()[0] == p1);
    ck_assert(output.points()[1] == p2);
    ck_assert(output.points()[2] == p3);
    ck_assert(output.indices().size() == 3);
    ck_assert(output.indices()[0] == 0u);
    ck_assert(output.indices()[1] == 1u);
    ck_assert(output.indices()[2] == 2u);
  }

  { // equilateral triangle subdivide once in xy-plane.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p3(0.5f, 1.125f, 0.0f);

    opengl_math::point_3d<float> m1 = opengl_math::midpoint_of_line(
      opengl_math::line<float>(p1, p2));
    opengl_math::point_3d<float> m2 = opengl_math::midpoint_of_line(
      opengl_math::line<float>(p2, p3));
    opengl_math::point_3d<float> m3 = opengl_math::midpoint_of_line(
      opengl_math::line<float>(p3, p1));

    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::triangle<float> tri(p1, p2, p3);
    opengl_math::tessellate_triangle_by_midpoint_subdivision<float>(
      tri, 1, current_index, output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 6u);
    ck_assert(output.points()[0] == p1);
    ck_assert(output.points()[1] == m1);
    ck_assert(output.points()[2] == m3);
    ck_assert(output.points()[3] == p2);
    ck_assert(output.points()[4] == m2);
    ck_assert(output.points()[5] == p3);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 12u);
    ck_assert(output.indices()[0] == 0u);
    ck_assert(output.indices()[1] == 1u);
    ck_assert(output.indices()[2] == 2u);
    ck_assert(output.indices()[3] == 1u);
    ck_assert(output.indices()[4] == 3u);
    ck_assert(output.indices()[5] == 4u);
    ck_assert(output.indices()[6] == 1u);
    ck_assert(output.indices()[7] == 4u);
    ck_assert(output.indices()[8] == 2u);
    ck_assert(output.indices()[9] == 2u);
    ck_assert(output.indices()[10] == 4u);
    ck_assert(output.indices()[11] == 5u);
  }

  { // equilateral triangle subdivide once in xy-plane.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p3(0.5f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::triangle<float> tri(p1, p2, p3);
    opengl_math::tessellate_triangle_by_midpoint_subdivision<float>(
      tri, 2, current_index, output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 15u);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 48u);
  }
}
END_TEST

START_TEST(test_tessellate_triangles_by_midpoint_subdivision)
{
  opengl_math::point_3d<float> points[6] = {
    opengl_math::point_3d<float>(+0.0f, -1.0f, +0.0f),
    opengl_math::point_3d<float>(+0.0f, +0.0f, +1.0f),
    opengl_math::point_3d<float>(+1.0f, +0.0f, +0.0f),
    opengl_math::point_3d<float>(+0.0f, +0.0f, -1.0f),
    opengl_math::point_3d<float>(-1.0f, +0.0f, +0.0f),
    opengl_math::point_3d<float>(+0.0f, +1.0f, +0.0f)
  };
  std::vector<opengl_math::triangle<float>> octahedron_tris = {
    opengl_math::triangle<float>(points[0], points[1], points[2]),
    opengl_math::triangle<float>(points[5], points[1], points[2]),
    opengl_math::triangle<float>(points[0], points[3], points[2]),
    opengl_math::triangle<float>(points[5], points[2], points[3]),
    opengl_math::triangle<float>(points[0], points[3], points[4]),
    opengl_math::triangle<float>(points[5], points[3], points[4]),
    opengl_math::triangle<float>(points[0], points[4], points[1]),
    opengl_math::triangle<float>(points[5], points[4], points[1])
  };
  {
    std::uint32_t current_index = 0;
    opengl_math::tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangles_by_midpoint_subdivision<float>(
      octahedron_tris, 0, current_index, output);
    std::size_t points_count = output.points().size();
    ck_assert(points_count == 6u);
    std::size_t indices_count = output.indices().size();
    ck_assert(indices_count == 24u);
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

  tcase_add_test(tc, test_tessellate_triangle_by_subdivision);
  tcase_add_test(tc, test_tessellate_triangles_by_subdivision);
  tcase_add_test(tc, test_tessellate_triangle_by_midpoint_subdivision);
  tcase_add_test(tc, test_tessellate_triangles_by_midpoint_subdivision);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
