#include "opengl_math/primitives/points/type_point_2d.h"
#include "opengl_math/primitives/points/type_point_3d.h"

#include "suite.h"

#include <check.h>

/*! \brief This is a test to see if default constructor for
* 2d and 3d points itializes all of its components to 0.0f
*/
START_TEST(test_default_2d_point_constructor)
{
  opengl_math::point_2d<float> p1;
  ck_assert(p1.x() == 0.0f);
  ck_assert(p1.y() == 0.0f);

  opengl_math::point_2d<double> p2;
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.0);
}
END_TEST

START_TEST(test_default_3d_point_constructor)
{
  opengl_math::point_3d<float> p1;
  ck_assert(p1.x() == 0.0f);
  ck_assert(p1.y() == 0.0f);
  ck_assert(p1.z() == 0.0f);

  opengl_math::point_3d<double> p2;
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.0);
  ck_assert(p2.z() == 0.0);
}
END_TEST

/*! \brief This is a test to see if paramaterized constructor for
* 2d and rgba points itializes all of its components correctly
*/
START_TEST(test_2d_point_constructor)
{
  opengl_math::point_2d<float> p1(1.0f, 2.0f);
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 2.0f);

  opengl_math::point_2d<double> p2(1.0, 0.97);
  ck_assert(p2.x() == 1.0);
  ck_assert(p2.y() == 0.97);
}
END_TEST

START_TEST(test_3d_point_constructor)
{
  opengl_math::point_3d<float> p1(1.0f, 2.0f, 3.0f);
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 2.0f);
  ck_assert(p1.z() == 3.0f);

  opengl_math::point_3d<double> p2(1.0, 0.97, 0.2);
  ck_assert(p2.x() == 1.0);
  ck_assert(p2.y() == 0.97);
  ck_assert(p2.z() == 0.2);
}
END_TEST

/*! \brief This is a test to see if the copy constructor for
* 2d and rgba points initializes all of its components correctly
*/
START_TEST(test_point_2d_copy_constructor)
{
  opengl_math::point_2d<float> p1(0.9f, 0.75f);
  opengl_math::point_2d<float> p2(p1);
  ck_assert(p2.x() == 0.9f);
  ck_assert(p2.y() == 0.75f);

  opengl_math::point_2d<double> p3(0.145, 0.1);
  opengl_math::point_2d<double> p4(p3);
  ck_assert(p4.x() == 0.145);
  ck_assert(p4.y() == 0.1);
}
END_TEST

START_TEST(test_point_3d_copy_constructor)
{
  opengl_math::point_3d<float> p1(0.82f, 1.0e-10f, 10.0);
  opengl_math::point_3d<float> p2(p1);
  ck_assert(p2.x() == 0.82f);
  ck_assert(p2.y() == 0.0000000001f);
  ck_assert(p2.z() == 10.0f);

  opengl_math::point_3d<double> p3(0.7, 1.0e-18, 1.000000001);
  opengl_math::point_3d<double> p4(p3);
  ck_assert(p4.x() == 0.7);
  ck_assert(p4.y() == 1.0e-18);
  ck_assert(p4.z() == 1.000000001);
}
END_TEST

/*! \brief This is a test to see if the assignment operator copies
* the contents of the rhs value into the lhs without modifying the
* rhs.
*/
START_TEST(test_point_2d_assignment_operator)
{
  opengl_math::point_2d<float> p1(0.88f, 0.0f);
  opengl_math::point_2d<float> p2 = p1;
  ck_assert(p2.x() == 0.88f);
  ck_assert(p2.y() == 0.0f);
  ck_assert(p1.x() == 0.88f);
  ck_assert(p1.y() == 0.0f);

  p2 = opengl_math::point_2d<float>(0.99f, 0.0f);
  ck_assert(p2.x() == 0.99f);
  ck_assert(p2.y() == 0.0f);
  ck_assert(p1.x() == 0.88f);
  ck_assert(p1.y() == 0.0f);

  opengl_math::point_2d<double> p3(0.11, 0.22);
  opengl_math::point_2d<double> p4 = p3;
  ck_assert(p4.x() == 0.11);
  ck_assert(p4.y() == 0.22);
  ck_assert(p3.x() == 0.11);
  ck_assert(p3.y() == 0.22);

  p4 = opengl_math::point_2d<double>(0.22, 0.33);
  ck_assert(p4.x() == 0.22);
  ck_assert(p4.y() == 0.33);
  ck_assert(p3.x() == 0.11);
  ck_assert(p3.y() == 0.22);
}
END_TEST

START_TEST(test_point_3d_assignment_operator)
{
  opengl_math::point_3d<float> p1(0.82f, 1.0f, 1.0f);
  opengl_math::point_3d<float> p2 = p1;
  ck_assert(p2.x() == 0.82f);
  ck_assert(p2.y() == 1.0f);
  ck_assert(p2.z() == 1.0f);
  ck_assert(p1.x() == 0.82f);
  ck_assert(p1.y() == 1.0f);
  ck_assert(p1.z() == 1.0f);

  p2 = opengl_math::point_3d<float>(0.83f, 0.99f, 0.98f);
  ck_assert(p2.x() == 0.83f);
  ck_assert(p2.y() == 0.99f);
  ck_assert(p2.z() == 0.98f);
  ck_assert(p1.x() == 0.82f);
  ck_assert(p1.y() == 1.0f);
  ck_assert(p1.z() == 1.0f);

  opengl_math::point_3d<double> p3(0.66, 0.88, 0.988);
  opengl_math::point_3d<double> p4 = p3;
  ck_assert(p4.x() == 0.66);
  ck_assert(p4.y() == 0.88);
  ck_assert(p4.z() == 0.988);
  ck_assert(p3.x() == 0.66);
  ck_assert(p3.y() == 0.88);
  ck_assert(p3.z() == 0.988);

  p4 = opengl_math::point_3d<double>();
  ck_assert(p4.x() == 0.0);
  ck_assert(p4.y() == 0.0);
  ck_assert(p4.z() == 0.0);
  ck_assert(p3.x() == 0.66);
  ck_assert(p3.y() == 0.88);
  ck_assert(p3.z() == 0.988);
}
END_TEST

/*! \brief This is a test to see if the setters for 2d and 3d points
* set the value to a new value.
*/
START_TEST(test_point_2d_setters)
{
  opengl_math::point_2d<float> p1;
  p1.x(1.0f);
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 0.0f);
  p1.y(0.5f);
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 0.5f);
  p1.y(0.2f);
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 0.2f);
  p1.x_and_y(0.0f, 0.0f);
  ck_assert(p1.x() == 0.0f);
  ck_assert(p1.y() == 0.0f);

  opengl_math::point_2d<double> p2;
  p2.x(0.5);
  ck_assert(p2.x() == 0.5);
  ck_assert(p2.y() == 0.0);
  p2.y(0.5);
  ck_assert(p2.x() == 0.5);
  ck_assert(p2.y() == 0.5);
  p2.x(0.4);
  ck_assert(p2.x() == 0.4);
  ck_assert(p2.y() == 0.5);
  p2.x_and_y(0.1, 0.1);
  ck_assert(p2.x() == 0.1);
  ck_assert(p2.y() == 0.1);
}
END_TEST

START_TEST(test_point_3d_setters)
{
  opengl_math::point_3d<float> p1;
  p1.x(0.01f);
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.00f);
  ck_assert(p1.z() == 0.00f);
  p1.y(0.02f);
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.02f);
  ck_assert(p1.z() == 0.00f);
  p1.z(0.05f);
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.02f);
  ck_assert(p1.z() == 0.05f);
  p1.z(0.07f);
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.02f);
  ck_assert(p1.z() == 0.07f);
  p1.x_and_y_and_z(0.09f, 0.11f, 0.15f);
  ck_assert(p1.x() == 0.09f);
  ck_assert(p1.y() == 0.11f);
  ck_assert(p1.z() == 0.15f);

  opengl_math::point_3d<double> p2;
  p2.x(0.0);
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.0);
  ck_assert(p2.z() == 0.0);
  p2.y(0.5);
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.5);
  ck_assert(p2.z() == 0.0);
  p2.z(0.7);
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.5);
  ck_assert(p2.z() == 0.7);
  p2.x(0.1);
  ck_assert(p2.x() == 0.1);
  ck_assert(p2.y() == 0.5);
  ck_assert(p2.z() == 0.7);
  p2.x_and_y_and_z(0.1, 0.1, 0.1);
  ck_assert(p2.x() == 0.1);
  ck_assert(p2.y() == 0.1);
  ck_assert(p2.z() == 0.1);
}
END_TEST

START_TEST(test_point_2d_get_reference)
{
  opengl_math::point_2d<float> p1;
  p1.xref() = 1.0f;
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 0.0f);
  p1.yref() = 0.5f;
  ck_assert(p1.x() == 1.0f);
  ck_assert(p1.y() == 0.5f);
  p1.xref() = 0.2f;
  ck_assert(p1.x() == 0.2f);
  ck_assert(p1.y() == 0.5f);

  opengl_math::point_2d<double> p2;
  p2.xref() = 0.5;
  ck_assert(p2.x() == 0.5);
  ck_assert(p2.y() == 0.0);
  p2.yref() = 0.5;
  ck_assert(p2.x() == 0.5);
  ck_assert(p2.y() == 0.5);
  p2.yref() = 0.4;
  ck_assert(p2.x() == 0.5);
  ck_assert(p2.y() == 0.4);
}
END_TEST

START_TEST(test_point_3d_get_reference)
{
  opengl_math::point_3d<float> p1;
  p1.xref() = 0.01f;
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.00f);
  ck_assert(p1.z() == 0.00f);
  p1.yref() = 0.02f;
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.02f);
  ck_assert(p1.z() == 0.00f);
  p1.zref() = 0.05f;
  ck_assert(p1.x() == 0.01f);
  ck_assert(p1.y() == 0.02f);
  ck_assert(p1.z() == 0.05f);

  opengl_math::point_3d<double> p2;
  p2.xref() = 0.0;
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.0);
  ck_assert(p2.z() == 0.0);
  p2.yref() = 0.5;
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.5);
  ck_assert(p2.z() == 0.0);
  p2.zref() = 0.7;
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.5);
  ck_assert(p2.z() == 0.7);
  p2.zref() = 0.1;
  ck_assert(p2.x() == 0.0);
  ck_assert(p2.y() == 0.5);
  ck_assert(p2.z() == 0.1);
}
END_TEST

/*! \brief This is a test to if two points can be compared for equivalence
*/
START_TEST(test_equivalence_type_point_2d)
{
  opengl_math::point_2d<float> p1;
  opengl_math::point_2d<float> p2;
  ck_assert(p1 == p2);

  p2.x_and_y(0.0001f, 1.000001f);
  ck_assert(p1 != p2);

  opengl_math::point_2d<float> p3(1.0f, 0.5f);
  opengl_math::point_2d<float> p4(1.0f, 0.5f);
  ck_assert(p3 == p4);

  p3.xref() = 0.0f;
  ck_assert(p3 != p4);
}
END_TEST

START_TEST(test_equivalence_type_point_3d)
{
  opengl_math::point_3d<float> p1;
  opengl_math::point_3d<float> p2;
  ck_assert(p1 == p2);

  p2.x_and_y_and_z(0.0001f, 1.000001f, 0.0f);
  ck_assert(p1 != p2);

  opengl_math::point_3d<float> p3(1.0f, 0.7f, 0.8f);
  opengl_math::point_3d<float> p4(1.0f, 0.7f, 0.8f);
  ck_assert(p3 == p4);

  p3.yref() = 0.6f;
  ck_assert(p3 != p4);
}
END_TEST

START_TEST(test_extrenuous_type_point_usecases)
{
  opengl_math::point_2d<float> p1(1.0f, 0.9f);
  // Convert the raw point to an array
  float *raw_data = &p1.xref();
  ck_assert(raw_data[1] == 0.9f);
  raw_data[1] = 0.8f;
  ck_assert(raw_data[0] == 1.0f);
  ck_assert(raw_data[1] == 0.8f);

  // Check to see if it is POD
  opengl_math::point_3d<float> p2(1.0f, 1.0f, 0.9f);
  float point_array[3];
  memcpy(point_array, &p2, sizeof(p2));
  ck_assert(point_array[0] == 1.0f);
  ck_assert(point_array[1] == 1.0f);
  ck_assert(point_array[2] == 0.9f);
}
END_TEST

START_TEST(test_type_point_get_dimension)
{
  ck_assert(2 == opengl_math::point_2d<float>::dimension);
  ck_assert(2 == opengl_math::point_2d<double>::dimension);
  ck_assert(3 == opengl_math::point_3d<float>::dimension);
  ck_assert(3 == opengl_math::point_3d<double>::dimension);
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

  tcase_add_test(tc, test_default_2d_point_constructor);
  tcase_add_test(tc, test_default_3d_point_constructor);
  tcase_add_test(tc, test_2d_point_constructor);
  tcase_add_test(tc, test_3d_point_constructor);
  tcase_add_test(tc, test_point_2d_copy_constructor);
  tcase_add_test(tc, test_point_3d_copy_constructor);
  tcase_add_test(tc, test_point_2d_assignment_operator);
  tcase_add_test(tc, test_point_3d_assignment_operator);
  tcase_add_test(tc, test_point_2d_setters);
  tcase_add_test(tc, test_point_3d_setters);
  tcase_add_test(tc, test_point_2d_get_reference);
  tcase_add_test(tc, test_point_3d_get_reference);
  tcase_add_test(tc, test_equivalence_type_point_2d);
  tcase_add_test(tc, test_equivalence_type_point_3d);
  tcase_add_test(tc, test_extrenuous_type_point_usecases);
  tcase_add_test(tc, test_type_point_get_dimension);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
