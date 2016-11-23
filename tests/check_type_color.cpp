#include "opengl_math/primitives/colors/type_color_rgb.h"
#include "opengl_math/primitives/colors/type_color_rgba.h"

#include "suite.h"

#include <check.h>

/*! \brief This is a test to see if default constructor for
* rgb and rgba colors initializes all of its components to 0.0f
*/
START_TEST(test_default_rgb_color_constructor)
{
  opengl_math::color_rgb<float> c1;
  ck_assert(c1.r() == 0.0f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 0.0f);

  opengl_math::color_rgb<double> c2;
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.0);
  ck_assert(c2.b() == 0.0);
}
END_TEST

START_TEST(test_default_rgba_color_constructor)
{
  opengl_math::color_rgba<float> c1;
  ck_assert(c1.r() == 0.0f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 0.0f);
  ck_assert(c1.a() == 0.0f);

  opengl_math::color_rgba<double> c2;
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.0);
  ck_assert(c2.b() == 0.0);
  ck_assert(c2.a() == 0.0);
}
END_TEST

/*! \brief This is a test to see if parameterized constructor for
* rgb and rgba colors initializes all of its components correctly
*/
START_TEST(test_rgb_color_constructor)
{
  opengl_math::color_rgb<float> c1(1.0f, 2.0f, 3.0f);
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 2.0f / 255.0f);
  ck_assert(c1.b() == 3.0f / 255.0f);

  opengl_math::color_rgb<double> c2(1.0, 0.97, 0.2);
  ck_assert(c2.r() == 1.0);
  ck_assert(c2.g() == 0.97);
  ck_assert(c2.b() == 0.2);
}
END_TEST

START_TEST(test_rgba_color_constructor)
{
  opengl_math::color_rgba<float> c1(1.0f, 2.0f, 3.0f, 1.0f);
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 2.0f / 255.0f);
  ck_assert(c1.b() == 3.0f / 255.0f);
  ck_assert(c1.a() == 1.0f);

  opengl_math::color_rgba<double> c2(1.0, 0.97, 0.2, 1.0);
  ck_assert(c2.r() == 1.0);
  ck_assert(c2.g() == 0.97);
  ck_assert(c2.b() == 0.2);
  ck_assert(c2.a() == 1.0);
}
END_TEST

/*! \brief This is a test to see if the copy constructor for
* rgb and rgba colors initializes all of its components correctly
*/
START_TEST(test_rgb_copy_constructor)
{
  opengl_math::color_rgb<float> c1(0.9f, 0.75f, 0.26f);
  opengl_math::color_rgb<float> c2(c1);
  ck_assert(c2.r() == 0.9f);
  ck_assert(c2.g() == 0.75f);
  ck_assert(c2.b() == 0.26f);

  opengl_math::color_rgb<double> c3(0.145, 0.1, 1.0);
  opengl_math::color_rgb<double> c4(c3);
  ck_assert(c4.r() == 0.145);
  ck_assert(c4.g() == 0.1);
  ck_assert(c4.b() == 1.0);
}
END_TEST

START_TEST(test_rgba_copy_constructor)
{
  opengl_math::color_rgba<float> c1(0.82f, 1.0e-10f, 10.0, 255);
  opengl_math::color_rgba<float> c2(c1);
  ck_assert(c2.r() == 0.82f);
  ck_assert(c2.g() == 0.0000000001f);
  ck_assert(c2.b() == 10.0f / 255.0f);
  ck_assert(c2.a() == 1.0f);

  opengl_math::color_rgba<double> c3(0.7, 1.0e-18, 1.000000001, 255);
  opengl_math::color_rgba<double> c4(c3);
  ck_assert(c4.r() == 0.7);
  ck_assert(c4.g() == 1.0e-18);
  ck_assert(c4.b() == 1.000000001 / 255.0);
  ck_assert(c4.a() == 1.0);
}
END_TEST

/*! \brief This is a test to see if the assignment operator copies
* the contents of the rhs value into the lhs without modifying the
* rhs.
*/
START_TEST(test_rgb_assignment_operator)
{
  opengl_math::color_rgb<float> c1(0.88f, 0.0f, 0.1f);
  opengl_math::color_rgb<float> c2 = c1;
  ck_assert(c2.r() == 0.88f);
  ck_assert(c2.g() == 0.0f);
  ck_assert(c2.b() == 0.1f);
  ck_assert(c1.r() == 0.88f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 0.1f);

  c2 = opengl_math::color_rgb<float>(0.99f, 0.0f, 1.0f);
  ck_assert(c2.r() == 0.99f);
  ck_assert(c2.g() == 0.0f);
  ck_assert(c2.b() == 1.0f);
  ck_assert(c1.r() == 0.88f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 0.1f);

  opengl_math::color_rgb<double> c3(0.11, 0.22, 0.33);
  opengl_math::color_rgb<double> c4 = c3;
  ck_assert(c4.r() == 0.11);
  ck_assert(c4.g() == 0.22);
  ck_assert(c4.b() == 0.33);
  ck_assert(c3.r() == 0.11);
  ck_assert(c3.g() == 0.22);
  ck_assert(c3.b() == 0.33);

  c4 = opengl_math::color_rgb<double>(0.22, 0.33, 0.11);
  ck_assert(c4.r() == 0.22);
  ck_assert(c4.g() == 0.33);
  ck_assert(c4.b() == 0.11);
  ck_assert(c3.r() == 0.11);
  ck_assert(c3.g() == 0.22);
  ck_assert(c3.b() == 0.33);
}
END_TEST

START_TEST(test_rgba_assignment_operator)
{
  opengl_math::color_rgba<float> c1(0.82f, 1.0f, 1.0f, 0.1f);
  opengl_math::color_rgba<float> c2 = c1;
  ck_assert(c2.r() == 0.82f);
  ck_assert(c2.g() == 1.0f);
  ck_assert(c2.b() == 1.0f);
  ck_assert(c2.a() == 0.1f);
  ck_assert(c1.r() == 0.82f);
  ck_assert(c1.g() == 1.0f);
  ck_assert(c1.b() == 1.0f);
  ck_assert(c1.a() == 0.1f);

  c2 = opengl_math::color_rgba<float>(0.83f, 0.99f, 0.98f, 0.1f);
  ck_assert(c2.r() == 0.83f);
  ck_assert(c2.g() == 0.99f);
  ck_assert(c2.b() == 0.98f);
  ck_assert(c2.a() == 0.1f);
  ck_assert(c1.r() == 0.82f);
  ck_assert(c1.g() == 1.0f);
  ck_assert(c1.b() == 1.0f);
  ck_assert(c1.a() == 0.1f);

  opengl_math::color_rgba<double> c3(0.66, 0.88, 0.988, 1.0);
  opengl_math::color_rgba<double> c4 = c3;
  ck_assert(c4.r() == 0.66);
  ck_assert(c4.g() == 0.88);
  ck_assert(c4.b() == 0.988);
  ck_assert(c4.a() == 1.0);
  ck_assert(c3.r() == 0.66);
  ck_assert(c3.g() == 0.88);
  ck_assert(c3.b() == 0.988);
  ck_assert(c3.a() == 1.0);

  c4 = opengl_math::color_rgba<double>();
  ck_assert(c4.r() == 0.0);
  ck_assert(c4.g() == 0.0);
  ck_assert(c4.b() == 0.0);
  ck_assert(c4.a() == 0.0);
  ck_assert(c3.r() == 0.66);
  ck_assert(c3.g() == 0.88);
  ck_assert(c3.b() == 0.988);
  ck_assert(c3.a() == 1.0);
}
END_TEST

/*! \brief This is a test to see if the setters for rgb and rgba colors
* set the value to a new value.
*/
START_TEST(test_rgb_setters)
{
  opengl_math::color_rgb<float> c1;
  c1.r(1.0f);
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 0.0f);
  c1.g(0.5f);
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 0.5f);
  ck_assert(c1.b() == 0.0f);
  c1.b(0.2f);
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 0.5f);
  ck_assert(c1.b() == 0.2f);
  c1.rgb(0.0f, 0.0f, 1.0f);
  ck_assert(c1.r() == 0.0f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 1.0f);

  opengl_math::color_rgb<double> c2;
  c2.r(0.5);
  ck_assert(c2.r() == 0.5);
  ck_assert(c2.g() == 0.0);
  ck_assert(c2.b() == 0.0);
  c2.g(0.5f);
  ck_assert(c2.r() == 0.5);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.0);
  c2.b(0.5f);
  ck_assert(c2.r() == 0.5);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.5);
  c2.rgb(0.1, 0.1, 0.1);
  ck_assert(c2.r() == 0.1);
  ck_assert(c2.g() == 0.1);
  ck_assert(c2.b() == 0.1);
}
END_TEST

START_TEST(test_rgba_setters)
{
  opengl_math::color_rgba<float> c1;
  c1.r(0.01f);
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.00f);
  ck_assert(c1.b() == 0.00f);
  ck_assert(c1.a() == 0.00f);
  c1.g(0.02f);
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.02f);
  ck_assert(c1.b() == 0.00f);
  ck_assert(c1.a() == 0.00f);
  c1.b(0.05f);
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.02f);
  ck_assert(c1.b() == 0.05f);
  ck_assert(c1.a() == 0.00f);
  c1.a(0.07f);
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.02f);
  ck_assert(c1.b() == 0.05f);
  ck_assert(c1.a() == 0.07f);
  c1.rgba(0.09f, 0.11f, 0.15f, 0.22f);
  ck_assert(c1.r() == 0.09f);
  ck_assert(c1.g() == 0.11f);
  ck_assert(c1.b() == 0.15f);
  ck_assert(c1.a() == 0.22f);

  opengl_math::color_rgba<double> c2;
  c2.r(0.0);
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.0);
  ck_assert(c2.b() == 0.0);
  ck_assert(c2.a() == 0.0);
  c2.g(0.5);
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.0);
  ck_assert(c2.a() == 0.0);
  c2.b(0.7);
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.7);
  ck_assert(c2.a() == 0.0);
  c2.a(0.1);
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.7);
  ck_assert(c2.a() == 0.1);
  c2.rgba(0.1, 0.1, 0.1, 0.1);
  ck_assert(c2.r() == 0.1);
  ck_assert(c2.g() == 0.1);
  ck_assert(c2.b() == 0.1);
  ck_assert(c2.a() == 0.1);
}
END_TEST

START_TEST(test_rgb_get_reference)
{
  opengl_math::color_rgb<float> c1;
  c1.rref() = 1.0f;
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 0.0f);
  ck_assert(c1.b() == 0.0f);
  c1.gref() = 0.5f;
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 0.5f);
  ck_assert(c1.b() == 0.0f);
  c1.bref() = 0.2f;
  ck_assert(c1.r() == 1.0f);
  ck_assert(c1.g() == 0.5f);
  ck_assert(c1.b() == 0.2f);

  opengl_math::color_rgb<double> c2;
  c2.rref() = 0.5;
  ck_assert(c2.r() == 0.5);
  ck_assert(c2.g() == 0.0);
  ck_assert(c2.b() == 0.0);
  c2.gref() = 0.5f;
  ck_assert(c2.r() == 0.5);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.0);
  c2.bref() = 0.5f;
  ck_assert(c2.r() == 0.5);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.5);
}
END_TEST

START_TEST(test_rgba_get_reference)
{
  opengl_math::color_rgba<float> c1;
  c1.rref() = 0.01f;
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.00f);
  ck_assert(c1.b() == 0.00f);
  ck_assert(c1.a() == 0.00f);
  c1.gref() = 0.02f;
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.02f);
  ck_assert(c1.b() == 0.00f);
  ck_assert(c1.a() == 0.00f);
  c1.bref() = 0.05f;
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.02f);
  ck_assert(c1.b() == 0.05f);
  ck_assert(c1.a() == 0.00f);
  c1.aref() = 0.07f;
  ck_assert(c1.r() == 0.01f);
  ck_assert(c1.g() == 0.02f);
  ck_assert(c1.b() == 0.05f);
  ck_assert(c1.a() == 0.07f);

  opengl_math::color_rgba<double> c2;
  c2.rref() = 0.0;
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.0);
  ck_assert(c2.b() == 0.0);
  ck_assert(c2.a() == 0.0);
  c2.gref() = 0.5;
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.0);
  ck_assert(c2.a() == 0.0);
  c2.bref() = 0.7;
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.7);
  ck_assert(c2.a() == 0.0);
  c2.aref() = 0.1;
  ck_assert(c2.r() == 0.0);
  ck_assert(c2.g() == 0.5);
  ck_assert(c2.b() == 0.7);
  ck_assert(c2.a() == 0.1);
}
END_TEST

/*! \brief This is a test to if two colors can be compared for equivalence
*/
START_TEST(test_equivalence_rgb)
{
  opengl_math::color_rgb<float> c1;
  opengl_math::color_rgb<float> c2;
  ck_assert(c1 == c2);

  c2.rgb(0.0001f, 1.000001f, 0.0f);
  ck_assert(c1 != c2);

  // NOTE: all values > 1.0f are divided by 255
  opengl_math::color_rgb<float> c3(1.0f, 0.5f, 0.2f);
  opengl_math::color_rgb<float> c4(1.0f, 0.5f, 51.0f);
  ck_assert(c3 == c4);

  c3.rref() = 0.0f;
  ck_assert(c3 != c4);
}
END_TEST

START_TEST(test_equivalence_rgba)
{
  opengl_math::color_rgba<float> c1;
  opengl_math::color_rgba<float> c2;
  ck_assert(c1 == c2);

  c2.rgba(0.0001f, 1.000001f, 0.0f, 254.0f);
  ck_assert(c1 != c2);

  opengl_math::color_rgba<float> c3(1.0f, 0.7f, 0.8f, 0.0f);
  opengl_math::color_rgba<float> c4(1.0f, 0.7f, 0.8f, 0.0f);
  ck_assert(c3 == c4);

  c3.gref() = 0.6f;
  ck_assert(c3 != c4);
}
END_TEST

START_TEST(test_extrenuous_type_color_usecases)
{
  opengl_math::color_rgb<float> c1(1.0f, 0.9f, 0.8f);
  // Convert the raw color to an array
  float *raw_data = &c1.rref();
  ck_assert(raw_data[1] == 0.9f);
  raw_data[2] = 0.9f;
  c1.b(0.8f);
  ck_assert(raw_data[0] == 1.0f);
  ck_assert(raw_data[1] == 0.9f);
  ck_assert(raw_data[2] == 0.8f);

  // Check to see if it is POD
  opengl_math::color_rgba<float> c2(1.0f, 1.0f, 0.9f, 0.1f);
  float color_array[4];
  memcpy(color_array, &c2, sizeof(c2));
  ck_assert(color_array[0] == 1.0f);
  ck_assert(color_array[1] == 1.0f);
  ck_assert(color_array[2] == 0.9f);
  ck_assert(color_array[3] == 0.1f);
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

  tcase_add_test(tc, test_default_rgb_color_constructor);
  tcase_add_test(tc, test_default_rgba_color_constructor);
  tcase_add_test(tc, test_rgb_color_constructor);
  tcase_add_test(tc, test_rgba_color_constructor);
  tcase_add_test(tc, test_rgb_copy_constructor);
  tcase_add_test(tc, test_rgba_copy_constructor);
  tcase_add_test(tc, test_rgb_assignment_operator);
  tcase_add_test(tc, test_rgba_assignment_operator);
  tcase_add_test(tc, test_rgb_setters);
  tcase_add_test(tc, test_rgba_setters);
  tcase_add_test(tc, test_rgb_get_reference);
  tcase_add_test(tc, test_rgba_get_reference);
  tcase_add_test(tc, test_equivalence_rgb);
  tcase_add_test(tc, test_equivalence_rgba);
  tcase_add_test(tc, test_extrenuous_type_color_usecases);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
