#ifndef POINT_TESTS
#define POINT_TESTS

#include <cxxtest/TestSuite.h>

#include <graphics/primitives/points/type_point_2d.h>
#include <graphics/primitives/points/type_point_3d.h>

#include <iostream>
#include <vector>
#include <cassert>

class point_tests : public CxxTest::TestSuite
{
public:
  /*! \brief This is a test to see if default constructor for
   * 2d and 3d points itializes all of its components to 0.0f
   */
  void test_default_2d_point_constructor()
  {
    gl_wrapper::point_2d<float> p1;
    TS_ASSERT(p1.x() == 0.0f);
    TS_ASSERT(p1.y() == 0.0f);

    gl_wrapper::point_2d<double> p2;
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.0);
  }

  void test_default_3d_point_constructor()
  {
    gl_wrapper::point_3d<float> p1;
    TS_ASSERT(p1.x() == 0.0f);
    TS_ASSERT(p1.y() == 0.0f);
    TS_ASSERT(p1.z() == 0.0f);

    gl_wrapper::point_3d<double> p2;
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.0);
    TS_ASSERT(p2.z() == 0.0);
  }

  /*! \brief This is a test to see if paramaterized constructor for
   * 2d and rgba points itializes all of its components correctly
   */
  void test_2d_point_constructor()
  {
    gl_wrapper::point_2d<float> p1(1.0f, 2.0f);
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 2.0f);

    gl_wrapper::point_2d<double> p2(1.0, 0.97);
    TS_ASSERT(p2.x() == 1.0);
    TS_ASSERT(p2.y() == 0.97);
  }

  void test_3d_point_constructor()
  {
    gl_wrapper::point_3d<float> p1(1.0f, 2.0f, 3.0f);
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 2.0f);
    TS_ASSERT(p1.z() == 3.0f);

    gl_wrapper::point_3d<double> p2(1.0, 0.97, 0.2);
    TS_ASSERT(p2.x() == 1.0);
    TS_ASSERT(p2.y() == 0.97);
    TS_ASSERT(p2.z() == 0.2);
  }

  /*! \brief This is a test to see if the copy constructor for
   * 2d and rgba points itializes all of its components correctly
   */
  void test_point_2d_copy_constructor()
  {
    gl_wrapper::point_2d<float> p1(0.9f, 0.75f);
    gl_wrapper::point_2d<float> p2(p1);
    TS_ASSERT(p2.x() == 0.9f);
    TS_ASSERT(p2.y() == 0.75f);

    gl_wrapper::point_2d<double> p3(0.145, 0.1);
    gl_wrapper::point_2d<double> p4(p3);
    TS_ASSERT(p4.x() == 0.145);
    TS_ASSERT(p4.y() == 0.1);
  }

  void test_point_3d_copy_constructor()
  {
    gl_wrapper::point_3d<float> p1(0.82f, 1.0e-10f, 10.0);
    gl_wrapper::point_3d<float> p2(p1);
    TS_ASSERT(p2.x() == 0.82f);
    TS_ASSERT(p2.y() == 0.0000000001f);
    TS_ASSERT(p2.z() == 10.0f);

    gl_wrapper::point_3d<double> p3(0.7, 1.0e-18, 1.000000001);
    gl_wrapper::point_3d<double> p4(p3);
    TS_ASSERT(p4.x() == 0.7);
    TS_ASSERT(p4.y() == 1.0e-18);
    TS_ASSERT(p4.z() == 1.000000001);
  }

  /*! \brief This is a test to see if the assignment operator copies
   * the contents of the rhs value into the lhs without modifying the
   * rhs.
   */
  void test_point_2d_assignment_operator()
  {
    gl_wrapper::point_2d<float> p1(0.88f, 0.0f);
    gl_wrapper::point_2d<float> p2 = p1;
    TS_ASSERT(p2.x() == 0.88f);
    TS_ASSERT(p2.y() == 0.0f);
    TS_ASSERT(p1.x() == 0.88f);
    TS_ASSERT(p1.y() == 0.0f);

    p2 = gl_wrapper::point_2d<float>(0.99f, 0.0f);
    TS_ASSERT(p2.x() == 0.99f);
    TS_ASSERT(p2.y() == 0.0f);
    TS_ASSERT(p1.x() == 0.88f);
    TS_ASSERT(p1.y() == 0.0f);

    gl_wrapper::point_2d<double> p3(0.11, 0.22);
    gl_wrapper::point_2d<double> p4 = p3;
    TS_ASSERT(p4.x() == 0.11);
    TS_ASSERT(p4.y() == 0.22);
    TS_ASSERT(p3.x() == 0.11);
    TS_ASSERT(p3.y() == 0.22);

    p4 = gl_wrapper::point_2d<double>(0.22, 0.33);
    TS_ASSERT(p4.x() == 0.22);
    TS_ASSERT(p4.y() == 0.33);
    TS_ASSERT(p3.x() == 0.11);
    TS_ASSERT(p3.y() == 0.22);
  }

  void test_point_3d_assignment_operator()
  {
    gl_wrapper::point_3d<float> p1(0.82f, 1.0f, 1.0f);
    gl_wrapper::point_3d<float> p2 = p1;
    TS_ASSERT(p2.x() == 0.82f);
    TS_ASSERT(p2.y() == 1.0f);
    TS_ASSERT(p2.z() == 1.0f);
    TS_ASSERT(p1.x() == 0.82f);
    TS_ASSERT(p1.y() == 1.0f);
    TS_ASSERT(p1.z() == 1.0f);

    p2 = gl_wrapper::point_3d<float>(0.83f, 0.99f, 0.98f);
    TS_ASSERT(p2.x() == 0.83f);
    TS_ASSERT(p2.y() == 0.99f);
    TS_ASSERT(p2.z() == 0.98f);
    TS_ASSERT(p1.x() == 0.82f);
    TS_ASSERT(p1.y() == 1.0f);
    TS_ASSERT(p1.z() == 1.0f);

    gl_wrapper::point_3d<double> p3(0.66, 0.88, 0.988);
    gl_wrapper::point_3d<double> p4 = p3;
    TS_ASSERT(p4.x() == 0.66);
    TS_ASSERT(p4.y() == 0.88);
    TS_ASSERT(p4.z() == 0.988);
    TS_ASSERT(p3.x() == 0.66);
    TS_ASSERT(p3.y() == 0.88);
    TS_ASSERT(p3.z() == 0.988);

    p4 = gl_wrapper::point_3d<double>();
    TS_ASSERT(p4.x() == 0.0);
    TS_ASSERT(p4.y() == 0.0);
    TS_ASSERT(p4.z() == 0.0);
    TS_ASSERT(p3.x() == 0.66);
    TS_ASSERT(p3.y() == 0.88);
    TS_ASSERT(p3.z() == 0.988);
  }

  /*! \brief This is a test to see if the setters for 2d and 3d points
   * set the value to a new value.
   */
  void test_point_2d_setters()
  {
    gl_wrapper::point_2d<float> p1;
    p1.x(1.0f);
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 0.0f);
    p1.y(0.5f);
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 0.5f);
    p1.y(0.2f);
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 0.2f);
    p1.x_and_y(0.0f, 0.0f);
    TS_ASSERT(p1.x() == 0.0f);
    TS_ASSERT(p1.y() == 0.0f);

    gl_wrapper::point_2d<double> p2;
    p2.x(0.5);
    TS_ASSERT(p2.x() == 0.5);
    TS_ASSERT(p2.y() == 0.0);
    p2.y(0.5);
    TS_ASSERT(p2.x() == 0.5);
    TS_ASSERT(p2.y() == 0.5);
    p2.x(0.4);
    TS_ASSERT(p2.x() == 0.4);
    TS_ASSERT(p2.y() == 0.5);
    p2.x_and_y(0.1, 0.1);
    TS_ASSERT(p2.x() == 0.1);
    TS_ASSERT(p2.y() == 0.1);
  }

  void test_point_3d_setters()
  {
    gl_wrapper::point_3d<float> p1;
    p1.x(0.01f);
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.00f);
    TS_ASSERT(p1.z() == 0.00f);
    p1.y(0.02f);
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.02f);
    TS_ASSERT(p1.z() == 0.00f);
    p1.z(0.05f);
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.02f);
    TS_ASSERT(p1.z() == 0.05f);
    p1.z(0.07f);
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.02f);
    TS_ASSERT(p1.z() == 0.07f);
    p1.x_and_y_and_z(0.09f, 0.11f, 0.15f);
    TS_ASSERT(p1.x() == 0.09f);
    TS_ASSERT(p1.y() == 0.11f);
    TS_ASSERT(p1.z() == 0.15f);

    gl_wrapper::point_3d<double> p2;
    p2.x(0.0);
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.0);
    TS_ASSERT(p2.z() == 0.0);
    p2.y(0.5);
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.5);
    TS_ASSERT(p2.z() == 0.0);
    p2.z(0.7);
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.5);
    TS_ASSERT(p2.z() == 0.7);
    p2.x(0.1);
    TS_ASSERT(p2.x() == 0.1);
    TS_ASSERT(p2.y() == 0.5);
    TS_ASSERT(p2.z() == 0.7);
    p2.x_and_y_and_z(0.1, 0.1, 0.1);
    TS_ASSERT(p2.x() == 0.1);
    TS_ASSERT(p2.y() == 0.1);
    TS_ASSERT(p2.z() == 0.1);
  }

  void test_point_2d_get_reference()
  {
    gl_wrapper::point_2d<float> p1;
    p1.xref() = 1.0f;
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 0.0f);
    p1.yref() = 0.5f;
    TS_ASSERT(p1.x() == 1.0f);
    TS_ASSERT(p1.y() == 0.5f);
    p1.xref() = 0.2f;
    TS_ASSERT(p1.x() == 0.2f);
    TS_ASSERT(p1.y() == 0.5f);

    gl_wrapper::point_2d<double> p2;
    p2.xref() = 0.5;
    TS_ASSERT(p2.x() == 0.5);
    TS_ASSERT(p2.y() == 0.0);
    p2.yref() = 0.5;
    TS_ASSERT(p2.x() == 0.5);
    TS_ASSERT(p2.y() == 0.5);
    p2.yref() = 0.4;
    TS_ASSERT(p2.x() == 0.5);
    TS_ASSERT(p2.y() == 0.4);
  }

  void test_point_3d_get_reference()
  {
    gl_wrapper::point_3d<float> p1;
    p1.xref() = 0.01f;
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.00f);
    TS_ASSERT(p1.z() == 0.00f);
    p1.yref() = 0.02f;
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.02f);
    TS_ASSERT(p1.z() == 0.00f);
    p1.zref() = 0.05f;
    TS_ASSERT(p1.x() == 0.01f);
    TS_ASSERT(p1.y() == 0.02f);
    TS_ASSERT(p1.z() == 0.05f);

    gl_wrapper::point_3d<double> p2;
    p2.xref() = 0.0;
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.0);
    TS_ASSERT(p2.z() == 0.0);
    p2.yref() = 0.5;
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.5);
    TS_ASSERT(p2.z() == 0.0);
    p2.zref() = 0.7;
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.5);
    TS_ASSERT(p2.z() == 0.7);
    p2.zref() = 0.1;
    TS_ASSERT(p2.x() == 0.0);
    TS_ASSERT(p2.y() == 0.5);
    TS_ASSERT(p2.z() == 0.1);
  }

  /*! \brief This is a test to if two points can be compared for equivalence
   */
  void test_equivalence_2d()
  {
    gl_wrapper::point_2d<float> p1;
    gl_wrapper::point_2d<float> p2;
    TS_ASSERT(p1 == p2);

    p2.x_and_y(0.0001f, 1.000001f);
    TS_ASSERT(p1 != p2);

    gl_wrapper::point_2d<float> p3(1.0f, 0.5f);
    gl_wrapper::point_2d<float> p4(1.0f, 0.5f);
    TS_ASSERT(p3 == p4);

    p3.xref() = 0.0f;
    TS_ASSERT(p3 != p4);
  }

  void test_equivalence_2da()
  {
    gl_wrapper::point_3d<float> p1;
    gl_wrapper::point_3d<float> p2;
    TS_ASSERT(p1 == p2);

    p2.x_and_y_and_z(0.0001f, 1.000001f, 0.0f);
    TS_ASSERT(p1 != p2);

    gl_wrapper::point_3d<float> p3(1.0f, 0.7f, 0.8f);
    gl_wrapper::point_3d<float> p4(1.0f, 0.7f, 0.8f);
    TS_ASSERT(p3 == p4);

    p3.yref() = 0.6f;
    TS_ASSERT(p3 != p4);
  }

  void test_extrenuous_usecases()
  {
    gl_wrapper::point_2d<float> p1(1.0f, 0.9f);
    // Convert the raw point to an array
    float *raw_data = &p1.xref();
    TS_ASSERT(raw_data[1] == 0.9f);
    raw_data[1] = 0.8f;
    TS_ASSERT(raw_data[0] == 1.0f);
    TS_ASSERT(raw_data[1] == 0.8f);

    // Check to see if it is POD
    gl_wrapper::point_3d<float> p2(1.0f, 1.0f, 0.9f);
    float point_array[3];
    memcpy(point_array, &p2, sizeof(p2));
    TS_ASSERT(point_array[0] == 1.0f);
    TS_ASSERT(point_array[1] == 1.0f);
    TS_ASSERT(point_array[2] == 0.9f);
  }

  void test_get_dimension()
  {
    TS_ASSERT_EQUALS(2, gl_wrapper::point_2d<float>::dimension);
    TS_ASSERT_EQUALS(2, gl_wrapper::point_2d<double>::dimension);
    TS_ASSERT_EQUALS(3, gl_wrapper::point_3d<float>::dimension);
    TS_ASSERT_EQUALS(3, gl_wrapper::point_3d<double>::dimension);
  }
};

#endif
