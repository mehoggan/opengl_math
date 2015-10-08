#include "test_operations.h"

void test_clamp_1()
{
  {
    float mock_color = 255.1f;
    opengl_math::clamp(mock_color, 0.0f, 255.0f);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_color, 255.0f, eps));
  }

  {
    float mock_color = 254.99f;
    opengl_math::clamp(mock_color, 0.0f, 255.0f);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_color, 254.99f, eps));
  }
}

void test_clamp_2()
{
  {
    float mock_red = 255.1f;
    float mock_green = 254.9f;
    opengl_math::clamp(mock_red, 0.0f, 255.0f);
    opengl_math::clamp(mock_green, 0.0f, 255.0f);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_red, 255.0f, eps));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_green, 254.9f, eps));
  }

    {
      float mock_red = 255.1f;
      float mock_green = -0.99f;
      opengl_math::clamp_pair(mock_red, mock_green, 0.0f, 255.0f);
      OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_red, 255.0f, eps));
      OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_green, 0.0f, eps));
    }
}

void test_clamp_3()
{
  {
    float mock_red = 255.1f;
    float mock_green = 254.9f;
    float mock_blue = 0.1f;
    opengl_math::clamp_triplet(mock_red, mock_green, mock_blue,
      0.0f, 255.0f);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_red, 255.0f, eps));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_green, 254.9f, eps));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_blue, 0.1f, eps));
  }
}

void test_clamp_4()
{
  {
    float mock_red = 255.1f;
    float mock_green = 254.9f;
    float mock_blue = 0.1f;
    float mock_alpha = 0.0f;
    opengl_math::clamp_quad(mock_red, mock_green, mock_blue,
      mock_alpha, 0.0f, 255.0f);
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_red, 255.0f, eps));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_green, 254.9f, eps));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_blue, 0.1f, eps));
    OPENGL_MATH_ASSERT(opengl_math::float_equals(mock_alpha, 0.0f, eps));
  }
}

bool test_operations::run()
{
  test_clamp_1();
  test_clamp_2();
  test_clamp_3();
  test_clamp_4();

  return true;
}