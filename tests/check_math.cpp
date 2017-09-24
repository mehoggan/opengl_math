#include "opengl_math/core/enumerations.h"
#include "opengl_math/math/numbers.h"
#include "opengl_math/math/matrix.h"
#include "opengl_math/math/geometry.h"
#include "opengl_math/matrices/type_matrix_4X4.h"

#include "suite.h"

#include <limits>

#include <check.h>

/*! \brief Unit tests for translate to and from functions
*/
START_TEST(test_translate_to_2d_identity)
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0f, 10.0f));

    opengl_math::vector_3d<float> expected(5.0f, 10.0f, 1.0f);
    ck_assert(expected == trans[2]);
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::row> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0f, 10.0f));

    ck_assert(opengl_math::vector_3d<float>(5.0f, 10.0f, 1.0f) ==
      trans[2]);
  }
}
END_TEST

START_TEST(test_translate_to_3d_identity)
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(5.0f, 5.0f, 5.0f));

    ck_assert(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f) ==
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> mat(
      opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::row> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(5.0f, 5.0f, 5.0f));

    ck_assert(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f) ==
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);
    mat = opengl_math::scale_by(mat, 2.5f, 2.0f, 1.0f);
    mat = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(1.0f, 1.0f, 1000.0f));

    // Position is affected by scaling.
    ck_assert(opengl_math::vector_4d<float>(2.5f, 2.0f, 1000.0f, 1.0f) ==
      mat[3]);
  }
}
END_TEST

START_TEST(test_translate_to_2d_no_rotation)
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
      opengl_math::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0, 1.0));

    ck_assert(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f) ==
      trans[2]);
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
      opengl_math::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_3X3<float, opengl_math::row> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0, 1.0));

    ck_assert(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f) ==
      trans[2]);
  }
}
END_TEST

START_TEST(test_translate_to_3d_no_rotation)
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
      opengl_math::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
      opengl_math::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
      opengl_math::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_4X4<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(5.0, 5.0, 5.0));

    ck_assert(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f) ==
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> mat(
      opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
      opengl_math::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
      opengl_math::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
      opengl_math::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_4X4<float, opengl_math::row> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(5.0, 5.0, 5.0));

    ck_assert(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f) ==
      trans[3]);
  }
}
END_TEST

START_TEST(test_translate_by_2d_identity)
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_2d<float>(5.0f, 1.0f));

    ck_assert(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f) ==
      trans[2]);
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::row> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_2d<float>(5.0f, 1.0f));

    ck_assert(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f) ==
      trans[2]);
  }
}
END_TEST

START_TEST(test_translate_by_3d_identity)
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_3d<float>(5.0f, 5.0f, 5.0f));

    ck_assert(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f) ==
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> mat(
      opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::row> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_3d<float>(5.0f, 5.0f, 5.0f));

    ck_assert(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f) ==
      trans[3]);
  }
}
END_TEST

START_TEST(test_translate_by_2d_no_rotation)
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
      opengl_math::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_2d<float>(5.0, 5.0));

    ck_assert(opengl_math::vector_3d<float>(15.0f, 15.0f, 1.0f) ==
      trans[2]);
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
      opengl_math::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_3X3<float, opengl_math::row> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_2d<float>(5.0, 5.0));

    ck_assert(opengl_math::vector_3d<float>(15.0f, 15.0f, 1.0f) ==
      trans[2]);
  }
}
END_TEST

START_TEST(test_translate_by_3d_no_rotation)
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
      opengl_math::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
      opengl_math::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
      opengl_math::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_4X4<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_3d<float>(5.0, 5.0, 5.0));

    ck_assert(opengl_math::vector_4d<float>(15.0f, 15.0f, 15.0f, 1.0f) ==
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> mat(
      opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), // r
      opengl_math::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f), // u
      opengl_math::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f), // @
      opengl_math::vector_4d<float>(10.0f, 10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_4X4<float, opengl_math::row> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_3d<float>(5.0, 5.0, 5.0));

    ck_assert(opengl_math::vector_4d<float>(15.0f, 15.0f, 15.0f, 1.0f) ==
      trans[3]);
  }
}
END_TEST

/*! \brief Unit tests for rotation matrix functions starting from the
* identity matrix.
*/
START_TEST(test_rotate_to_2d)
{
  { // Quadrant 1
    const float cos30 = 0.86602540378f;
    const float sin30 = 0.50000000000f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }

  { // Quadrant 2
    const float cos165 = -0.96592582600f;
    const float sin165 = 0.25881904500f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        165.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }

  { // Quadrant 3
    const float cos265 = -0.08715574274f;
    const float sin265 = -0.99619469809f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        265.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }

  { // Quadrant 4
    const float cos330 = 0.86602540378f;
    const float sin330 = -0.50000000000f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        330.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
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
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      rot = opengl_math::rotate_to<float, opengl_math::column>(rot,
        165.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      rot = opengl_math::rotate_to<float, opengl_math::column>(rot,
        265.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      rot = opengl_math::rotate_to<float, opengl_math::column>(rot,
        330.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      rot = opengl_math::rotate_to<float, opengl_math::row>(rot,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      rot = opengl_math::rotate_to<float, opengl_math::row>(rot,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      rot = opengl_math::rotate_to<float, opengl_math::row>(rot,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }
}
END_TEST

START_TEST(test_rotate_to_3d_about_standard_basis)
{
  { // Quadrant 1
    const float cos30 = 0.86602540378f;
    const float sin30 = 0.50000000000f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }
  }

  { // Quadrant 2
    const float cos165 = -0.96592582600f;
    const float sin165 = 0.25881904500f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }
  }

  { // Quadrant 3
    const float cos265 = -0.08715574274f;
    const float sin265 = -0.99619469809f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }
  }

  { // Quadrant 4
    const float cos330 = 0.86602540378f;
    const float sin330 = -0.50000000000f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
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
      opengl_math::matrix_4X4<float, opengl_math::column> mat_x(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::column> mat_y(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::column> mat_z(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot_x;
      opengl_math::matrix_4X4<float, opengl_math::column> rot_y;
      opengl_math::matrix_4X4<float, opengl_math::column> rot_z;

      // At (z axis)
      // Quadrant 1
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(mat_x,
        30.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(rot_x,
        165.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(rot_x,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(rot_x,
        330.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(mat_y,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(rot_y,
        165.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(rot_y,
        265.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(rot_y,
        330.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(mat_z,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(rot_z,
        165.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(rot_z,
        265.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(rot_z,
        330.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat_x(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::row> mat_y(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::row> mat_z(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot_x;
      opengl_math::matrix_4X4<float, opengl_math::row> rot_y;
      opengl_math::matrix_4X4<float, opengl_math::row> rot_z;

      // At (z axis)
      // Quadrant 1
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(mat_x,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(mat_y,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(mat_z,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), rot_z[3],
        1e-006f));
    }
  }
}
END_TEST

/*! \brief Unit tests for rotation matrix functions starting from
*  a non standard basis vector.
*/
START_TEST(test_rotate_to_3d_about_not_standard_basis_vector)
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);

    opengl_math::matrix_4X4<float, opengl_math::column> rot;

    // First Vector
    const float len = (1.0f / opengl_math::sqrt(3.0f));

    // The values in this test can be visualized using the vector viewer
    rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
      45.0f, opengl_math::vector_3d<float>(len, len, len),
      opengl_math::degrees);

    ck_assert(opengl_math::vector_4d_float_equals( // Right
      opengl_math::vector_4d<float>(0.80473787f, 0.50587940f, -0.31061724f,
      0.0f), rot[0], 1e-006f));
    ck_assert(opengl_math::vector_4d_float_equals( // Up
      opengl_math::vector_4d<float>(-0.31061724f, 0.80473787f, 0.50587940f,
      0.0f), rot[1], 1e-006f));
    ck_assert(opengl_math::vector_4d_float_equals( // At
      opengl_math::vector_4d<float>(0.50587940f, -0.31061724f, 0.80473787f,
      0.0f), rot[2], 1e-006f));
    ck_assert(opengl_math::vector_4d_float_equals( // Pos
      opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f,
      1.0f), rot[3], 1e-006f));
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> mat(
      opengl_math::identity);

    opengl_math::matrix_4X4<float, opengl_math::row> rot;

    // First Vector
    const float len = (1.0f / opengl_math::sqrt(3.0f));

    // The values in this test can be visualized using the vector viewer
    rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
      45.0f, opengl_math::vector_3d<float>(len, len, len),
      opengl_math::degrees);

    ck_assert(opengl_math::vector_4d_float_equals( // Right
      opengl_math::vector_4d<float>(0.80473787f, 0.50587940f, -0.31061724f,
      0.0f), rot[0], 1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
      opengl_math::vector_4d<float>(-0.31061724f, 0.80473787f, 0.50587940f,
      0.0f), rot[1], 1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
      opengl_math::vector_4d<float>(0.50587940f, -0.31061724f, 0.80473787f,
      0.0f), rot[2], 1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Pos
      opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f,
      1.0f), rot[3], 1e-006f));
  }
}
END_TEST

/*! brief test rotate_by 3D and 4D matrices: first test about standard basis
 * then test about non standard basis.
 */
START_TEST(test_rotate_by_2d)
{
  { // Quadrant 1
    const float cos30 = 0.86602540378f;
    const float sin30 = 0.50000000000f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }

  { // Quadrant 2
    const float cos165 = -0.96592582600f;
    const float sin165 = 0.25881904500f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        165.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }

  { // Quadrant 3
    const float cos265 = -0.08715574274f;
    const float sin265 = -0.99619469809f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        265.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }

  { // Quadrant 4
    const float cos330 = 0.86602540378f;
    const float sin330 = -0.50000000000f;

    {
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        330.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
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
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      // (135 degrees to 165 degrees from previous rotation)
      rot = opengl_math::rotate_by<float, opengl_math::column>(rot,
        135.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      // (100 degrees to 265 degrees from previous rotation)
      rot = opengl_math::rotate_by<float, opengl_math::column>(rot,
        100.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      // (65 degrees to 330 degrees from previous rotation)
      rot = opengl_math::rotate_by<float, opengl_math::column>(rot,
        65.0f, opengl_math::degrees);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::row> rot;

      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      // (135 degrees to 165 degrees from previous rotation)
      rot = opengl_math::rotate_by<float, opengl_math::row>(rot,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      // (100 degrees to 265 degrees from previous rotation)
      rot = opengl_math::rotate_by<float, opengl_math::row>(rot,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));

      // (65 degrees to 330 degrees from previous rotation)
      rot = opengl_math::rotate_by<float, opengl_math::row>(rot,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::radians);

      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
        1e-006f));
    }
  }
}
END_TEST

START_TEST(test_rotate_by_3d_about_standard_basis)
{
  { // Quadrant 1
    const float cos30 = 0.86602540378f;
    const float sin30 = 0.50000000000f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }
  }

  { // Quadrant 2
    const float cos165 = -0.96592582600f;
    const float sin165 = 0.25881904500f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }
  }

  { // Quadrant 3
    const float cos265 = -0.08715574274f;
    const float sin265 = -0.99619469809f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }
  }

  { // Quadrant 4
    const float cos330 = 0.86602540378f;
    const float sin330 = -0.50000000000f;

    {
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
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
      opengl_math::matrix_4X4<float, opengl_math::column> mat_x(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::column> mat_y(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::column> mat_z(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot_x;
      opengl_math::matrix_4X4<float, opengl_math::column> rot_y;
      opengl_math::matrix_4X4<float, opengl_math::column> rot_z;

      // At (z axis)
      // Quadrant 1
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(mat_x,
        30.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2 (130 degrees to 165 degrees from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(rot_x,
        135.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 degrees from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(rot_x,
        100.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 degrees from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(rot_x,
        65.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(mat_y,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(rot_y,
        135.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(rot_y,
        100.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(rot_y,
        65.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(mat_z,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(rot_z,
        135.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(rot_z,
        100.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4 (65 dgerees to 330 from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(rot_z,
        65.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
    }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat_x(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::row> mat_y(
        opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::row> mat_z(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::row> rot_x;
      opengl_math::matrix_4X4<float, opengl_math::row> rot_y;
      opengl_math::matrix_4X4<float, opengl_math::row> rot_z;

      // At (z axis)
      // Quadrant 1
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(mat_x,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(mat_y,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(mat_z,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 degrees from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 degrees from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 degrees from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      ck_assert(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      ck_assert(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), rot_z[3],
        1e-006f));
    }
  }
}
END_TEST

/*! brief test rotate_by 3D and 4D matrices: first test about standard basis
 * then test about non standard basis.
 */
START_TEST(test_scale_by_2d)
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f);
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f);
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
  }
}
END_TEST

START_TEST(test_scale_by_3d)
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f, 300.0f);
    ck_assert(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(100.0f, 0.0f, 0.0f, 0.0f), mat[0],
      1e-006f));
    ck_assert(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(0.0f, 200.0f, 0.0f, 0.0f), mat[1],
      1e-006f));
    ck_assert(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(0.0f, 0.0f, 300.0f, 0.0f), mat[2],
      1e-006f));
    ck_assert(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), mat[3],
      1e-006f));
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f);
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
    ck_assert(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
  }
}
END_TEST

START_TEST(test_ctor_triangle)
{
  opengl_math::point_3d<float> p1;
  opengl_math::point_3d<float> p2;
  opengl_math::point_3d<float> p3;
  opengl_math::triangle<float> tri(p1, p2, p3);
  ck_assert(tri._p1 == opengl_math::point_3d<float>());
  ck_assert(tri._p2 == opengl_math::point_3d<float>());
  ck_assert(tri._p3 == opengl_math::point_3d<float>());
}
END_TEST

START_TEST(test_points_of_triangle_are_not_collinear)
{
  { // point
    ck_assert(opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(),
        opengl_math::point_3d<float>(),
        opengl_math::point_3d<float>())));
  }

  { // x-y plane
    ck_assert(!opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
        opengl_math::point_3d<float>(2.0f, 0.0f, 0.0f),
        opengl_math::point_3d<float>(1.0f, 2.0f, 0.0f))));
  }

  { // x-z plane
    ck_assert(!opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(0.0f, 0.0f, 0.0f),
        opengl_math::point_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::point_3d<float>(1.0f, 0.0f, 0.0f))));
  }

  { // arbitrary plane
    ck_assert(!opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(+0.0f, -1.0f, +0.0f),
        opengl_math::point_3d<float>(+0.0f, +1.0f, +1.0f),
        opengl_math::point_3d<float>(+1.0f, +0.0f, +0.0f))));
  }

  { // line
    ck_assert(opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(+0.0f, +0.0f, +0.0f),
        opengl_math::point_3d<float>(+1.0f, +0.0f, +0.0f),
        opengl_math::point_3d<float>(+2.0f, +0.0f, +0.0f))));
  }

  { // almost line
    ck_assert(!opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(+0.0f, +0.0f, +0.0f),
        opengl_math::point_3d<float>(+1.0f, +0.0000001f, +0.0f),
        opengl_math::point_3d<float>(+2.0f, +0.0f, +0.0f))));
  }

  { // very close to a line
    ck_assert(opengl_math::points_of_triangle_are_collinear<float>(
      opengl_math::triangle<float>(
        opengl_math::point_3d<float>(+0.0f, +0.0f, +0.0f),
        opengl_math::point_3d<float>(+1.0f, +0.000000000001f, +0.0f),
        opengl_math::point_3d<float>(+2.0f, +0.0f, +0.0f))));
  }
}
END_TEST

START_TEST(test_tessellate_triangle_by_subdivision)
{
  { // zero tessellation
    opengl_math::point_3d<float> p1;
    opengl_math::point_3d<float> p2;
    opengl_math::point_3d<float> p3;
    std::uint32_t current_index = 0;
    opengl_math::subdivided_tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangle_by_subdivision<float>(
      opengl_math::triangle<float>(p1, p2, p3), 0, current_index, output);
    ck_assert(output._points.empty());
    ck_assert(output._indices.empty());
    ck_assert(current_index == 0);
  }

  { // equilateral triangle subdivide zero times.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::subdivided_tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::tessellate_triangle_by_subdivision<float>(
      opengl_math::triangle<float>(p1, p2, p3), 0, current_index, output);
    ck_assert(output._points.size() == 3);
    ck_assert(output._points[0] == p1);
    ck_assert(output._points[1] == p2);
    ck_assert(output._points[2] == p3);
    ck_assert(output._indices.size() == 3);
    ck_assert(output._indices[0] == 0u);
    ck_assert(output._indices[1] == 1u);
    ck_assert(output._indices[2] == 2u);
  }

  { // equilateral triangle subdivide once.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::subdivided_tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::triangle<float> tri(p1, p2, p3);
    opengl_math::tessellate_triangle_by_subdivision<float>(
      tri, 1, current_index, output);
    std::size_t points_count = output._points.size();
    ck_assert(points_count == 4u);
    ck_assert(output._points[0] == p1);
    ck_assert(output._points[1] == opengl_math::centroid_of_triangle(tri));
    ck_assert(output._points[2] == p3);
    ck_assert(output._points[3] == p2);
    std::size_t indices_count = output._indices.size();
    ck_assert(indices_count == 9u);
    ck_assert(output._indices[0] == 0u);
    ck_assert(output._indices[1] == 1u);
    ck_assert(output._indices[2] == 2u);
    ck_assert(output._indices[3] == 0u);
    ck_assert(output._indices[4] == 3u);
    ck_assert(output._indices[5] == 1u);
    ck_assert(output._indices[6] == 3u);
    ck_assert(output._indices[7] == 2u);
    ck_assert(output._indices[8] == 1u);
  }

    { // equilateral triangle subdivide twice.
    opengl_math::point_3d<float> p1(0.0f, 0.0f, 0.0f);
    opengl_math::point_3d<float> p2(1.0f, 0.0f, 1.0f);
    opengl_math::point_3d<float> p3(0.0f, 1.125f, 0.0f);
    std::uint32_t current_index = 0;
    opengl_math::subdivided_tessellated_triangle_data<float, std::uint32_t>
      output;
    opengl_math::triangle<float> tri(p1, p2, p3);
    opengl_math::tessellate_triangle_by_subdivision<float>(
      tri, 2, current_index, output);
    std::size_t points_count = output._points.size();
    ck_assert(points_count == 7u);
    std::size_t indices_count = output._indices.size();
    ck_assert(indices_count == 27u);
  }
}
END_TEST

START_TEST(test_centroid_of_triangle)
{
  {
    opengl_math::triangle<float> right_tri(
      opengl_math::point_3d<float>(+0.0f, +0.0f, +0.0f),
      opengl_math::point_3d<float>(+1.0f, +0.0f, +0.0f),
      opengl_math::point_3d<float>(+0.0f, +1.0f, +0.0f));

    opengl_math::point_3d<float> centroid =
      opengl_math::centroid_of_triangle(right_tri);
    ck_assert(opengl_math::float_equals(0.3333333333333333f, centroid._x,
      std::numeric_limits<float>::epsilon()));
    ck_assert(opengl_math::float_equals(0.3333333333333333f, centroid._y,
      std::numeric_limits<float>::epsilon()));
    ck_assert(opengl_math::float_equals(0.0f, centroid._z,
      std::numeric_limits<float>::epsilon()));
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

  tcase_add_test(tc, test_translate_to_2d_identity);
  tcase_add_test(tc, test_translate_to_3d_identity);
  tcase_add_test(tc, test_translate_to_2d_no_rotation);
  tcase_add_test(tc, test_translate_to_3d_no_rotation);
  tcase_add_test(tc, test_translate_by_2d_identity);
  tcase_add_test(tc, test_translate_by_3d_identity);
  tcase_add_test(tc, test_translate_by_2d_no_rotation);
  tcase_add_test(tc, test_translate_by_3d_no_rotation);
  tcase_add_test(tc, test_rotate_to_2d);
  tcase_add_test(tc, test_rotate_to_3d_about_standard_basis);
  tcase_add_test(tc, test_rotate_to_3d_about_not_standard_basis_vector);
  tcase_add_test(tc, test_rotate_by_2d);
  tcase_add_test(tc, test_rotate_by_3d_about_standard_basis);
  tcase_add_test(tc, test_scale_by_2d);
  tcase_add_test(tc, test_scale_by_3d);
  tcase_add_test(tc, test_ctor_triangle);
  tcase_add_test(tc, test_points_of_triangle_are_not_collinear);
  tcase_add_test(tc, test_tessellate_triangle_by_subdivision);
  tcase_add_test(tc, test_centroid_of_triangle);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
