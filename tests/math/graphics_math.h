#ifndef GRAPHICS_TESTS
#define GRAPHICS_TESTS

#include <cxxtest/TestSuite.h>

#include <graphics/math/matrix.h>
#include <core/math/numbers.h>
#include <core/math/trig.h>
#include <graphics/matrices/type_matrix_4X4.h>
#include <graphics/primitives/points/type_point_3d.h>
#include <graphics/primitives/vectors/type_vector_3d.h>
#include <graphics/primitives/vectors/type_vector_4d.h>

#include <iostream>
#include <vector>
#include <cassert>

// TODO: Note that there are no rotation tests that test negative rotations
// TODO: Note that all the matrix calculation such as ortho, pers, and lookat
// are not tested. This is because a graphical frame work with shaders would
// be needed to verify their correctness.
// TODO: Test norm
// TODO: Test angle_between
// TODO: Test operator- (point2, point2)
// TODO: Test operator- (point3, point3)

class graphics_tests : public CxxTest::TestSuite
{
public:
  /*! \brief Unit tests for translate to and from functions
   */
  void test_translate_to_2d_identity()
  {
    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
        gl_wrapper::identity);
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_2d<float>(5.0f, 10.0f));

      gl_wrapper::vector_3d<float> expected(5.0f, 10.0f, 1.0f);
      TS_ASSERT_EQUALS(expected, trans[2]);
    }

    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
        gl_wrapper::identity);
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_2d<float>(5.0f, 10.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(5.0f, 10.0f, 1.0f),
        trans[2]);
    }
  }

  void test_translate_to_3d_identity()
  {
    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
        gl_wrapper::identity);
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_to(mat,
          gl_wrapper::point_3d<float>(5.0f, 5.0f, 5.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }

    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(gl_wrapper::identity);
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_3d<float>(5.0f, 5.0f, 5.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }
  }

  void test_translate_to_2d_no_rotation()
  {
    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
        gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
        gl_wrapper::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_2d<float>(5.0, 1.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(5.0f, 1.0f, 1.0f),
        trans[2]);
    }

    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
        gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
        gl_wrapper::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_2d<float>(5.0, 1.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(5.0f, 1.0f, 1.0f),
        trans[2]);
    }
  }

  void test_translate_to_3d_no_rotation()
  {
    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
        gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
        gl_wrapper::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_3d<float>(5.0, 5.0, 5.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }

    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
        gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
        gl_wrapper::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_to(mat,
        gl_wrapper::point_3d<float>(5.0, 5.0, 5.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }
  }

  void test_translate_by_2d_identity()
  {
    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
        gl_wrapper::identity);
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_by(mat,
          gl_wrapper::vector_2d<float>(5.0f, 1.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(5.0f, 1.0f, 1.0f),
        trans[2]);
    }

    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(gl_wrapper::identity);
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_by(mat,
        gl_wrapper::vector_2d<float>(5.0f, 1.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(5.0f, 1.0f, 1.0f),
        trans[2]);
    }
  }

  void test_translate_by_3d_identity()
  {
    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
        gl_wrapper::identity);
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_by(mat,
          gl_wrapper::vector_3d<float>(5.0f, 5.0f, 5.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }

    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(gl_wrapper::identity);
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_by(mat,
        gl_wrapper::vector_3d<float>(5.0f, 5.0f, 5.0f));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }
  }

  void test_translate_by_2d_no_rotation()
  {
    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
        gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
        gl_wrapper::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_by(mat,
        gl_wrapper::vector_2d<float>(5.0, 5.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(15.0f, 15.0f, 1.0f),
        trans[2]);
    }

    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
        gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
        gl_wrapper::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_by(mat,
        gl_wrapper::vector_2d<float>(5.0, 5.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_3d<float>(15.0f, 15.0f, 1.0f),
        trans[2]);
    }
  }

  void test_translate_by_3d_no_rotation()
  {
    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
        gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
        gl_wrapper::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> trans;

      trans = gl_wrapper::translate_by(mat,
        gl_wrapper::vector_3d<float>(5.0, 5.0, 5.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(15.0f, 15.0f, 15.0f, 1.0f),
        trans[3]);
    }

    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
        gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
        gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
        gl_wrapper::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> trans;

      trans = gl_wrapper::translate_by(mat,
        gl_wrapper::vector_3d<float>(5.0, 5.0, 5.0));

      TS_ASSERT_EQUALS(gl_wrapper::vector_4d<float>(15.0f, 15.0f, 15.0f, 1.0f),
        trans[3]);
    }
  }

  /*! \brief Unit tests for rotation matrix functions starting from the
   * identity matrix.
   */
  void test_rotate_to_2d()
  {
    { // Quadrant 1
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Quadrant 2
      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Quadrant 3
      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Quadrant 4
      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Chain of rotate_to(s)
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot,
          165.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot,
          265.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot,
          330.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }
  }

  void test_rotate_to_3d_about_standard_basis()
  {
    { // Quadrant 1
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Quadrant 2
      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Quadrant 3
      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Quadrant 4
      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Chain of rotate_to(s)
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat_x(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat_y(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat_z(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot_x;
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot_y;
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot_z;

        // At (z axis)
        // Quadrant 1
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat_x,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 2
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_x,
          165.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 3
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 4
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_x,
          330.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));

        // Up (y axis)
        // Quadrant 1
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat_y,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 2
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_y,
          165.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 3
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_y,
          265.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 4
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_y,
          330.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));

        // Right (x axis)
        // Quadrant 1
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat_z,
          30.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 2
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_z,
          165.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 3
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_z,
          265.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 4
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::column>(rot_z,
          330.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat_x(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat_y(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat_z(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot_x;
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot_y;
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot_z;

        // At (z axis)
        // Quadrant 1
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat_x,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 2
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 3
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 4
        rot_x = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));

        // Up (y axis)
        // Quadrant 1
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat_y,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 2
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_y,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 3
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_y,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 4
        rot_y = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_y,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));

        // Right (x axis)
        // Quadrant 1
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat_z,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 2
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_z,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 3
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_z,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 4
        rot_z = gl_wrapper::rotate_to<float, gl_wrapper::row>(rot_z,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), rot_z[3],
          1e-006f));
      }
    }
  }

  /*! \brief Unit tests for rotation matrix functions starting from
   *  a non standard basis vector.
   */
  void test_rotate_to_3d_about_not_standard_basis_vector()
  {
    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
         gl_wrapper::identity);

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

       // First Vector
      const float len = (1.0f / gl_wrapper::core::math::sqrt(3.0f));

      // The values in this test can be visualized using the vector viewer
      rot = gl_wrapper::rotate_to<float, gl_wrapper::column>(mat,
        45.0f, gl_wrapper::vector_3d<float>(len, len, len),
        gl_wrapper::core::math::degrees);

      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
        gl_wrapper::vector_4d<float>(0.80473787f, 0.50587940f, -0.31061724f,
        0.0f), rot[0], 1e-006f))
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
        gl_wrapper::vector_4d<float>(-0.31061724f, 0.80473787f, 0.50587940f,
        0.0f), rot[1], 1e-006f))
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
        gl_wrapper::vector_4d<float>(0.50587940f, -0.31061724f, 0.80473787f,
        0.0f), rot[2], 1e-006f))
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Pos
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f,
        1.0f), rot[3], 1e-006f))
    }

    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
         gl_wrapper::identity);

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

       // First Vector
      const float len = (1.0f / gl_wrapper::core::math::sqrt(3.0f));

      // The values in this test can be visualized using the vector viewer
      rot = gl_wrapper::rotate_to<float, gl_wrapper::row>(mat,
        45.0f, gl_wrapper::vector_3d<float>(len, len, len),
        gl_wrapper::core::math::degrees);

      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
        gl_wrapper::vector_4d<float>(0.80473787f, 0.50587940f, -0.31061724f,
        0.0f), rot[0], 1e-006f))
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
        gl_wrapper::vector_4d<float>(-0.31061724f, 0.80473787f, 0.50587940f,
        0.0f), rot[1], 1e-006f))
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
        gl_wrapper::vector_4d<float>(0.50587940f, -0.31061724f, 0.80473787f,
        0.0f), rot[2], 1e-006f))
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Pos
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f,
        1.0f), rot[3], 1e-006f))
    }
  }

  /*! brief test rotate_by 3D and 4D matrices: first test about standard basis then
   * test about non standard basis
   */
  void test_rotate_by_2d()
  {
    { // Quadrant 1
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Quadrant 2
      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Quadrant 3
      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Quadrant 4
      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }

    { // Chain of rotate_by(s)
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::column> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (135 degrees to 165 degrees from previous rotation)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot,
          135.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (100 degrees to 265 degrees from previous rotation)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot,
          100.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (65 degrees to 330 degrees from previous rotation)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot,
          65.0f, gl_wrapper::core::math::degrees);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }

      {
        gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_3X3<float, gl_wrapper::row> rot;

        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (135 degrees to 165 degrees from previous rotation)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot,
          gl_wrapper::core::math::degrees_to_radians(135.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (100 degrees to 265 degrees from previous rotation)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot,
          gl_wrapper::core::math::degrees_to_radians(100.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (65 degrees to 330 degrees from previous rotation)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot,
          gl_wrapper::core::math::degrees_to_radians(65.0f),
          gl_wrapper::core::math::radians);

        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));
      }
    }
  }

  void test_rotate_by_3d_about_standard_basis()
  {
    { // Quadrant 1
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          30.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Quadrant 2
      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          165.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(165.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Quadrant 3
      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          265.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(265.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Quadrant 4
      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat,
          330.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot;

        // At (z axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat,
          gl_wrapper::core::math::degrees_to_radians(330.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));
      }
    }

    { // Chain of rotate_by(s)
      const float cos30 = 0.86602540378f;
      const float sin30 = 0.50000000000f;

      const float cos165 = -0.96592582600f;
      const float sin165 = 0.25881904500f;

      const float cos265 = -0.08715574274f;
      const float sin265 = -0.99619469809f;

      const float cos330 = 0.86602540378f;
      const float sin330 = -0.50000000000f;

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat_x(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat_y(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat_z(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot_x;
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot_y;
        gl_wrapper::matrix_4X4<float, gl_wrapper::column> rot_z;

        // At (z axis)
        // Quadrant 1
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat_x,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 2 (130 degrees to 165 degrees from previous rotation)
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_x,
          135.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 3 (100 degrees to 265 degrees from previous rotation)
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_x,
          100.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 4 (65 degrees to 330 degrees from previous rotation)
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_x,
          65.0f, gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));

        // Up (y axis)
        // Quadrant 1
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat_y,
          30.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 2 (135 degrees to 165 from previous rotation)
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_y,
          135.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 3 (100 degrees to 265 from previous rotation)
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_y,
          100.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 4 (65 degrees to 330 from previous rotation)
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_y,
          65.0f, gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));

        // Right (x axis)
        // Quadrant 1
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::column>(mat_z,
          30.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 2 (135 degrees to 165 from previous rotation)
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_z,
          135.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 3 (100 degrees to 265 from previous rotation)
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_z,
          100.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 4 (65 dgerees to 330 from previous rotation)
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::column>(rot_z,
          65.0f, gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::degrees);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
      }

      {
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat_x(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat_y(
          gl_wrapper::identity);
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> mat_z(
          gl_wrapper::identity);

        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot_x;
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot_y;
        gl_wrapper::matrix_4X4<float, gl_wrapper::row> rot_z;

        // At (z axis)
        // Quadrant 1
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat_x,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 2 (135 degrees to 165 from previous rotation)
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(135.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 3 (100 degrees to 265 from previous rotation)
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(100.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));
        // Quadrant 4 (65 degrees to 330 from previous rotation)
        rot_x = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_x,
          gl_wrapper::core::math::degrees_to_radians(65.0f),
          gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
          1e-006f));

        // Up (y axis)
        // Quadrant 1
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat_y,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 2 (135 degrees to 165 from previous rotation)
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_y,
          gl_wrapper::core::math::degrees_to_radians(135.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 3 (100 degrees to 265 from previous rotation)
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_y,
          gl_wrapper::core::math::degrees_to_radians(100.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));
        // Quadrant 4 (65 degrees to 330 from previous rotation)
        rot_y = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_y,
          gl_wrapper::core::math::degrees_to_radians(65.0f),
          gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
          1e-006f));

        // Right (x axis)
        // Quadrant 1
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::row>(mat_z,
          gl_wrapper::core::math::degrees_to_radians(30.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 2 (135 degrees to 165 degrees from previous rotation)
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_z,
          gl_wrapper::core::math::degrees_to_radians(135.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 3 (100 degrees to 265 degrees from previous rotation)
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_z,
          gl_wrapper::core::math::degrees_to_radians(100.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
          1e-006f));
        // Quadrant 4 (65 degrees to 330 degrees from previous rotation)
        rot_z = gl_wrapper::rotate_by<float, gl_wrapper::row>(rot_z,
          gl_wrapper::core::math::degrees_to_radians(65.0f),
          gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f),
          gl_wrapper::core::math::radians);
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Right
          gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Up
          gl_wrapper::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // At
          gl_wrapper::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
          1e-006f));
        TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals( // Position
          gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), rot_z[3],
          1e-006f));
      }
    }
  }

  /*! brief test rotate_by 3D and 4D matrices: first test about standard basis then
   * test about non standard basis
   */
  void test_scale_by_2d()
  {
    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> mat(
        gl_wrapper::identity);

      mat = gl_wrapper::scale_by(mat, 100.0f, 200.0f);
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
    }

    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
        gl_wrapper::identity);

      mat = gl_wrapper::scale_by(mat, 100.0f, 200.0f);
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
    }
  }

  void test_scale_by_3d()
  {
    {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> mat(
        gl_wrapper::identity);

      mat = gl_wrapper::scale_by(mat, 100.0f, 200.0f, 300.0f);
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals(
        gl_wrapper::vector_4d<float>(100.0f, 0.0f, 0.0f, 0.0f), mat[0],
        1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals(
        gl_wrapper::vector_4d<float>(0.0f, 200.0f, 0.0f, 0.0f), mat[1],
        1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals(
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 300.0f, 0.0f), mat[2],
        1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_4d_float_equals(
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), mat[3],
        1e-006f));
    }

    {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> mat(
        gl_wrapper::identity);

      mat = gl_wrapper::scale_by(mat, 100.0f, 200.0f);
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
      TS_ASSERT(gl_wrapper::core::math::vector_3d_float_equals(
        gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
    }
  }

  /*! brief
   */
  void test_ortho_lrtb()
  {
  }

  void test_ortho_lrtbznf()
  {
  }
};
#endif
