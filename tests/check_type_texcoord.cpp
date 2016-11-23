#include "test_type_texcoord.h"

/*! \brief This is a test to see if default constructor for
* 2d, 3d, and 4d texcoords initializes all of its components to 0.0f
*/
void test_default_2d_texcoord_constructor()
{
  opengl_math::texcoord_2d<float> tc1;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);

  opengl_math::texcoord_2d<double> tc2;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
}

void test_default_3d_texcoord_constructor()
{
  opengl_math::texcoord_3d<float> tc1;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.0f);

  opengl_math::texcoord_3d<double> tc2;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
}

void test_default_4d_texcoord_constructor()
{
  opengl_math::texcoord_4d<float> tc1;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.0f);

  opengl_math::texcoord_4d<double> tc2;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
}

/*! \brief This is a test to see if paramaterized constructor for
* 2d, 3d, and 4d texcoords itializes all of its components correctly
*/
void test_2d_texcoord_constructor()
{
  opengl_math::texcoord_2d<float> tc1(1.0f, 2.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);

  opengl_math::texcoord_2d<double> tc2(1.0, 0.97);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.97);
}

void test_3d_texcoord_constructor()
{
  opengl_math::texcoord_3d<float> tc1(1.0f, 2.0f, 3.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 1.0f);

  opengl_math::texcoord_3d<double> tc2(1.0, 0.97, 0.2);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.97);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.2);
}

void test_4d_texcoord_constructor()
{
  opengl_math::texcoord_4d<float> tc1(1.0f, 2.0f, 4.0f, 3.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 1.0f);

  opengl_math::texcoord_4d<double> tc2(1.0, 0.97, 0.2, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.97);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.2);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.1);
}

/*! \brief This is a test to see if the copy constructor for
* 2d and 4d texcoords itializes all of its components correctly
*/
void test_texcoord_2d_copy_constructor()
{
  opengl_math::texcoord_2d<float> tc1(0.9f, 0.75f);
  opengl_math::texcoord_2d<float> tc2(tc1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.9f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.75f);

  opengl_math::texcoord_2d<double> tc3(0.145, 0.1);
  opengl_math::texcoord_2d<double> tc4(tc3);
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.145);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.1);
}

void test_texcoord_3d_copy_constructor()
{
  opengl_math::texcoord_3d<float> tc1(0.82f, 1.0e-10f, 10.0f);
  opengl_math::texcoord_3d<float> tc2(tc1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0000000001f);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 1.0f);

  opengl_math::texcoord_3d<double> tc3(0.7, 1.0e-18, 1.000000001);
  opengl_math::texcoord_3d<double> tc4(tc3);
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 1.0e-18);
  OPENGL_MATH_ASSERT_EQ(tc4.r(), 1.0);
}

void test_texcoord_4d_copy_constructor()
{
  opengl_math::texcoord_4d<float> tc1(0.82f, 1.0e-10f, 10.0f, 1.0f);
  opengl_math::texcoord_4d<float> tc2(tc1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0000000001f);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 1.0f);

  opengl_math::texcoord_4d<double> tc3(0.7, 1.0e-18, 1.000000001, 1.0);
  opengl_math::texcoord_4d<double> tc4(tc3);
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 1.0e-18);
  OPENGL_MATH_ASSERT_EQ(tc4.r(), 1.0);
  OPENGL_MATH_ASSERT_EQ(tc4.q(), 1.0);
}

/*! \brief This is a test to see if the assignment operator copies
* the contents of the rhs value into the lhs without modifying the
* rhs.
*/
void test_texcoord_2d_assignment_operator()
{
  opengl_math::texcoord_2d<float> tc1(0.88f, 0.0f);
  opengl_math::texcoord_2d<float> tc2 = tc1;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);

  tc2 = opengl_math::texcoord_2d<float>(0.99f, 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);

  opengl_math::texcoord_2d<double> tc3(0.11, 0.22);
  opengl_math::texcoord_2d<double> tc4 = tc3;
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.11);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.22);
  OPENGL_MATH_ASSERT_EQ(tc3.s(), 0.11);
  OPENGL_MATH_ASSERT_EQ(tc3.t(), 0.22);

  tc4 = opengl_math::texcoord_2d<double>(0.22, 0.33);
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.22);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.33);
  OPENGL_MATH_ASSERT_EQ(tc3.s(), 0.11);
  OPENGL_MATH_ASSERT_EQ(tc3.t(), 0.22);
}

void test_texcoord_3d_assignment_operator()
{
  opengl_math::texcoord_3d<float> tc1(0.82f, 1.0f, 1.0f);
  opengl_math::texcoord_3d<float> tc2 = tc1;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 1.0f);

  tc2 = opengl_math::texcoord_3d<float>(0.83f, 0.99f, 0.98f);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.83f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.98f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 1.0f);

  opengl_math::texcoord_3d<double> tc3(0.66, 0.88, 0.988);
  opengl_math::texcoord_3d<double> tc4 = tc3;
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc4.r(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3.s(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.t(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.r(), 0.988);

  tc4 = opengl_math::texcoord_3d<double>();
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc3.s(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.t(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.r(), 0.988);
}

void test_texcoord_4d_assignment_operator()
{
  opengl_math::texcoord_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
  opengl_math::texcoord_4d<float> tc2 = tc1;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.92f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.92f);

  tc2 = opengl_math::texcoord_4d<float>(0.83f, 0.99f, 0.98f, 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.83f);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.98f);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.92f);

  opengl_math::texcoord_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
  opengl_math::texcoord_4d<double> tc4 = tc3;
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc4.r(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc4.q(), 0.28);
  OPENGL_MATH_ASSERT_EQ(tc3.s(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.t(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.r(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3.q(), 0.28);

  tc4 = opengl_math::texcoord_4d<double>();
  OPENGL_MATH_ASSERT_EQ(tc4.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc4.q(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc3.s(), 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3.t(), 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3.r(), 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3.q(), 0.28);
}

/*! \brief This is a test to see if both constant and non constant versions
* of the subscript operators behave according to specification.
*/
void test_texcoord_2d_subscript_operator()
{
  opengl_math::texcoord_2d<float> tc1(0.82f, 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);
  tc1[0] = 0.81f;
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.81f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);

  opengl_math::texcoord_2d<double> tc3(0.66, 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  tc3[1] = 0.99;
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.99);
}

void test_texcoord_3d_subscript_operator()
{
  opengl_math::texcoord_3d<float> tc1(0.82f, 1.0f, 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.82f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1[2], 1.0f);
  tc1[0] = 0.83f;
  tc1[1] = 0.99f;
  OPENGL_MATH_ASSERT_EQ(tc1[0], 0.83f);
  OPENGL_MATH_ASSERT_EQ(tc1[1], 0.99f);
  OPENGL_MATH_ASSERT_EQ(tc1[2], 1.0f);

  opengl_math::texcoord_3d<double> tc3(0.66, 0.88, 0.988);
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[2], 0.988);
  tc3[2] = 0.01;
  OPENGL_MATH_ASSERT_EQ(tc3[0], 0.66);
  OPENGL_MATH_ASSERT_EQ(tc3[1], 0.88);
  OPENGL_MATH_ASSERT_EQ(tc3[2], 0.01);
}

void test_texcoord_4d_subscript_operator()
{
  opengl_math::texcoord_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
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

  opengl_math::texcoord_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
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

/*! \brief This is a test to see if the setters for 2d and 3d texcoords
* set the value to a new value.
*/
void test_texcoord_2d_setters()
{
  opengl_math::texcoord_2d<float> tc1;
  tc1.s(1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);
  tc1.t(0.5f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.5f);
  tc1.t(0.2f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.2f);
  tc1.s_and_t(0.0f, 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);

  opengl_math::texcoord_2d<double> tc2;
  tc2.s(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  tc2.t(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  tc2.s(0.4);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.4);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  tc2.s_and_t(0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.1);
}

void test_texcoord_3d_setters()
{
  opengl_math::texcoord_3d<float> tc1;
  tc1.s(0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  tc1.t(0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  tc1.r(0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.05f);
  tc1.r(0.07f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.07f);
  tc1.s_and_t_and_r(0.09f, 0.11f, 0.15f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.09f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.11f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.15f);

  opengl_math::texcoord_3d<double> tc2;
  tc2.s(0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  tc2.t(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  tc2.r(0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  tc2.s(0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  tc2.s_and_t_and_r(0.1, 0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.1);
}

void test_texcoord_4d_setters()
{
  opengl_math::texcoord_4d<float> tc1;
  tc1.s(0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.00f);
  tc1.t(0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.00f);
  tc1.r(0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.00f);
  tc1.q(0.07f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.07f);
  tc1.s_and_t_and_r_and_q(0.09f, 0.11f, 0.15f, 0.22f);
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.09f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.11f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.15f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.22f);

  opengl_math::texcoord_4d<double> tc2;
  tc2.s(0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
  tc2.t(0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
  tc2.r(0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
  tc2.q(0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.1);
  tc2.s_and_t_and_r_and_q(0.1, 0.1, 0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.1);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.1);
}

/*! \brief This is a test to see if the getters by ref for 2d, 3d, and 4d
* texcoords set the value to a new value.
*/
void test_texcoord_2d_get_reference()
{
  opengl_math::texcoord_2d<float> tc1;
  tc1.sref() = 1.0f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.0f);
  tc1.tref() = 0.5f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.5f);
  tc1.sref() = 0.2f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.2f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.5f);

  opengl_math::texcoord_2d<double> tc2;
  tc2.sref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  tc2.tref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  tc2.tref() = 0.4;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.4);
}

void test_texcoord_3d_get_reference()
{
  opengl_math::texcoord_3d<float> tc1;
  tc1.sref() = 0.01f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  tc1.tref() = 0.02f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  tc1.rref() = 0.05f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.05f);

  opengl_math::texcoord_3d<double> tc2;
  tc2.sref() = 0.0;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  tc2.tref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  tc2.rref() = 0.7;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  tc2.rref() = 0.1;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.1);
}

void test_texcoord_4d_get_reference()
{
  opengl_math::texcoord_4d<float> tc1;
  tc1.sref() = 0.01f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.00f);
  tc1.tref() = 0.02f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.00f);
  tc1.rref() = 0.05f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 0.00f);
  tc1.qref() = 1.0f;
  OPENGL_MATH_ASSERT_EQ(tc1.s(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(tc1.t(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(tc1.r(), 0.05f);
  OPENGL_MATH_ASSERT_EQ(tc1.q(), 1.00f);

  opengl_math::texcoord_4d<double> tc2;
  tc2.sref() = 0.0;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
  tc2.tref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
  tc2.rref() = 0.7;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.0);
  tc2.qref() = 0.1;
  OPENGL_MATH_ASSERT_EQ(tc2.s(), 0.0);
  OPENGL_MATH_ASSERT_EQ(tc2.t(), 0.5);
  OPENGL_MATH_ASSERT_EQ(tc2.r(), 0.7);
  OPENGL_MATH_ASSERT_EQ(tc2.q(), 0.1);
}

/*! \brief This is a test to if two texcoords can be compared for equivalence
*/
void test_equivalence_type_texcoord_2d()
{
  opengl_math::texcoord_2d<float> tc1;
  opengl_math::texcoord_2d<float> tc2;
  OPENGL_MATH_ASSERT_EQ(tc1, tc2);

  tc2.s_and_t(0.0001f, 1.000001f);
  OPENGL_MATH_ASSERT_NE(tc1, tc2);

  opengl_math::texcoord_2d<float> tc3(1.0f, 0.5f);
  opengl_math::texcoord_2d<float> tc4(1.0f, 0.5f);
  OPENGL_MATH_ASSERT_EQ(tc3, tc4);

  tc3.sref() = 0.0f;
  OPENGL_MATH_ASSERT_NE(tc3, tc4);
}

void test_equivalence_type_texcoord_3d()
{
  opengl_math::texcoord_3d<float> tc1;
  opengl_math::texcoord_3d<float> tc2;
  OPENGL_MATH_ASSERT_EQ(tc1, tc2);

  tc2.s_and_t_and_r(0.0001f, 1.000001f, 0.0f);
  OPENGL_MATH_ASSERT_NE(tc1, tc2);

  opengl_math::texcoord_3d<float> tc3(1.0f, 0.7f, 0.8f);
  opengl_math::texcoord_3d<float> tc4(1.0f, 0.7f, 0.8f);
  OPENGL_MATH_ASSERT_EQ(tc3, tc4);

  tc3.tref() = 0.6f;
  OPENGL_MATH_ASSERT_NE(tc3, tc4);
}

void test_equivalence_type_texcoord_4d()
{
  opengl_math::texcoord_4d<float> tc1;
  opengl_math::texcoord_4d<float> tc2;
  OPENGL_MATH_ASSERT_EQ(tc1, tc2);

  tc2.s_and_t_and_r_and_q(0.0001f, 1.000001f, 0.0f, 0.0f);
  OPENGL_MATH_ASSERT_NE(tc1, tc2);

  opengl_math::texcoord_4d<float> tc3(1.0f, 0.7f, 0.8f, 0.8f);
  opengl_math::texcoord_4d<float> tc4(1.0f, 0.7f, 0.8f, 0.8f);
  OPENGL_MATH_ASSERT_EQ(tc3, tc4);

  tc3.tref() = 0.6f;
  OPENGL_MATH_ASSERT_NE(tc3, tc4);
}

void test_extrenuous_type_texcoord_usecases()
{
  opengl_math::texcoord_2d<float> tc1(1.0f, 0.9f);
  // Convert the raw texcoord to an array
  float *raw_data = &tc1.sref();
  OPENGL_MATH_ASSERT_EQ(raw_data[1], 0.9f);
  raw_data[1] = 0.8f;
  OPENGL_MATH_ASSERT_EQ(raw_data[0], 1.0f);
  OPENGL_MATH_ASSERT_EQ(raw_data[1], 0.8f);

  // Check to see if it is POD
  opengl_math::texcoord_3d<float> tc2(1.0f, 1.0f, 0.9f);
  float texcoord_array[3];
  memcpy(texcoord_array, &tc2, sizeof(tc2));
  OPENGL_MATH_ASSERT_EQ(texcoord_array[0], 1.0f);
  OPENGL_MATH_ASSERT_EQ(texcoord_array[1], 1.0f);
  OPENGL_MATH_ASSERT_EQ(texcoord_array[2], 0.9f);
}

void test_type_texcoord_get_dimension()
{
  OPENGL_MATH_ASSERT_EQ(2, opengl_math::texcoord_2d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(2, opengl_math::texcoord_2d<double>::dimension);
  OPENGL_MATH_ASSERT_EQ(3, opengl_math::texcoord_3d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(3, opengl_math::texcoord_3d<double>::dimension);
  OPENGL_MATH_ASSERT_EQ(4, opengl_math::texcoord_4d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(4, opengl_math::texcoord_4d<double>::dimension);
}

bool test_type_texcoord::run()
{
  test_default_2d_texcoord_constructor();
  test_default_3d_texcoord_constructor();
  test_default_4d_texcoord_constructor();
  test_2d_texcoord_constructor();
  test_3d_texcoord_constructor();
  test_4d_texcoord_constructor();
  test_texcoord_2d_copy_constructor();
  test_texcoord_3d_copy_constructor();
  test_texcoord_4d_copy_constructor();
  test_texcoord_2d_assignment_operator();
  test_texcoord_3d_assignment_operator();
  test_texcoord_4d_assignment_operator();
  test_texcoord_2d_subscript_operator();
  test_texcoord_3d_subscript_operator();
  test_texcoord_4d_subscript_operator();
  test_texcoord_2d_setters();
  test_texcoord_3d_setters();
  test_texcoord_4d_setters();
  test_texcoord_2d_get_reference();
  test_texcoord_3d_get_reference();
  test_texcoord_4d_get_reference();
  test_equivalence_type_texcoord_2d();
  test_equivalence_type_texcoord_3d();
  test_equivalence_type_texcoord_4d();
  test_extrenuous_type_texcoord_usecases();
  test_type_texcoord_get_dimension();

  return true;
}