#include "opengl_math/math/numbers.h"
#include "opengl_math/primitives/vectors/type_vector_2d.h"

#include "suite.h"

#include <check.h>

/*! \brief This is a test to see if default constructor for
* 2d, 3d, and 4d vectors initializes all of its components to 0.0f
*/
START_TEST(test_default_2d_vector_constructor)
{
  opengl_math::vector_2d<float> tc1;
  ck_assert(tc1.x() == 0.0f);
  ck_assert(tc1.y() == 0.0f);

  opengl_math::vector_2d<double> tc2;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
}
END_TEST

START_TEST(test_default_3d_vector_constructor)
{
  opengl_math::vector_3d<float> tc1;
  ck_assert(tc1.x() == 0.0f);
  ck_assert(tc1.y() == 0.0f);
  ck_assert(tc1.z() == 0.0f);

  opengl_math::vector_3d<double> tc2;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
  ck_assert(tc2.z() == 0.0);
}
END_TEST

START_TEST(test_default_4d_vector_constructor)
{
  opengl_math::vector_4d<float> tc1;
  ck_assert(tc1.x() == 0.0f);
  ck_assert(tc1.y() == 0.0f);
  ck_assert(tc1.z() == 0.0f);
  ck_assert(tc1.w() == 0.0f);

  opengl_math::vector_4d<double> tc2;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
  ck_assert(tc2.z() == 0.0);
  ck_assert(tc2.w() == 0.0);
}
END_TEST

/*! \brief This is a test to see if paramaterized constructor for
* 2d, 3d, and 4d vectors itializes all of its components correctly
*/
START_TEST(test_2d_vector_constructor)
{
  opengl_math::vector_2d<float> tc1(1.0f, 2.0f);
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 2.0f);

  opengl_math::vector_2d<double> tc2(1.0, 0.97);
  ck_assert(tc2.x() == 1.0);
  ck_assert(tc2.y() == 0.97);
}
END_TEST

START_TEST(test_3d_vector_constructor)
{
  opengl_math::vector_3d<float> tc1(1.0f, 2.0f, 3.0f);
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 2.0f);
  ck_assert(tc1.z() == 3.0f);

  opengl_math::vector_3d<double> tc2(1.0, 0.97, 0.2);
  ck_assert(tc2.x() == 1.0);
  ck_assert(tc2.y() == 0.97);
  ck_assert(tc2.z() == 0.2);
}
END_TEST

START_TEST(test_4d_vector_constructor)
{
  opengl_math::vector_4d<float> tc1(1.0f, 2.0f, 4.0f, 3.0f);
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 2.0f);
  ck_assert(tc1.z() == 4.0f);
  ck_assert(tc1.w() == 3.0f);

  opengl_math::vector_4d<double> tc2(1.0, 0.97, 0.2, 0.1);
  ck_assert(tc2.x() == 1.0);
  ck_assert(tc2.y() == 0.97);
  ck_assert(tc2.z() == 0.2);
  ck_assert(tc2.w() == 0.1);
}
END_TEST

/*! \brief This is a test to see if the copy constructor for
* 2d and 4d vectors itializes all of its components correctly
*/
START_TEST(test_vector_2d_copy_constructor)
{
  opengl_math::vector_2d<float> tc1(0.9f, 0.75f);
  opengl_math::vector_2d<float> tc2(tc1);
  ck_assert(tc2.x() == 0.9f);
  ck_assert(tc2.y() == 0.75f);

  opengl_math::vector_2d<double> tc3(0.145, 0.1);
  opengl_math::vector_2d<double> tc4(tc3);
  ck_assert(tc4.x() == 0.145);
  ck_assert(tc4.y() == 0.1);
}
END_TEST

START_TEST(test_vector_3d_copy_constructor)
{
  opengl_math::vector_3d<float> tc1(0.82f, 1.0e-10f, 10.0f);
  opengl_math::vector_3d<float> tc2(tc1);
  ck_assert(tc2.x() == 0.82f);
  ck_assert(tc2.y() == 0.0000000001f);
  ck_assert(tc2.z() == 10.0f);

  opengl_math::vector_3d<double> tc3(0.7, 1.0e-18, 1.000000001);
  opengl_math::vector_3d<double> tc4(tc3);
  ck_assert(tc4.x() == 0.7);
  ck_assert(tc4.y() == 1.0e-18);
  ck_assert(tc4.z() == 1.000000001);
}
END_TEST

START_TEST(test_vector_4d_copy_constructor)
{
  opengl_math::vector_4d<float> tc1(0.82f, 1.0e-10f, 10.0f, 1.0f);
  opengl_math::vector_4d<float> tc2(tc1);
  ck_assert(tc2.x() == 0.82f);
  ck_assert(tc2.y() == 0.0000000001f);
  ck_assert(tc2.z() == 10.0f);
  ck_assert(tc2.w() == 1.0f);

  opengl_math::vector_4d<double> tc3(0.7, 1.0e-18, 1.000000001, 1.0);
  opengl_math::vector_4d<double> tc4(tc3);
  ck_assert(tc4.x() == 0.7);
  ck_assert(tc4.y() == 1.0e-18);
  ck_assert(tc4.z() == 1.000000001);
  ck_assert(tc4.w() == 1.0);
}
END_TEST

/*! \brief This is a test to see if the assignment operator copies
* the contents of the rhs value into the lhs without modifying the
* rhs.
*/
START_TEST(test_vector_2d_assignment_operator)
{
  opengl_math::vector_2d<float> tc1(0.88f, 0.0f);
  opengl_math::vector_2d<float> tc2 = tc1;
  ck_assert(tc2.x() == 0.88f);
  ck_assert(tc2.y() == 0.0f);
  ck_assert(tc1.x() == 0.88f);
  ck_assert(tc1.y() == 0.0f);

  tc2 = opengl_math::vector_2d<float>(0.99f, 0.0f);
  ck_assert(tc2.x() == 0.99f);
  ck_assert(tc2.y() == 0.0f);
  ck_assert(tc1.x() == 0.88f);
  ck_assert(tc1.y() == 0.0f);

  opengl_math::vector_2d<double> tc3(0.11, 0.22);
  opengl_math::vector_2d<double> tc4 = tc3;
  ck_assert(tc4.x() == 0.11);
  ck_assert(tc4.y() == 0.22);
  ck_assert(tc3.x() == 0.11);
  ck_assert(tc3.y() == 0.22);

  tc4 = opengl_math::vector_2d<double>(0.22, 0.33);
  ck_assert(tc4.x() == 0.22);
  ck_assert(tc4.y() == 0.33);
  ck_assert(tc3.x() == 0.11);
  ck_assert(tc3.y() == 0.22);
}
END_TEST

START_TEST(test_vector_3d_assignment_operator)
{
  opengl_math::vector_3d<float> tc1(0.82f, 1.0f, 1.0f);
  opengl_math::vector_3d<float> tc2 = tc1;
  ck_assert(tc2.x() == 0.82f);
  ck_assert(tc2.y() == 1.0f);
  ck_assert(tc2.z() == 1.0f);
  ck_assert(tc1.x() == 0.82f);
  ck_assert(tc1.y() == 1.0f);
  ck_assert(tc1.z() == 1.0f);

  tc2 = opengl_math::vector_3d<float>(0.83f, 0.99f, 0.98f);
  ck_assert(tc2.x() == 0.83f);
  ck_assert(tc2.y() == 0.99f);
  ck_assert(tc2.z() == 0.98f);
  ck_assert(tc1.x() == 0.82f);
  ck_assert(tc1.y() == 1.0f);
  ck_assert(tc1.z() == 1.0f);

  opengl_math::vector_3d<double> tc3(0.66, 0.88, 0.988);
  opengl_math::vector_3d<double> tc4 = tc3;
  ck_assert(tc4.x() == 0.66);
  ck_assert(tc4.y() == 0.88);
  ck_assert(tc4.z() == 0.988);
  ck_assert(tc3.x() == 0.66);
  ck_assert(tc3.y() == 0.88);
  ck_assert(tc3.z() == 0.988);

  tc4 = opengl_math::vector_3d<double>();
  ck_assert(tc4.x() == 0.0);
  ck_assert(tc4.y() == 0.0);
  ck_assert(tc4.z() == 0.0);
  ck_assert(tc3.x() == 0.66);
  ck_assert(tc3.y() == 0.88);
  ck_assert(tc3.z() == 0.988);
}
END_TEST

START_TEST(test_vector_4d_assignment_operator)
{
  opengl_math::vector_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
  opengl_math::vector_4d<float> tc2 = tc1;
  ck_assert(tc2.x() == 0.82f);
  ck_assert(tc2.y() == 1.0f);
  ck_assert(tc2.z() == 1.0f);
  ck_assert(tc2.w() == 0.92f);
  ck_assert(tc1.x() == 0.82f);
  ck_assert(tc1.y() == 1.0f);
  ck_assert(tc1.z() == 1.0f);
  ck_assert(tc1.w() == 0.92f);

  tc2 = opengl_math::vector_4d<float>(0.83f, 0.99f, 0.98f, 0.01f);
  ck_assert(tc2.x() == 0.83f);
  ck_assert(tc2.y() == 0.99f);
  ck_assert(tc2.z() == 0.98f);
  ck_assert(tc2.w() == 0.01f);
  ck_assert(tc1.x() == 0.82f);
  ck_assert(tc1.y() == 1.0f);
  ck_assert(tc1.z() == 1.0f);
  ck_assert(tc1.w() == 0.92f);

  opengl_math::vector_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
  opengl_math::vector_4d<double> tc4 = tc3;
  ck_assert(tc4.x() == 0.66);
  ck_assert(tc4.y() == 0.88);
  ck_assert(tc4.z() == 0.988);
  ck_assert(tc4.w() == 0.28);
  ck_assert(tc3.x() == 0.66);
  ck_assert(tc3.y() == 0.88);
  ck_assert(tc3.z() == 0.988);
  ck_assert(tc3.w() == 0.28);

  tc4 = opengl_math::vector_4d<double>();
  ck_assert(tc4.x() == 0.0);
  ck_assert(tc4.y() == 0.0);
  ck_assert(tc4.z() == 0.0);
  ck_assert(tc4.w() == 0.0);
  ck_assert(tc3.x() == 0.66);
  ck_assert(tc3.y() == 0.88);
  ck_assert(tc3.z() == 0.988);
  ck_assert(tc3.w() == 0.28);
}
END_TEST

/*! \brief This is a test to see if both constant and non constant versions
* of the subscript operators behave according to specification.
*/
START_TEST(test_vector_2d_subscript_operator)
{
  opengl_math::vector_2d<float> tc1(0.82f, 1.0f);
  ck_assert(tc1[0] == 0.82f);
  ck_assert(tc1[1] == 1.0f);
  tc1[0] = 0.81f;
  ck_assert(tc1[0] == 0.81f);
  ck_assert(tc1[1] == 1.0f);

  opengl_math::vector_2d<double> tc3(0.66, 0.88);
  ck_assert(tc3[0] == 0.66);
  ck_assert(tc3[1] == 0.88);
  tc3[1] = 0.99;
  ck_assert(tc3[0] == 0.66);
  ck_assert(tc3[1] == 0.99);
}
END_TEST

START_TEST(test_vector_3d_subscript_operator)
{
  opengl_math::vector_3d<float> tc1(0.82f, 1.0f, 1.0f);
  ck_assert(tc1[0] == 0.82f);
  ck_assert(tc1[1] == 1.0f);
  ck_assert(tc1[2] == 1.0f);
  tc1[0] = 0.83f;
  tc1[1] = 0.99f;
  ck_assert(tc1[0] == 0.83f);
  ck_assert(tc1[1] == 0.99f);
  ck_assert(tc1[2] == 1.0f);

  opengl_math::vector_3d<double> tc3(0.66, 0.88, 0.988);
  ck_assert(tc3[0] == 0.66);
  ck_assert(tc3[1] == 0.88);
  ck_assert(tc3[2] == 0.988);
  tc3[2] = 0.01;
  ck_assert(tc3[0] == 0.66);
  ck_assert(tc3[1] == 0.88);
  ck_assert(tc3[2] == 0.01);
}
END_TEST

START_TEST(test_vector_4d_subscript_operator)
{
  opengl_math::vector_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
  ck_assert(tc1[0] == 0.82f);
  ck_assert(tc1[1] == 1.0f);
  ck_assert(tc1[2] == 1.0f);
  ck_assert(tc1[3] == 0.92f);
  tc1[0] = 0.00f;
  tc1[1] = 0.00f;
  ck_assert(tc1[0] == 0.00f);
  ck_assert(tc1[1] == 0.00f);
  ck_assert(tc1[2] == 1.00f);
  ck_assert(tc1[3] == 0.92f);

  opengl_math::vector_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
  ck_assert(tc3[0] == 0.66);
  ck_assert(tc3[1] == 0.88);
  ck_assert(tc3[2] == 0.988);
  ck_assert(tc3[3] == 0.28);
  tc3[2] = 0.00;
  tc3[3] = 0.00;
  ck_assert(tc3[0] == 0.66);
  ck_assert(tc3[1] == 0.88);
  ck_assert(tc3[2] == 0.00);
  ck_assert(tc3[3] == 0.00);
}
END_TEST

/*! \brief This is a test to see if the setters for 2d and 3d vectors
* set the value to a new value.
*/
START_TEST(test_vector_2d_setters)
{
  opengl_math::vector_2d<float> tc1;
  tc1.x(1.0f);
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 0.0f);
  tc1.y(0.5f);
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 0.5f);
  tc1.y(0.2f);
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 0.2f);
  tc1.x_and_y(0.0f, 0.0f);
  ck_assert(tc1.x() == 0.0f);
  ck_assert(tc1.y() == 0.0f);

  opengl_math::vector_2d<double> tc2;
  tc2.x(0.5);
  ck_assert(tc2.x() == 0.5);
  ck_assert(tc2.y() == 0.0);
  tc2.y(0.5);
  ck_assert(tc2.x() == 0.5);
  ck_assert(tc2.y() == 0.5);
  tc2.x(0.4);
  ck_assert(tc2.x() == 0.4);
  ck_assert(tc2.y() == 0.5);
  tc2.x_and_y(0.1, 0.1);
  ck_assert(tc2.x() == 0.1);
  ck_assert(tc2.y() == 0.1);
}
END_TEST

START_TEST(test_vector_3d_setters)
{
  opengl_math::vector_3d<float> tc1;
  tc1.x(0.01f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.00f);
  ck_assert(tc1.z() == 0.00f);
  tc1.y(0.02f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.00f);
  tc1.z(0.05f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.05f);
  tc1.z(0.07f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.07f);
  tc1.x_and_y_and_z(0.09f, 0.11f, 0.15f);
  ck_assert(tc1.x() == 0.09f);
  ck_assert(tc1.y() == 0.11f);
  ck_assert(tc1.z() == 0.15f);

  opengl_math::vector_3d<double> tc2;
  tc2.x(0.0);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
  ck_assert(tc2.z() == 0.0);
  tc2.y(0.5);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.0);
  tc2.z(0.7);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  tc2.x(0.1);
  ck_assert(tc2.x() == 0.1);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  tc2.x_and_y_and_z(0.1, 0.1, 0.1);
  ck_assert(tc2.x() == 0.1);
  ck_assert(tc2.y() == 0.1);
  ck_assert(tc2.z() == 0.1);
}
END_TEST

START_TEST(test_vector_4d_setters)
{
  opengl_math::vector_4d<float> tc1;
  tc1.x(0.01f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.00f);
  ck_assert(tc1.z() == 0.00f);
  ck_assert(tc1.w() == 0.00f);
  tc1.y(0.02f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.00f);
  ck_assert(tc1.w() == 0.00f);
  tc1.z(0.05f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.05f);
  ck_assert(tc1.w() == 0.00f);
  tc1.w(0.07f);
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.05f);
  ck_assert(tc1.w() == 0.07f);
  tc1.x_and_y_and_z_and_w(0.09f, 0.11f, 0.15f, 0.22f);
  ck_assert(tc1.x() == 0.09f);
  ck_assert(tc1.y() == 0.11f);
  ck_assert(tc1.z() == 0.15f);
  ck_assert(tc1.w() == 0.22f);

  opengl_math::vector_4d<double> tc2;
  tc2.x(0.0);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
  ck_assert(tc2.z() == 0.0);
  ck_assert(tc2.w() == 0.0);
  tc2.y(0.5);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.0);
  ck_assert(tc2.w() == 0.0);
  tc2.z(0.7);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  ck_assert(tc2.w() == 0.0);
  tc2.w(0.1);
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  ck_assert(tc2.w() == 0.1);
  tc2.x_and_y_and_z_and_w(0.1, 0.1, 0.1, 0.1);
  ck_assert(tc2.x() == 0.1);
  ck_assert(tc2.y() == 0.1);
  ck_assert(tc2.z() == 0.1);
  ck_assert(tc2.w() == 0.1);
}
END_TEST

/*! \brief This is a test to see if the getters by ref for 2d, 3d, and 4d
* vectors set the value to a new value.
*/
START_TEST(test_vector_2d_get_reference)
{
  opengl_math::vector_2d<float> tc1;
  tc1.xref() = 1.0f;
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 0.0f);
  tc1.yref() = 0.5f;
  ck_assert(tc1.x() == 1.0f);
  ck_assert(tc1.y() == 0.5f);
  tc1.xref() = 0.2f;
  ck_assert(tc1.x() == 0.2f);
  ck_assert(tc1.y() == 0.5f);

  opengl_math::vector_2d<double> tc2;
  tc2.xref() = 0.5;
  ck_assert(tc2.x() == 0.5);
  ck_assert(tc2.y() == 0.0);
  tc2.yref() = 0.5;
  ck_assert(tc2.x() == 0.5);
  ck_assert(tc2.y() == 0.5);
  tc2.yref() = 0.4;
  ck_assert(tc2.x() == 0.5);
  ck_assert(tc2.y() == 0.4);
}
END_TEST

START_TEST(test_vector_3d_get_reference)
{
  opengl_math::vector_3d<float> tc1;
  tc1.xref() = 0.01f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.00f);
  ck_assert(tc1.z() == 0.00f);
  tc1.yref() = 0.02f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.00f);
  tc1.zref() = 0.05f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.05f);

  opengl_math::vector_3d<double> tc2;
  tc2.xref() = 0.0;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
  ck_assert(tc2.z() == 0.0);
  tc2.yref() = 0.5;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.0);
  tc2.zref() = 0.7;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  tc2.zref() = 0.1;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.1);
}
END_TEST

START_TEST(test_vector_4d_get_reference)
{
  opengl_math::vector_4d<float> tc1;
  tc1.xref() = 0.01f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.00f);
  ck_assert(tc1.z() == 0.00f);
  ck_assert(tc1.w() == 0.00f);
  tc1.yref() = 0.02f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.00f);
  ck_assert(tc1.w() == 0.00f);
  tc1.zref() = 0.05f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.05f);
  ck_assert(tc1.w() == 0.00f);
  tc1.wref() = 1.0f;
  ck_assert(tc1.x() == 0.01f);
  ck_assert(tc1.y() == 0.02f);
  ck_assert(tc1.z() == 0.05f);
  ck_assert(tc1.w() == 1.00f);

  opengl_math::vector_4d<double> tc2;
  tc2.xref() = 0.0;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.0);
  ck_assert(tc2.z() == 0.0);
  ck_assert(tc2.w() == 0.0);
  tc2.yref() = 0.5;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.0);
  ck_assert(tc2.w() == 0.0);
  tc2.zref() = 0.7;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  ck_assert(tc2.w() == 0.0);
  tc2.wref() = 0.1;
  ck_assert(tc2.x() == 0.0);
  ck_assert(tc2.y() == 0.5);
  ck_assert(tc2.z() == 0.7);
  ck_assert(tc2.w() == 0.1);
}
END_TEST

/*! \brief This is a test to if two vectors can be compared for equivalence
*/
START_TEST(test_equivalence_type_vector_2d)
{
  opengl_math::vector_2d<float> tc1;
  opengl_math::vector_2d<float> tc2;
  ck_assert(tc1 == tc2);

  tc2.x_and_y(0.0001f, 1.000001f);
  ck_assert(tc1 != tc2);

  opengl_math::vector_2d<float> tc3(1.0f, 0.5f);
  opengl_math::vector_2d<float> tc4(1.0f, 0.5f);
  ck_assert(tc3 == tc4);

  tc3.xref() = 0.0f;
  ck_assert(tc3 != tc4);
}
END_TEST

START_TEST(test_equivalence_type_vector_3d)
{
  opengl_math::vector_3d<float> tc1;
  opengl_math::vector_3d<float> tc2;
  ck_assert(tc1 == tc2);

  tc2.x_and_y_and_z(0.0001f, 1.000001f, 0.0f);
  ck_assert(tc1 != tc2);

  opengl_math::vector_3d<float> tc3(1.0f, 0.7f, 0.8f);
  opengl_math::vector_3d<float> tc4(1.0f, 0.7f, 0.8f);
  ck_assert(tc3 == tc4);

  tc3.yref() = 0.6f;
  ck_assert(tc3 != tc4);
}
END_TEST

START_TEST(test_equivalence_type_vector_4d)
{
  opengl_math::vector_4d<float> tc1;
  opengl_math::vector_4d<float> tc2;
  ck_assert(tc1 == tc2);

  tc2.x_and_y_and_z_and_w(0.0001f, 1.000001f, 0.0f, 0.0f);
  ck_assert(tc1 != tc2);

  opengl_math::vector_4d<float> tc3(1.0f, 0.7f, 0.8f, 0.8f);
  opengl_math::vector_4d<float> tc4(1.0f, 0.7f, 0.8f, 0.8f);
  ck_assert(tc3 == tc4);

  tc3.yref() = 0.6f;
  ck_assert(tc3 != tc4);
}
END_TEST

START_TEST(test_extrenuous_type_vector_usecases)
{
  opengl_math::vector_2d<float> tc1(1.0f, 0.9f);
  // Convert the raw vector to an array
  float *raw_data = &tc1.xref();
  ck_assert(raw_data[1] == 0.9f);
  raw_data[1] = 0.8f;
  ck_assert(raw_data[0] == 1.0f);
  ck_assert(raw_data[1] == 0.8f);

  // Check to see if it is POD
  opengl_math::vector_3d<float> tc2(1.0f, 1.0f, 0.9f);
  float vector_array[3];
  memcpy(vector_array, &tc2, sizeof(tc2));
  ck_assert(vector_array[0] == 1.0f);
  ck_assert(vector_array[1] == 1.0f);
  ck_assert(vector_array[2] == 0.9f);
}
END_TEST

/*! brief Arithmatic operator tests
*/
START_TEST(test_magnitude_2d)
{
  const opengl_math::vector_2d<float> vf(20.0f, 10.0f);
  ck_assert(opengl_math::float_equals(
    static_cast<float>(sqrt(500.0f)), vf.magnitude(),
    1e-006f));

  const opengl_math::vector_2d<double> vd(20.0, 10.0);
  ck_assert(opengl_math::float_equals(sqrt(500.0), vd.magnitude(),
    1e-006));
}
END_TEST

START_TEST(test_magnitude_3d)
{
  const opengl_math::vector_3d<float> vf(20.0f, 10.0f, 20.0f);
  ck_assert(opengl_math::float_equals(30.0f, vf.magnitude(), 1e-006f));

  const opengl_math::vector_3d<double> vd(20.0, 10.0, 20.0);
  ck_assert(opengl_math::float_equals(30.0, vd.magnitude(), 1e-006));
}
END_TEST

START_TEST(test_magnitude_4d)
{
  const opengl_math::vector_4d<float> vf(20.0f, 10.0f, 20.0f, 0.0f);
  ck_assert(opengl_math::float_equals(30.0f, vf.magnitude(),
    1e-006f));

  const opengl_math::vector_4d<double> vd(20.0, 10.0, 20.0, 0.0);
  ck_assert(opengl_math::float_equals(30.0, vd.magnitude(), 1e-006));
}
END_TEST

START_TEST(test_normalize_2d)
{
  opengl_math::vector_2d<float> vf(20.0f, 10.0f);
  vf.normalize();
  ck_assert(opengl_math::float_equals(0.89443f, vf.x(), 1e-005f));
  ck_assert(opengl_math::float_equals(0.44721f, vf.y(), 1e-005f));

  opengl_math::vector_2d<double> vd(20.0, 10.0);
  vd.normalize();
  ck_assert(opengl_math::float_equals(0.89443, vd.x(), 1e-005));
  ck_assert(opengl_math::float_equals(0.44721, vd.y(), 1e-005));
}
END_TEST

START_TEST(test_normalize_3d)
{
  opengl_math::vector_3d<float> vf(20.0f, 10.0f, 20.0f);
  vf.normalize();
  ck_assert(opengl_math::float_equals(2.0f / 3.0f, vf.x(), 1e-005f));
  ck_assert(opengl_math::float_equals(1.0f / 3.0f, vf.y(), 1e-005f));
  ck_assert(opengl_math::float_equals(2.0f / 3.0f, vf.z(), 1e-005f));

  opengl_math::vector_3d<double> vd(20.0, 10.0, 20.0);
  vd.normalize();
  ck_assert(opengl_math::float_equals(2.0 / 3.0, vd.x(), 1e-005));
  ck_assert(opengl_math::float_equals(1.0 / 3.0, vd.y(), 1e-005));
  ck_assert(opengl_math::float_equals(2.0 / 3.0, vd.z(), 1e-005));
}
END_TEST

START_TEST(test_normalize_4d)
{
  opengl_math::vector_4d<float> vf(20.0f, 10.0f, 20.0f, 0.0f);
  vf.normalize();
  ck_assert(opengl_math::float_equals(2.0f / 3.0f, vf.x(), 1e-005f));
  ck_assert(opengl_math::float_equals(1.0f / 3.0f, vf.y(), 1e-005f));
  ck_assert(opengl_math::float_equals(2.0f / 3.0f, vf.z(), 1e-005f));
  ck_assert(opengl_math::float_equals(0.0f, vf.w(), 1e-005f));

  opengl_math::vector_4d<double> vd(20.0, 10.0, 20.0, 0.0f);
  vd.normalize();
  ck_assert(opengl_math::float_equals(2.0 / 3.0, vd.x(), 1e-005));
  ck_assert(opengl_math::float_equals(1.0 / 3.0, vd.y(), 1e-005));
  ck_assert(opengl_math::float_equals(2.0 / 3.0, vd.z(), 1e-005));
  ck_assert(opengl_math::float_equals(0.0, vd.w(), 1e-005));
}
END_TEST

START_TEST(test_dot_2d)
{
  const opengl_math::vector_2d<float> vf1(1.0f, 2.0f);
  const opengl_math::vector_2d<float> vf2(3.0f, 2.0f);
  ck_assert(opengl_math::float_equals(7.0f, vf1.dot(vf2), 1e-006f));

  const opengl_math::vector_2d<double> vd1(1.0, 2.0);
  const opengl_math::vector_2d<double> vd2(3.0, 2.0);
  ck_assert(opengl_math::float_equals(7.0, vd1.dot(vd2), 1e-006));
}
END_TEST

START_TEST(test_dot_3d)
{
  const opengl_math::vector_3d<float> vf1(1.0f, 2.0f, 4.0f);
  const opengl_math::vector_3d<float> vf2(3.0f, 2.0f, 8.0f);
  ck_assert(opengl_math::float_equals(39.0f, vf1.dot(vf2), 1e-006f));

  const opengl_math::vector_3d<double> vd1(1.0, 2.0, 4.0);
  const opengl_math::vector_3d<double> vd2(3.0, 2.0, 8.0);
  ck_assert(opengl_math::float_equals(39.0, vd1.dot(vd2), 1e-006));
}
END_TEST

START_TEST(test_dot_4d)
{
  const opengl_math::vector_4d<float> vf1(1.0f, 2.0f, 4.0f, 10000.0f);
  const opengl_math::vector_4d<float> vf2(3.0f, 2.0f, 8.0f, 90000.0f);
  ck_assert(opengl_math::float_equals(900000039.0f, vf1.dot(vf2),
    1e-006f));

  const opengl_math::vector_4d<double> vd1(1.0, 2.0, 4.0, 10000.0);
  const opengl_math::vector_4d<double> vd2(3.0, 2.0, 8.0, 90000.0);
  ck_assert(opengl_math::float_equals(900000039.0, vd1.dot(vd2),
    1e-006));
}
END_TEST

START_TEST(test_cross_3d)
{
  {
    const opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 8.0f);
    const opengl_math::vector_3d<float> vf2(2.0f, 4.0f, 8.0f);

    const opengl_math::vector_3d<float> cross12 = vf1.cross(vf2);
    ck_assert(opengl_math::float_equals(0.0f, cross12.x(), 1e-006f));
    ck_assert(opengl_math::float_equals(0.0f, cross12.y(), 1e-006f));
    ck_assert(opengl_math::float_equals(0.0f, cross12.z(), 1e-006f));

    const opengl_math::vector_3d<float> cross21 = vf2.cross(vf1);
    ck_assert(opengl_math::float_equals(0.0f, cross21.x(), 1e-006f));
    ck_assert(opengl_math::float_equals(0.0f, cross21.y(), 1e-006f));
    ck_assert(opengl_math::float_equals(0.0f, cross21.z(), 1e-006f));
  }

  {
    const opengl_math::vector_3d<double> vd1(1.0, 0.0, 0.0);
    const opengl_math::vector_3d<double> vd2(0.0, 1.0, 0.0);
    const opengl_math::vector_3d<double> vd3(0.0, 0.0, 1.0);

    const opengl_math::vector_3d<double> crossxy = vd1.cross(vd2);
    ck_assert(opengl_math::float_equals(0.0, crossxy.x(), 1e-006));
    ck_assert(opengl_math::float_equals(0.0, crossxy.y(), 1e-006));
    ck_assert(opengl_math::float_equals(1.0, crossxy.z(), 1e-006));

    const opengl_math::vector_3d<double> crossxz = vd3.cross(vd1);
    ck_assert(opengl_math::float_equals(0.0, crossxz.x(), 1e-006));
    ck_assert(opengl_math::float_equals(1.0, crossxz.y(), 1e-006));
    ck_assert(opengl_math::float_equals(0.0, crossxz.z(), 1e-006));

    const opengl_math::vector_3d<double> crossyz = vd2.cross(vd3);
    ck_assert(opengl_math::float_equals(1.0, crossyz.x(), 1e-006));
    ck_assert(opengl_math::float_equals(0.0, crossyz.y(), 1e-006));
    ck_assert(opengl_math::float_equals(0.0, crossyz.z(), 1e-006));
  }
}
END_TEST

START_TEST(test_plus_equals_2d)
{
  opengl_math::vector_2d<float> vf1(12.38f, 1.22f);
  vf1 += opengl_math::vector_2d<float>(0.62f, 0.78f);
  ck_assert(opengl_math::float_equals(13.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(2.0f, vf1.y(), 1e-006f));
}
END_TEST

START_TEST(test_plus_equals_3d)
{
  opengl_math::vector_3d<float> vf1(12.38f, 1.22f, 3.06f);
  vf1 += opengl_math::vector_3d<float>(0.62f, 0.78f, 1.94f);
  ck_assert(opengl_math::float_equals(13.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(2.0f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(5.0f, vf1.z(), 1e-006f));
}
END_TEST

START_TEST(test_plus_equals_4d)
{
  opengl_math::vector_4d<float> vf1(12.38f, 1.22f, 3.06f, 0.01f);
  vf1 += opengl_math::vector_4d<float>(0.62f, 0.78f, 1.94f, 0.99f);
  ck_assert(opengl_math::float_equals(13.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(2.0f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(5.0f, vf1.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(1.0f, vf1.w(), 1e-006f));
}
END_TEST

START_TEST(test_minus_equals_2d)
{
  opengl_math::vector_2d<float> vf1(12.38f, 1.22f);
  vf1 -= opengl_math::vector_2d<float>(0.38f, 0.22f);
  ck_assert(opengl_math::float_equals(12.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(1.00f, vf1.y(), 1e-006f));
}
END_TEST

START_TEST(test_minus_equals_3d)
{
  opengl_math::vector_3d<float> vf1(12.38f, 1.22f, 0.01f);
  vf1 -= opengl_math::vector_3d<float>(0.38f, 0.22f, 0.01f);
  ck_assert(opengl_math::float_equals(12.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(1.00f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf1.z(), 1e-006f));
}
END_TEST

START_TEST(test_minus_equals_4d)
{
  opengl_math::vector_4d<float> vf1(12.38f, 1.22f, 0.01f, 0.00f);
  vf1 -= opengl_math::vector_4d<float>(0.38f, 0.22f, 0.01f, 0.00f);
  ck_assert(opengl_math::float_equals(12.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(1.00f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf1.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf1.w(), 1e-006f));
}
END_TEST

START_TEST(test_times_equals_scalar_2d)
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  vf1 *= 2.0f;
  ck_assert(opengl_math::float_equals(4.00f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.00f, vf1.y(), 1e-006f));
}
END_TEST

START_TEST(test_times_equals_scalar_3d)
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 2.0f);
  vf1 *= 2.0f;
  ck_assert(opengl_math::float_equals(4.00f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.00f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(4.00f, vf1.z(), 1e-006f));
}
END_TEST

START_TEST(test_times_equals_scalar_4d)
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 2.0f, 8.1f);
  vf1 *= 2.0f;
  ck_assert(opengl_math::float_equals(4.00f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.00f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(4.00f, vf1.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(16.2f, vf1.w(), 1e-006f));
}
END_TEST

START_TEST(test_addition_2d)
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  opengl_math::vector_2d<float> vf2(2.0f, 4.0f);

  opengl_math::vector_2d<float> vf3 = vf1 + vf2;
  opengl_math::vector_2d<float> vf4 = vf2 + vf1;

  ck_assert(vf3 == vf4);
  ck_assert(opengl_math::float_equals(4.00f, vf3.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.00f, vf3.y(), 1e-006f));
}
END_TEST

START_TEST(test_addition_3d)
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  opengl_math::vector_3d<float> vf2(2.0f, 4.0f, 15.7f);

  opengl_math::vector_3d<float> vf3 = vf1 + vf2;
  opengl_math::vector_3d<float> vf4 = vf2 + vf1;

  ck_assert(vf3 == vf4);
  ck_assert(opengl_math::float_equals(4.00f, vf3.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.00f, vf3.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(32.00f, vf3.z(), 1e-006f));
}
END_TEST

START_TEST(test_addition_4d)
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  opengl_math::vector_4d<float> vf2(2.0f, 4.0f, 15.7f, 0.7f);

  opengl_math::vector_4d<float> vf3 = vf1 + vf2;
  opengl_math::vector_4d<float> vf4 = vf2 + vf1;

  ck_assert(vf3 == vf4);
  ck_assert(opengl_math::float_equals(4.00f, vf3.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.00f, vf3.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(32.00f, vf3.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(100.9f, vf3.w(), 1e-001f));
}
END_TEST

START_TEST(test_subtraction_2d)
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  opengl_math::vector_2d<float> vf2(2.0f, 4.0f);

  opengl_math::vector_2d<float> vf3 = vf1 - vf2;
  ck_assert(opengl_math::float_equals(0.0f, vf3.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.0f, vf3.y(), 1e-006f));

  opengl_math::vector_2d<float> vf4 = vf2 - vf1;
  ck_assert(opengl_math::float_equals(0.0f, vf4.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.0f, vf4.y(), 1e-006f));
}
END_TEST

START_TEST(test_subtraction_3d)
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  opengl_math::vector_3d<float> vf2(2.0f, 4.0f, 15.7f);

  opengl_math::vector_3d<float> vf3 = vf1 - vf2;
  ck_assert(opengl_math::float_equals(0.00f, vf3.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf3.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.6f, vf3.z(), 1e-006f));

  opengl_math::vector_3d<float> vf4 = vf2 - vf1;
  ck_assert(opengl_math::float_equals(0.00f, vf4.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf4.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(-0.6f, vf4.z(), 1e-006f));
}
END_TEST

START_TEST(test_subtraction_4d)
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  opengl_math::vector_4d<float> vf2(2.0f, 4.0f, 15.7f, 0.7f);

  opengl_math::vector_4d<float> vf3 = vf1 - vf2;
  ck_assert(opengl_math::float_equals(0.00f, vf3.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf3.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.6f, vf3.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(99.5f, vf3.w(), 1e-006f));

  opengl_math::vector_4d<float> vf4 = vf2 - vf1;
  ck_assert(opengl_math::float_equals(0.00f, vf4.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(0.00f, vf4.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(-0.6f, vf4.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(-99.5f, vf4.w(), 1e-006f));
}
END_TEST

START_TEST(test_unary_minus_2d)
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  vf1 = -vf1;

  ck_assert(-2.0f == vf1.x());
  ck_assert(-4.0f == vf1.y());
}
END_TEST

START_TEST(test_unary_minus_3d)
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  vf1 = -vf1;

  ck_assert(-2.0f == vf1.x());
  ck_assert(-4.0f == vf1.y());
  ck_assert(-16.3f == vf1.z());
}
END_TEST

START_TEST(test_unary_minus_4d)
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  vf1 = -vf1;

  ck_assert(-2.0f == vf1.x());
  ck_assert(-4.0f == vf1.y());
  ck_assert(-16.3f == vf1.z());
  ck_assert(-100.2f == vf1.w());
}
END_TEST

START_TEST(test_time_scalar_2d)
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  vf1 = 2.0f * vf1;

  ck_assert(opengl_math::float_equals(4.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.0f, vf1.y(), 1e-006f));

  vf1 = vf1 * (1.0f / 2.0f);
  ck_assert(opengl_math::float_equals(2.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(4.0f, vf1.y(), 1e-006f));
}
END_TEST

START_TEST(test_time_scalar_3d)
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  vf1 = 2.0f * vf1;

  ck_assert(opengl_math::float_equals(4.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.0f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(32.6f, vf1.z(), 1e-006f));

  vf1 = vf1 * (1.0f / 2.0f);
  ck_assert(opengl_math::float_equals(2.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(4.0f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(16.3f, vf1.z(), 1e-006f));
}
END_TEST

START_TEST(test_time_scalar_4d)
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  vf1 = 2.0f * vf1;

  ck_assert(opengl_math::float_equals(4.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(8.0f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(32.6f, vf1.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(200.4f, vf1.w(), 1e-006f));

  vf1 = vf1 * (1.0f / 2.0f);
  ck_assert(opengl_math::float_equals(2.0f, vf1.x(), 1e-006f));
  ck_assert(opengl_math::float_equals(4.0f, vf1.y(), 1e-006f));
  ck_assert(opengl_math::float_equals(16.3f, vf1.z(), 1e-006f));
  ck_assert(opengl_math::float_equals(100.2f, vf1.w(), 1e-006f));
}
END_TEST

START_TEST(test_type_vector_get_dimension)
{
  ck_assert(2 == opengl_math::vector_2d<float>::dimension);
  ck_assert(2 == opengl_math::vector_2d<double>::dimension);
  ck_assert(3 == opengl_math::vector_3d<float>::dimension);
  ck_assert(3 == opengl_math::vector_3d<double>::dimension);
  ck_assert(4 == opengl_math::vector_4d<float>::dimension);
  ck_assert(4 == opengl_math::vector_4d<double>::dimension);
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

  tcase_add_test(tc, test_default_2d_vector_constructor);
  tcase_add_test(tc, test_default_3d_vector_constructor);
  tcase_add_test(tc, test_default_4d_vector_constructor);
  tcase_add_test(tc, test_2d_vector_constructor);
  tcase_add_test(tc, test_3d_vector_constructor);
  tcase_add_test(tc, test_4d_vector_constructor);
  tcase_add_test(tc, test_vector_2d_copy_constructor);
  tcase_add_test(tc, test_vector_3d_copy_constructor);
  tcase_add_test(tc, test_vector_4d_copy_constructor);
  tcase_add_test(tc, test_vector_2d_assignment_operator);
  tcase_add_test(tc, test_vector_3d_assignment_operator);
  tcase_add_test(tc, test_vector_4d_assignment_operator);
  tcase_add_test(tc, test_vector_2d_subscript_operator);
  tcase_add_test(tc, test_vector_3d_subscript_operator);
  tcase_add_test(tc, test_vector_4d_subscript_operator);
  tcase_add_test(tc, test_vector_2d_setters);
  tcase_add_test(tc, test_vector_3d_setters);
  tcase_add_test(tc, test_vector_4d_setters);
  tcase_add_test(tc, test_vector_2d_get_reference);
  tcase_add_test(tc, test_vector_3d_get_reference);
  tcase_add_test(tc, test_vector_4d_get_reference);
  tcase_add_test(tc, test_equivalence_type_vector_2d);
  tcase_add_test(tc, test_equivalence_type_vector_3d);
  tcase_add_test(tc, test_equivalence_type_vector_4d);
  tcase_add_test(tc, test_extrenuous_type_vector_usecases);
  tcase_add_test(tc, test_magnitude_2d);
  tcase_add_test(tc, test_magnitude_3d);
  tcase_add_test(tc, test_magnitude_4d);
  tcase_add_test(tc, test_normalize_2d);
  tcase_add_test(tc, test_normalize_3d);
  tcase_add_test(tc, test_normalize_4d);
  tcase_add_test(tc, test_dot_2d);
  tcase_add_test(tc, test_dot_3d);
  tcase_add_test(tc, test_dot_4d);
  tcase_add_test(tc, test_cross_3d);
  tcase_add_test(tc, test_plus_equals_2d);
  tcase_add_test(tc, test_plus_equals_3d);
  tcase_add_test(tc, test_plus_equals_4d);
  tcase_add_test(tc, test_minus_equals_2d);
  tcase_add_test(tc, test_minus_equals_3d);
  tcase_add_test(tc, test_minus_equals_4d);
  tcase_add_test(tc, test_times_equals_scalar_2d);
  tcase_add_test(tc, test_times_equals_scalar_3d);
  tcase_add_test(tc, test_times_equals_scalar_4d);
  tcase_add_test(tc, test_addition_2d);
  tcase_add_test(tc, test_addition_3d);
  tcase_add_test(tc, test_addition_4d);
  tcase_add_test(tc, test_subtraction_2d);
  tcase_add_test(tc, test_subtraction_3d);
  tcase_add_test(tc, test_subtraction_4d);
  tcase_add_test(tc, test_unary_minus_2d);
  tcase_add_test(tc, test_unary_minus_3d);
  tcase_add_test(tc, test_unary_minus_4d);
  tcase_add_test(tc, test_time_scalar_2d);
  tcase_add_test(tc, test_time_scalar_3d);
  tcase_add_test(tc, test_time_scalar_4d);
  tcase_add_test(tc, test_type_vector_get_dimension);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
