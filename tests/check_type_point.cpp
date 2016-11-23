#include "test_type_point.h"

/*! \brief This is a test to see if default constructor for
* 2d and 3d points itializes all of its components to 0.0f
*/
void test_default_2d_point_constructor()
{
  opengl_math::point_2d<float> p1;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);

  opengl_math::point_2d<double> p2;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0);
}

void test_default_3d_point_constructor()
{
  opengl_math::point_3d<float> p1;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.0f);

  opengl_math::point_3d<double> p2;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.0);
}

/*! \brief This is a test to see if paramaterized constructor for
* 2d and rgba points itializes all of its components correctly
*/
void test_2d_point_constructor()
{
  opengl_math::point_2d<float> p1(1.0f, 2.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 2.0f);

  opengl_math::point_2d<double> p2(1.0, 0.97);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 1.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.97);
}

void test_3d_point_constructor()
{
  opengl_math::point_3d<float> p1(1.0f, 2.0f, 3.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 2.0f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 3.0f);

  opengl_math::point_3d<double> p2(1.0, 0.97, 0.2);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 1.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.97);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.2);
}

/*! \brief This is a test to see if the copy constructor for
* 2d and rgba points initializes all of its components correctly
*/
void test_point_2d_copy_constructor()
{
  opengl_math::point_2d<float> p1(0.9f, 0.75f);
  opengl_math::point_2d<float> p2(p1);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.9f);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.75f);

  opengl_math::point_2d<double> p3(0.145, 0.1);
  opengl_math::point_2d<double> p4(p3);
  OPENGL_MATH_ASSERT_EQ(p4.x(), 0.145);
  OPENGL_MATH_ASSERT_EQ(p4.y(), 0.1);
}

void test_point_3d_copy_constructor()
{
  opengl_math::point_3d<float> p1(0.82f, 1.0e-10f, 10.0);
  opengl_math::point_3d<float> p2(p1);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0000000001f);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 10.0f);

  opengl_math::point_3d<double> p3(0.7, 1.0e-18, 1.000000001);
  opengl_math::point_3d<double> p4(p3);
  OPENGL_MATH_ASSERT_EQ(p4.x(), 0.7);
  OPENGL_MATH_ASSERT_EQ(p4.y(), 1.0e-18);
  OPENGL_MATH_ASSERT_EQ(p4.z(), 1.000000001);
}

/*! \brief This is a test to see if the assignment operator copies
* the contents of the rhs value into the lhs without modifying the
* rhs.
*/
void test_point_2d_assignment_operator()
{
  opengl_math::point_2d<float> p1(0.88f, 0.0f);
  opengl_math::point_2d<float> p2 = p1;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);

  p2 = opengl_math::point_2d<float>(0.99f, 0.0f);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.88f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);

  opengl_math::point_2d<double> p3(0.11, 0.22);
  opengl_math::point_2d<double> p4 = p3;
  OPENGL_MATH_ASSERT_EQ(p4.x(), 0.11);
  OPENGL_MATH_ASSERT_EQ(p4.y(), 0.22);
  OPENGL_MATH_ASSERT_EQ(p3.x(), 0.11);
  OPENGL_MATH_ASSERT_EQ(p3.y(), 0.22);

  p4 = opengl_math::point_2d<double>(0.22, 0.33);
  OPENGL_MATH_ASSERT_EQ(p4.x(), 0.22);
  OPENGL_MATH_ASSERT_EQ(p4.y(), 0.33);
  OPENGL_MATH_ASSERT_EQ(p3.x(), 0.11);
  OPENGL_MATH_ASSERT_EQ(p3.y(), 0.22);
}

void test_point_3d_assignment_operator()
{
  opengl_math::point_3d<float> p1(0.82f, 1.0f, 1.0f);
  opengl_math::point_3d<float> p2 = p1;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 1.0f);

  p2 = opengl_math::point_3d<float>(0.83f, 0.99f, 0.98f);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.83f);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.99f);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.98f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.82f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 1.0f);

  opengl_math::point_3d<double> p3(0.66, 0.88, 0.988);
  opengl_math::point_3d<double> p4 = p3;
  OPENGL_MATH_ASSERT_EQ(p4.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(p4.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(p4.z(), 0.988);
  OPENGL_MATH_ASSERT_EQ(p3.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(p3.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(p3.z(), 0.988);

  p4 = opengl_math::point_3d<double>();
  OPENGL_MATH_ASSERT_EQ(p4.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p4.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p4.z(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p3.x(), 0.66);
  OPENGL_MATH_ASSERT_EQ(p3.y(), 0.88);
  OPENGL_MATH_ASSERT_EQ(p3.z(), 0.988);
}

/*! \brief This is a test to see if the setters for 2d and 3d points
* set the value to a new value.
*/
void test_point_2d_setters()
{
  opengl_math::point_2d<float> p1;
  p1.x(1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);
  p1.y(0.5f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.5f);
  p1.y(0.2f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.2f);
  p1.x_and_y(0.0f, 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);

  opengl_math::point_2d<double> p2;
  p2.x(0.5);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0);
  p2.y(0.5);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  p2.x(0.4);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.4);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  p2.x_and_y(0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.1);
}

void test_point_3d_setters()
{
  opengl_math::point_3d<float> p1;
  p1.x(0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.00f);
  p1.y(0.02f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.00f);
  p1.z(0.05f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.05f);
  p1.z(0.07f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.07f);
  p1.x_and_y_and_z(0.09f, 0.11f, 0.15f);
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.09f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.11f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.15f);

  opengl_math::point_3d<double> p2;
  p2.x(0.0);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.0);
  p2.y(0.5);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.0);
  p2.z(0.7);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.7);
  p2.x(0.1);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.7);
  p2.x_and_y_and_z(0.1, 0.1, 0.1);
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.1);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.1);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.1);
}

void test_point_2d_get_reference()
{
  opengl_math::point_2d<float> p1;
  p1.xref() = 1.0f;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.0f);
  p1.yref() = 0.5f;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 1.0f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.5f);
  p1.xref() = 0.2f;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.2f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.5f);

  opengl_math::point_2d<double> p2;
  p2.xref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0);
  p2.yref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  p2.yref() = 0.4;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.4);
}

void test_point_3d_get_reference()
{
  opengl_math::point_3d<float> p1;
  p1.xref() = 0.01f;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.00f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.00f);
  p1.yref() = 0.02f;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.00f);
  p1.zref() = 0.05f;
  OPENGL_MATH_ASSERT_EQ(p1.x(), 0.01f);
  OPENGL_MATH_ASSERT_EQ(p1.y(), 0.02f);
  OPENGL_MATH_ASSERT_EQ(p1.z(), 0.05f);

  opengl_math::point_3d<double> p2;
  p2.xref() = 0.0;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.0);
  p2.yref() = 0.5;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.0);
  p2.zref() = 0.7;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.7);
  p2.zref() = 0.1;
  OPENGL_MATH_ASSERT_EQ(p2.x(), 0.0);
  OPENGL_MATH_ASSERT_EQ(p2.y(), 0.5);
  OPENGL_MATH_ASSERT_EQ(p2.z(), 0.1);
}

/*! \brief This is a test to if two points can be compared for equivalence
*/
void test_equivalence_type_point_2d()
{
  opengl_math::point_2d<float> p1;
  opengl_math::point_2d<float> p2;
  OPENGL_MATH_ASSERT_EQ(p1, p2);

  p2.x_and_y(0.0001f, 1.000001f);
  OPENGL_MATH_ASSERT_NE(p1, p2);

  opengl_math::point_2d<float> p3(1.0f, 0.5f);
  opengl_math::point_2d<float> p4(1.0f, 0.5f);
  OPENGL_MATH_ASSERT_EQ(p3, p4);

  p3.xref() = 0.0f;
  OPENGL_MATH_ASSERT_NE(p3, p4);
}

void test_equivalence_type_point_3d()
{
  opengl_math::point_3d<float> p1;
  opengl_math::point_3d<float> p2;
  OPENGL_MATH_ASSERT_EQ(p1, p2);

  p2.x_and_y_and_z(0.0001f, 1.000001f, 0.0f);
  OPENGL_MATH_ASSERT_NE(p1, p2);

  opengl_math::point_3d<float> p3(1.0f, 0.7f, 0.8f);
  opengl_math::point_3d<float> p4(1.0f, 0.7f, 0.8f);
  OPENGL_MATH_ASSERT_EQ(p3, p4);

  p3.yref() = 0.6f;
  OPENGL_MATH_ASSERT_NE(p3, p4);
}

void test_extrenuous_type_point_usecases()
{
  opengl_math::point_2d<float> p1(1.0f, 0.9f);
  // Convert the raw point to an array
  float *raw_data = &p1.xref();
  OPENGL_MATH_ASSERT_EQ(raw_data[1], 0.9f);
  raw_data[1] = 0.8f;
  OPENGL_MATH_ASSERT_EQ(raw_data[0], 1.0f);
  OPENGL_MATH_ASSERT_EQ(raw_data[1], 0.8f);

  // Check to see if it is POD
  opengl_math::point_3d<float> p2(1.0f, 1.0f, 0.9f);
  float point_array[3];
  memcpy(point_array, &p2, sizeof(p2));
  OPENGL_MATH_ASSERT_EQ(point_array[0], 1.0f);
  OPENGL_MATH_ASSERT_EQ(point_array[1], 1.0f);
  OPENGL_MATH_ASSERT_EQ(point_array[2], 0.9f);
}

void test_type_point_get_dimension()
{
  OPENGL_MATH_ASSERT_EQ(2, opengl_math::point_2d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(2, opengl_math::point_2d<double>::dimension);
  OPENGL_MATH_ASSERT_EQ(3, opengl_math::point_3d<float>::dimension);
  OPENGL_MATH_ASSERT_EQ(3, opengl_math::point_3d<double>::dimension);
}

bool test_type_point::run()
{
  test_default_2d_point_constructor();
  test_default_3d_point_constructor();
  test_2d_point_constructor();
  test_3d_point_constructor();
  test_point_2d_copy_constructor();
  test_point_3d_copy_constructor();
  test_point_2d_assignment_operator();
  test_point_3d_assignment_operator();
  test_point_2d_setters();
  test_point_3d_setters();
  test_point_2d_get_reference();
  test_point_3d_get_reference();
  test_equivalence_type_point_2d();
  test_equivalence_type_point_3d();
  test_extrenuous_type_point_usecases();
  test_type_point_get_dimension();

  return true;
}