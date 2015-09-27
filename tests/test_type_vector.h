#ifndef VECTOR_TESTS
#define VECTOR_TESTS

#include <cxxtest/TestSuite.h>

#include <graphics/primitives/vectors/type_vector_2d.h>
#include <graphics/primitives/vectors/type_vector_3d.h>
#include <graphics/primitives/vectors/type_vector_4d.h>

#include <iostream>
#include <vector>
#include <cassert>

class vector_tests : public CxxTest::TestSuite
{
public:
  /*! \brief This is a test to see if default constructor for
   * 2d, 3d, and 4d vectors itializes all of its components to 0.0f
   */
  void test_default_2d_vector_constructor()
  {
    gl_wrapper::vector_2d<float> tc1;
    TS_ASSERT(tc1.x() == 0.0f);
    TS_ASSERT(tc1.y() == 0.0f);

    gl_wrapper::vector_2d<double> tc2;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
  }

  void test_default_3d_vector_constructor()
  {
    gl_wrapper::vector_3d<float> tc1;
    TS_ASSERT(tc1.x() == 0.0f);
    TS_ASSERT(tc1.y() == 0.0f);
    TS_ASSERT(tc1.z() == 0.0f);

    gl_wrapper::vector_3d<double> tc2;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
    TS_ASSERT(tc2.z() == 0.0);
  }

  void test_default_4d_vector_constructor()
  {
    gl_wrapper::vector_4d<float> tc1;
    TS_ASSERT(tc1.x() == 0.0f);
    TS_ASSERT(tc1.y() == 0.0f);
    TS_ASSERT(tc1.z() == 0.0f);
    TS_ASSERT(tc1.w() == 0.0f);

    gl_wrapper::vector_4d<double> tc2;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
    TS_ASSERT(tc2.z() == 0.0);
    TS_ASSERT(tc2.w() == 0.0);
  }

  /*! \brief This is a test to see if paramaterized constructor for
   * 2d, 3d, and 4d vectors itializes all of its components correctly
   */
  void test_2d_vector_constructor()
  {
    gl_wrapper::vector_2d<float> tc1(1.0f, 2.0f);
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 2.0f);

    gl_wrapper::vector_2d<double> tc2(1.0, 0.97);
    TS_ASSERT(tc2.x() == 1.0);
    TS_ASSERT(tc2.y() == 0.97);
  }

  void test_3d_vector_constructor()
  {
    gl_wrapper::vector_3d<float> tc1(1.0f, 2.0f, 3.0f);
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 2.0f);
    TS_ASSERT(tc1.z() == 3.0f);

    gl_wrapper::vector_3d<double> tc2(1.0, 0.97, 0.2);
    TS_ASSERT(tc2.x() == 1.0);
    TS_ASSERT(tc2.y() == 0.97);
    TS_ASSERT(tc2.z() == 0.2);
  }

  void test_4d_vector_constructor()
  {
    gl_wrapper::vector_4d<float> tc1(1.0f, 2.0f, 4.0f, 3.0f);
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 2.0f);
    TS_ASSERT(tc1.z() == 4.0f);
    TS_ASSERT(tc1.w() == 3.0f);

    gl_wrapper::vector_4d<double> tc2(1.0, 0.97, 0.2, 0.1);
    TS_ASSERT(tc2.x() == 1.0);
    TS_ASSERT(tc2.y() == 0.97);
    TS_ASSERT(tc2.z() == 0.2);
    TS_ASSERT(tc2.w() == 0.1);
  }

  /*! \brief This is a test to see if the copy constructor for
   * 2d and 4d vectors itializes all of its components correctly
   */
  void test_vector_2d_copy_constructor()
  {
    gl_wrapper::vector_2d<float> tc1(0.9f, 0.75f);
    gl_wrapper::vector_2d<float> tc2(tc1);
    TS_ASSERT(tc2.x() == 0.9f);
    TS_ASSERT(tc2.y() == 0.75f);

    gl_wrapper::vector_2d<double> tc3(0.145, 0.1);
    gl_wrapper::vector_2d<double> tc4(tc3);
    TS_ASSERT(tc4.x() == 0.145);
    TS_ASSERT(tc4.y() == 0.1);
  }

  void test_vector_3d_copy_constructor()
  {
    gl_wrapper::vector_3d<float> tc1(0.82f, 1.0e-10f, 10.0f);
    gl_wrapper::vector_3d<float> tc2(tc1);
    TS_ASSERT(tc2.x() == 0.82f);
    TS_ASSERT(tc2.y() == 0.0000000001f);
    TS_ASSERT(tc2.z() == 10.0f);

    gl_wrapper::vector_3d<double> tc3(0.7, 1.0e-18, 1.000000001);
    gl_wrapper::vector_3d<double> tc4(tc3);
    TS_ASSERT(tc4.x() == 0.7);
    TS_ASSERT(tc4.y() == 1.0e-18);
    TS_ASSERT(tc4.z() == 1.000000001);
  }

  void test_vector_4d_copy_constructor()
  {
    gl_wrapper::vector_4d<float> tc1(0.82f, 1.0e-10f, 10.0f, 1.0f);
    gl_wrapper::vector_4d<float> tc2(tc1);
    TS_ASSERT(tc2.x() == 0.82f);
    TS_ASSERT(tc2.y() == 0.0000000001f);
    TS_ASSERT(tc2.z() == 10.0f);
    TS_ASSERT(tc2.w() == 1.0f);

    gl_wrapper::vector_4d<double> tc3(0.7, 1.0e-18, 1.000000001, 1.0);
    gl_wrapper::vector_4d<double> tc4(tc3);
    TS_ASSERT(tc4.x() == 0.7);
    TS_ASSERT(tc4.y() == 1.0e-18);
    TS_ASSERT(tc4.z() == 1.000000001);
    TS_ASSERT(tc4.w() == 1.0);
  }

  /*! \brief This is a test to see if the assignment operator copies
   * the contents of the rhs value into the lhs without modifying the
   * rhs.
   */
  void test_vector_2d_assignment_operator()
  {
    gl_wrapper::vector_2d<float> tc1(0.88f, 0.0f);
    gl_wrapper::vector_2d<float> tc2 = tc1;
    TS_ASSERT(tc2.x() == 0.88f);
    TS_ASSERT(tc2.y() == 0.0f);
    TS_ASSERT(tc1.x() == 0.88f);
    TS_ASSERT(tc1.y() == 0.0f);

    tc2 = gl_wrapper::vector_2d<float>(0.99f, 0.0f);
    TS_ASSERT(tc2.x() == 0.99f);
    TS_ASSERT(tc2.y() == 0.0f);
    TS_ASSERT(tc1.x() == 0.88f);
    TS_ASSERT(tc1.y() == 0.0f);

    gl_wrapper::vector_2d<double> tc3(0.11, 0.22);
    gl_wrapper::vector_2d<double> tc4 = tc3;
    TS_ASSERT(tc4.x() == 0.11);
    TS_ASSERT(tc4.y() == 0.22);
    TS_ASSERT(tc3.x() == 0.11);
    TS_ASSERT(tc3.y() == 0.22);

    tc4 = gl_wrapper::vector_2d<double>(0.22, 0.33);
    TS_ASSERT(tc4.x() == 0.22);
    TS_ASSERT(tc4.y() == 0.33);
    TS_ASSERT(tc3.x() == 0.11);
    TS_ASSERT(tc3.y() == 0.22);
  }

  void test_vector_3d_assignment_operator()
  {
    gl_wrapper::vector_3d<float> tc1(0.82f, 1.0f, 1.0f);
    gl_wrapper::vector_3d<float> tc2 = tc1;
    TS_ASSERT(tc2.x() == 0.82f);
    TS_ASSERT(tc2.y() == 1.0f);
    TS_ASSERT(tc2.z() == 1.0f);
    TS_ASSERT(tc1.x() == 0.82f);
    TS_ASSERT(tc1.y() == 1.0f);
    TS_ASSERT(tc1.z() == 1.0f);

    tc2 = gl_wrapper::vector_3d<float>(0.83f, 0.99f, 0.98f);
    TS_ASSERT(tc2.x() == 0.83f);
    TS_ASSERT(tc2.y() == 0.99f);
    TS_ASSERT(tc2.z() == 0.98f);
    TS_ASSERT(tc1.x() == 0.82f);
    TS_ASSERT(tc1.y() == 1.0f);
    TS_ASSERT(tc1.z() == 1.0f);

    gl_wrapper::vector_3d<double> tc3(0.66, 0.88, 0.988);
    gl_wrapper::vector_3d<double> tc4 = tc3;
    TS_ASSERT(tc4.x() == 0.66);
    TS_ASSERT(tc4.y() == 0.88);
    TS_ASSERT(tc4.z() == 0.988);
    TS_ASSERT(tc3.x() == 0.66);
    TS_ASSERT(tc3.y() == 0.88);
    TS_ASSERT(tc3.z() == 0.988);

    tc4 = gl_wrapper::vector_3d<double>();
    TS_ASSERT(tc4.x() == 0.0);
    TS_ASSERT(tc4.y() == 0.0);
    TS_ASSERT(tc4.z() == 0.0);
    TS_ASSERT(tc3.x() == 0.66);
    TS_ASSERT(tc3.y() == 0.88);
    TS_ASSERT(tc3.z() == 0.988);
  }

  void test_vector_4d_assignment_operator()
  {
    gl_wrapper::vector_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
    gl_wrapper::vector_4d<float> tc2 = tc1;
    TS_ASSERT(tc2.x() == 0.82f);
    TS_ASSERT(tc2.y() == 1.0f);
    TS_ASSERT(tc2.z() == 1.0f);
    TS_ASSERT(tc2.w() == 0.92f);
    TS_ASSERT(tc1.x() == 0.82f);
    TS_ASSERT(tc1.y() == 1.0f);
    TS_ASSERT(tc1.z() == 1.0f);
    TS_ASSERT(tc1.w() == 0.92f);

    tc2 = gl_wrapper::vector_4d<float>(0.83f, 0.99f, 0.98f, 0.01f);
    TS_ASSERT(tc2.x() == 0.83f);
    TS_ASSERT(tc2.y() == 0.99f);
    TS_ASSERT(tc2.z() == 0.98f);
    TS_ASSERT(tc2.w() == 0.01f);
    TS_ASSERT(tc1.x() == 0.82f);
    TS_ASSERT(tc1.y() == 1.0f);
    TS_ASSERT(tc1.z() == 1.0f);
    TS_ASSERT(tc1.w() == 0.92f);

    gl_wrapper::vector_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
    gl_wrapper::vector_4d<double> tc4 = tc3;
    TS_ASSERT(tc4.x() == 0.66);
    TS_ASSERT(tc4.y() == 0.88);
    TS_ASSERT(tc4.z() == 0.988);
    TS_ASSERT(tc4.w() == 0.28);
    TS_ASSERT(tc3.x() == 0.66);
    TS_ASSERT(tc3.y() == 0.88);
    TS_ASSERT(tc3.z() == 0.988);
    TS_ASSERT(tc3.w() == 0.28);

    tc4 = gl_wrapper::vector_4d<double>();
    TS_ASSERT(tc4.x() == 0.0);
    TS_ASSERT(tc4.y() == 0.0);
    TS_ASSERT(tc4.z() == 0.0);
    TS_ASSERT(tc4.w() == 0.0);
    TS_ASSERT(tc3.x() == 0.66);
    TS_ASSERT(tc3.y() == 0.88);
    TS_ASSERT(tc3.z() == 0.988);
    TS_ASSERT(tc3.w() == 0.28);
  }

  /*! \brief This is a test to see if both constant and non constant versions
   * of the subscript operators behave according to specification.
   */
  void test_vector_2d_subscript_operator()
  {
    gl_wrapper::vector_2d<float> tc1(0.82f, 1.0f);
    TS_ASSERT(tc1[0] == 0.82f);
    TS_ASSERT(tc1[1] == 1.0f);
    tc1[0] = 0.81f;
    TS_ASSERT(tc1[0] == 0.81f);
    TS_ASSERT(tc1[1] == 1.0f);

    gl_wrapper::vector_2d<double> tc3(0.66, 0.88);
    TS_ASSERT(tc3[0] == 0.66);
    TS_ASSERT(tc3[1] == 0.88);
    tc3[1] = 0.99;
    TS_ASSERT(tc3[0] == 0.66);
    TS_ASSERT(tc3[1] == 0.99);
  }

  void test_vector_3d_subscript_operator()
  {
    gl_wrapper::vector_3d<float> tc1(0.82f, 1.0f, 1.0f);
    TS_ASSERT(tc1[0] == 0.82f);
    TS_ASSERT(tc1[1] == 1.0f);
    TS_ASSERT(tc1[2] == 1.0f);
    tc1[0] = 0.83f;
    tc1[1] = 0.99f;
    TS_ASSERT(tc1[0] == 0.83f);
    TS_ASSERT(tc1[1] == 0.99f);
    TS_ASSERT(tc1[2] == 1.0f);

    gl_wrapper::vector_3d<double> tc3(0.66, 0.88, 0.988);
    TS_ASSERT(tc3[0] == 0.66);
    TS_ASSERT(tc3[1] == 0.88);
    TS_ASSERT(tc3[2] == 0.988);
    tc3[2] = 0.01;
    TS_ASSERT(tc3[0] == 0.66);
    TS_ASSERT(tc3[1] == 0.88);
    TS_ASSERT(tc3[2] == 0.01);
  }

  void test_vector_4d_subscript_operator()
  {
    gl_wrapper::vector_4d<float> tc1(0.82f, 1.0f, 1.0f, 0.92f);
    TS_ASSERT(tc1[0] == 0.82f);
    TS_ASSERT(tc1[1] == 1.0f);
    TS_ASSERT(tc1[2] == 1.0f);
    TS_ASSERT(tc1[3] == 0.92f);
    tc1[0] = 0.00f;
    tc1[1] = 0.00f;
    TS_ASSERT(tc1[0] == 0.00f);
    TS_ASSERT(tc1[1] == 0.00f);
    TS_ASSERT(tc1[2] == 1.00f);
    TS_ASSERT(tc1[3] == 0.92f);

    gl_wrapper::vector_4d<double> tc3(0.66, 0.88, 0.988, 0.28);
    TS_ASSERT(tc3[0] == 0.66);
    TS_ASSERT(tc3[1] == 0.88);
    TS_ASSERT(tc3[2] == 0.988);
    TS_ASSERT(tc3[3] == 0.28);
    tc3[2] = 0.00;
    tc3[3] = 0.00;
    TS_ASSERT(tc3[0] == 0.66);
    TS_ASSERT(tc3[1] == 0.88);
    TS_ASSERT(tc3[2] == 0.00);
    TS_ASSERT(tc3[3] == 0.00);
  }

  /*! \brief This is a test to see if the setters for 2d and 3d vectors
   * set the value to a new value.
   */
  void test_vector_2d_setters()
  {
    gl_wrapper::vector_2d<float> tc1;
    tc1.x(1.0f);
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 0.0f);
    tc1.y(0.5f);
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 0.5f);
    tc1.y(0.2f);
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 0.2f);
    tc1.x_and_y(0.0f, 0.0f);
    TS_ASSERT(tc1.x() == 0.0f);
    TS_ASSERT(tc1.y() == 0.0f);

    gl_wrapper::vector_2d<double> tc2;
    tc2.x(0.5);
    TS_ASSERT(tc2.x() == 0.5);
    TS_ASSERT(tc2.y() == 0.0);
    tc2.y(0.5);
    TS_ASSERT(tc2.x() == 0.5);
    TS_ASSERT(tc2.y() == 0.5);
    tc2.x(0.4);
    TS_ASSERT(tc2.x() == 0.4);
    TS_ASSERT(tc2.y() == 0.5);
    tc2.x_and_y(0.1, 0.1);
    TS_ASSERT(tc2.x() == 0.1);
    TS_ASSERT(tc2.y() == 0.1);
  }

  void test_vector_3d_setters()
  {
    gl_wrapper::vector_3d<float> tc1;
    tc1.x(0.01f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.00f);
    TS_ASSERT(tc1.z() == 0.00f);
    tc1.y(0.02f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.00f);
    tc1.z(0.05f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.05f);
    tc1.z(0.07f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.07f);
    tc1.x_and_y_and_z(0.09f, 0.11f, 0.15f);
    TS_ASSERT(tc1.x() == 0.09f);
    TS_ASSERT(tc1.y() == 0.11f);
    TS_ASSERT(tc1.z() == 0.15f);

    gl_wrapper::vector_3d<double> tc2;
    tc2.x(0.0);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
    TS_ASSERT(tc2.z() == 0.0);
    tc2.y(0.5);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.0);
    tc2.z(0.7);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    tc2.x(0.1);
    TS_ASSERT(tc2.x() == 0.1);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    tc2.x_and_y_and_z(0.1, 0.1, 0.1);
    TS_ASSERT(tc2.x() == 0.1);
    TS_ASSERT(tc2.y() == 0.1);
    TS_ASSERT(tc2.z() == 0.1);
  }

  void test_vector_4d_setters()
  {
    gl_wrapper::vector_4d<float> tc1;
    tc1.x(0.01f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.00f);
    TS_ASSERT(tc1.z() == 0.00f);
    TS_ASSERT(tc1.w() == 0.00f);
    tc1.y(0.02f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.00f);
    TS_ASSERT(tc1.w() == 0.00f);
    tc1.z(0.05f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.05f);
    TS_ASSERT(tc1.w() == 0.00f);
    tc1.w(0.07f);
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.05f);
    TS_ASSERT(tc1.w() == 0.07f);
    tc1.x_and_y_and_z_and_w(0.09f, 0.11f, 0.15f, 0.22f);
    TS_ASSERT(tc1.x() == 0.09f);
    TS_ASSERT(tc1.y() == 0.11f);
    TS_ASSERT(tc1.z() == 0.15f);
    TS_ASSERT(tc1.w() == 0.22f);

    gl_wrapper::vector_4d<double> tc2;
    tc2.x(0.0);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
    TS_ASSERT(tc2.z() == 0.0);
    TS_ASSERT(tc2.w() == 0.0);
    tc2.y(0.5);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.0);
    TS_ASSERT(tc2.w() == 0.0);
    tc2.z(0.7);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    TS_ASSERT(tc2.w() == 0.0);
    tc2.w(0.1);
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    TS_ASSERT(tc2.w() == 0.1);
    tc2.x_and_y_and_z_and_w(0.1, 0.1, 0.1, 0.1);
    TS_ASSERT(tc2.x() == 0.1);
    TS_ASSERT(tc2.y() == 0.1);
    TS_ASSERT(tc2.z() == 0.1);
    TS_ASSERT(tc2.w() == 0.1);
  }

  /*! \brief This is a test to see if the getters by ref for 2d, 3d, and 4d
   * vectors set the value to a new value.
   */
  void test_vector_2d_get_reference()
  {
    gl_wrapper::vector_2d<float> tc1;
    tc1.xref() = 1.0f;
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 0.0f);
    tc1.yref() = 0.5f;
    TS_ASSERT(tc1.x() == 1.0f);
    TS_ASSERT(tc1.y() == 0.5f);
    tc1.xref() = 0.2f;
    TS_ASSERT(tc1.x() == 0.2f);
    TS_ASSERT(tc1.y() == 0.5f);

    gl_wrapper::vector_2d<double> tc2;
    tc2.xref() = 0.5;
    TS_ASSERT(tc2.x() == 0.5);
    TS_ASSERT(tc2.y() == 0.0);
    tc2.yref() = 0.5;
    TS_ASSERT(tc2.x() == 0.5);
    TS_ASSERT(tc2.y() == 0.5);
    tc2.yref() = 0.4;
    TS_ASSERT(tc2.x() == 0.5);
    TS_ASSERT(tc2.y() == 0.4);
  }

  void test_vector_3d_get_reference()
  {
    gl_wrapper::vector_3d<float> tc1;
    tc1.xref() = 0.01f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.00f);
    TS_ASSERT(tc1.z() == 0.00f);
    tc1.yref() = 0.02f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.00f);
    tc1.zref() = 0.05f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.05f);

    gl_wrapper::vector_3d<double> tc2;
    tc2.xref() = 0.0;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
    TS_ASSERT(tc2.z() == 0.0);
    tc2.yref() = 0.5;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.0);
    tc2.zref() = 0.7;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    tc2.zref() = 0.1;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.1);
  }

  void test_vector_4d_get_reference()
  {
    gl_wrapper::vector_4d<float> tc1;
    tc1.xref() = 0.01f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.00f);
    TS_ASSERT(tc1.z() == 0.00f);
    TS_ASSERT(tc1.w() == 0.00f);
    tc1.yref() = 0.02f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.00f);
    TS_ASSERT(tc1.w() == 0.00f);
    tc1.zref() = 0.05f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.05f);
    TS_ASSERT(tc1.w() == 0.00f);
    tc1.wref() = 1.0f;
    TS_ASSERT(tc1.x() == 0.01f);
    TS_ASSERT(tc1.y() == 0.02f);
    TS_ASSERT(tc1.z() == 0.05f);
    TS_ASSERT(tc1.w() == 1.00f);

    gl_wrapper::vector_4d<double> tc2;
    tc2.xref() = 0.0;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.0);
    TS_ASSERT(tc2.z() == 0.0);
    TS_ASSERT(tc2.w() == 0.0);
    tc2.yref() = 0.5;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.0);
    TS_ASSERT(tc2.w() == 0.0);
    tc2.zref() = 0.7;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    TS_ASSERT(tc2.w() == 0.0);
    tc2.wref() = 0.1;
    TS_ASSERT(tc2.x() == 0.0);
    TS_ASSERT(tc2.y() == 0.5);
    TS_ASSERT(tc2.z() == 0.7);
    TS_ASSERT(tc2.w() == 0.1);
  }

  /*! \brief This is a test to if two vectors can be compared for equivalence
   */
  void test_equivalence_2d()
  {
    gl_wrapper::vector_2d<float> tc1;
    gl_wrapper::vector_2d<float> tc2;
    TS_ASSERT(tc1 == tc2);

    tc2.x_and_y(0.0001f, 1.000001f);
    TS_ASSERT(tc1 != tc2);

    gl_wrapper::vector_2d<float> tc3(1.0f, 0.5f);
    gl_wrapper::vector_2d<float> tc4(1.0f, 0.5f);
    TS_ASSERT(tc3 == tc4);

    tc3.xref() = 0.0f;
    TS_ASSERT(tc3 != tc4);
  }

  void test_equivalence_3d()
  {
    gl_wrapper::vector_3d<float> tc1;
    gl_wrapper::vector_3d<float> tc2;
    TS_ASSERT(tc1 == tc2);

    tc2.x_and_y_and_z(0.0001f, 1.000001f, 0.0f);
    TS_ASSERT(tc1 != tc2);

    gl_wrapper::vector_3d<float> tc3(1.0f, 0.7f, 0.8f);
    gl_wrapper::vector_3d<float> tc4(1.0f, 0.7f, 0.8f);
    TS_ASSERT(tc3 == tc4);

    tc3.yref() = 0.6f;
    TS_ASSERT(tc3 != tc4);
  }

  void test_equivalence_4d()
  {
    gl_wrapper::vector_4d<float> tc1;
    gl_wrapper::vector_4d<float> tc2;
    TS_ASSERT(tc1 == tc2);

    tc2.x_and_y_and_z_and_w(0.0001f, 1.000001f, 0.0f, 0.0f);
    TS_ASSERT(tc1 != tc2);

    gl_wrapper::vector_4d<float> tc3(1.0f, 0.7f, 0.8f, 0.8f);
    gl_wrapper::vector_4d<float> tc4(1.0f, 0.7f, 0.8f, 0.8f);
    TS_ASSERT(tc3 == tc4);

    tc3.yref() = 0.6f;
    TS_ASSERT(tc3 != tc4);
  }

  void test_extrenuous_usecases()
  {
    gl_wrapper::vector_2d<float> tc1(1.0f, 0.9f);
    // Convert the raw vector to an array
    float *raw_data = &tc1.xref();
    TS_ASSERT(raw_data[1] == 0.9f);
    raw_data[1] = 0.8f;
    TS_ASSERT(raw_data[0] == 1.0f);
    TS_ASSERT(raw_data[1] == 0.8f);

    // Check to see if it is POD
    gl_wrapper::vector_3d<float> tc2(1.0f, 1.0f, 0.9f);
    float vector_array[3];
    memcpy(vector_array, &tc2, sizeof(tc2));
    TS_ASSERT(vector_array[0] == 1.0f);
    TS_ASSERT(vector_array[1] == 1.0f);
    TS_ASSERT(vector_array[2] == 0.9f);
  }

  /*! brief Arithmatic operator tests
   */
  void test_magnitude_2d()
  {
    const gl_wrapper::vector_2d<float> vf(20.0f, 10.0f);
    TS_ASSERT_DELTA(sqrt(500.0f), vf.magnitude(), 1e-006f);

    const gl_wrapper::vector_2d<double> vd(20.0, 10.0);
    TS_ASSERT_DELTA(sqrt(500.0), vd.magnitude(), 1e-006);
  }

  void test_magnitude_3d()
  {
    const gl_wrapper::vector_3d<float> vf(20.0f, 10.0f, 20.0f);
    TS_ASSERT_DELTA(30.0, vf.magnitude(), 1e-006f);

    const gl_wrapper::vector_3d<double> vd(20.0, 10.0, 20.0);
    TS_ASSERT_DELTA(30.0, vd.magnitude(), 1e-006);
  }

  void test_magnitude_4d()
  {
    const gl_wrapper::vector_4d<float> vf(20.0f, 10.0f, 20.0f, 0.0f);
    TS_ASSERT_DELTA(30.0, vf.magnitude(), 1e-006f);

    const gl_wrapper::vector_4d<double> vd(20.0, 10.0, 20.0, 0.0);
    TS_ASSERT_DELTA(30.0, vd.magnitude(), 1e-006);
  }


  void test_normalize_2d()
  {
    gl_wrapper::vector_2d<float> vf(20.0f, 10.0f);
    vf.normalize();
    TS_ASSERT_DELTA(0.89443f, vf.x(), 1e-005f);
    TS_ASSERT_DELTA(0.44721f, vf.y(), 1e-005f);

    gl_wrapper::vector_2d<double> vd(20.0, 10.0);
    vd.normalize();
    TS_ASSERT_DELTA(0.89443, vd.x(), 1e-005);
    TS_ASSERT_DELTA(0.44721, vd.y(), 1e-005);
  }

  void test_normalize_3d()
  {
    gl_wrapper::vector_3d<float> vf(20.0f, 10.0f, 20.0f);
    vf.normalize();
    TS_ASSERT_DELTA(2.0f / 3.0f, vf.x(), 1e-005f);
    TS_ASSERT_DELTA(1.0f / 3.0f, vf.y(), 1e-005f);
    TS_ASSERT_DELTA(2.0f / 3.0f, vf.z(), 1e-005f);

    gl_wrapper::vector_3d<double> vd(20.0, 10.0, 20.0);
    vd.normalize();
    TS_ASSERT_DELTA(2.0 / 3.0, vd.x(), 1e-005);
    TS_ASSERT_DELTA(1.0 / 3.0, vd.y(), 1e-005);
    TS_ASSERT_DELTA(2.0 / 3.0, vd.z(), 1e-005);
  }

  void test_normalize_4d()
  {
    gl_wrapper::vector_4d<float> vf(20.0f, 10.0f, 20.0f, 0.0f);
    vf.normalize();
    TS_ASSERT_DELTA(2.0f / 3.0f, vf.x(), 1e-005f);
    TS_ASSERT_DELTA(1.0f / 3.0f, vf.y(), 1e-005f);
    TS_ASSERT_DELTA(2.0f / 3.0f, vf.z(), 1e-005f);
    TS_ASSERT_DELTA(0.0f, vf.w(), 1e-005f);

    gl_wrapper::vector_4d<double> vd(20.0, 10.0, 20.0, 0.0f);
    vd.normalize();
    TS_ASSERT_DELTA(2.0 / 3.0, vd.x(), 1e-005);
    TS_ASSERT_DELTA(1.0 / 3.0, vd.y(), 1e-005);
    TS_ASSERT_DELTA(2.0 / 3.0, vd.z(), 1e-005);
    TS_ASSERT_DELTA(0.0, vd.w(), 1e-005);
  }

  void test_dot_2d()
  {
    const gl_wrapper::vector_2d<float> vf1(1.0f, 2.0f);
    const gl_wrapper::vector_2d<float> vf2(3.0f, 2.0f);
    TS_ASSERT_DELTA(7.0f, vf1.dot(vf2), 1e-006f);

    const gl_wrapper::vector_2d<double> vd1(1.0, 2.0);
    const gl_wrapper::vector_2d<double> vd2(3.0, 2.0);
    TS_ASSERT_DELTA(7.0, vd1.dot(vd2), 1e-006);
  }

  void test_dot_3d()
  {
    const gl_wrapper::vector_3d<float> vf1(1.0f, 2.0f, 4.0f);
    const gl_wrapper::vector_3d<float> vf2(3.0f, 2.0f, 8.0f);
    TS_ASSERT_DELTA(39.0f, vf1.dot(vf2), 1e-006f);

    const gl_wrapper::vector_3d<double> vd1(1.0, 2.0, 4.0);
    const gl_wrapper::vector_3d<double> vd2(3.0, 2.0, 8.0);
    TS_ASSERT_DELTA(39.0, vd1.dot(vd2), 1e-006);
  }

  void test_dot_4d()
  {
    const gl_wrapper::vector_4d<float> vf1(1.0f, 2.0f, 4.0f, 10000.0f);
    const gl_wrapper::vector_4d<float> vf2(3.0f, 2.0f, 8.0f, 90000.0f);
    TS_ASSERT_DELTA(900000039.0f, vf1.dot(vf2), 1e-006f);

    const gl_wrapper::vector_4d<double> vd1(1.0, 2.0, 4.0, 10000.0);
    const gl_wrapper::vector_4d<double> vd2(3.0, 2.0, 8.0, 90000.0);
    TS_ASSERT_DELTA(900000039.0, vd1.dot(vd2), 1e-006);
  }

  void test_cross_3d()
  {
    {
      const gl_wrapper::vector_3d<float> vf1(2.0f, 4.0f, 8.0f);
      const gl_wrapper::vector_3d<float> vf2(2.0f, 4.0f, 8.0f);

      const gl_wrapper::vector_3d<float> cross12 = vf1.cross(vf2);
      TS_ASSERT_DELTA(0.0f, cross12.x(), 1e-006f);
      TS_ASSERT_DELTA(0.0f, cross12.y(), 1e-006f);
      TS_ASSERT_DELTA(0.0f, cross12.z(), 1e-006f);

      const gl_wrapper::vector_3d<float> cross21 = vf2.cross(vf1);
      TS_ASSERT_DELTA(0.0f, cross21.x(), 1e-006f);
      TS_ASSERT_DELTA(0.0f, cross21.y(), 1e-006f);
      TS_ASSERT_DELTA(0.0f, cross21.z(), 1e-006f);
    }

    {
      const gl_wrapper::vector_3d<double> vd1(1.0, 0.0, 0.0);
      const gl_wrapper::vector_3d<double> vd2(0.0, 1.0, 0.0);
      const gl_wrapper::vector_3d<double> vd3(0.0, 0.0, 1.0);

      const gl_wrapper::vector_3d<double> crossxy = vd1.cross(vd2);
      TS_ASSERT_DELTA(0.0, crossxy.x(), 1e-006);
      TS_ASSERT_DELTA(0.0, crossxy.y(), 1e-006);
      TS_ASSERT_DELTA(1.0, crossxy.z(), 1e-006);

      const gl_wrapper::vector_3d<double> crossxz = vd3.cross(vd1);
      TS_ASSERT_DELTA(0.0, crossxz.x(), 1e-006);
      TS_ASSERT_DELTA(1.0, crossxz.y(), 1e-006);
      TS_ASSERT_DELTA(0.0, crossxz.z(), 1e-006);

      const gl_wrapper::vector_3d<double> crossyz = vd2.cross(vd3);
      TS_ASSERT_DELTA(1.0, crossyz.x(), 1e-006);
      TS_ASSERT_DELTA(0.0, crossyz.y(), 1e-006);
      TS_ASSERT_DELTA(0.0, crossyz.z(), 1e-006);
    }
  }

  void test_plus_equals_2d()
  {
    gl_wrapper::vector_2d<float> vf1(12.38f, 1.22f);
    vf1 += gl_wrapper::vector_2d<float>(0.62f, 0.78f);
    TS_ASSERT_DELTA(13.0f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(2.0f, vf1.y(), 1e-006f);
  }

  void test_plus_equals_3d()
  {
    gl_wrapper::vector_3d<float> vf1(12.38f, 1.22f, 3.06f);
    vf1 += gl_wrapper::vector_3d<float>(0.62f, 0.78f, 1.94f);
    TS_ASSERT_DELTA(13.0f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(2.0f, vf1.y(), 1e-006f);
    TS_ASSERT_DELTA(5.0f, vf1.z(), 1e-006f);
  }

  void test_plus_equals_4d()
  {
    gl_wrapper::vector_4d<float> vf1(12.38f, 1.22f, 3.06f, 0.01f);
    vf1 += gl_wrapper::vector_4d<float>(0.62f, 0.78f, 1.94f, 0.99f);
    TS_ASSERT_DELTA(13.0f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(2.0f, vf1.y(), 1e-006f);
    TS_ASSERT_DELTA(5.0f, vf1.z(), 1e-006f);
    TS_ASSERT_DELTA(1.0f, vf1.w(), 1e-006f);
  }

  void test_minus_equals_2d()
  {
    gl_wrapper::vector_2d<float> vf1(12.38f, 1.22f);
    vf1 -= gl_wrapper::vector_2d<float>(0.38f, 0.22f);
    TS_ASSERT_DELTA(12.0f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(1.00f, vf1.y(), 1e-006f);
  }

  void test_minus_equals_3d()
  {
    gl_wrapper::vector_3d<float> vf1(12.38f, 1.22f, 0.01f);
    vf1 -= gl_wrapper::vector_3d<float>(0.38f, 0.22f, 0.01f);
    TS_ASSERT_DELTA(12.0f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(1.00f, vf1.y(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf1.z(), 1e-006f);
  }

  void test_minus_equals_4d()
  {
    gl_wrapper::vector_4d<float> vf1(12.38f, 1.22f, 0.01f, 0.00f);
    vf1 -= gl_wrapper::vector_4d<float>(0.38f, 0.22f, 0.01f, 0.00f);
    TS_ASSERT_DELTA(12.0f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(1.00f, vf1.y(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf1.z(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf1.w(), 1e-006f);
  }

  void test_times_equals_scalar_2d()
  {
    gl_wrapper::vector_2d<float> vf1(2.0f, 4.0f);
    vf1 *= 2.0f;
    TS_ASSERT_DELTA(4.00f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(8.00f, vf1.y(), 1e-006f);
  }

  void test_times_equals_scalar_3d()
  {
    gl_wrapper::vector_3d<float> vf1(2.0f, 4.0f, 2.0f);
    vf1 *= 2.0f;
    TS_ASSERT_DELTA(4.00f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(8.00f, vf1.y(), 1e-006f);
    TS_ASSERT_DELTA(4.00f, vf1.z(), 1e-006f);
  }

  void test_times_equals_scalar_4d()
  {
    gl_wrapper::vector_4d<float> vf1(2.0f, 4.0f, 2.0f, 8.1f);
    vf1 *= 2.0f;
    TS_ASSERT_DELTA(4.00f, vf1.x(), 1e-006f);
    TS_ASSERT_DELTA(8.00f, vf1.y(), 1e-006f);
    TS_ASSERT_DELTA(4.00f, vf1.z(), 1e-006f);
    TS_ASSERT_DELTA(16.2f, vf1.w(), 1e-006f);
  }

  void test_addition_2d()
  {
    gl_wrapper::vector_2d<float> vf1(2.0f, 4.0f);
    gl_wrapper::vector_2d<float> vf2(2.0f, 4.0f);

    gl_wrapper::vector_2d<float> vf3 = vf1 + vf2;
    gl_wrapper::vector_2d<float> vf4 = vf2 + vf1;

    TS_ASSERT_EQUALS(vf3, vf4);
    TS_ASSERT_DELTA(4.00f, vf3.x(), 1e-006f);
    TS_ASSERT_DELTA(8.00f, vf3.y(), 1e-006f);
  }

  void test_addition_3d()
  {
    gl_wrapper::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
    gl_wrapper::vector_3d<float> vf2(2.0f, 4.0f, 15.7f);

    gl_wrapper::vector_3d<float> vf3 = vf1 + vf2;
    gl_wrapper::vector_3d<float> vf4 = vf2 + vf1;

    TS_ASSERT_EQUALS(vf3, vf4);
    TS_ASSERT_DELTA(4.00f, vf3.x(), 1e-006f);
    TS_ASSERT_DELTA(8.00f, vf3.y(), 1e-006f);
    TS_ASSERT_DELTA(32.00f, vf3.z(), 1e-006f);
  }

  void test_addition_4d()
  {
    gl_wrapper::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
    gl_wrapper::vector_4d<float> vf2(2.0f, 4.0f, 15.7f, 0.7f);

    gl_wrapper::vector_4d<float> vf3 = vf1 + vf2;
    gl_wrapper::vector_4d<float> vf4 = vf2 + vf1;

    TS_ASSERT_EQUALS(vf3, vf4);
    TS_ASSERT_DELTA(4.00f, vf3.x(), 1e-006f);
    TS_ASSERT_DELTA(8.00f, vf3.y(), 1e-006f);
    TS_ASSERT_DELTA(32.00f, vf3.z(), 1e-006f);
    TS_ASSERT_DELTA(100.9f, vf3.w(), 1e-001);
  }

  void test_subtraction_2d()
  {
    gl_wrapper::vector_2d<float> vf1(2.0f, 4.0f);
    gl_wrapper::vector_2d<float> vf2(2.0f, 4.0f);

    gl_wrapper::vector_2d<float> vf3 = vf1 - vf2;
    TS_ASSERT_DELTA(0.0f, vf3.x(), 1e-006f);
    TS_ASSERT_DELTA(0.0f, vf3.y(), 1e-006f);

    gl_wrapper::vector_2d<float> vf4 = vf2 - vf1;
    TS_ASSERT_DELTA(0.0f, vf4.x(), 1e-006f);
    TS_ASSERT_DELTA(0.0f, vf4.y(), 1e-006f);
  }

  void test_subtraction_3d()
  {
    gl_wrapper::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
    gl_wrapper::vector_3d<float> vf2(2.0f, 4.0f, 15.7f);

    gl_wrapper::vector_3d<float> vf3 = vf1 - vf2;
    TS_ASSERT_DELTA(0.00f, vf3.x(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf3.y(), 1e-006f);
    TS_ASSERT_DELTA(0.6f, vf3.z(), 1e-006f);

    gl_wrapper::vector_3d<float> vf4 = vf2 - vf1;
    TS_ASSERT_DELTA(0.00f, vf4.x(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf4.y(), 1e-006f);
    TS_ASSERT_DELTA(-0.6f, vf4.z(), 1e-006f);
  }

  void test_subtraction_4d()
  {
    gl_wrapper::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
    gl_wrapper::vector_4d<float> vf2(2.0f, 4.0f, 15.7f, 0.7f);

    gl_wrapper::vector_4d<float> vf3 = vf1 - vf2;
    TS_ASSERT_DELTA(0.00f, vf3.x(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf3.y(), 1e-006f);
    TS_ASSERT_DELTA(0.6f, vf3.z(), 1e-006f);
    TS_ASSERT_DELTA(99.5f, vf3.w(), 1e-006f);

    gl_wrapper::vector_4d<float> vf4 = vf2 - vf1;
    TS_ASSERT_DELTA(0.00f, vf4.x(), 1e-006f);
    TS_ASSERT_DELTA(0.00f, vf4.y(), 1e-006f);
    TS_ASSERT_DELTA(-0.6f, vf4.z(), 1e-006f);
    TS_ASSERT_DELTA(-99.5f, vf4.w(), 1e-006f);
  }

  void test_unary_minus_2d()
  {
    gl_wrapper::vector_2d<float> vf1(2.0f, 4.0f);
    vf1 = -vf1;

    TS_ASSERT_EQUALS(-2.0f, vf1.x());
    TS_ASSERT_EQUALS(-4.0f, vf1.y());
  }

  void test_unary_minus_3d()
  {
    gl_wrapper::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
    vf1 = -vf1;

    TS_ASSERT_EQUALS(-2.0f, vf1.x());
    TS_ASSERT_EQUALS(-4.0f, vf1.y());
    TS_ASSERT_EQUALS(-16.3f, vf1.z());
  }

  void test_unary_minus_4d()
  {
    gl_wrapper::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
    vf1 = -vf1;

    TS_ASSERT_EQUALS(-2.0f, vf1.x());
    TS_ASSERT_EQUALS(-4.0f, vf1.y());
    TS_ASSERT_EQUALS(-16.3f, vf1.z());
    TS_ASSERT_EQUALS(-100.2f, vf1.w());
  }

  void test_time_scalar_2d()
  {
    gl_wrapper::vector_2d<float> vf1(2.0f, 4.0f);
    vf1 = 2.0f * vf1;

    TS_ASSERT_DELTA(4.0f, vf1.x(), 1e-006);
    TS_ASSERT_DELTA(8.0f, vf1.y(), 1e-006);

    vf1 = vf1 * (1.0f / 2.0f);
    TS_ASSERT_DELTA(2.0f, vf1.x(), 1e-006);
    TS_ASSERT_DELTA(4.0f, vf1.y(), 1e-006);
  }

  void test_time_scalar_3d()
  {
    gl_wrapper::vector_3d<float> vf1(2.0f, 4.0f, 16.3f);
    vf1 = 2.0f * vf1;

    TS_ASSERT_DELTA(4.0f, vf1.x(), 1e-006);
    TS_ASSERT_DELTA(8.0f, vf1.y(), 1e-006);
    TS_ASSERT_DELTA(32.6f, vf1.z(), 1e-006);

    vf1 = vf1 * (1.0f / 2.0f);
    TS_ASSERT_DELTA(2.0f, vf1.x(), 1e-006);
    TS_ASSERT_DELTA(4.0f, vf1.y(), 1e-006);
    TS_ASSERT_DELTA(16.3f, vf1.z(), 1e-006);
  }

  void test_time_scalar_4d()
  {
    gl_wrapper::vector_4d<float> vf1(2.0f, 4.0f, 16.3f, 100.2f);
    vf1 = 2.0f * vf1;

    TS_ASSERT_DELTA(4.0f, vf1.x(), 1e-006);
    TS_ASSERT_DELTA(8.0f, vf1.y(), 1e-006);
    TS_ASSERT_DELTA(32.6f, vf1.z(), 1e-006);
    TS_ASSERT_DELTA(200.4f, vf1.w(), 1e-006);

    vf1 = vf1 * (1.0f / 2.0f);
    TS_ASSERT_DELTA(2.0f, vf1.x(), 1e-006);
    TS_ASSERT_DELTA(4.0f, vf1.y(), 1e-006);
    TS_ASSERT_DELTA(16.3f, vf1.z(), 1e-006);
    TS_ASSERT_DELTA(100.2f, vf1.w(), 1e-006);
  }

  void test_get_dimension()
  {
    TS_ASSERT_EQUALS(2, gl_wrapper::vector_2d<float>::dimension);
    TS_ASSERT_EQUALS(2, gl_wrapper::vector_2d<double>::dimension);
    TS_ASSERT_EQUALS(3, gl_wrapper::vector_3d<float>::dimension);
    TS_ASSERT_EQUALS(3, gl_wrapper::vector_3d<double>::dimension);
    TS_ASSERT_EQUALS(4, gl_wrapper::vector_4d<float>::dimension);
    TS_ASSERT_EQUALS(4, gl_wrapper::vector_4d<double>::dimension);
  }
};

#endif
