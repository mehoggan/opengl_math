#include "opengl_math/math/numbers.h"
#include "opengl_math/matrices/type_matrix_2X2.h"
#include "opengl_math/matrices/type_matrix_3X3.h"
#include "opengl_math/matrices/type_matrix_4X4.h"
#include "opengl_math/primitives/vectors/type_vector_2d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"
#include "opengl_math/primitives/vectors/type_vector_4d.h"

#include "suite.h"

#include <check.h>

namespace internal
{
  /*! \brief NOTE that all tests assume that the operator[] for both
   * vector_Nd and matrix_NXN work correctly.
   */
  class matrix_tester
  {
  public:
    /*
    * Start of helper functions
    */
    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_addition(
      const opengl_math::matrix_2X2<T, ML> &m1,
      const opengl_math::matrix_2X2<T, ML> &m2,
      bool self_add = false)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp;
      if (self_add) {
        tmp = m1;
        tmp += m2;
      } else {
        tmp = m1 + m2;
      }

      for (int i = 0; i < (2 * 2); ++i) {
        float tval = (m1[i / 2][i % 2] + m2[i / 2][i % 2]);
        ret &= (tmp[i / 2][i % 2] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_addition(
      const opengl_math::matrix_3X3<T, ML> &m1,
      const opengl_math::matrix_3X3<T, ML> &m2,
      bool self_add = false)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp;
      if (self_add) {
        tmp = m1;
        tmp += m2;
      } else {
        tmp = m1 + m2;
      }

      for (int i = 0; i < (3 * 3); ++i) {
        float tval = (m1[i / 3][i % 3] + m2[i / 3][i % 3]);
        ret &= (tmp[i / 3][i % 3] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_addition(
      const opengl_math::matrix_4X4<T, ML> &m1,
      const opengl_math::matrix_4X4<T, ML> &m2,
      bool self_add = false)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp;
      if (self_add) {
        tmp = m1;
        tmp += m2;
      } else {
        tmp = m1 + m2;
      }

      for (int i = 0; i < (4 * 4); ++i) {
        float tval = (m1[i / 4][i % 4] + m2[i / 4][i % 4]);
        ret &= (tmp[i / 4][i % 4] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_subtraction(
      const opengl_math::matrix_2X2<T, ML> &m1,
      const opengl_math::matrix_2X2<T, ML> &m2,
      bool self_sub = false)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp;
      if (self_sub) {
        tmp = m1;
        tmp -= m2;
      } else {
        tmp = m1 - m2;
      }

      for (int i = 0; i < (2 * 2); ++i) {
        float tval = (m1[i / 2][i % 2] - m2[i / 2][i % 2]);
        ret &= (tmp[i / 2][i % 2] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_subtraction(
      const opengl_math::matrix_3X3<T, ML> &m1,
      const opengl_math::matrix_3X3<T, ML> &m2,
      bool self_sub = false)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp;
      if (self_sub) {
        tmp = m1;
        tmp -= m2;
      } else {
        tmp = m1 - m2;
      }

      for (int i = 0; i < (3 * 3); ++i) {
        float tval = (m1[i / 3][i % 3] - m2[i / 3][i % 3]);
        ret &= (tmp[i / 3][i % 3] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_subtraction(
      const opengl_math::matrix_4X4<T, ML> &m1,
      const opengl_math::matrix_4X4<T, ML> &m2,
      bool self_sub = false)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp;
      if (self_sub) {
        tmp = m1;
        tmp -= m2;
      } else {
        tmp = m1 - m2;
      }

      for (int i = 0; i < (4 * 4); ++i) {
        float tval = (m1[i / 4][i % 4] - m2[i / 4][i % 4]);
        ret &= (tmp[i / 4][i % 4] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_scalar_matrix_multiplication(
      const opengl_math::matrix_2X2<T, ML> &m1, const T &scalar,
      bool self_scale)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp;
      if (self_scale) {
        tmp = m1;
        tmp *= scalar;
      } else {
        tmp = scalar * tmp;
      }

      for (int i = 0; i < 2 * 2; ++i) {
        float tval = (m1[i / 2][i % 2] * scalar);
        ret &= (tmp[i / 2][i % 2] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_scalar_matrix_multiplication(
      const opengl_math::matrix_3X3<T, ML> &m1, const T &scalar,
      bool self_scale)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp;
      if (self_scale) {
        tmp = m1;
        tmp *= scalar;
      } else {
        tmp = scalar * tmp;
      }

      for (int i = 0; i < 3 * 3; ++i) {
        float tval = (m1[i / 3][i % 3] * scalar);
        ret &= (tmp[i / 3][i % 3] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_scalar_matrix_multiplication(
      const opengl_math::matrix_4X4<T, ML> &m1, const T &scalar,
      bool self_scale)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp;
      if (self_scale) {
        tmp = m1;
        tmp *= scalar;
      } else {
        tmp = scalar * tmp;
      }

      for (int i = 0; i < 4 * 4; ++i) {
        float tval = (m1[i / 4][i % 4] * scalar);
        ret &= (tmp[i / 4][i % 4] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_multiplication(
      const opengl_math::matrix_2X2<T, ML> &m1,
      const opengl_math::matrix_2X2<T, ML> &m2,
      bool self_mult = false)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp;
      if (self_mult) {
        tmp = m1;
        tmp *= m2;
      } else {
        tmp = m1 * m2;
      }

      // Matrix Mult is m[row] * m[col]. Let i and k represent
      // these abstract concepts.
      for (unsigned short j = 0; j < 2; ++j) { // row
        for (unsigned short k = 0; k < 2; ++k) { // col
          T val(0);
          for (unsigned short i = 0; i < 2; ++i) {
            // Dot Product
            if (ML == opengl_math::column) {
              // [col][row]
              val += (m1[i][j] * m2[k][i]);
            } else {
              // [row][col]
              val += (m1[j][i] * m2[i][k]);
            }
          }
          if (ML == opengl_math::column) {
            ret &= (tmp[k][j] == val);
          } else {
            ret &= (tmp[j][k] == val);
          }
        }
      }
      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_multiplication(
      const opengl_math::matrix_3X3<T, ML> &m1,
      const opengl_math::matrix_3X3<T, ML> &m2,
      bool self_mult = false)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp;
      if (self_mult) {
        tmp = m1;
        tmp *= m2;
      } else {
        tmp = m1 * m2;
      }

      // Matrix Mult is m[row] * m[col]. Let i and k represent
      // these abstract concepts.
      for (unsigned short j = 0; j < 3; ++j) { // row
        for (unsigned short k = 0; k < 3; ++k) { // col
          T val(0);
          for (unsigned short i = 0; i < 3; ++i) {
            // Dot Product
            if (ML == opengl_math::column) {
              // [col][row]
              val += (m1[i][j] * m2[k][i]);
            } else {
              // [row][col]
              val += (m1[j][i] * m2[i][k]);
            }
          }
          if (ML == opengl_math::column) {
            ret &= (tmp[k][j] == val);
          } else {
            ret &= (tmp[j][k] == val);
          }
        }
      }
      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_multiplication(
      const opengl_math::matrix_4X4<T, ML> &m1,
      const opengl_math::matrix_4X4<T, ML> &m2,
      bool self_mult = false)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp;
      if (self_mult) {
        tmp = m1;
        tmp *= m2;
      } else {
        tmp = m1 * m2;
      }

      // Matrix Mult is m[row] * m[col]. Let i and k represent
      // these abstract concepts.
      for (unsigned short j = 0; j < 4; ++j) { // row
        for (unsigned short k = 0; k < 4; ++k) { // col
          T val(0);
          for (unsigned short i = 0; i < 4; ++i) {
            // Dot Product
            if (ML == opengl_math::column) {
              // [col][row]
              val += (m1[i][j] * m2[k][i]);
            } else {
              // [row][col]
              val += (m1[j][i] * m2[i][k]);
            }
          }
          if (ML == opengl_math::column) {
            ret &= (tmp[k][j] == val);
          } else {
            ret &= (tmp[j][k] == val);
          }
        }
      }
      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_vector_multiplication(
      const opengl_math::matrix_2X2<T, ML> &m1,
      const opengl_math::vector_2d<T> &v1)
    {
      bool ret = true;

      opengl_math::vector_2d<float> tmp = m1 * v1;
      for (int i = 0; i < 2; ++i) {
        if (ML == opengl_math::column) {
          ret &= (opengl_math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i]), 1e-006f));
        } else {
          ret &= (opengl_math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i]), 1e-006f));
        }
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_vector_multiplication(
      const opengl_math::matrix_3X3<T, ML> &m1,
      const opengl_math::vector_3d<T> &v1)
    {
      bool ret = true;

      opengl_math::vector_3d<float> tmp = m1 * v1;
      for (int i = 0; i < 3; ++i) {
        if (ML == opengl_math::column) {
          ret &= (opengl_math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i] + v1[2] * m1[2][i]),
            1e-006f));
        } else {
          ret &= (opengl_math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i] + v1[2] * m1[2][i]),
            1e-006f));
        }
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_matrix_vector_multiplication(
      const opengl_math::matrix_4X4<T, ML> &m1,
      const opengl_math::vector_4d<T> &v1)
    {
      bool ret = true;

      opengl_math::vector_4d<float> tmp = m1 * v1;
      for (int i = 0; i < 3; ++i) {
        if (ML == opengl_math::column) {
          ret &= (opengl_math::float_equals(tmp[i],
            (v1[0] * m1[0][i] +
            v1[1] * m1[1][i] +
            v1[2] * m1[2][i] +
            v1[3] * m1[3][i]), 1e-006f));
        } else {
          ret &= (opengl_math::float_equals(tmp[i],
            (v1[0] * m1[0][i] +
            v1[1] * m1[1][i] +
            v1[2] * m1[2][i] +
            v1[3] * m1[3][i]), 1e-006f));
        }
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_inverse(const opengl_math::matrix_2X2<T, ML> &m1)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp = -m1;
      for (int i = 0; i < (2 * 2); ++i) {
        float tval = -m1[i / 2][i % 2];
        ret &= (tmp[i / 2][i % 2] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_inverse(const opengl_math::matrix_3X3<T, ML> &m1)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp = -m1;
      for (int i = 0; i < (3 * 3); ++i) {
        float tval = -m1[i / 3][i % 3];
        ret &= (tmp[i / 3][i % 3] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_inverse(const opengl_math::matrix_4X4<T, ML> &m1)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp = -m1;
      for (int i = 0; i < (4 * 4); ++i) {
        float tval = -m1[i / 4][i % 4];
        ret &= (tmp[i / 4][i % 4] == tval);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_inversion(const opengl_math::matrix_2X2<T, ML> &m1,
      const opengl_math::matrix_2X2<T, ML> &expected,
      bool member_invert,
      T epsilon = 1e-8)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp;
      if (member_invert) {
        tmp = m1;
        tmp.inverse();
      } else {
        tmp = m1.inversion();
      }

      for (unsigned int i = 0; i < (2 * 2); ++i) {
        T test = tmp[i / 2][i % 2];
        T expe = expected[i / 2][i % 2];
        T diff = std::abs(test - expe);
        ret &= (diff < epsilon);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_inversion(const opengl_math::matrix_3X3<T, ML> &m1,
      const opengl_math::matrix_3X3<T, ML> &expected,
      bool member_invert,
      T epsilon = 1e-8)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp;
      if (member_invert) {
        tmp = m1;
        tmp.inverse();
      } else {
        tmp = m1.inversion();
      }

      for (unsigned int i = 0; i < (3 * 3); ++i) {
        T test = tmp[i / 3][i % 3];
        T expe = expected[i / 3][i % 3];
        T diff = std::abs(test - expe);
        ret &= (diff < epsilon);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_inversion(const opengl_math::matrix_4X4<T, ML> &m1,
      const opengl_math::matrix_4X4<T, ML> &expected,
      bool member_invert,
      T epsilon = 1e-8)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp;
      if (member_invert) {
        tmp = m1;
        tmp.inverse();
      } else {
        tmp = m1.inversion();
      }

      for (unsigned int i = 0; i < (4 * 4); ++i) {
        T test = tmp[i / 4][i % 4];
        T expe = expected[i / 4][i % 4];
        T diff = std::abs(test - expe);
        ret &= (diff < epsilon);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_transpose(const opengl_math::matrix_2X2<T, ML> &m1,
      bool member_trans)
    {
      bool ret = true;

      opengl_math::matrix_2X2<T, ML> tmp;
      if (member_trans) {
        tmp = m1;
        tmp.transpose();
      } else {
        tmp = m1.transposed();
      }

      for (int i = 0; i < 2 * 2; ++i) {
        ret &= (tmp[i / 2][i % 2] == m1[i % 2][i / 2]);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_transpose(const opengl_math::matrix_3X3<T, ML> &m1,
      bool member_trans)
    {
      bool ret = true;

      opengl_math::matrix_3X3<T, ML> tmp;
      if (member_trans) {
        tmp = m1;
        tmp.transpose();
      } else {
        tmp = m1.transposed();
      }

      for (int i = 0; i < 3 * 3; ++i) {
        ret &= (tmp[i / 3][i % 3] == m1[i % 3][i / 3]);
      }

      return ret;
    }

    template <typename T, opengl_math::matrix_layout ML>
    static bool test_transpose(const opengl_math::matrix_4X4<T, ML> &m1,
      bool member_trans)
    {
      bool ret = true;

      opengl_math::matrix_4X4<T, ML> tmp;
      if (member_trans) {
        tmp = m1;
        tmp.transpose();
      } else {
        tmp = m1.transposed();
      }

      for (int i = 0; i < 4 * 4; ++i) {
        ret &= (tmp[i / 4][i % 4] == m1[i % 4][i / 4]);
      }

      return ret;
    }
  };
}

/*! \brief This is a test for the default ctor in the matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_default_matrix_2X2_constructor)
{
  opengl_math::matrix_2X2<float, opengl_math::column> m1;
  ck_assert(m1[0] == opengl_math::vector_2d<float>());
  ck_assert(m1[1] == opengl_math::vector_2d<float>());

  opengl_math::matrix_2X2<float, opengl_math::row> m2;
  ck_assert(m2[0] == opengl_math::vector_2d<float>());
  ck_assert(m2[1] == opengl_math::vector_2d<float>());

  opengl_math::matrix_2X2<double, opengl_math::column> m3;
  ck_assert(m3[0] == opengl_math::vector_2d<double>());
  ck_assert(m3[1] == opengl_math::vector_2d<double>());

  opengl_math::matrix_2X2<double, opengl_math::row> m4;
  ck_assert(m4[0] == opengl_math::vector_2d<double>());
  ck_assert(m4[1] == opengl_math::vector_2d<double>());
}
END_TEST

START_TEST(test_default_matrix_3X3_constructor)
{
  opengl_math::matrix_3X3<float, opengl_math::column> m1;
  ck_assert(m1[0] == opengl_math::vector_3d<float>());
  ck_assert(m1[1] == opengl_math::vector_3d<float>());
  ck_assert(m1[2] == opengl_math::vector_3d<float>());

  opengl_math::matrix_3X3<float, opengl_math::row> m2;
  ck_assert(m2[0] == opengl_math::vector_3d<float>());
  ck_assert(m2[1] == opengl_math::vector_3d<float>());
  ck_assert(m2[2] == opengl_math::vector_3d<float>());

  opengl_math::matrix_3X3<double, opengl_math::column> m3;
  ck_assert(m3[0] == opengl_math::vector_3d<double>());
  ck_assert(m3[1] == opengl_math::vector_3d<double>());
  ck_assert(m3[2] == opengl_math::vector_3d<double>());

  opengl_math::matrix_3X3<double, opengl_math::row> m4;
  ck_assert(m4[0] == opengl_math::vector_3d<double>());
  ck_assert(m4[1] == opengl_math::vector_3d<double>());
  ck_assert(m4[2] == opengl_math::vector_3d<double>());
}
END_TEST

START_TEST(test_default_matrix_4X4_constructor)
{
  opengl_math::matrix_4X4<float, opengl_math::column> m1;
  ck_assert(m1[0] == opengl_math::vector_4d<float>());
  ck_assert(m1[1] == opengl_math::vector_4d<float>());
  ck_assert(m1[2] == opengl_math::vector_4d<float>());
  ck_assert(m1[3] == opengl_math::vector_4d<float>());

  opengl_math::matrix_4X4<float, opengl_math::row> m2;
  ck_assert(m2[0] == opengl_math::vector_4d<float>());
  ck_assert(m2[1] == opengl_math::vector_4d<float>());
  ck_assert(m2[2] == opengl_math::vector_4d<float>());
  ck_assert(m2[3] == opengl_math::vector_4d<float>());

  opengl_math::matrix_4X4<double, opengl_math::column> m3;
  ck_assert(m3[0] == opengl_math::vector_4d<double>());
  ck_assert(m3[1] == opengl_math::vector_4d<double>());
  ck_assert(m3[2] == opengl_math::vector_4d<double>());
  ck_assert(m3[3] == opengl_math::vector_4d<double>());

  opengl_math::matrix_4X4<double, opengl_math::row> m4;
  ck_assert(m4[0] == opengl_math::vector_4d<double>());
  ck_assert(m4[1] == opengl_math::vector_4d<double>());
  ck_assert(m4[2] == opengl_math::vector_4d<double>());
  ck_assert(m4[3] == opengl_math::vector_4d<double>());
}
END_TEST

/*! \brief This is a test for the default ctor in the matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes which takes the identity flag
*/
START_TEST(test_matrix_2X2_identity_constructor)
{
  opengl_math::matrix_2X2<float, opengl_math::column> m1(
    opengl_math::identity);
  ck_assert(m1[0] == opengl_math::vector_2d<float>(1.0f, 0.0f));
  ck_assert(m1[1] == opengl_math::vector_2d<float>(0.0f, 1.0f));

  opengl_math::matrix_2X2<float, opengl_math::row> m2(opengl_math::identity);
  ck_assert(m2[0] == opengl_math::vector_2d<float>(1.0f, 0.0f));
  ck_assert(m2[1] == opengl_math::vector_2d<float>(0.0f, 1.0f));

  opengl_math::matrix_2X2<double, opengl_math::column> m3(
    opengl_math::identity);
  ck_assert(m3[0] == opengl_math::vector_2d<double>(1.0, 0.0));
  ck_assert(m3[1] == opengl_math::vector_2d<double>(0.0, 1.0));

  opengl_math::matrix_2X2<double, opengl_math::row> m4(
    opengl_math::identity);
  ck_assert(m4[0] == opengl_math::vector_2d<double>(1.0, 0.0));
  ck_assert(m4[1] == opengl_math::vector_2d<double>(0.0, 1.0));
}
END_TEST

START_TEST(test_matrix_3X3_identity_constructor)
{
  opengl_math::matrix_3X3<float, opengl_math::column> m1(
    opengl_math::identity);
  ck_assert(m1[0] == opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f));
  ck_assert(m1[1] == opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));
  ck_assert(m1[2] == opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f));

  opengl_math::matrix_3X3<float, opengl_math::row> m2(opengl_math::identity);
  ck_assert(m2[0] == opengl_math::vector_3d<float>(1.0f, 0.0f, 0.0f));
  ck_assert(m2[1] == opengl_math::vector_3d<float>(0.0f, 1.0f, 0.0f));
  ck_assert(m2[2] == opengl_math::vector_3d<float>(0.0f, 0.0f, 1.0f));

  opengl_math::matrix_3X3<double, opengl_math::column> m3(
    opengl_math::identity);
  ck_assert(m3[0] == opengl_math::vector_3d<double>(1.0, 0.0, 0.0));
  ck_assert(m3[1] == opengl_math::vector_3d<double>(0.0, 1.0, 0.0));
  ck_assert(m3[2] == opengl_math::vector_3d<double>(0.0, 0.0, 1.0));

  opengl_math::matrix_3X3<double, opengl_math::row> m4(
    opengl_math::identity);
  ck_assert(m4[0] == opengl_math::vector_3d<double>(1.0, 0.0, 0.0));
  ck_assert(m4[1] == opengl_math::vector_3d<double>(0.0, 1.0, 0.0));
  ck_assert(m4[2] == opengl_math::vector_3d<double>(0.0, 0.0, 1.0));
}
END_TEST

START_TEST(test_matrix_4X4_identity_constructor)
{
  opengl_math::matrix_4X4<float, opengl_math::column> m1(
    opengl_math::identity);
  ck_assert(m1[0] == opengl_math::vector_4d<float>(
    1.0f, 0.0f, 0.0f, 0.0f));
  ck_assert(m1[1] == opengl_math::vector_4d<float>(
    0.0f, 1.0f, 0.0f, 0.0f));
  ck_assert(m1[2] == opengl_math::vector_4d<float>(
    0.0f, 0.0f, 1.0f, 0.0f));
  ck_assert(m1[3] == opengl_math::vector_4d<float>(
    0.0f, 0.0f, 0.0f, 1.0f));

  opengl_math::matrix_4X4<float, opengl_math::row> m2(opengl_math::identity);
  ck_assert(m2[0] == opengl_math::vector_4d<float>(
    1.0f, 0.0f, 0.0f, 0.0f));
  ck_assert(m2[1] == opengl_math::vector_4d<float>(
    0.0f, 1.0f, 0.0f, 0.0f));
  ck_assert(m2[2] == opengl_math::vector_4d<float>(
    0.0f, 0.0f, 1.0f, 0.0f));
  ck_assert(m2[3] == opengl_math::vector_4d<float>(
    0.0f, 0.0f, 0.0f, 1.0f));

  opengl_math::matrix_4X4<double, opengl_math::column> m3(
    opengl_math::identity);
  ck_assert(m3[0] == opengl_math::vector_4d<double>(
    1.0f, 0.0f, 0.0f, 0.0f));
  ck_assert(m3[1] == opengl_math::vector_4d<double>(
    0.0f, 1.0f, 0.0f, 0.0f));
  ck_assert(m3[2] == opengl_math::vector_4d<double>(
    0.0f, 0.0f, 1.0f, 0.0f));
  ck_assert(m3[3] == opengl_math::vector_4d<double>(
    0.0f, 0.0f, 0.0f, 1.0f));

  opengl_math::matrix_4X4<double, opengl_math::row> m4(
    opengl_math::identity);
  ck_assert(m4[0] == opengl_math::vector_4d<double>(
    1.0f, 0.0f, 0.0f, 0.0f));
  ck_assert(m4[1] == opengl_math::vector_4d<double>(
    0.0f, 1.0f, 0.0f, 0.0f));
  ck_assert(m4[2] == opengl_math::vector_4d<double>(
    0.0f, 0.0f, 1.0f, 0.0f));
  ck_assert(m4[3] == opengl_math::vector_4d<double>(
    0.0f, 0.0f, 0.0f, 1.0f));
}
END_TEST

/*! \brief This is a test for the ctor in the matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes with can be constructed
* from the vector family of classes.
*/
START_TEST(test_matrix_2X2_vector_constructor)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_2X2<float, opengl_math::column> m1(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  ck_assert(m1[0] == opengl_math::vector_2d<float>(rand1, rand2));
  ck_assert(m1[1] == opengl_math::vector_2d<float>(rand2, rand1));

  opengl_math::matrix_2X2<float, opengl_math::row> m2(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  ck_assert(m2[0] == opengl_math::vector_2d<float>(rand1, rand2));
  ck_assert(m2[1] == opengl_math::vector_2d<float>(rand2, rand1));

  double rand3 = static_cast<double>(std::rand() / std::rand());
  double rand4 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_2X2<double, opengl_math::column> m3(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  ck_assert(m3[0] == opengl_math::vector_2d<double>(rand3, rand4));
  ck_assert(m3[1] == opengl_math::vector_2d<double>(rand4, rand3));

  opengl_math::matrix_2X2<double, opengl_math::row> m4(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  ck_assert(m4[0] == opengl_math::vector_2d<double>(rand3, rand4));
  ck_assert(m4[1] == opengl_math::vector_2d<double>(rand4, rand3));
}
END_TEST

START_TEST(test_matrix_3X3_vector_constructor)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_3X3<float, opengl_math::column> m1(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  ck_assert(m1[0] ==
    opengl_math::vector_3d<float>(rand1, rand2, rand3));
  ck_assert(m1[1] ==
    opengl_math::vector_3d<float>(rand2, rand3, rand1));
  ck_assert(m1[2] ==
    opengl_math::vector_3d<float>(rand3, rand1, rand2));

  opengl_math::matrix_3X3<float, opengl_math::row> m2(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  ck_assert(m2[0] ==
    opengl_math::vector_3d<float>(rand1, rand2, rand3));
  ck_assert(m2[1] ==
    opengl_math::vector_3d<float>(rand2, rand3, rand1));
  ck_assert(m2[2] ==
    opengl_math::vector_3d<float>(rand3, rand1, rand2));

  double rand4 = static_cast<double>(std::rand() / std::rand());
  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_3X3<double, opengl_math::column> m3(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  ck_assert(m3[0] ==
    opengl_math::vector_3d<double>(rand4, rand5, rand6));
  ck_assert(m3[1] ==
    opengl_math::vector_3d<double>(rand5, rand6, rand4));
  ck_assert(m3[2] ==
    opengl_math::vector_3d<double>(rand6, rand4, rand5));

  opengl_math::matrix_3X3<double, opengl_math::row> m4(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  ck_assert(m4[0] ==
    opengl_math::vector_3d<double>(rand4, rand5, rand6));
  ck_assert(m4[1] ==
    opengl_math::vector_3d<double>(rand5, rand6, rand4));
  ck_assert(m4[2] ==
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
}
END_TEST

START_TEST(test_matrix_4X4_vector_constructor)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());
  float rand4 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_4X4<float, opengl_math::column> m1(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  ck_assert(m1[0] ==
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4));
  ck_assert(m1[1] ==
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1));
  ck_assert(m1[2] ==
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2));
  ck_assert(m1[3] ==
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));

  opengl_math::matrix_4X4<float, opengl_math::row> m2(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  ck_assert(m2[0] ==
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4));
  ck_assert(m2[1] ==
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1));
  ck_assert(m2[2] ==
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2));
  ck_assert(m2[3] ==
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));

  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());
  double rand7 = static_cast<double>(std::rand() / std::rand());
  double rand8 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_4X4<double, opengl_math::column> m3(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  ck_assert(m3[0] ==
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8));
  ck_assert(m3[1] ==
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5));
  ck_assert(m3[2] ==
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6));
  ck_assert(m3[3] ==
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));

  opengl_math::matrix_4X4<double, opengl_math::row> m4(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  ck_assert(m4[0] ==
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8));
  ck_assert(m4[1] ==
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5));
  ck_assert(m4[2] ==
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6));
  ck_assert(m4[3] ==
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
}
END_TEST

/*! \brief This is a test for the copy ctor in the matrix_2X2 and
* matrix 3X3 matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_copy_constructor)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_2X2<float, opengl_math::column> m1(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  opengl_math::matrix_2X2<float, opengl_math::column> m1_copy(m1);
  ck_assert(m1 == m1_copy);
  ck_assert(!(m1 != m1_copy));

  opengl_math::matrix_2X2<float, opengl_math::row> m2(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  opengl_math::matrix_2X2<float, opengl_math::row> m2_copy(m2);
  ck_assert(m2 == m2_copy);
  ck_assert(!(m2 != m2_copy));

  double rand3 = static_cast<double>(std::rand() / std::rand());
  double rand4 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_2X2<double, opengl_math::column> m3(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  opengl_math::matrix_2X2<double, opengl_math::column> m3_copy(m3);
  ck_assert(m3 == m3_copy);
  ck_assert(!(m3 != m3_copy));

  opengl_math::matrix_2X2<double, opengl_math::row> m4(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  opengl_math::matrix_2X2<double, opengl_math::row> m4_copy(m4);
  ck_assert(m4 == m4_copy);
  ck_assert(!(m4 != m4_copy));
}
END_TEST

START_TEST(test_matrix_3X3_copy_constructor)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_3X3<float, opengl_math::column> m1(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  opengl_math::matrix_3X3<float, opengl_math::column> m1_copy(m1);
  ck_assert(m1 == m1_copy);
  ck_assert(!(m1 != m1_copy));

  opengl_math::matrix_3X3<float, opengl_math::row> m2(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  opengl_math::matrix_3X3<float, opengl_math::row> m2_copy(m2);
  ck_assert(m2 == m2_copy);
  ck_assert(!(m2 != m2_copy));

  double rand4 = static_cast<double>(std::rand() / std::rand());
  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_3X3<double, opengl_math::column> m3(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  opengl_math::matrix_3X3<double, opengl_math::column> m3_copy(m3);
  ck_assert(m3 == m3_copy);
  ck_assert(!(m3 != m3_copy));

  opengl_math::matrix_3X3<double, opengl_math::row> m4(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  opengl_math::matrix_3X3<double, opengl_math::row> m4_copy(m4);
  ck_assert(m4 == m4_copy);
  ck_assert(!(m4 != m4_copy));
}
END_TEST

START_TEST(test_matrix_4X4_copy_constructor)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());
  float rand4 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_4X4<float, opengl_math::column> m1(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  opengl_math::matrix_4X4<float, opengl_math::column> m1_copy(m1);
  ck_assert(m1 == m1_copy);
  ck_assert(!(m1 != m1_copy));

  opengl_math::matrix_4X4<float, opengl_math::row> m2(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  opengl_math::matrix_4X4<float, opengl_math::row> m2_copy(m2);
  ck_assert(m2 == m2_copy);
  ck_assert(!(m2 != m2_copy));

  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());
  double rand7 = static_cast<double>(std::rand() / std::rand());
  double rand8 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_4X4<double, opengl_math::column> m3(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  opengl_math::matrix_4X4<double, opengl_math::column> m3_copy(m3);
  ck_assert(m3 == m3_copy);
  ck_assert(!(m3 != m3_copy));

  opengl_math::matrix_4X4<double, opengl_math::row> m4(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  opengl_math::matrix_4X4<double, opengl_math::row> m4_copy(m4);
  ck_assert(m4 == m4_copy);
  ck_assert(!(m4 != m4_copy));
}
END_TEST

/*! \brief This is a test for the assignment operator in the matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_copy_assignment_operator)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_2X2<float, opengl_math::column> m1(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  opengl_math::matrix_2X2<float, opengl_math::column> m1_copy;
  m1_copy = m1;
  ck_assert(m1 == m1_copy);
  ck_assert(!(m1 != m1_copy));

  opengl_math::matrix_2X2<float, opengl_math::row> m2(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  opengl_math::matrix_2X2<float, opengl_math::row> m2_copy;
  m2_copy = m2;
  ck_assert(m2 == m2_copy);
  ck_assert(!(m2 != m2_copy));

  double rand3 = static_cast<double>(std::rand() / std::rand());
  double rand4 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_2X2<double, opengl_math::column> m3(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  opengl_math::matrix_2X2<double, opengl_math::column> m3_copy;
  m3_copy = m3;
  ck_assert(m3 == m3_copy);
  ck_assert(!(m3 != m3_copy));

  opengl_math::matrix_2X2<double, opengl_math::row> m4(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  opengl_math::matrix_2X2<double, opengl_math::row> m4_copy;
  m4_copy = m4;
  ck_assert(m4 == m4_copy);
  ck_assert(!(m4 != m4_copy));
}
END_TEST

START_TEST(test_matrix_3X3_copy_assignment_operator)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_3X3<float, opengl_math::column> m1(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  opengl_math::matrix_3X3<float, opengl_math::column> m1_copy;
  m1_copy = m1;
  ck_assert(m1 == m1_copy);
  ck_assert(!(m1 != m1_copy));

  opengl_math::matrix_3X3<float, opengl_math::row> m2(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  opengl_math::matrix_3X3<float, opengl_math::row> m2_copy;
  m2_copy = m2;
  ck_assert(m2 == m2_copy);
  ck_assert(!(m2 != m2_copy));

  double rand4 = static_cast<double>(std::rand() / std::rand());
  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_3X3<double, opengl_math::column> m3(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  opengl_math::matrix_3X3<double, opengl_math::column> m3_copy;
  m3_copy = m3;
  ck_assert(m3 == m3_copy);
  ck_assert(!(m3 != m3_copy));

  opengl_math::matrix_3X3<double, opengl_math::row> m4(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  opengl_math::matrix_3X3<double, opengl_math::row> m4_copy;
  m4_copy = m4;
  ck_assert(m4 == m4_copy);
  ck_assert(!(m4 != m4_copy));
}
END_TEST

START_TEST(test_matrix_4X4_copy_assignment_operator)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());
  float rand4 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_4X4<float, opengl_math::column> m1(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  opengl_math::matrix_4X4<float, opengl_math::column> m1_copy;
  m1_copy = m1;
  ck_assert(m1 == m1_copy);
  ck_assert(!(m1 != m1_copy));

  opengl_math::matrix_4X4<float, opengl_math::row> m2(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  opengl_math::matrix_4X4<float, opengl_math::row> m2_copy;
  m2_copy = m2;
  ck_assert(m2 == m2_copy);
  ck_assert(!(m2 != m2_copy));

  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());
  double rand7 = static_cast<double>(std::rand() / std::rand());
  double rand8 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_4X4<double, opengl_math::column> m3(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  opengl_math::matrix_4X4<double, opengl_math::column> m3_copy;
  m3_copy = m3;
  ck_assert(m3 == m3_copy);
  ck_assert(!(m3 != m3_copy));

  opengl_math::matrix_4X4<double, opengl_math::row> m4(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  opengl_math::matrix_4X4<double, opengl_math::row> m4_copy;
  m4_copy = m4;
  ck_assert(m4 == m4_copy);
  ck_assert(!(m4 != m4_copy));
}
END_TEST

/*! \brief This is a test for the setters in the matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_setters)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_2X2<float, opengl_math::column> m1(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  m1.vec0(m1.vec1());
  ck_assert(m1.vec0() == m1.vec1());
  ck_assert(m1.vec1() == opengl_math::vector_2d<float>(rand2, rand1));

  opengl_math::matrix_2X2<float, opengl_math::row> m2(
    opengl_math::vector_2d<float>(rand1, rand2),
    opengl_math::vector_2d<float>(rand2, rand1));
  m2.vec1(m2.vec0());
  ck_assert(m2.vec0() == opengl_math::vector_2d<float>(rand1, rand2));
  ck_assert(m2.vec1() == m2.vec0());

  double rand3 = static_cast<double>(std::rand() / std::rand());
  double rand4 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_2X2<double, opengl_math::column> m3(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  m3.vec1(m3.vec0());
  ck_assert(m3.vec0() == 
    opengl_math::vector_2d<double>(rand3, rand4));
  ck_assert(m3.vec1() == m3.vec0());

  opengl_math::matrix_2X2<double, opengl_math::row> m4(
    opengl_math::vector_2d<double>(rand3, rand4),
    opengl_math::vector_2d<double>(rand4, rand3));
  m4.vec0(m4.vec1());
  ck_assert(m4.vec0() == m4.vec1());
  ck_assert(m4.vec1() ==
    opengl_math::vector_2d<double>(rand4, rand3));
}
END_TEST

START_TEST(test_matrix_3X3_setters)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_3X3<float, opengl_math::column> m1(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  m1.vec0(m1.vec1());
  ck_assert(m1.vec0() == m1.vec1());
  ck_assert(m1.vec1() ==
    opengl_math::vector_3d<float>(rand2, rand3, rand1));
  ck_assert(m1.vec2() ==
    opengl_math::vector_3d<float>(rand3, rand1, rand2));

  opengl_math::matrix_3X3<float, opengl_math::row> m2(
    opengl_math::vector_3d<float>(rand1, rand2, rand3),
    opengl_math::vector_3d<float>(rand2, rand3, rand1),
    opengl_math::vector_3d<float>(rand3, rand1, rand2));
  m2.vec1(m2.vec2());
  ck_assert(m2.vec0() == 
    opengl_math::vector_3d<float>(rand1, rand2, rand3));
  ck_assert(m2.vec1() == m2.vec2());
  ck_assert(m2.vec2() ==
    opengl_math::vector_3d<float>(rand3, rand1, rand2));

  double rand4 = static_cast<double>(std::rand() / std::rand());
  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_3X3<double, opengl_math::column> m3(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  m3.vec2(m3.vec0());
  ck_assert(m3.vec0() ==
    opengl_math::vector_3d<double>(rand4, rand5, rand6));
  ck_assert(m3.vec1() ==
    opengl_math::vector_3d<double>(rand5, rand6, rand4));
  ck_assert(m3.vec2() == m3.vec0());

  opengl_math::matrix_3X3<double, opengl_math::row> m4(
    opengl_math::vector_3d<double>(rand4, rand5, rand6),
    opengl_math::vector_3d<double>(rand5, rand6, rand4),
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
  m4.vec0(m4.vec0());
  ck_assert(m4.vec0() == m4.vec0());
  ck_assert(m4.vec1() ==
    opengl_math::vector_3d<double>(rand5, rand6, rand4));
  ck_assert(m4.vec2() ==
    opengl_math::vector_3d<double>(rand6, rand4, rand5));
}
END_TEST

START_TEST(test_matrix_4X4_setters)
{
  std::srand(static_cast<unsigned int>(time(NULL)));

  float rand1 = static_cast<float>(std::rand() / std::rand());
  float rand2 = static_cast<float>(std::rand() / std::rand());
  float rand3 = static_cast<float>(std::rand() / std::rand());
  float rand4 = static_cast<float>(std::rand() / std::rand());

  opengl_math::matrix_4X4<float, opengl_math::column> m1(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  m1.vec0(m1.vec3());
  ck_assert(m1.vec0() == m1.vec3());
  ck_assert(m1.vec1() ==
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1));
  ck_assert(m1.vec2() ==
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2));
  ck_assert(m1.vec3() ==
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));

  opengl_math::matrix_4X4<float, opengl_math::row> m2(
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4),
    opengl_math::vector_4d<float>(rand2, rand3, rand4, rand1),
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2),
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));
  m2.vec1(m2.vec0());
  ck_assert(m2.vec0() ==
    opengl_math::vector_4d<float>(rand1, rand2, rand3, rand4));
  ck_assert(m2.vec1() == m2.vec0());
  ck_assert(m2.vec2() ==
    opengl_math::vector_4d<float>(rand3, rand4, rand1, rand2));
  ck_assert(m2.vec3() ==
    opengl_math::vector_4d<float>(rand4, rand1, rand2, rand3));

  double rand5 = static_cast<double>(std::rand() / std::rand());
  double rand6 = static_cast<double>(std::rand() / std::rand());
  double rand7 = static_cast<double>(std::rand() / std::rand());
  double rand8 = static_cast<double>(std::rand() / std::rand());

  opengl_math::matrix_4X4<double, opengl_math::column> m3(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  m3.vec2(m3.vec0());
  ck_assert(m3.vec0() ==
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8));
  ck_assert(m3.vec1() ==
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5));
  ck_assert(m3.vec2() == m3.vec0());
  ck_assert(m3.vec3() ==
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));

  opengl_math::matrix_4X4<double, opengl_math::row> m4(
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8),
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5),
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6),
    opengl_math::vector_4d<double>(rand8, rand5, rand6, rand7));
  m4.vec3(m4.vec1());
  ck_assert(m4.vec0() ==
    opengl_math::vector_4d<double>(rand5, rand6, rand7, rand8));
  ck_assert(m4.vec1() ==
    opengl_math::vector_4d<double>(rand6, rand7, rand8, rand5));
  ck_assert(m4.vec2() ==
    opengl_math::vector_4d<double>(rand7, rand8, rand5, rand6));
  ck_assert(m4.vec3() == m4.vec1());
}
END_TEST

/*! \brief This is a test for the member addition (+=) of matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_member_addition)
{
  opengl_math::matrix_2X2<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::row> Ir(opengl_math::identity);

  opengl_math::matrix_2X2<float, opengl_math::column> m1;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m1, Ic, true));

  opengl_math::matrix_2X2<float, opengl_math::column> m2;
  opengl_math::matrix_2X2<float, opengl_math::column> I(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m2, Ic, true));
  // Unit test the tester
  ck_assert(m1 == m2);

  opengl_math::matrix_2X2<float, opengl_math::column> m3;
  opengl_math::matrix_2X2<float, opengl_math::column> m4(
    opengl_math::vector_2d<float>(-0.3f, -0.2f),
    opengl_math::vector_2d<float>(0.0f, 0.1f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m3, m4, true));

  m3 = opengl_math::matrix_2X2<float, opengl_math::column>(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m3, m4, true));

  opengl_math::matrix_2X2<float, opengl_math::column> m5(
    opengl_math::vector_2d<float>(std::numeric_limits<float>::max(), 0.0f),
    opengl_math::vector_2d<float>(1.0f, std::numeric_limits<float>::max()));
  opengl_math::matrix_2X2<float, opengl_math::column> m6(
    opengl_math::vector_2d<float>(0.0f, 0.0f),
    opengl_math::vector_2d<float>(1.0f, exp(1.0f)));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m5, m6, true));

  opengl_math::matrix_2X2<float, opengl_math::row> m7;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m7, Ir, true));

  opengl_math::matrix_2X2<float, opengl_math::row> m8;
  opengl_math::matrix_2X2<float, opengl_math::row> rI(opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m8, Ir, true));
  ck_assert(m7 == m8);

  opengl_math::matrix_2X2<float, opengl_math::row> m9;
  opengl_math::matrix_2X2<float, opengl_math::row> m10(
    opengl_math::vector_2d<float>(-0.3f, -0.2f),
    opengl_math::vector_2d<float>(100.0f, -7e-2f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m9, m10, true));

  m9 = opengl_math::matrix_2X2<float, opengl_math::row>(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m9, m10, true));

  opengl_math::matrix_2X2<float, opengl_math::row> m11(
    opengl_math::vector_2d<float>(std::numeric_limits<float>::max(), 0.0f),
    opengl_math::vector_2d<float>(1.0f, std::numeric_limits<float>::max()));
  opengl_math::matrix_2X2<float, opengl_math::row> m12(
    opengl_math::vector_2d<float>(0.0f, 0.0f),
    opengl_math::vector_2d<float>(1.0f, exp(1.0f)));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m11, m12, true));

  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::column> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::row> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, true));
  }
}
END_TEST

START_TEST(test_matrix_3X3_member_addition)
{
  opengl_math::matrix_3X3<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::row> Ir(opengl_math::identity);

  opengl_math::matrix_3X3<float, opengl_math::column> m1;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m1, Ic, true));

  opengl_math::matrix_3X3<float, opengl_math::column> m2;
  opengl_math::matrix_3X3<float, opengl_math::column> I(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m2, Ic, true));
  // Unit test the tester
  ck_assert(m1 == m2);

  opengl_math::matrix_3X3<float, opengl_math::column> m3;
  opengl_math::matrix_3X3<float, opengl_math::column> m4(
    opengl_math::vector_3d<float>(-0.3f, -0.2f, -0.1f),
    opengl_math::vector_3d<float>(0.0f, 0.1f, 0.2f),
    opengl_math::vector_3d<float>(100.0f, -7e-2f, 12.0f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m3, m4, true));

  m3 = opengl_math::matrix_3X3<float, opengl_math::column>(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m3, m4, true));

  opengl_math::matrix_3X3<float, opengl_math::column> m5(
    opengl_math::vector_3d<float>(std::numeric_limits<float>::max(), 0.0f,
      0.4f),
    opengl_math::vector_3d<float>(1.0f, std::numeric_limits<float>::max(),
      0.7f),
    opengl_math::vector_3d<float>(2.0f, 1.1f,
      std::numeric_limits<float>::max() - 0.7f));
  opengl_math::matrix_3X3<float, opengl_math::column> m6(
    opengl_math::vector_3d<float>(0.0f, 0.0f, 0.1f),
    opengl_math::vector_3d<float>(1.0f, exp(1.0f), 0.7f),
    opengl_math::vector_3d<float>(0.1f, static_cast<float>(M_PI), 0.7f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m5, m6, true));

  opengl_math::matrix_3X3<float, opengl_math::row> m7;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m7, Ir, true));

  opengl_math::matrix_3X3<float, opengl_math::row> m8;
  opengl_math::matrix_3X3<float, opengl_math::row> rI(opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m8, Ir, true));
  ck_assert(m7 == m8);

  opengl_math::matrix_3X3<float, opengl_math::row> m9;
  opengl_math::matrix_3X3<float, opengl_math::row> m10(
    opengl_math::vector_3d<float>(-0.3f, -0.2f, -0.1f),
    opengl_math::vector_3d<float>(0.0f, 0.1f, 0.2f),
    opengl_math::vector_3d<float>(100.0f, -7e-2f, 12.0f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m9, m10, true));

  m9 = opengl_math::matrix_3X3<float, opengl_math::row>(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m9, m10, true));

  opengl_math::matrix_3X3<float, opengl_math::row> m11(
    opengl_math::vector_3d<float>(std::numeric_limits<float>::max(), 0.0f,
      0.4f),
    opengl_math::vector_3d<float>(1.0f, std::numeric_limits<float>::max(),
      0.7f),
    opengl_math::vector_3d<float>(2.0f, 1.1f,
      std::numeric_limits<float>::max() - 0.7f));
  opengl_math::matrix_3X3<float, opengl_math::row> m12(
    opengl_math::vector_3d<float>(0.0f, 0.0f, 0.1f),
    opengl_math::vector_3d<float>(1.0f, exp(1.0f), 0.7f),
    opengl_math::vector_3d<float>(0.1f, static_cast<float>(M_PI), 0.7f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m11, m12, true));

  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::column> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::row> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, true));
  }
}
END_TEST

START_TEST(test_matrix_4X4_member_addition)
{
  opengl_math::matrix_4X4<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::row> Ir(opengl_math::identity);

  opengl_math::matrix_4X4<float, opengl_math::column> m1;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m1, Ic, true));

  opengl_math::matrix_4X4<float, opengl_math::column> m2;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m2, Ic, true));
  ck_assert(m1 == m2);

  opengl_math::matrix_4X4<float, opengl_math::column> m3;
  opengl_math::matrix_4X4<float, opengl_math::column> m4(
    opengl_math::vector_4d<float>(-0.3f, -0.2f, -0.1f, 0.0f),
    opengl_math::vector_4d<float>(0.0f, 0.1f, 0.2f, 0.1f),
    opengl_math::vector_4d<float>(100.0f, -7e-2f, 12.0f, 100.0f),
    opengl_math::vector_4d<float>(100.0f, 7e-2f, -12.0f, -100.0f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m3, m4, true));

  m3 = opengl_math::matrix_4X4<float, opengl_math::column>(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m3, m4, true));
  ck_assert(m3 != m4);

  opengl_math::matrix_4X4<float, opengl_math::column> m5(
    opengl_math::vector_4d<float>(std::numeric_limits<float>::max(), 0.0f,
      0.4f, 1.4f),
    opengl_math::vector_4d<float>(1.0f, std::numeric_limits<float>::max(),
      0.7f, 2.4f),
    opengl_math::vector_4d<float>(2.0f, 1.1f,
      std::numeric_limits<float>::max() - 0.7f, 3.4f),
    opengl_math::vector_4d<float>(2.0f, 1.1f,
      std::numeric_limits<float>::max() - 0.7f, 5.4f));
  opengl_math::matrix_4X4<float, opengl_math::column> m6(
    opengl_math::vector_4d<float>(0.0f, 0.0f, 0.1f, 2.00f),
    opengl_math::vector_4d<float>(1.0f, exp(1.0f), 0.7f, 1.00f),
    opengl_math::vector_4d<float>(0.1f, static_cast<float>(M_PI), 0.7f,
      3.0f),
    opengl_math::vector_4d<float>(0.1f, static_cast<float>(M_PI), 0.7f,
      3.0f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m5, m6, true));

  opengl_math::matrix_4X4<float, opengl_math::row> m7;
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m7, Ir, true));

  opengl_math::matrix_4X4<float, opengl_math::row> m8;
  opengl_math::matrix_4X4<float, opengl_math::row> rI(opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m8, Ir, true));
  ck_assert(m7 == m8);

  opengl_math::matrix_4X4<float, opengl_math::row> m9;
  opengl_math::matrix_4X4<float, opengl_math::row> m10(
    opengl_math::vector_4d<float>(-0.3f, -0.2f, -0.1f, 0.1f),
    opengl_math::vector_4d<float>(0.0f, 0.1f, 0.2f, 0.1f),
    opengl_math::vector_4d<float>(100.0f, -7e-2f, 12.0f, 0.1f),
    opengl_math::vector_4d<float>(-10e-12f, 1.21f, 1.88f, 0.1f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m9, m10, true));

  m9 = opengl_math::matrix_4X4<float, opengl_math::row>(
    opengl_math::identity);
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m9, m10, true));
  ck_assert(m9 != m10);

  opengl_math::matrix_4X4<float, opengl_math::row> m11(
    opengl_math::vector_4d<float>(std::numeric_limits<float>::max(), 0.0f,
      0.4f, 0.5f),
    opengl_math::vector_4d<float>(1.0f, std::numeric_limits<float>::max(),
      0.7f, 0.8f),
    opengl_math::vector_4d<float>(2.0f, 1.1f,
      std::numeric_limits<float>::max(), 0.8f),
    opengl_math::vector_4d<float>(std::numeric_limits<float>::max(), 0.0f,
      0.0f, 1.0f));
  opengl_math::matrix_4X4<float, opengl_math::row> m12(
    opengl_math::vector_4d<float>(0.0f, 0.0f, 0.1f,
      std::numeric_limits<float>::max()),
    opengl_math::vector_4d<float>(1.0f, exp(1.0f), 0.7f, 1.0f),
    opengl_math::vector_4d<float>(0.1f, (float)M_PI, 0.7f,
      std::numeric_limits<float>::max()),
    opengl_math::vector_4d<float>(-1.0f, 0.0f, 1.0f, -1.0f));
  ck_assert(internal::matrix_tester::test_matrix_addition(
    m11, m12, true));

  // This set of tests cover std::rand number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::column> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::row> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, true));
  }
}
END_TEST

/*! \brief This is a test for the member subtraction (-=) of matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_member_subtraction)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::column> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[3], v[4]));

    opengl_math::matrix_2X2<float, opengl_math::row> im2(
      opengl_math::vector_2d<float>(v[5], v[6]),
      opengl_math::vector_2d<float>(v[7], v[8]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, true));
  }
}
END_TEST

START_TEST(test_matrix_3X3_member_subtraction)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::column> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::row> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, true));
  }
}
END_TEST

START_TEST(test_matrix_4X4_member_subtraction)
{
  opengl_math::matrix_4X4<float, opengl_math::column> ctest;
  opengl_math::matrix_4X4<float, opengl_math::row> rtest;

  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::column> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::row> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, true));
  }
}
END_TEST

/*! \brief This is a test for the member multiplication (*=)
* of matrix_2X2 and matrix_3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_member_multiplication)
{
  opengl_math::matrix_2X2<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::row> Ir(opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::column> m1c(
    opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::row> m1r(
    opengl_math::identity);

  // See class above for def of test_matrix_multiplication
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1c, Ic, true));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1r, Ir, true));

  opengl_math::matrix_2X2<float, opengl_math::column> m2c(opengl_math::null);
  opengl_math::matrix_2X2<float, opengl_math::row> m2r(opengl_math::null);
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2c, m2c, true));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2r, m2r, true));

  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_2X2<float, opengl_math::column> m1(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    opengl_math::matrix_2X2<float, opengl_math::column> m2(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_2X2<float, opengl_math::row> m1(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    opengl_math::matrix_2X2<float, opengl_math::row> m2(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, true));
  }
}
END_TEST

START_TEST(test_matrix_3X3_member_multiplication)
{
  opengl_math::matrix_3X3<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::row> Ir(opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::column> m1c(
    opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::row> m1r(
    opengl_math::identity);

  // See class above for def of test_matrix_multiplication
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1c, Ic, true));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1r, Ir, true));

  opengl_math::matrix_3X3<float, opengl_math::column> m2c(opengl_math::null);
  opengl_math::matrix_3X3<float, opengl_math::row> m2r(opengl_math::null);
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2c, m2c, true));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2r, m2r, true));

  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_3X3<float, opengl_math::column> m1(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    opengl_math::matrix_3X3<float, opengl_math::column> m2(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_3X3<float, opengl_math::row> m1(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    opengl_math::matrix_3X3<float, opengl_math::row> m2(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, true));
  }
}
END_TEST

START_TEST(test_matrix_4X4_member_multiplication)
{
  opengl_math::matrix_4X4<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::row> Ir(opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::column> m1c(
    opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::row> m1r(
    opengl_math::identity);

  // See class above for def of test_matrix_multiplication
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1c, Ic, true));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1r, Ir, true));

  opengl_math::matrix_4X4<float, opengl_math::column> m2c(opengl_math::null);
  opengl_math::matrix_4X4<float, opengl_math::row> m2r(opengl_math::null);
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2c, m2c, true));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2r, m2r, true));

  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_4X4<float, opengl_math::column> m1(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    opengl_math::matrix_4X4<float, opengl_math::column> m2(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_4X4<float, opengl_math::row> m1(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    opengl_math::matrix_4X4<float, opengl_math::row> m2(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, true));
  }
}
END_TEST

/*! \brief This is a test for the member scalar multiplication (*=)
* of matrix_2X2 and matrix_4X4 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_member_scalar_multiplication)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    float scalar = std::rand() /
      (0.1f + exp(static_cast<float>(std::rand() / static_cast<float>(
      std::rand()))));

    ck_assert(
      internal::matrix_tester::test_scalar_matrix_multiplication(im1, scalar,
      true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    float scalar = std::rand() /
      (0.1f + exp(static_cast<float>(std::rand() / static_cast<float>(
      std::rand()))));

    ck_assert(
      internal::matrix_tester::test_scalar_matrix_multiplication(im1, scalar,
      true));
  }
}
END_TEST

START_TEST(test_matrix_3X3_member_scalar_multiplication)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    float scalar = std::rand() /
      (0.1f + exp(static_cast<float>(std::rand() / static_cast<float>(
      std::rand()))));

    ck_assert(
      internal::matrix_tester::test_scalar_matrix_multiplication(im1, scalar,
      true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    float scalar = std::rand() /
      (0.1f + exp(static_cast<float>(std::rand() / static_cast<float>(
      std::rand()))));

    ck_assert(
      internal::matrix_tester::test_scalar_matrix_multiplication(im1, scalar,
      true));
  }
}
END_TEST

START_TEST(test_matrix_4X4_member_scalar_multiplication)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    float scalar = std::rand() /
      (0.1f + exp(static_cast<float>(std::rand() / static_cast<float>(
      std::rand()))));

    ck_assert(
      internal::matrix_tester::test_scalar_matrix_multiplication(im1, scalar,
      true));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    float scalar = std::rand() /
      (0.1f + exp(static_cast<float>(std::rand() / static_cast<float>(
      std::rand()))));

    ck_assert(
      internal::matrix_tester::test_scalar_matrix_multiplication(im1, scalar,
      true));
  }
}
END_TEST

/*! \brief This is a test for the +operator defined outside of matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_addition_operator)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::column> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::row> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, false));
  }
}
END_TEST

START_TEST(test_matrix_3X3_addition_operator)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::column> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::row> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, false));
  }
}
END_TEST

START_TEST(test_matrix_4X4_addition_operator)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::column> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::row> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_addition(
      im1, im2, false));
  }
}
END_TEST

/*! \brief This is a test for the -operator defined outside of matrix_2X2 and
* matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_subtraction_operator)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::column> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::row> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, false));
  }
}
END_TEST

START_TEST(test_matrix_3X3_subtraction_operator)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::column> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::row> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, false));
  }
}
END_TEST

START_TEST(test_matrix_4X4_subtraction_operator)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::column> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::row> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_matrix_subtraction(
      im1, im2, false));
  }
}
END_TEST

/*! \brief This is a test for the -operator defined outside of matrix_2X2 and
* and matrix 3X3 and matrix 4X4 classes which is for the inverse of a matrix
*/
START_TEST(test_matrix_2X2_inverse_operator)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::column> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_inverse(im1));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[2 * 2 * 2];
    for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(v[0], v[1]),
      opengl_math::vector_2d<float>(v[2], v[3]));

    opengl_math::matrix_2X2<float, opengl_math::row> im2(
      opengl_math::vector_2d<float>(v[4], v[5]),
      opengl_math::vector_2d<float>(v[6], v[7]));

    ck_assert(internal::matrix_tester::test_inverse(im1));
  }
}
END_TEST

START_TEST(test_matrix_3X3_inverse_operator)
{
  // This set of tests cover std::random number cases
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::column> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_inverse(im1));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[3 * 3 * 2];
    for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(v[0], v[1], v[2]),
      opengl_math::vector_3d<float>(v[3], v[4], v[5]),
      opengl_math::vector_3d<float>(v[6], v[7], v[8]));

    opengl_math::matrix_3X3<float, opengl_math::row> im2(
      opengl_math::vector_3d<float>(v[9], v[10], v[11]),
      opengl_math::vector_3d<float>(v[12], v[13], v[14]),
      opengl_math::vector_3d<float>(v[15], v[16], v[17]));

    ck_assert(internal::matrix_tester::test_inverse(im1));
  }
}
END_TEST

START_TEST(test_matrix_4X4_inverse_operator)
{
  std::srand(static_cast<int>(time(NULL)));
  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::column> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_inverse(im1));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    float v[4 * 4 * 2];
    for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
      v[j] = std::rand() / 2.0f;
    }

    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(v[0], v[1], v[2], v[3]),
      opengl_math::vector_4d<float>(v[4], v[5], v[6], v[7]),
      opengl_math::vector_4d<float>(v[8], v[9], v[10], v[11]),
      opengl_math::vector_4d<float>(v[12], v[13], v[14], v[15]));

    opengl_math::matrix_4X4<float, opengl_math::row> im2(
      opengl_math::vector_4d<float>(v[16], v[17], v[18], v[19]),
      opengl_math::vector_4d<float>(v[20], v[21], v[22], v[23]),
      opengl_math::vector_4d<float>(v[24], v[25], v[26], v[27]),
      opengl_math::vector_4d<float>(v[28], v[29], v[30], v[31]));

    ck_assert(internal::matrix_tester::test_inverse(im1));
  }
}
END_TEST

/*! \brief This is a test for the member multiplication (*=)
* of matrix_2X2 and matrix 3X3 and matrix 3X3 classes
*/
START_TEST(test_matrix_2X2_multiplication)
{
  opengl_math::matrix_2X2<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::row> Ir(opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::column> m1c(
    opengl_math::identity);
  opengl_math::matrix_2X2<float, opengl_math::row> m1r(
    opengl_math::identity);

  // See class above for def of test_matrix_multiplication
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1c, Ic, false));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1r, Ir, false));

  opengl_math::matrix_2X2<float, opengl_math::column> m2c(opengl_math::null);
  opengl_math::matrix_2X2<float, opengl_math::row> m2r(opengl_math::null);
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2c, m2c, false));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2r, m2r, false));

  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_2X2<float, opengl_math::column> m1(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    opengl_math::matrix_2X2<float, opengl_math::column> m2(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_2X2<float, opengl_math::row> m1(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    opengl_math::matrix_2X2<float, opengl_math::row> m2(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, false));
  }
}
END_TEST

START_TEST(test_matrix_3X3_multiplication)
{
  opengl_math::matrix_3X3<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::row> Ir(opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::column> m1c(
    opengl_math::identity);
  opengl_math::matrix_3X3<float, opengl_math::row> m1r(
    opengl_math::identity);

  // See class above for def of test_matrix_multiplication
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1c, Ic, false));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1r, Ir, false));

  opengl_math::matrix_3X3<float, opengl_math::column> m2c(opengl_math::null);
  opengl_math::matrix_3X3<float, opengl_math::row> m2r(opengl_math::null);
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2c, m2c, false));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2r, m2r, false));

  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_3X3<float, opengl_math::column> m1(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    opengl_math::matrix_3X3<float, opengl_math::column> m2(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_3X3<float, opengl_math::row> m1(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    opengl_math::matrix_3X3<float, opengl_math::row> m2(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, false));
  }
}
END_TEST

START_TEST(test_matrix_4X4_multiplication)
{
  opengl_math::matrix_4X4<float, opengl_math::column> Ic(
    opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::row> Ir(opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::column> m1c(
    opengl_math::identity);
  opengl_math::matrix_4X4<float, opengl_math::row> m1r(
    opengl_math::identity);

  // See class above for def of test_matrix_multiplication
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1c, Ic, false));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m1r, Ir, false));

  opengl_math::matrix_4X4<float, opengl_math::column> m2c(opengl_math::null);
  opengl_math::matrix_4X4<float, opengl_math::row> m2r(opengl_math::null);
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2c, m2c, false));
  ck_assert(internal::matrix_tester::test_matrix_multiplication(
    m2r, m2r, false));

  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_4X4<float, opengl_math::column> m1(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    opengl_math::matrix_4X4<float, opengl_math::column> m2(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, false));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_4X4<float, opengl_math::row> m1(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    opengl_math::matrix_4X4<float, opengl_math::row> m2(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    ck_assert(internal::matrix_tester::test_matrix_multiplication(
      m1, m2, false));
  }
}
END_TEST

/*! \brief This is a test for the vector multiplication (*=)
* by matrix_3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_vector_2d_multiplication)
{
  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_2X2<float, opengl_math::column> m1(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    opengl_math::vector_2d<float> v1(std::rand() / f, std::rand() / f);

    ck_assert(
      internal::matrix_tester::test_matrix_vector_multiplication(m1, v1));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_2X2<float, opengl_math::row> m1(
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f),
      opengl_math::vector_2d<float>(std::rand() / f, std::rand() / f));

    opengl_math::vector_2d<float> v1(std::rand() / f, std::rand() / f);

    ck_assert(
      internal::matrix_tester::test_matrix_vector_multiplication(m1, v1));
  }
}
END_TEST

START_TEST(test_matrix_3X3_vector_3d_multiplication)
{
  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_3X3<float, opengl_math::column> m1(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    opengl_math::vector_3d<float> v1(
      std::rand() / f, std::rand() / f, std::rand() / f);

    ck_assert(
      internal::matrix_tester::test_matrix_vector_multiplication(m1, v1));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_3X3<float, opengl_math::row> m1(
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_3d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f));

    opengl_math::vector_3d<float> v1(
      std::rand() / f, std::rand() / f, std::rand() / f);

    ck_assert(
      internal::matrix_tester::test_matrix_vector_multiplication(m1, v1));
  }
}
END_TEST

START_TEST(test_matrix_4X4_vector_4d_multiplication)
{
  std::srand(static_cast<int>(time(NULL)));
  const float f = std::numeric_limits<float>::max();
  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_4X4<float, opengl_math::column> m1(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    opengl_math::vector_4d<float> v1(
      std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f);

    ck_assert(
      internal::matrix_tester::test_matrix_vector_multiplication(m1, v1));
  }

  for (unsigned short i = 0; i < 100; ++i) {
    opengl_math::matrix_4X4<float, opengl_math::row> m1(
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f),
      opengl_math::vector_4d<float>(
        std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f)
      );

    opengl_math::vector_4d<float> v1(
      std::rand() / f, std::rand() / f, std::rand() / f, std::rand() / f);

    ck_assert(
      internal::matrix_tester::test_matrix_vector_multiplication(m1, v1));
  }
}
END_TEST

/*! \brief This is a test for the transpose and transposed methods
* of matrix_2X2 and matrix_3X3 and matrix_4X4 classes
*/
START_TEST(test_matrix_2X2_transposed)
{
  ck_assert(internal::matrix_tester::test_transpose(
    opengl_math::matrix_2X2<float, opengl_math::column>(
      opengl_math::identity), true));

  std::srand(static_cast<int>(time(NULL)));
  for (int i = 0; i < 100; ++i) {
    float d = std::numeric_limits<float>::max();
    opengl_math::matrix_2X2<float, opengl_math::column> im1(
      opengl_math::vector_2d<float>(std::rand() / d, std::rand() / d),
      opengl_math::vector_2d<float>(std::rand() / d, std::rand() / d));

    ck_assert(internal::matrix_tester::test_transpose(im1, true));
    ck_assert(internal::matrix_tester::test_transpose(im1, false));
  }

  for (int i = 0; i < 100; ++i) {
    float d = std::numeric_limits<float>::max();
    opengl_math::matrix_2X2<float, opengl_math::row> im1(
      opengl_math::vector_2d<float>(std::rand() / d, std::rand() / d),
      opengl_math::vector_2d<float>(std::rand() / d, std::rand() / d));

    ck_assert(internal::matrix_tester::test_transpose(im1, true));
    ck_assert(internal::matrix_tester::test_transpose(im1, false));
  }
}
END_TEST

START_TEST(test_matrix_3X3_transposed)
{
  ck_assert(internal::matrix_tester::test_transpose(
    opengl_math::matrix_3X3<float, opengl_math::column>(
      opengl_math::identity), true));

  std::srand(static_cast<int>(time(NULL)));
  for (int i = 0; i < 100; ++i) {
    float d = std::numeric_limits<float>::max();
    opengl_math::matrix_3X3<float, opengl_math::column> im1(
      opengl_math::vector_3d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_3d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_3d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d));

    ck_assert(internal::matrix_tester::test_transpose(im1, true));
    ck_assert(internal::matrix_tester::test_transpose(im1, false));
  }

  for (int i = 0; i < 100; ++i) {
    float d = std::numeric_limits<float>::max();
    opengl_math::matrix_3X3<float, opengl_math::row> im1(
      opengl_math::vector_3d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_3d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_3d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d));

    ck_assert(internal::matrix_tester::test_transpose(im1, true));
    ck_assert(internal::matrix_tester::test_transpose(im1, false));
  }
}
END_TEST

START_TEST(test_matrix_4X4_transposed)
{
  ck_assert(internal::matrix_tester::test_transpose(
    opengl_math::matrix_4X4<float, opengl_math::column>(
      opengl_math::identity), true));

  std::srand(static_cast<int>(time(NULL)));
  for (int i = 0; i < 100; ++i) {
    float d = std::numeric_limits<float>::max();
    opengl_math::matrix_4X4<float, opengl_math::column> im1(
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d)
      );

    ck_assert(internal::matrix_tester::test_transpose(im1, true));
    ck_assert(internal::matrix_tester::test_transpose(im1, false));
  }

  for (int i = 0; i < 100; ++i) {
    float d = std::numeric_limits<float>::max();
    opengl_math::matrix_4X4<float, opengl_math::row> im1(
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d),
      opengl_math::vector_4d<float>(
        std::rand() / d, std::rand() / d, std::rand() / d, std::rand() / d)
      );

    ck_assert(internal::matrix_tester::test_transpose(im1, true));
    ck_assert(internal::matrix_tester::test_transpose(im1, false));
  }
}
END_TEST

/*! \brief This is a test for calculating the determinant of a matrix_2X2
* and matrix_3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_determinant)
{
  // This initial matrix was derived from www.purplemath.com/modules/
  // determs.htm
  opengl_math::matrix_2X2<float, opengl_math::column> mc1(
    opengl_math::vector_2d<float>(1.0f, 3.0f),
    opengl_math::vector_2d<float>(2.0f, 4.0f));
  ck_assert(mc1.determinant() == -2.0f);

  opengl_math::matrix_2X2<float, opengl_math::row> mr1(
    opengl_math::vector_2d<float>(1.0f, 2.0f),
    opengl_math::vector_2d<float>(3.0f, 4.0f));
  ck_assert(mr1.determinant() == -2.0f);
}
END_TEST

START_TEST(test_matrix_3X3_determinant)
{
  // This initial matrix was derived from http://www.wikihow.com/
  // Find-the-Determinant-of-a-3X3-Matrix
  opengl_math::matrix_3X3<float, opengl_math::column> mc1(
    opengl_math::vector_3d<float>(1.0f, 2.0f, 4.0f),
    opengl_math::vector_3d<float>(5.0f, 4.0f, 6.0f),
    opengl_math::vector_3d<float>(3.0f, 7.0f, 2.0f));
  ck_assert(mc1.determinant() == 74.0);


  opengl_math::matrix_3X3<float, opengl_math::row> mr1(
    opengl_math::vector_3d<float>(1.0f, 5.0f, 3.0f),
    opengl_math::vector_3d<float>(2.0f, 4.0f, 7.0f),
    opengl_math::vector_3d<float>(4.0f, 6.0f, 2.0f));
  ck_assert(mr1.determinant() == 74.0);
}
END_TEST

START_TEST(test_matrix_4X4_determinant)
{
  opengl_math::matrix_4X4<float, opengl_math::column> mc1(
    opengl_math::vector_4d<float>(3.0, 0.8f, -0.142857143f, 0.0f),
    opengl_math::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f),
    opengl_math::vector_4d<float>(-1.0, 1.0f, -5.0f, 0.0f),
    opengl_math::vector_4d<float>(0.0f, 2.0f, 0.0f, 0.0f));
  ck_assert(opengl_math::float_equals(mc1.determinant(), 30.2857151f,
    1e-8f));

  opengl_math::matrix_4X4<float, opengl_math::row> mr1(
    opengl_math::vector_4d<float>(3.0f, 0.0f, -1.0f, 0.0f),
    opengl_math::vector_4d<float>(0.8f, 0.0f, 1.0f, 2.0f),
    opengl_math::vector_4d<float>(-0.142857143f, 0.0f, -5.0f, 0.0f),
    opengl_math::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f));
  ck_assert(opengl_math::float_equals(mr1.determinant(), 30.2857151f,
    1e-8f));
}
END_TEST

/*! \brief This is a test for the inverted and invert methods
* of matrix_2X2 and and matrix 3X3 and matrix 4X4 classes
*/
START_TEST(test_matrix_2X2_inversion)
{
  {
    const opengl_math::matrix_2X2<float, opengl_math::column> m1(
      opengl_math::vector_2d<float>(-3, 4),
      opengl_math::vector_2d<float>(-6, 5));

    const opengl_math::matrix_2X2<float, opengl_math::column> m1I(
      opengl_math::vector_2d<float>(0.55556f, -0.44444f),
      opengl_math::vector_2d<float>(0.66667f, -0.33333f));

    bool inverted =
      internal::matrix_tester::test_inversion(m1, m1I, true, 1e-005f);

    ck_assert(inverted);
  }

    {
      const opengl_math::matrix_2X2<float, opengl_math::row> m2(
        opengl_math::vector_2d<float>(-3, -6),
        opengl_math::vector_2d<float>(4, 5));

      const opengl_math::matrix_2X2<float, opengl_math::row> m2I(
        opengl_math::vector_2d<float>(0.55556f, 0.66667f),
        opengl_math::vector_2d<float>(-0.44444f, -0.33333f));

      bool inverted =
        internal::matrix_tester::test_inversion(m2, m2I, true, 1e-005f);

      ck_assert(inverted);
    }

    const opengl_math::matrix_2X2<float, opengl_math::column> m3(
      opengl_math::identity);
    ck_assert(m3.inversion() == m3);
}
END_TEST

START_TEST(test_matrix_3X3_inversion)
{
  {
    const opengl_math::matrix_3X3<float, opengl_math::column> m1(
      opengl_math::vector_3d<float>(-3, 4, -9),
      opengl_math::vector_3d<float>(-1, 2, -6),
      opengl_math::vector_3d<float>(-6, 5, 2));

    const opengl_math::matrix_3X3<float, opengl_math::column> m1I(
      opengl_math::vector_3d<float>(-2.61538f, 4.07692f, 0.46154f),
      opengl_math::vector_3d<float>(-2.92308f, 4.61538f, 0.69231f),
      opengl_math::vector_3d<float>(-0.53846f, 0.69231f, 0.15385f));

    bool inverted =
      internal::matrix_tester::test_inversion(m1, m1I, true, 1e-005f);

    ck_assert(inverted);
  }

    {
      const opengl_math::matrix_3X3<float, opengl_math::row> m2(
        opengl_math::vector_3d<float>(-3, -1, -6),
        opengl_math::vector_3d<float>(4, 2, 5),
        opengl_math::vector_3d<float>(-9, -6, 2));

      const opengl_math::matrix_3X3<float, opengl_math::row> m2I(
        opengl_math::vector_3d<float>(-2.61538f, -2.92308f, -0.53846f),
        opengl_math::vector_3d<float>(4.07692f, 4.61538f, 0.69231f),
        opengl_math::vector_3d<float>(0.46154f, 0.69231f, 0.15385f));

      bool inverted =
        internal::matrix_tester::test_inversion(m2, m2I, true, 1e-005f);

      ck_assert(inverted);
    }

    const opengl_math::matrix_3X3<float, opengl_math::column> m3(
      opengl_math::identity);
    ck_assert(m3.inversion() == m3);
}
END_TEST

START_TEST(test_matrix_4X4_inversion)
{
  {
    const opengl_math::matrix_4X4<float, opengl_math::column> m1(
      opengl_math::vector_4d<float>(-3, 4, 4, -9),
      opengl_math::vector_4d<float>(-1, 2, 3, -6),
      opengl_math::vector_4d<float>(-6, 5, -4, 2),
      opengl_math::vector_4d<float>(-1, -1, 1, 1));

    const opengl_math::matrix_4X4<float, opengl_math::column> m1I(
      opengl_math::vector_4d<float>(
        -3.000000f, 4.692808f, 0.538462f, 0.076923f),
      opengl_math::vector_4d<float>(
        -6.000000f, 9.538462f, 1.307692f, 0.615385f),
      opengl_math::vector_4d<float>(
        -5.000000f, 8.000000f, 1.000000f, 1.000000f),
      opengl_math::vector_4d<float>(
        -4.000000f, 6.230769f, 0.846154f, 0.692308f));

    bool inverted =
      internal::matrix_tester::test_inversion(m1, m1I, true, 1e-003f);

    ck_assert(inverted);
  }

  {
    const opengl_math::matrix_4X4<float, opengl_math::row> m2(
      opengl_math::vector_4d<float>(-3, -1, -6, -1),
      opengl_math::vector_4d<float>(4, 2, 5, -1),
      opengl_math::vector_4d<float>(4, 3, -4, 1),
      opengl_math::vector_4d<float>(-9, -6, 2, 1));

    const opengl_math::matrix_4X4<float, opengl_math::row> m2I(
      opengl_math::vector_4d<float>(
        -3.00000f, -6.00000f, -5.00000f, -4.00000f),
      opengl_math::vector_4d<float>(
        4.692308f, 9.538462f, 8.000000f, 6.230769f),
      opengl_math::vector_4d<float>(
        0.538462f, 1.307962f, 1.000000f, 0.846154f),
      opengl_math::vector_4d<float>(
        0.076923f, 0.615385f, 1.000000f, 0.692308f));

    bool inverted =
      internal::matrix_tester::test_inversion(m2, m2I, true, 1e-003f);

    ck_assert(inverted);
  }

  const opengl_math::matrix_4X4<float, opengl_math::column> m3(
    opengl_math::identity);
  ck_assert(m3.inversion() == m3);
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

  tcase_add_test(tc, test_default_matrix_2X2_constructor);
  tcase_add_test(tc, test_default_matrix_3X3_constructor);
  tcase_add_test(tc, test_default_matrix_4X4_constructor);
  tcase_add_test(tc, test_matrix_2X2_identity_constructor);
  tcase_add_test(tc, test_matrix_3X3_identity_constructor);
  tcase_add_test(tc, test_matrix_4X4_identity_constructor);
  tcase_add_test(tc, test_matrix_2X2_vector_constructor);
  tcase_add_test(tc, test_matrix_3X3_vector_constructor);
  tcase_add_test(tc, test_matrix_4X4_vector_constructor);
  tcase_add_test(tc, test_matrix_2X2_copy_constructor);
  tcase_add_test(tc, test_matrix_3X3_copy_constructor);
  tcase_add_test(tc, test_matrix_4X4_copy_constructor);
  tcase_add_test(tc, test_matrix_2X2_copy_assignment_operator);
  tcase_add_test(tc, test_matrix_3X3_copy_assignment_operator);
  tcase_add_test(tc, test_matrix_4X4_copy_assignment_operator);
  tcase_add_test(tc, test_matrix_2X2_setters);
  tcase_add_test(tc, test_matrix_3X3_setters);
  tcase_add_test(tc, test_matrix_4X4_setters);
  tcase_add_test(tc, test_matrix_2X2_member_addition);
  tcase_add_test(tc, test_matrix_3X3_member_addition);
  tcase_add_test(tc, test_matrix_4X4_member_addition);
  tcase_add_test(tc, test_matrix_2X2_member_subtraction);
  tcase_add_test(tc, test_matrix_3X3_member_subtraction);
  tcase_add_test(tc, test_matrix_4X4_member_subtraction);
  tcase_add_test(tc, test_matrix_2X2_member_multiplication);
  tcase_add_test(tc, test_matrix_3X3_member_multiplication);
  tcase_add_test(tc, test_matrix_4X4_member_multiplication);
  tcase_add_test(tc, test_matrix_2X2_member_scalar_multiplication);
  tcase_add_test(tc, test_matrix_3X3_member_scalar_multiplication);
  tcase_add_test(tc, test_matrix_4X4_member_scalar_multiplication);
  tcase_add_test(tc, test_matrix_2X2_addition_operator);
  tcase_add_test(tc, test_matrix_3X3_addition_operator);
  tcase_add_test(tc, test_matrix_4X4_addition_operator);
  tcase_add_test(tc, test_matrix_2X2_subtraction_operator);
  tcase_add_test(tc, test_matrix_3X3_subtraction_operator);
  tcase_add_test(tc, test_matrix_4X4_subtraction_operator);
  tcase_add_test(tc, test_matrix_2X2_inverse_operator);
  tcase_add_test(tc, test_matrix_3X3_inverse_operator);
  tcase_add_test(tc, test_matrix_4X4_inverse_operator);
  tcase_add_test(tc, test_matrix_2X2_multiplication);
  tcase_add_test(tc, test_matrix_3X3_multiplication);
  tcase_add_test(tc, test_matrix_4X4_multiplication);
  tcase_add_test(tc, test_matrix_2X2_vector_2d_multiplication);
  tcase_add_test(tc, test_matrix_3X3_vector_3d_multiplication);
  tcase_add_test(tc, test_matrix_4X4_vector_4d_multiplication);
  tcase_add_test(tc, test_matrix_2X2_transposed);
  tcase_add_test(tc, test_matrix_3X3_transposed);
  tcase_add_test(tc, test_matrix_4X4_transposed);
  tcase_add_test(tc, test_matrix_2X2_determinant);
  tcase_add_test(tc, test_matrix_3X3_determinant);
  tcase_add_test(tc, test_matrix_4X4_determinant);
  tcase_add_test(tc, test_matrix_2X2_inversion);
  tcase_add_test(tc, test_matrix_3X3_inversion);
  tcase_add_test(tc, test_matrix_4X4_inversion);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
