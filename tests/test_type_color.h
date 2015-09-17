#ifndef COLOR_TESTS
#define COLOR_TESTS

#include <cxxtest/TestSuite.h>

#include <graphics/primitives/colors/type_color_rgb.h>
#include <graphics/primitives/colors/type_color_rgba.h>

#include <iostream>
#include <vector>
#include <cassert>

class color_tests : public CxxTest::TestSuite
{
public:
  /*! \brief This is a test to see if default constructor for
   * rgb and rgba colors itializes all of its components to 0.0f
   */
  void test_default_rgb_color_constructor()
  {
    gl_wrapper::color_rgb<float> c1;
    TS_ASSERT(c1.r() == 0.0f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 0.0f);

    gl_wrapper::color_rgb<double> c2;
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.0);
    TS_ASSERT(c2.b() == 0.0);
  }

  void test_default_rgba_color_constructor()
  {
    gl_wrapper::color_rgba<float> c1;
    TS_ASSERT(c1.r() == 0.0f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 0.0f);
    TS_ASSERT(c1.a() == 0.0f);

    gl_wrapper::color_rgba<double> c2;
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.0);
    TS_ASSERT(c2.b() == 0.0);
    TS_ASSERT(c2.a() == 0.0);
  }

  /*! \brief This is a test to see if paramaterized constructor for
   * rgb and rgba colors itializes all of its components correctly
   */
  void test_rgb_color_constructor()
  {
    gl_wrapper::color_rgb<float> c1(1.0f, 2.0f, 3.0f);
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 2.0f / 255.0f);
    TS_ASSERT(c1.b() == 3.0f / 255.0f);

    gl_wrapper::color_rgb<double> c2(1.0, 0.97, 0.2);
    TS_ASSERT(c2.r() == 1.0);
    TS_ASSERT(c2.g() == 0.97);
    TS_ASSERT(c2.b() == 0.2);
  }

  void test_rgba_color_constructor()
  {
    gl_wrapper::color_rgba<float> c1(1.0f, 2.0f, 3.0f, 1.0f);
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 2.0f / 255.0f);
    TS_ASSERT(c1.b() == 3.0f / 255.0f);
    TS_ASSERT(c1.a() == 1.0f);

    gl_wrapper::color_rgba<double> c2(1.0, 0.97, 0.2, 1.0);
    TS_ASSERT(c2.r() == 1.0);
    TS_ASSERT(c2.g() == 0.97);
    TS_ASSERT(c2.b() == 0.2);
    TS_ASSERT(c2.a() == 1.0);
  }

  /*! \brief This is a test to see if the copy constructor for
   * rgb and rgba colors itializes all of its components correctly
   */
  void test_rgb_copy_constructor()
  {
    gl_wrapper::color_rgb<float> c1(0.9f, 0.75f, 0.26f);
    gl_wrapper::color_rgb<float> c2(c1);
    TS_ASSERT(c2.r() == 0.9f);
    TS_ASSERT(c2.g() == 0.75f);
    TS_ASSERT(c2.b() == 0.26f);

    gl_wrapper::color_rgb<double> c3(0.145, 0.1, 1.0);
    gl_wrapper::color_rgb<double> c4(c3);
    TS_ASSERT(c4.r() == 0.145);
    TS_ASSERT(c4.g() == 0.1);
    TS_ASSERT(c4.b() == 1.0);
  }

  void test_rgba_copy_constructor()
  {
    gl_wrapper::color_rgba<float> c1(0.82f, 1.0e-10f, 10.0, 255);
    gl_wrapper::color_rgba<float> c2(c1);
    TS_ASSERT(c2.r() == 0.82f);
    TS_ASSERT(c2.g() == 0.0000000001f);
    TS_ASSERT(c2.b() == 10.0f / 255.0f);
    TS_ASSERT(c2.a() == 1.0f);

    gl_wrapper::color_rgba<double> c3(0.7, 1.0e-18, 1.000000001, 255);
    gl_wrapper::color_rgba<double> c4(c3);
    TS_ASSERT(c4.r() == 0.7);
    TS_ASSERT(c4.g() == 1.0e-18);
    TS_ASSERT(c4.b() == 1.000000001 / 255.0);
    TS_ASSERT(c4.a() == 1.0);
  }

  /*! \brief This is a test to see if the assignment operator copies
   * the contents of the rhs value into the lhs without modifying the
   * rhs.
   */
  void test_rgb_assignment_operator()
  {
    gl_wrapper::color_rgb<float> c1(0.88f, 0.0f, 0.1f);
    gl_wrapper::color_rgb<float> c2 = c1;
    TS_ASSERT(c2.r() == 0.88f);
    TS_ASSERT(c2.g() == 0.0f);
    TS_ASSERT(c2.b() == 0.1f);
    TS_ASSERT(c1.r() == 0.88f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 0.1f);

    c2 = gl_wrapper::color_rgb<float>(0.99f, 0.0f, 1.0f);
    TS_ASSERT(c2.r() == 0.99f);
    TS_ASSERT(c2.g() == 0.0f);
    TS_ASSERT(c2.b() == 1.0f);
    TS_ASSERT(c1.r() == 0.88f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 0.1f);

    gl_wrapper::color_rgb<double> c3(0.11, 0.22, 0.33);
    gl_wrapper::color_rgb<double> c4 = c3;
    TS_ASSERT(c4.r() == 0.11);
    TS_ASSERT(c4.g() == 0.22);
    TS_ASSERT(c4.b() == 0.33);
    TS_ASSERT(c3.r() == 0.11);
    TS_ASSERT(c3.g() == 0.22);
    TS_ASSERT(c3.b() == 0.33);

    c4 = gl_wrapper::color_rgb<double>(0.22, 0.33, 0.11);
    TS_ASSERT(c4.r() == 0.22);
    TS_ASSERT(c4.g() == 0.33);
    TS_ASSERT(c4.b() == 0.11);
    TS_ASSERT(c3.r() == 0.11);
    TS_ASSERT(c3.g() == 0.22);
    TS_ASSERT(c3.b() == 0.33);
  }

  void test_rgba_assignment_operator()
  {
    gl_wrapper::color_rgba<float> c1(0.82f, 1.0f, 1.0f, 0.1f);
    gl_wrapper::color_rgba<float> c2 = c1;
    TS_ASSERT(c2.r() == 0.82f);
    TS_ASSERT(c2.g() == 1.0f);
    TS_ASSERT(c2.b() == 1.0f);
    TS_ASSERT(c2.a() == 0.1f);
    TS_ASSERT(c1.r() == 0.82f);
    TS_ASSERT(c1.g() == 1.0f);
    TS_ASSERT(c1.b() == 1.0f);
    TS_ASSERT(c1.a() == 0.1f);

    c2 = gl_wrapper::color_rgba<float>(0.83f, 0.99f, 0.98f, 0.1f);
    TS_ASSERT(c2.r() == 0.83f);
    TS_ASSERT(c2.g() == 0.99f);
    TS_ASSERT(c2.b() == 0.98f);
    TS_ASSERT(c2.a() == 0.1f);
    TS_ASSERT(c1.r() == 0.82f);
    TS_ASSERT(c1.g() == 1.0f);
    TS_ASSERT(c1.b() == 1.0f);
    TS_ASSERT(c1.a() == 0.1f);

    gl_wrapper::color_rgba<double> c3(0.66, 0.88, 0.988, 1.0);
    gl_wrapper::color_rgba<double> c4 = c3;
    TS_ASSERT(c4.r() == 0.66);
    TS_ASSERT(c4.g() == 0.88);
    TS_ASSERT(c4.b() == 0.988);
    TS_ASSERT(c4.a() == 1.0);
    TS_ASSERT(c3.r() == 0.66);
    TS_ASSERT(c3.g() == 0.88);
    TS_ASSERT(c3.b() == 0.988);
    TS_ASSERT(c3.a() == 1.0);

    c4 = gl_wrapper::color_rgba<double>();
    TS_ASSERT(c4.r() == 0.0);
    TS_ASSERT(c4.g() == 0.0);
    TS_ASSERT(c4.b() == 0.0);
    TS_ASSERT(c4.a() == 0.0);
    TS_ASSERT(c3.r() == 0.66);
    TS_ASSERT(c3.g() == 0.88);
    TS_ASSERT(c3.b() == 0.988);
    TS_ASSERT(c3.a() == 1.0);
  }

  /*! \brief This is a test to see if the setters for rgb and rgba colors
   * set the value to a new value.
   */
  void test_rgb_setters()
  {
    gl_wrapper::color_rgb<float> c1;
    c1.r(1.0f);
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 0.0f);
    c1.g(0.5f);
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 0.5f);
    TS_ASSERT(c1.b() == 0.0f);
    c1.b(0.2f);
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 0.5f);
    TS_ASSERT(c1.b() == 0.2f);
    c1.rgb(0.0f, 0.0f, 1.0f);
    TS_ASSERT(c1.r() == 0.0f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 1.0f);

    gl_wrapper::color_rgb<double> c2;
    c2.r(0.5);
    TS_ASSERT(c2.r() == 0.5);
    TS_ASSERT(c2.g() == 0.0);
    TS_ASSERT(c2.b() == 0.0);
    c2.g(0.5f);
    TS_ASSERT(c2.r() == 0.5);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.0);
    c2.b(0.5f);
    TS_ASSERT(c2.r() == 0.5);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.5);
    c2.rgb(0.1, 0.1, 0.1);
    TS_ASSERT(c2.r() == 0.1);
    TS_ASSERT(c2.g() == 0.1);
    TS_ASSERT(c2.b() == 0.1);
  }

  void test_rgba_setters()
  {
    gl_wrapper::color_rgba<float> c1;
    c1.r(0.01f);
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.00f);
    TS_ASSERT(c1.b() == 0.00f);
    TS_ASSERT(c1.a() == 0.00f);
    c1.g(0.02f);
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.02f);
    TS_ASSERT(c1.b() == 0.00f);
    TS_ASSERT(c1.a() == 0.00f);
    c1.b(0.05f);
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.02f);
    TS_ASSERT(c1.b() == 0.05f);
    TS_ASSERT(c1.a() == 0.00f);
    c1.a(0.07f);
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.02f);
    TS_ASSERT(c1.b() == 0.05f);
    TS_ASSERT(c1.a() == 0.07f);
    c1.rgba(0.09f, 0.11f, 0.15f, 0.22f);
    TS_ASSERT(c1.r() == 0.09f);
    TS_ASSERT(c1.g() == 0.11f);
    TS_ASSERT(c1.b() == 0.15f);
    TS_ASSERT(c1.a() == 0.22f);

    gl_wrapper::color_rgba<double> c2;
    c2.r(0.0);
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.0);
    TS_ASSERT(c2.b() == 0.0);
    TS_ASSERT(c2.a() == 0.0);
    c2.g(0.5);
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.0);
    TS_ASSERT(c2.a() == 0.0);
    c2.b(0.7);
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.7);
    TS_ASSERT(c2.a() == 0.0);
    c2.a(0.1);
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.7);
    TS_ASSERT(c2.a() == 0.1);
    c2.rgba(0.1, 0.1, 0.1, 0.1);
    TS_ASSERT(c2.r() == 0.1);
    TS_ASSERT(c2.g() == 0.1);
    TS_ASSERT(c2.b() == 0.1);
    TS_ASSERT(c2.a() == 0.1);
  }

  void test_rgb_get_reference()
  {
    gl_wrapper::color_rgb<float> c1;
    c1.rref() = 1.0f;
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 0.0f);
    TS_ASSERT(c1.b() == 0.0f);
    c1.gref() = 0.5f;
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 0.5f);
    TS_ASSERT(c1.b() == 0.0f);
    c1.bref() = 0.2f;
    TS_ASSERT(c1.r() == 1.0f);
    TS_ASSERT(c1.g() == 0.5f);
    TS_ASSERT(c1.b() == 0.2f);

    gl_wrapper::color_rgb<double> c2;
    c2.rref() = 0.5;
    TS_ASSERT(c2.r() == 0.5);
    TS_ASSERT(c2.g() == 0.0);
    TS_ASSERT(c2.b() == 0.0);
    c2.gref() = 0.5f;
    TS_ASSERT(c2.r() == 0.5);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.0);
    c2.bref() = 0.5f;
    TS_ASSERT(c2.r() == 0.5);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.5);
  }

  void test_rgba_get_reference()
  {
    gl_wrapper::color_rgba<float> c1;
    c1.rref() = 0.01f;
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.00f);
    TS_ASSERT(c1.b() == 0.00f);
    TS_ASSERT(c1.a() == 0.00f);
    c1.gref() = 0.02f;
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.02f);
    TS_ASSERT(c1.b() == 0.00f);
    TS_ASSERT(c1.a() == 0.00f);
    c1.bref() = 0.05f;
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.02f);
    TS_ASSERT(c1.b() == 0.05f);
    TS_ASSERT(c1.a() == 0.00f);
    c1.aref() = 0.07f;
    TS_ASSERT(c1.r() == 0.01f);
    TS_ASSERT(c1.g() == 0.02f);
    TS_ASSERT(c1.b() == 0.05f);
    TS_ASSERT(c1.a() == 0.07f);

    gl_wrapper::color_rgba<double> c2;
    c2.rref() = 0.0;
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.0);
    TS_ASSERT(c2.b() == 0.0);
    TS_ASSERT(c2.a() == 0.0);
    c2.gref() = 0.5;
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.0);
    TS_ASSERT(c2.a() == 0.0);
    c2.bref() = 0.7;
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.7);
    TS_ASSERT(c2.a() == 0.0);
    c2.aref() = 0.1;
    TS_ASSERT(c2.r() == 0.0);
    TS_ASSERT(c2.g() == 0.5);
    TS_ASSERT(c2.b() == 0.7);
    TS_ASSERT(c2.a() == 0.1);
  }

  /*! \brief This is a test to if two colors can be compared for equivalence
   */
  void test_equivalence_rgb()
  {
    gl_wrapper::color_rgb<float> c1;
    gl_wrapper::color_rgb<float> c2;
    TS_ASSERT(c1 == c2);

    c2.rgb(0.0001f, 1.000001f, 0.0f);
    TS_ASSERT(c1 != c2);

    // NOTE: all values > 1.0f are divided by 255
    gl_wrapper::color_rgb<float> c3(1.0f, 0.5f, 0.2f);
    gl_wrapper::color_rgb<float> c4(1.0f, 0.5f, 51.0f);
    TS_ASSERT(c3 == c4);

    c3.rref() = 0.0f;
    TS_ASSERT(c3 != c4);
  }

  void test_equivalence_rgba()
  {
    gl_wrapper::color_rgba<float> c1;
    gl_wrapper::color_rgba<float> c2;
    TS_ASSERT(c1 == c2);

    c2.rgba(0.0001f, 1.000001f, 0.0f, 254.0f);
    TS_ASSERT(c1 != c2);

    gl_wrapper::color_rgba<float> c3(1.0f, 0.7f, 0.8f, 0.0f);
    gl_wrapper::color_rgba<float> c4(1.0f, 0.7f, 0.8f, 0.0f);
    TS_ASSERT(c3 == c4);

    c3.gref() = 0.6f;
    TS_ASSERT(c3 != c4);
  }

  void test_extrenuous_usecases()
  {
    gl_wrapper::color_rgb<float> c1(1.0f, 0.9f, 0.8f);
    // Convert the raw color to an array
    float *raw_data = &c1.rref();
    TS_ASSERT(raw_data[1] == 0.9f);
    raw_data[2] = 0.9f;
    c1.b(0.8f);
    TS_ASSERT(raw_data[0] == 1.0f);
    TS_ASSERT(raw_data[1] == 0.9f);
    TS_ASSERT(raw_data[2] == 0.8f);

    // Check to see if it is POD
    gl_wrapper::color_rgba<float> c2(1.0f, 1.0f, 0.9f, 0.1f);
    float color_array[4];
    memcpy(color_array, &c2, sizeof(c2));
    TS_ASSERT(color_array[0] == 1.0f);
    TS_ASSERT(color_array[1] == 1.0f);
    TS_ASSERT(color_array[2] == 0.9f);
    TS_ASSERT(color_array[3] == 0.1f);
  }
};

#endif
