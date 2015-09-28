#include "test_type_vector.h"

/*! \brief This is a test to see if default constructor for
* 2d, 3d, and 4d vectors initializes all of its components to 0.0f
*/
void test_default_2d_vector_constructor()
{
  opengl_math::vector_2d<float> tc1;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);

  opengl_math::vector_2d<double> tc2;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
}

void test_default_3d_vector_constructor()
{
  opengl_math::vector_3d<float> tc1;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.0f);

  opengl_math::vector_3d<double> tc2;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
}

void test_default_4d_vector_constructor()
{
  opengl_math::vector_4d<float> tc1;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.0f);

  opengl_math::vector_4d<double> tc2;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
}

/*! \brief This is a test to see if paramaterized constructor for
* 2d, 3d, and 4d vectors itializes all of its components correctly
*/
void test_2d_vector_constructor()
{
  opengl_math::vector_2d<float> tc1(1.0f, 2.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 2.0f);

  opengl_math::vector_2d<double> tc2(1.0, 0.97);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.97);
}

void test_3d_vector_constructor()
{
  opengl_math::vector_3d<float> tc1(1.0f, 2.0f, 3.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 2.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 3.0f);

  opengl_math::vector_3d<double> tc2(1.0, 0.97, 0.2);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.97);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.2);
}

void test_4d_vector_constructor()
{
  opengl_math::vector_4d<float> tc1(1.0f, 2.0f, 4.0f, 3.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 2.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 4.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 3.0f);

  opengl_math::vector_4d<double> tc2(1.0, 0.97, 0.2, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.97);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.2);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.1);
}

/*! \brief This is a test to see if the copy constructor for
* 2d and 4d vectors itializes all of its components correctly
*/
void test_vector_2d_copy_constructor()
{
  opengl_math::vector_2d<float> tc1(0.9f, 0.75f);
  opengl_math::vector_2d<float> tc2(tc1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.9f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.75f);

  opengl_math::vector_2d<double> tc3(0.145, 0.1);
  opengl_math::vector_2d<double> tc4(tc3);
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.145);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.1);
}

void test_vector_3d_copy_constructor()
{
  opengl_math::vector_3d<float> tc1(0.82f, 1.0e-10f, 10.0f);
  opengl_math::vector_3d<float> tc2(tc1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0000000001f);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 10.0f);

  opengl_math::vector_3d<double> tc3(0.7, 1.0e-18, 1.000000001);
  opengl_math::vector_3d<double> tc4(tc3);
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 1.0e-18);
  OPENGL_MATH_ASSERT_EQ(tc4.z(), 1.000000001);
}

void test_vector_4d_copy_constructor()
{
  opengl_math::vector_4d<float> tc1(0.82f, 1.0e-10f, 10.0f, 1.0f);
  opengl_math::vector_4d<float> tc2(tc1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0000000001f);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 10.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 1.0f);

  opengl_math::vector_4d<double> tc3(0.7, 1.0e-18, 1.000000001, 1.0);
  opengl_math::vector_4d<double> tc4(tc3);
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 1.0e-18);
  OPENGL_MATH_ASSERT_EQ(tc4.z(), 1.000000001);
  OPENGL_MATH_ASSERT_EQ(tc4.w(), 1.0);
}

/*! \brief This is a test to see if the assignment operator copies
* the contents of the rhs value into the lhs without modifying the
* rhs.
*/
void test_vector_2d_assignment_operator()
{
  opengl_math::vector_2d<float> tc1(0.88f, 0.0f);
  opengl_math::vector_2d<float> tc2 = tc1;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);

  tc2 = opengl_math::vector_2d<float>(0.99f, 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);

  opengl_math::vector_2d<double> tc3(0.11, 0.22);
  opengl_math::vector_2d<double> tc4 = tc3;
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.11);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.22);
  OPENGL_MATH_ASSERT_EQ(tc3.x(), 0.11);
  OPENGL_MATH_ASSERT_EQ(tc3.y(), 0.22);

  tc4 = opengl_math::vector_2d<double>(0.22, 0.33);
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.22);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.33);
  OPENGL_MATH_ASSERT_EQ(tc3.x(), 0.11);
  OPENGL_MATH_ASSERT_EQ(tc3.y(), 0.22);
}

void test_vector_3d_assignment_operator()
{
  opengl_math::vector_3d<float> tc1(0.82f, 1.0f, 1.0f);
  opengl_math::vector_3d<float> tc2 = tc1;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 1.0f);

  tc2 = opengl_math::vector_3d<float>(0.83f, 0.99f, 0.98f);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.83f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.98f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 1.0f);

  opengl_math::vector_3d<double> tc3(0.66, 0.88, 0.988);
  opengl_math::vector_3d<double> tc4 = tc3;
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc4.z(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.z(), 0.988);

  tc4 = opengl_math::vector_3d<double>();
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc3.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.z(), 0.988);
}

void test_vector_4d_assignment_operator()
{
  opengl_math::vector_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
  opengl_math::vector_4d<float> tc2 = tc1;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.92f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.92f);

  tc2 = opengl_math::vector_4d<float>(0.83f, 0.99f, 0.98f, 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.83f);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.98f);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.92f);

  opengl_math::vector_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
  opengl_math::vector_4d<double> tc4 = tc3;
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc4.z(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc4.w(), 0.28);
  OPENGL_MATH_ASSERT_EQ(tc3.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.z(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3.w(), 0.28);

  tc4 = opengl_math::vector_4d<double>();
  OPENGL_MATH_ASSERT_EQ(tc4.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.w(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc3.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.z(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3.w(), 0.28);
}

/*! \brief This is a test to see if both constant and non constant versions
* of the subscript operators behave according to specification.
*/
void test_vector_2d_subscript_operator()
{
  opengl_math::vector_2d<float> tc1(0.82f, 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);
  tc1[0] = 0.81f;
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.81f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);

  opengl_math::vector_2d<double> tc3(0.66, 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  tc3[1] = 0.99;
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.99);
}

void test_vector_3d_subscript_operator()
{
  opengl_math::vector_3d<float> tc1(0.82f, 1.0f, 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[2], 1.0f);
  tc1[0] = 0.83f;
  tc1[1] = 0.99f;
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.83f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc1[2], 1.0f);

  opengl_math::vector_3d<double> tc3(0.66, 0.88, 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[2], 0.988);
  tc3[2] = 0.01;
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[2], 0.01);
}

void test_vector_4d_subscript_operator()
{
  opengl_math::vector_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[2], 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[3], 0.92f);
  tc1[0] = 0.00f;
  tc1[1] = 0.00f;
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1[2], 1.00f);
  OPENGL_MATH_ASSERT_EQ(tc1[3], 0.92f);

  opengl_math::vector_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[2], 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3[3], 0.28);
  tc3[2] = 0.00;
  tc3[3] = 0.00;
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[2], 0.00);
  OPENGL_MATH_ASSERT_EQ(tc3[3], 0.00);
}

/*! \brief This is a test to see if the setters for 2d and 3d vectors
* set the value to a new value.
*/
void test_vector_2d_setters()
{
  opengl_math::vector_2d<float> tc1;
  tc1.x(1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);
  tc1.y(0.5f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.5f);
  tc1.y(0.2f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.2f);
  tc1.x_and_y(0.0f, 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);

  opengl_math::vector_2d<double> tc2;
  tc2.x(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  tc2.y(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  tc2.x(0.4);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.4);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  tc2.x_and_y(0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.1);
}

void test_vector_3d_setters()
{
  opengl_math::vector_3d<float> tc1;
  tc1.x(0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  tc1.y(0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  tc1.z(0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.05f);
  tc1.z(0.07f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.07f);
  tc1.x_and_y_and_z(0.09f, 0.11f, 0.15f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.09f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.11f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.15f);

  opengl_math::vector_3d<double> tc2;
  tc2.x(0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  tc2.y(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  tc2.z(0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  tc2.x(0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  tc2.x_and_y_and_z(0.1, 0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.1);
}

void test_vector_4d_setters()
{
  opengl_math::vector_4d<float> tc1;
  tc1.x(0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.00f);
  tc1.y(0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.00f);
  tc1.z(0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.00f);
  tc1.w(0.07f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.07f);
  tc1.x_and_y_and_z_and_w(0.09f, 0.11f, 0.15f, 0.22f);
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.09f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.11f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.15f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.22f);

  opengl_math::vector_4d<double> tc2;
  tc2.x(0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
  tc2.y(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
  tc2.z(0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
  tc2.w(0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.1);
  tc2.x_and_y_and_z_and_w(0.1, 0.1, 0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.1);
}

/*! \brief This is a test to see if the getters by ref for 2d, 3d, and 4d
* vectors set the value to a new value.
*/
void test_vector_2d_get_reference()
{
  opengl_math::vector_2d<float> tc1;
  tc1.xref() = 1.0f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.0f);
  tc1.yref() = 0.5f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.5f);
  tc1.xref() = 0.2f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.2f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.5f);

  opengl_math::vector_2d<double> tc2;
  tc2.xref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  tc2.yref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  tc2.yref() = 0.4;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.4);
}

void test_vector_3d_get_reference()
{
  opengl_math::vector_3d<float> tc1;
  tc1.xref() = 0.01f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  tc1.yref() = 0.02f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  tc1.zref() = 0.05f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.05f);

  opengl_math::vector_3d<double> tc2;
  tc2.xref() = 0.0;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  tc2.yref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  tc2.zref() = 0.7;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  tc2.zref() = 0.1;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.1);
}

void test_vector_4d_get_reference()
{
  opengl_math::vector_4d<float> tc1;
  tc1.xref() = 0.01f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.00f);
  tc1.yref() = 0.02f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.00f);
  tc1.zref() = 0.05f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 0.00f);
  tc1.wref() = 1.0f;
  OPENGL_MATH_ASSERT_EQ(tc1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.z(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.w(), 1.00f);

  opengl_math::vector_4d<double> tc2;
  tc2.xref() = 0.0;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
  tc2.yref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
  tc2.zref() = 0.7;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.0);
  tc2.wref() = 0.1;
  OPENGL_MATH_ASSERT_EQ(tc2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.z(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.w(), 0.1);
}

/*! \brief This is a test to if two vectors can be compared for equivalence
*/
void test_equivalence_type_vector_2d()
{
  opengl_math::vector_2d<float> tc1;
  opengl_math::vector_2d<float> tc2;
  OPENGL_MATH_ASSERT_EQ(tc1, tc2);

  tc2.x_and_y(0.0001f, 1.000001f);
  OPENGL_MATH_ASSERT_NE(tc1, tc2);

  opengl_math::vector_2d<float> tc3(1.0f, 0.5f);
  opengl_math::vector_2d<float> tc4(1.0f, 0.5f);
  OPENGL_MATH_ASSERT_EQ(tc3, tc4);

  tc3.xref() = 0.0f;
  OPENGL_MATH_ASSERT_NE(tc3, tc4);
}

void test_equivalence_type_vector_3d()
{
  opengl_math::vector_3d<float> tc1;
  opengl_math::vector_3d<float> tc2;
  OPENGL_MATH_ASSERT_EQ(tc1, tc2);

  tc2.x_and_y_and_z(0.0001f, 1.000001f, 0.0f);
  OPENGL_MATH_ASSERT_NE(tc1, tc2);

  opengl_math::vector_3d<float> tc3(1.0f, 0.7f, 0.8f);
  opengl_math::vector_3d<float> tc4(1.0f, 0.7f, 0.8f);
  OPENGL_MATH_ASSERT_EQ(tc3, tc4);

  tc3.yref() = 0.6f;
  OPENGL_MATH_ASSERT_NE(tc3, tc4);
}

void test_equivalence_type_vector_4d()
{
  opengl_math::vector_4d<float> tc1;
  opengl_math::vector_4d<float> tc2;
  OPENGL_MATH_ASSERT_EQ(tc1, tc2);

  tc2.x_and_y_and_z_and_w(0.0001f, 1.000001f, 0.0f, 0.0f);
  OPENGL_MATH_ASSERT_NE(tc1, tc2);

  opengl_math::vector_4d<float> tc3(1.0f, 0.7f, 0.8f, 0.8f);
  opengl_math::vector_4d<float> tc4(1.0f, 0.7f, 0.8f, 0.8f);
  OPENGL_MATH_ASSERT_EQ(tc3, tc4);

  tc3.yref() = 0.6f;
  OPENGL_MATH_ASSERT_NE(tc3, tc4);
}

void test_extrenuous_type_vector_usecases()
{
  opengl_math::vector_2d<float> tc1(1.0f, 0.9f);
  // Convert the raw vector to an array
  float *raw_data = &tc1.xref();
  OPENGL_MATH_ASSERT_EQ(raw_data[1], 0.9f);
  raw_data[1] = 0.8f;
  OPENGL_MATH_ASSERT_EQ(raw_data[0], 1.0f);
  OPENGL_MATH_ASSERT_EQ(raw_data[1], 0.8f);

  // Check to see if it is POD
  opengl_math::vector_3d<float> tc2(1.0f, 1.0f, 0.9f);
  float vector_array[3];
  memcpy(vector_array, &tc2, sizeof(tc2));
  OPENGL_MATH_ASSERT_EQ(vector_array[0], 1.0f);
  OPENGL_MATH_ASSERT_EQ(vector_array[1], 1.0f);
  OPENGL_MATH_ASSERT_EQ(vector_array[2], 0.9f);
}

/*! brief Arithmatic operator tests
*/
void test_magnitude_2d()
{
  const opengl_math::vector_2d<float> vf(20.0f, 10.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(sqrt(500.0f), vf.magnitude(),
    1e-006f));

  const opengl_math::vector_2d<double> vd(20.0, 10.0);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(sqrt(500.0), vd.magnitude(),
    1e-006));
}

void test_magnitude_3d()
{
  const opengl_math::vector_3d<float> vf(20.0f, 10.0f, 20.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(30.0f, vf.magnitude(), 1e-006f));

  const opengl_math::vector_3d<double> vd(20.0, 10.0, 20.0);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(30.0, vd.magnitude(), 1e-006));
}

void test_magnitude_4d()
{
  const opengl_math::vector_4d<float> vf(20.0f, 10.0f, 20.0f, 0.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(30.0f, vf.magnitude(),
    1e-006f));

  const opengl_math::vector_4d<double> vd(20.0, 10.0, 20.0, 0.0);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(30.0, vd.magnitude(), 1e-006));
}


void test_normalize_2d()
{
  opengl_math::vector_2d<float> vf(20.0f, 10.0f);
  vf.normalize();
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.89443f, vf.x(), 1e-005f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.44721f, vf.y(), 1e-005f));

  opengl_math::vector_2d<double> vd(20.0, 10.0);
  vd.normalize();
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.89443, vd.x(), 1e-005));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.44721, vd.y(), 1e-005));
}

void test_normalize_3d()
{
  opengl_math::vector_3d<float> vf(20.0f, 10.0f, 20.0f);
  vf.normalize();
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f / 3.0f, vf.x(), 1e-005f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0f / 3.0f, vf.y(), 1e-005f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f / 3.0f, vf.z(), 1e-005f));

  opengl_math::vector_3d<double> vd(20.0, 10.0, 20.0);
  vd.normalize();
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0 / 3.0, vd.x(), 1e-005));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0 / 3.0, vd.y(), 1e-005));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0 / 3.0, vd.z(), 1e-005));
}

void test_normalize_4d()
{
  opengl_math::vector_4d<float> vf(20.0f, 10.0f, 20.0f, 0.0f);
  vf.normalize();
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f / 3.0f, vf.x(), 1e-005f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0f / 3.0f, vf.y(), 1e-005f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f / 3.0f, vf.z(), 1e-005f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, vf.w(), 1e-005f));

  opengl_math::vector_4d<double> vd(20.0, 10.0, 20.0, 0.0f);
  vd.normalize();
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0 / 3.0, vd.x(), 1e-005));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0 / 3.0, vd.y(), 1e-005));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0 / 3.0, vd.z(), 1e-005));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, vd.w(), 1e-005));
}

void test_dot_2d()
{
  const opengl_math::vector_2d<float> vf1(1.0f, 2.0f);
  const opengl_math::vector_2d<float> vf2(3.0f, 2.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(7.0f, vf1.dot(vf2), 1e-006f));

  const opengl_math::vector_2d<double> vd1(1.0, 2.0);
  const opengl_math::vector_2d<double> vd2(3.0, 2.0);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(7.0, vd1.dot(vd2), 1e-006));
}

void test_dot_3d()
{
  const opengl_math::vector_3d<float> vf1(1.0f, 2.0f, 4.0f);
  const opengl_math::vector_3d<float> vf2(3.0f, 2.0f, 8.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(39.0f, vf1.dot(vf2), 1e-006f));

  const opengl_math::vector_3d<double> vd1(1.0, 2.0, 4.0);
  const opengl_math::vector_3d<double> vd2(3.0, 2.0, 8.0);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(39.0, vd1.dot(vd2), 1e-006));
}

void test_dot_4d()
{
  const opengl_math::vector_4d<float> vf1(1.0f, 2.0f, 4.0f, 10000.0f);
  const opengl_math::vector_4d<float> vf2(3.0f, 2.0f, 8.0f, 90000.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(900000039.0f, vf1.dot(vf2),
    1e-006f));

  const opengl_math::vector_4d<double> vd1(1.0, 2.0, 4.0, 10000.0);
  const opengl_math::vector_4d<double> vd2(3.0, 2.0, 8.0, 90000.0);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(900000039.0, vd1.dot(vd2),
    1e-006));
}

void test_cross_3d()
{
  {
    const opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 8.0f);
    const opengl_math::vector_3d<float> vf2(2.0f, 4.0f, 8.0f);

    const opengl_math::vector_3d<float> cross12 = vf1.cross(vf2);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, cross12.x(), 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, cross12.y(), 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, cross12.z(), 1e-006f));

    const opengl_math::vector_3d<float> cross21 = vf2.cross(vf1);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, cross21.x(), 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, cross21.y(), 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, cross21.z(), 1e-006f));
  }

    {
      const opengl_math::vector_3d<double> vd1(1.0, 0.0, 0.0);
      const opengl_math::vector_3d<double> vd2(0.0, 1.0, 0.0);
      const opengl_math::vector_3d<double> vd3(0.0, 0.0, 1.0);

      const opengl_math::vector_3d<double> crossxy = vd1.cross(vd2);
      OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, crossxy.x(), 1e-006));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, crossxy.y(), 1e-006));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0, crossxy.z(), 1e-006));

      const opengl_math::vector_3d<double> crossxz = vd3.cross(vd1);
      OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, crossxz.x(), 1e-006));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0, crossxz.y(), 1e-006));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, crossxz.z(), 1e-006));

      const opengl_math::vector_3d<double> crossyz = vd2.cross(vd3);
      OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0, crossyz.x(), 1e-006));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, crossyz.y(), 1e-006));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0, crossyz.z(), 1e-006));
    }
}

void test_plus_equals_2d()
{
  opengl_math::vector_2d<float> vf1(12.38f, 1.22f);
  vf1 += opengl_math::vector_2d<float>(0.62f, 0.78f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(13.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f, vf1.y(), 1e-006f));
}

void test_plus_equals_3d()
{
  opengl_math::vector_3d<float> vf1(12.38f, 1.22f, 3.06f);
  vf1 += opengl_math::vector_3d<float>(0.62f, 0.78f, 1.94f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(13.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(5.0f, vf1.z(), 1e-006f));
}

void test_plus_equals_4d()
{
  opengl_math::vector_4d<float> vf1(12.38f, 1.22f, 3.06f, 0.01f);
  vf1 += opengl_math::vector_4d<float>(0.62f, 0.78f, 1.94f, 0.99f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(13.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(5.0f, vf1.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.0f, vf1.w(), 1e-006f));
}

void test_minus_equals_2d()
{
  opengl_math::vector_2d<float> vf1(12.38f, 1.22f);
  vf1 -= opengl_math::vector_2d<float>(0.38f, 0.22f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(12.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.00f, vf1.y(), 1e-006f));
}

void test_minus_equals_3d()
{
  opengl_math::vector_3d<float> vf1(12.38f, 1.22f, 0.01f);
  vf1 -= opengl_math::vector_3d<float>(0.38f, 0.22f, 0.01f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(12.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.00f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf1.z(), 1e-006f));
}

void test_minus_equals_4d()
{
  opengl_math::vector_4d<float> vf1(12.38f, 1.22f, 0.01f, 0.00f);
  vf1 -= opengl_math::vector_4d<float>(0.38f, 0.22f, 0.01f, 0.00f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(12.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(1.00f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf1.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf1.w(), 1e-006f));
}

void test_times_equals_scalar_2d()
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  vf1 *= 2.0f;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.00f, vf1.y(), 1e-006f));
}

void test_times_equals_scalar_3d()
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 2.0f);
  vf1 *= 2.0f;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.00f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf1.z(), 1e-006f));
}

void test_times_equals_scalar_4d()
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 2.0f, 8.1f);
  vf1 *= 2.0f;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.00f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf1.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(16.2f, vf1.w(), 1e-006f));
}

void test_addition_2d()
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  opengl_math::vector_2d<float> vf2(2.0f, 4.0f);

  opengl_math::vector_2d<float> vf3 = vf1 + vf2;
  opengl_math::vector_2d<float> vf4 = vf2 + vf1;

  OPENGL_MATH_ASSERT_EQ(vf3, vf4);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf3.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.00f, vf3.y(), 1e-006f));
}

void test_addition_3d()
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  opengl_math::vector_3d<float> vf2(2.0f, 4.0f, 15.7f);

  opengl_math::vector_3d<float> vf3 = vf1 + vf2;
  opengl_math::vector_3d<float> vf4 = vf2 + vf1;

  OPENGL_MATH_ASSERT_EQ(vf3, vf4);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf3.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.00f, vf3.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(32.00f, vf3.z(), 1e-006f));
}

void test_addition_4d()
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  opengl_math::vector_4d<float> vf2(2.0f, 4.0f, 15.7f, 0.7f);

  opengl_math::vector_4d<float> vf3 = vf1 + vf2;
  opengl_math::vector_4d<float> vf4 = vf2 + vf1;

  OPENGL_MATH_ASSERT_EQ(vf3, vf4);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.00f, vf3.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.00f, vf3.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(32.00f, vf3.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(100.9f, vf3.w(), 1e-001f));
}

void test_subtraction_2d()
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  opengl_math::vector_2d<float> vf2(2.0f, 4.0f);

  opengl_math::vector_2d<float> vf3 = vf1 - vf2;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, vf3.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, vf3.y(), 1e-006f));

  opengl_math::vector_2d<float> vf4 = vf2 - vf1;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, vf4.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.0f, vf4.y(), 1e-006f));
}

void test_subtraction_3d()
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  opengl_math::vector_3d<float> vf2(2.0f, 4.0f, 15.7f);

  opengl_math::vector_3d<float> vf3 = vf1 - vf2;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf3.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf3.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.6f, vf3.z(), 1e-006f));

  opengl_math::vector_3d<float> vf4 = vf2 - vf1;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf4.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf4.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(-0.6f, vf4.z(), 1e-006f));
}

void test_subtraction_4d()
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  opengl_math::vector_4d<float> vf2(2.0f, 4.0f, 15.7f, 0.7f);

  opengl_math::vector_4d<float> vf3 = vf1 - vf2;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf3.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf3.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.6f, vf3.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(99.5f, vf3.w(), 1e-006f));

  opengl_math::vector_4d<float> vf4 = vf2 - vf1;
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf4.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(0.00f, vf4.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(-0.6f, vf4.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(-99.5f, vf4.w(), 1e-006f));
}

void test_unary_minus_2d()
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  vf1 = -vf1;

  OPENGL_MATH_ASSERT_EQ(-2.0f, vf1.x());
  OPENGL_MATH_ASSERT_EQ(-4.0f, vf1.y());
}

void test_unary_minus_3d()
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  vf1 = -vf1;

  OPENGL_MATH_ASSERT_EQ(-2.0f, vf1.x());
  OPENGL_MATH_ASSERT_EQ(-4.0f, vf1.y());
  OPENGL_MATH_ASSERT_EQ(-16.3f, vf1.z());
}

void test_unary_minus_4d()
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  vf1 = -vf1;

  OPENGL_MATH_ASSERT_EQ(-2.0f, vf1.x());
  OPENGL_MATH_ASSERT_EQ(-4.0f, vf1.y());
  OPENGL_MATH_ASSERT_EQ(-16.3f, vf1.z());
  OPENGL_MATH_ASSERT_EQ(-100.2f, vf1.w());
}

void test_time_scalar_2d()
{
  opengl_math::vector_2d<float> vf1(2.0f, 4.0f);
  vf1 = 2.0f * vf1;

  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.0f, vf1.y(), 1e-006f));

  vf1 = vf1 * (1.0f / 2.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.0f, vf1.y(), 1e-006f));
}

void test_time_scalar_3d()
{
  opengl_math::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
  vf1 = 2.0f * vf1;

  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.0f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(32.6f, vf1.z(), 1e-006f));

  vf1 = vf1 * (1.0f / 2.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.0f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(16.3f, vf1.z(), 1e-006f));
}

void test_time_scalar_4d()
{
  opengl_math::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
  vf1 = 2.0f * vf1;

  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(8.0f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(32.6f, vf1.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(200.4f, vf1.w(), 1e-006f));

  vf1 = vf1 * (1.0f / 2.0f);
  OPENGL_MATH_ASSERT(opengl_math::float_equals(2.0f, vf1.x(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(4.0f, vf1.y(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(16.3f, vf1.z(), 1e-006f));
  OPENGL_MATH_ASSERT(opengl_math::float_equals(100.2f, vf1.w(), 1e-006f));
}

void test_type_vector_get_dimension()
{
  OPENGL_MATH_ASSERT_EQ(2, opengl_math::vector_2d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(2, opengl_math::vector_2d<double>::dimension);
  OPENGL_MATH_ASSERT_EQ(3, opengl_math::vector_3d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(3, opengl_math::vector_3d<double>::dimension);
  OPENGL_MATH_ASSERT_EQ(4, opengl_math::vector_4d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(4, opengl_math::vector_4d<double>::dimension);
}

bool test_type_vector::run()
{
  test_default_2d_vector_constructor();
  test_default_3d_vector_constructor();
  test_default_4d_vector_constructor();
  test_2d_vector_constructor();
  test_3d_vector_constructor();
  test_4d_vector_constructor();
  test_vector_3d_copy_constructor();
  test_vector_2d_assignment_operator();
  test_vector_3d_assignment_operator();
  test_vector_4d_assignment_operator();
  test_vector_2d_subscript_operator();
  test_vector_3d_subscript_operator();
  test_vector_4d_subscript_operator();
  test_vector_2d_setters();
  test_vector_3d_setters();
  test_vector_4d_setters();
  test_vector_2d_get_reference();
  test_vector_3d_get_reference();
  test_vector_4d_get_reference();
  test_equivalence_type_vector_2d();
  test_equivalence_type_vector_3d();
  test_equivalence_type_vector_4d();
  test_extrenuous_type_vector_usecases();
  test_magnitude_2d();
  test_magnitude_3d();
  test_magnitude_4d();
  test_normalize_2d();
  test_normalize_3d();
  test_normalize_4d();
  test_dot_2d();
  test_dot_3d();
  test_dot_4d();
  test_cross_3d();
  test_plus_equals_2d();
  test_plus_equals_3d();
  test_plus_equals_4d();
  test_minus_equals_2d();
  test_minus_equals_3d();
  test_minus_equals_4d();
  test_times_equals_scalar_2d();
  test_times_equals_scalar_3d();
  test_times_equals_scalar_4d();
  test_addition_2d();
  test_addition_3d();
  test_addition_4d();
  test_subtraction_2d();
  test_subtraction_3d();
  test_subtraction_4d();
  test_unary_minus_2d();
  test_unary_minus_3d();
  test_unary_minus_4d();
  test_time_scalar_2d();
  test_time_scalar_3d();
  test_time_scalar_4d();
  test_type_vector_get_dimension();

  return true;
}
