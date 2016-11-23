#include "opengl_math/math/clamp.h"
#include "opengl_math/math/numbers.h"

#include "suite.h"

#include <check.h>

static const float eps = 1e-6;

START_TEST(test_clamp_1)
{
  {
    float mock_color = 255.1f;
    opengl_math::clamp(mock_color, 0.0f, 255.0f);
    ck_assert(opengl_math::float_equals(mock_color, 255.0f, eps));
  }

  {
    float mock_color = 254.99f;
    opengl_math::clamp(mock_color, 0.0f, 255.0f);
    ck_assert(opengl_math::float_equals(mock_color, 254.99f, eps));
  }
}
END_TEST

START_TEST(test_clamp_2)
{
  {
    float mock_red = 255.1f;
    float mock_green = 254.9f;
    opengl_math::clamp(mock_red, 0.0f, 255.0f);
    opengl_math::clamp(mock_green, 0.0f, 255.0f);
    ck_assert(opengl_math::float_equals(mock_red, 255.0f, eps));
    ck_assert(opengl_math::float_equals(mock_green, 254.9f, eps));
  }

  {
    float mock_red = 255.1f;
    float mock_green = -0.99f;
    opengl_math::clamp_pair(mock_red, mock_green, 0.0f, 255.0f);
    ck_assert(opengl_math::float_equals(mock_red, 255.0f, eps));
    ck_assert(opengl_math::float_equals(mock_green, 0.0f, eps));
  }
}
END_TEST

START_TEST(test_clamp_3)
{
  {
    float mock_red = 255.1f;
    float mock_green = 254.9f;
    float mock_blue = 0.1f;
    opengl_math::clamp_triplet(mock_red, mock_green, mock_blue,
      0.0f, 255.0f);
    ck_assert(opengl_math::float_equals(mock_red, 255.0f, eps));
    ck_assert(opengl_math::float_equals(mock_green, 254.9f, eps));
    ck_assert(opengl_math::float_equals(mock_blue, 0.1f, eps));
  }
}
END_TEST

START_TEST(test_clamp_4)
{
  {
    float mock_red = 255.1f;
    float mock_green = 254.9f;
    float mock_blue = 0.1f;
    float mock_alpha = 0.0f;
    opengl_math::clamp_quad(mock_red, mock_green, mock_blue,
      mock_alpha, 0.0f, 255.0f);
    ck_assert(opengl_math::float_equals(mock_red, 255.0f, eps));
    ck_assert(opengl_math::float_equals(mock_green, 254.9f, eps));
    ck_assert(opengl_math::float_equals(mock_blue, 0.1f, eps));
    ck_assert(opengl_math::float_equals(mock_alpha, 0.0f, eps));
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

  tcase_add_test(tc, test_clamp_1);
  tcase_add_test(tc, test_clamp_2);
  tcase_add_test(tc, test_clamp_3);
  tcase_add_test(tc, test_clamp_4);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
