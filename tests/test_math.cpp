#include "test_math.h"

/*! \brief Unit tests for translate to and from functions
*/
void test_translate_to_2d_identity()
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0f, 10.0f));

    opengl_math::vector_3d<float> expected(5.0f, 10.0f, 1.0f);
    OPENGL_MATH_ASSERT_EQ(expected, trans[2]);
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::row> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0f, 10.0f));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(5.0f, 10.0f, 1.0f),
      trans[2]);
  }
}

void test_translate_to_3d_identity()
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(5.0f, 5.0f, 5.0f));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::row> mat(opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::row> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(5.0f, 5.0f, 5.0f));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
      trans[3]);
  }

  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);
    mat = opengl_math::scale_by(mat, 2.5f, 2.0f, 1.0f);
    mat = opengl_math::translate_to(mat,
      opengl_math::point_3d<float>(1.0f, 1.0f, 1000.0f));

    // Position is affected by scaling.
    OPENGL_MATH_ASSERT_EQ(
      opengl_math::vector_4d<float>(2.5f, 2.0f, 1000.0f, 1.0f), mat[3]);
  }
}

void test_translate_to_2d_no_rotation()
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
      opengl_math::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_to(mat,
      opengl_math::point_2d<float>(5.0, 1.0));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f),
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

      OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f),
        trans[2]);
    }
}

void test_translate_to_3d_no_rotation()
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

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
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

      OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }
}

void test_translate_by_2d_identity()
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_2d<float>(5.0f, 1.0f));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f),
      trans[2]);
  }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);
      opengl_math::matrix_3X3<float, opengl_math::row> trans;

      trans = opengl_math::translate_by(mat,
        opengl_math::vector_2d<float>(5.0f, 1.0f));

      OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(5.0f, 1.0f, 1.0f),
        trans[2]);
    }
}

void test_translate_by_3d_identity()
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);
    opengl_math::matrix_4X4<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_3d<float>(5.0f, 5.0f, 5.0f));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
      trans[3]);
  }

    {
      opengl_math::matrix_4X4<float, opengl_math::row> mat(opengl_math::identity);
      opengl_math::matrix_4X4<float, opengl_math::row> trans;

      trans = opengl_math::translate_by(mat,
        opengl_math::vector_3d<float>(5.0f, 5.0f, 5.0f));

      OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(5.0f, 5.0f, 5.0f, 1.0f),
        trans[3]);
    }
}

void test_translate_by_2d_no_rotation()
{
  {
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f), // r
      opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f), // u
      opengl_math::vector_3d<float>(10.0f, 10.0f, 1.0f)); // d

    opengl_math::matrix_3X3<float, opengl_math::column> trans;

    trans = opengl_math::translate_by(mat,
      opengl_math::vector_2d<float>(5.0, 5.0));

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(15.0f, 15.0f, 1.0f),
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

      OPENGL_MATH_ASSERT_EQ(opengl_math::vector_3d<float>(15.0f, 15.0f, 1.0f),
        trans[2]);
    }
}

void test_translate_by_3d_no_rotation()
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

    OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(15.0f, 15.0f, 15.0f, 1.0f),
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

      OPENGL_MATH_ASSERT_EQ(opengl_math::vector_4d<float>(15.0f, 15.0f, 15.0f, 1.0f),
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
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::degrees);

      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = opengl_math::rotate_to<float, opengl_math::column>(rot,
          165.0f, opengl_math::degrees);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = opengl_math::rotate_to<float, opengl_math::column>(rot,
          265.0f, opengl_math::degrees);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = opengl_math::rotate_to<float, opengl_math::column>(rot,
          330.0f, opengl_math::degrees);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = opengl_math::rotate_to<float, opengl_math::row>(rot,
          opengl_math::degrees_to_radians(165.0f),
          opengl_math::radians);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = opengl_math::rotate_to<float, opengl_math::row>(rot,
          opengl_math::degrees_to_radians(265.0f),
          opengl_math::radians);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        rot = opengl_math::rotate_to<float, opengl_math::row>(rot,
          opengl_math::degrees_to_radians(330.0f),
          opengl_math::radians);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
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
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(30.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(30.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(165.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(165.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(265.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(265.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(330.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_to<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(330.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(rot_x,
        165.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(rot_x,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4
      rot_x = opengl_math::rotate_to<float, opengl_math::column>(rot_x,
        330.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(mat_y,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(rot_y,
        165.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(rot_y,
        265.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4
      rot_y = opengl_math::rotate_to<float, opengl_math::column>(rot_y,
        330.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(mat_z,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(rot_z,
        165.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(rot_z,
        265.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4
      rot_z = opengl_math::rotate_to<float, opengl_math::column>(rot_z,
        330.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4
      rot_x = opengl_math::rotate_to<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(mat_y,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4
      rot_y = opengl_math::rotate_to<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(mat_z,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(165.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(265.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4
      rot_z = opengl_math::rotate_to<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(330.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), rot_z[3],
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
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);

    opengl_math::matrix_4X4<float, opengl_math::column> rot;

    // First Vector
    const float len = (1.0f / opengl_math::sqrt(3.0f));

    // The values in this test can be visualized using the vector viewer
    rot = opengl_math::rotate_to<float, opengl_math::column>(mat,
      45.0f, opengl_math::vector_3d<float>(len, len, len),
      opengl_math::degrees);

    OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
      opengl_math::vector_4d<float>(0.80473787f, 0.50587940f, -0.31061724f,
      0.0f), rot[0], 1e-006f))
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
      opengl_math::vector_4d<float>(-0.31061724f, 0.80473787f, 0.50587940f,
      0.0f), rot[1], 1e-006f))
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
      opengl_math::vector_4d<float>(0.50587940f, -0.31061724f, 0.80473787f,
      0.0f), rot[2], 1e-006f))
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Pos
      opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f,
      1.0f), rot[3], 1e-006f))
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

      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(0.80473787f, 0.50587940f, -0.31061724f,
        0.0f), rot[0], 1e-006f))
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-0.31061724f, 0.80473787f, 0.50587940f,
        0.0f), rot[1], 1e-006f))
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.50587940f, -0.31061724f, 0.80473787f,
        0.0f), rot[2], 1e-006f))
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Pos
        opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f,
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
      opengl_math::matrix_3X3<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_3X3<float, opengl_math::column> rot;

      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::degrees);

      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (135 degrees to 165 degrees from previous rotation)
        rot = opengl_math::rotate_by<float, opengl_math::column>(rot,
          135.0f, opengl_math::degrees);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (100 degrees to 265 degrees from previous rotation)
        rot = opengl_math::rotate_by<float, opengl_math::column>(rot,
          100.0f, opengl_math::degrees);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (65 degrees to 330 degrees from previous rotation)
        rot = opengl_math::rotate_by<float, opengl_math::column>(rot,
          65.0f, opengl_math::degrees);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
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

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos30, sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin30, cos30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (135 degrees to 165 degrees from previous rotation)
        rot = opengl_math::rotate_by<float, opengl_math::row>(rot,
          opengl_math::degrees_to_radians(135.0f),
          opengl_math::radians);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos165, sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin165, cos165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (100 degrees to 265 degrees from previous rotation)
        rot = opengl_math::rotate_by<float, opengl_math::row>(rot,
          opengl_math::degrees_to_radians(100.0f),
          opengl_math::radians);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos265, sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin265, cos265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
          1e-006f));

        // (65 degrees to 330 degrees from previous rotation)
        rot = opengl_math::rotate_by<float, opengl_math::row>(rot,
          opengl_math::degrees_to_radians(65.0f),
          opengl_math::radians);

        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(cos330, sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(-sin330, cos330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
          opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), rot[2],
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
      opengl_math::matrix_4X4<float, opengl_math::column> mat(
        opengl_math::identity);

      opengl_math::matrix_4X4<float, opengl_math::column> rot;

      // At (z axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(30.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(30.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        165.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(165.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(165.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        265.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(265.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(265.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Up (y axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
        1e-006f));

      // Right (x axis)
      rot = opengl_math::rotate_by<float, opengl_math::column>(mat,
        330.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Up (y axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(330.0f),
          opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
          opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot[3],
          1e-006f));

        // Right (x axis)
        rot = opengl_math::rotate_by<float, opengl_math::row>(mat,
          opengl_math::degrees_to_radians(330.0f),
          opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
          opengl_math::radians);
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
          opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot[0],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
          opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot[1],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
          opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot[2],
          1e-006f));
        OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2 (130 degrees to 165 degrees from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(rot_x,
        135.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 degrees from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(rot_x,
        100.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 degrees from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::column>(rot_x,
        65.0f, opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(mat_y,
        30.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(rot_y,
        135.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(rot_y,
        100.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::column>(rot_y,
        65.0f, opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(mat_z,
        30.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(rot_z,
        135.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(rot_z,
        100.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4 (65 dgerees to 330 from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::column>(rot_z,
        65.0f, opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::degrees);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
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
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, sin30, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin30, cos30, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, sin165, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin165, cos165, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, sin265, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin265, cos265, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 from previous rotation)
      rot_x = opengl_math::rotate_by<float, opengl_math::row>(rot_x,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, sin330, 0.0f, 0.0f), rot_x[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(-sin330, cos330, 0.0f, 0.0f), rot_x[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0, 0.0, 1.0f, 0.0f), rot_x[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_x[3],
        1e-006f));

      // Up (y axis)
      // Quadrant 1
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(mat_y,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos30, 0.0f, -sin30, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin30, 0.0f, cos30, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos165, 0.0f, -sin165, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin165, 0.0f, cos165, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos265, 0.0f, -sin265, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin265, 0.0f, cos265, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 from previous rotation)
      rot_y = opengl_math::rotate_by<float, opengl_math::row>(rot_y,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(cos330, 0.0f, -sin330, 0.0f), rot_y[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, 1.0, 0.0f, 0.0f), rot_y[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(sin330, 0.0f, cos330, 0.0f), rot_y[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_y[3],
        1e-006f));

      // Right (x axis)
      // Quadrant 1
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(mat_z,
        opengl_math::degrees_to_radians(30.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos30, sin30, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin30, cos30, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 2 (135 degrees to 165 degrees from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(135.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos165, sin165, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin165, cos165, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 3 (100 degrees to 265 degrees from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(100.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos265, sin265, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin265, cos265, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0, 0.0, 0.0f, 1.0f), rot_z[3],
        1e-006f));
      // Quadrant 4 (65 degrees to 330 degrees from previous rotation)
      rot_z = opengl_math::rotate_by<float, opengl_math::row>(rot_z,
        opengl_math::degrees_to_radians(65.0f),
        opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f),
        opengl_math::radians);
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Right
        opengl_math::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f), rot_z[0],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Up
        opengl_math::vector_4d<float>(0.0, cos330, sin330, 0.0f), rot_z[1],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // At
        opengl_math::vector_4d<float>(0.0f, -sin330, cos330, 0.0f), rot_z[2],
        1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals( // Position
        opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), rot_z[3],
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
    opengl_math::matrix_3X3<float, opengl_math::column> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f);
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
  }

    {
      opengl_math::matrix_3X3<float, opengl_math::row> mat(
        opengl_math::identity);

      mat = opengl_math::scale_by(mat, 100.0f, 200.0f);
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
      OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
        opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
    }
}

void test_scale_by_3d()
{
  {
    opengl_math::matrix_4X4<float, opengl_math::column> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f, 300.0f);
    OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(100.0f, 0.0f, 0.0f, 0.0f), mat[0],
      1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(0.0f, 200.0f, 0.0f, 0.0f), mat[1],
      1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(0.0f, 0.0f, 300.0f, 0.0f), mat[2],
      1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_4d_float_equals(
      opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f), mat[3],
      1e-006f));
  }

  {
    opengl_math::matrix_3X3<float, opengl_math::row> mat(
      opengl_math::identity);

    mat = opengl_math::scale_by(mat, 100.0f, 200.0f);
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(100.0f, 0.0f, 0.0f), mat[0], 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 200.0f, 0.0f), mat[1], 1e-006f));
    OPENGL_MATH_ASSERT(opengl_math::vector_3d_float_equals(
      opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f), mat[2], 1e-006f));
  }
}

bool test_math::run()
{
  test_translate_to_2d_identity();
  test_translate_to_3d_identity();
  test_translate_to_2d_no_rotation();
  test_translate_to_3d_no_rotation();
  test_translate_by_2d_identity();
  test_translate_by_3d_identity();
  test_translate_by_2d_no_rotation();
  test_translate_by_3d_no_rotation();
  test_rotate_to_2d();
  test_rotate_to_3d_about_standard_basis();
  test_rotate_to_3d_about_not_standard_basis_vector();
  test_rotate_by_2d();
  test_rotate_by_3d_about_standard_basis();
  test_scale_by_2d();

  return true;
}
