#ifndef COLOR_TESTS
#define COLOR_TESTS

#include <cxxtest/TestSuite.h>

#include <core/math/clamp.h>
#include <core/math/numbers.h>

#include <iostream>
#include <vector>
#include <cassert>

// TODO: Test sqrt
// TODO: Test sin, asin, cos, acos, tan, cot

static float eps = 1e-006f;

class operation_tests : public CxxTest::TestSuite
{
private:

public:
  void test_clamp_1()
  {
    {
      float mock_color = 255.1f;
      gl_wrapper::core::math::clamp(mock_color, 0.0f, 255.0f);
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_color, 255.0f, eps));
    }

    {
      float mock_color = 254.99f;
      gl_wrapper::core::math::clamp(mock_color, 0.0f, 255.0f);
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_color, 254.99f, eps));
    }
  }

  void test_clamp_2()
  {
    {
      float mock_red = 255.1f;
      float mock_green = 254.9f;
      gl_wrapper::core::math::clamp(mock_red, 0.0f, 255.0f);
      gl_wrapper::core::math::clamp(mock_green, 0.0f, 255.0f);
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_red, 255.0f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_green, 254.9f, eps));
    }

    {
      float mock_red = 255.1f;
      float mock_green = -0.99f;
      gl_wrapper::core::math::clamp_pair(mock_red, mock_green, 0.0f, 255.0f);
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_red, 255.0f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_green, 0.0f, eps));
    }
  }

  void test_clamp_3()
  {
    {
      float mock_red = 255.1f;
      float mock_green = 254.9f;
      float mock_blue = 0.1f;
      gl_wrapper::core::math::clamp_triplet(mock_red, mock_green, mock_blue,
        0.0f, 255.0f);
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_red, 255.0f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_green, 254.9f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_blue, 0.1f, eps));
    }
  }

  void test_clamp_4()
  {
    {
      float mock_red = 255.1f;
      float mock_green = 254.9f;
      float mock_blue = 0.1f;
      float mock_alpha = 0.0f;
      gl_wrapper::core::math::clamp_quad(mock_red, mock_green, mock_blue,
        mock_alpha, 0.0f, 255.0f);
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_red, 255.0f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_green, 254.9f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_blue, 0.1f, eps));
      TS_ASSERT(gl_wrapper::core::math::float_equals(mock_alpha, 0.0f, eps));
    }
  }
};
#endif
