#ifndef MATRICES_TESTS
#define MATRICES_TESTS

#define _USE_MATH_DEFINES

#include <cxxtest/TestSuite.h>

#include <graphics/matrices/type_matrix_2X2.h>
#include <graphics/matrices/type_matrix_3X3.h>
#include <graphics/matrices/type_matrix_4X4.h>
#include <graphics/primitives/vectors/type_vector_2d.h>
#include <graphics/primitives/vectors/type_vector_3d.h>
#include <graphics/primitives/vectors/type_vector_4d.h>
#include <core/math/numbers.h>
#include <cstdlib>

namespace internal
{
  /*! \brief NOTE that all tests assume that the operator[] for both vector_Nd
   * and matrix_NXN work correctly.
   */
  class matrix_tester
  {
  public:
    /*
     * Start of helper functions
     */
    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_addition(
      const gl_wrapper::matrix_2X2<T, ML> &m1,
      const gl_wrapper::matrix_2X2<T, ML> &m2,
      bool self_add = false)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_addition(
      const gl_wrapper::matrix_3X3<T, ML> &m1,
      const gl_wrapper::matrix_3X3<T, ML> &m2,
      bool self_add = false)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_addition(
      const gl_wrapper::matrix_4X4<T, ML> &m1,
      const gl_wrapper::matrix_4X4<T, ML> &m2,
      bool self_add = false)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_subtraction(
      const gl_wrapper::matrix_2X2<T, ML> &m1,
      const gl_wrapper::matrix_2X2<T, ML> &m2,
      bool self_sub = false)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_subtraction(
      const gl_wrapper::matrix_3X3<T, ML> &m1,
      const gl_wrapper::matrix_3X3<T, ML> &m2,
      bool self_sub = false)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_subtraction(
      const gl_wrapper::matrix_4X4<T, ML> &m1,
      const gl_wrapper::matrix_4X4<T, ML> &m2,
      bool self_sub = false)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_scalar_matrix_multiplication(
      const gl_wrapper::matrix_2X2<T, ML> &m1, const T &scalar, bool self_scale)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_scalar_matrix_multiplication(
      const gl_wrapper::matrix_3X3<T, ML> &m1, const T &scalar, bool self_scale)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_scalar_matrix_multiplication(
      const gl_wrapper::matrix_4X4<T, ML> &m1, const T &scalar, bool self_scale)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_multiplication(
      const gl_wrapper::matrix_2X2<T, ML> &m1,
      const gl_wrapper::matrix_2X2<T, ML> &m2,
      bool self_mult = false)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp;
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
            if (ML == gl_wrapper::column) {
              // [col][row]
              val += (m1[i][j] * m2[k][i]);
            } else {
              // [row][col]
              val += (m1[j][i] * m2[i][k]);
            }
          }
          if (ML == gl_wrapper::column) {
            ret &= (tmp[k][j] == val);
          } else {
            ret &= (tmp[j][k] == val);
          }
        }
      }
      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_multiplication(
      const gl_wrapper::matrix_3X3<T, ML> &m1,
      const gl_wrapper::matrix_3X3<T, ML> &m2,
      bool self_mult = false)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp;
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
            if (ML == gl_wrapper::column) {
              // [col][row]
              val += (m1[i][j] * m2[k][i]);
            } else {
              // [row][col]
              val += (m1[j][i] * m2[i][k]);
            }
          }
          if (ML == gl_wrapper::column) {
            ret &= (tmp[k][j] == val);
          } else {
            ret &= (tmp[j][k] == val);
          }
        }
      }
      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_multiplication(
        const gl_wrapper::matrix_4X4<T, ML> &m1,
        const gl_wrapper::matrix_4X4<T, ML> &m2,
        bool self_mult = false)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp;
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
            if (ML == gl_wrapper::column) {
              // [col][row]
              val += (m1[i][j] * m2[k][i]);
            } else {
              // [row][col]
              val += (m1[j][i] * m2[i][k]);
            }
          }
          if (ML == gl_wrapper::column) {
            ret &= (tmp[k][j] == val);
          } else {
            ret &= (tmp[j][k] == val);
          }
        }
      }
      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_vector_multiplication(
      const gl_wrapper::matrix_2X2<T, ML> &m1,
      const gl_wrapper::vector_2d<T> &v1)
    {
      bool ret = true;

      gl_wrapper::vector_2d<float> tmp = m1 * v1;
      for (int i = 0; i < 2; ++i) {
        if (ML == gl_wrapper::column) {
          ret &= (gl_wrapper::core::math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i]), 1e-006f));
        } else {
          ret &= (gl_wrapper::core::math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i]), 1e-006f));
        }
      }

      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_vector_multiplication(
      const gl_wrapper::matrix_3X3<T, ML> &m1,
      const gl_wrapper::vector_3d<T> &v1)
    {
      bool ret = true;

      gl_wrapper::vector_3d<float> tmp = m1 * v1;
      for (int i = 0; i < 3; ++i) {
        if (ML == gl_wrapper::column) {
          ret &= (gl_wrapper::core::math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i] + v1[2] * m1[2][i]),
            1e-006f));
        } else {
          ret &= (gl_wrapper::core::math::float_equals(tmp[i],
            (v1[0] * m1[0][i] + v1[1] * m1[1][i] + v1[2] * m1[2][i]),
            1e-006f));
        }
      }

      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_matrix_vector_multiplication(
      const gl_wrapper::matrix_4X4<T, ML> &m1,
      const gl_wrapper::vector_4d<T> &v1)
    {
      bool ret = true;

      gl_wrapper::vector_4d<float> tmp = m1 * v1;
      for (int i = 0; i < 3; ++i) {
        if (ML == gl_wrapper::column) {
          ret &= (gl_wrapper::core::math::float_equals(tmp[i],
            (v1[0] * m1[0][i] +
             v1[1] * m1[1][i] +
             v1[2] * m1[2][i] +
             v1[3] * m1[3][i]), 1e-006f));
        } else {
          ret &= (gl_wrapper::core::math::float_equals(tmp[i],
            (v1[0] * m1[0][i] +
             v1[1] * m1[1][i] +
             v1[2] * m1[2][i] +
             v1[3] * m1[3][i]), 1e-006f));
        }
      }

      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_inverse(const gl_wrapper::matrix_2X2<T, ML> &m1)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp = -m1;
      for (int i = 0; i < (2 * 2); ++i) {
        float tval = -m1[i / 2][i % 2];
        ret &= (tmp[i / 2][i % 2] == tval);
      }

      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_inverse(const gl_wrapper::matrix_3X3<T, ML> &m1)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp = -m1;
      for (int i = 0; i < (3 * 3); ++i) {
        float tval = -m1[i / 3][i % 3];
        ret &= (tmp[i / 3][i % 3] == tval);
      }

      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_inverse(const gl_wrapper::matrix_4X4<T, ML> &m1)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp = -m1;
      for (int i = 0; i < (4 * 4); ++i) {
        float tval = -m1[i / 4][i % 4];
        ret &= (tmp[i / 4][i % 4] == tval);
      }

      return ret;
    }

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_inversion(const gl_wrapper::matrix_2X2<T, ML> &m1,
      const gl_wrapper::matrix_2X2<T, ML> &expected,
      bool member_invert,
      T epsilon = 1e-8)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_inversion(const gl_wrapper::matrix_3X3<T, ML> &m1,
      const gl_wrapper::matrix_3X3<T, ML> &expected,
      bool member_invert,
      T epsilon = 1e-8)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_inversion(const gl_wrapper::matrix_4X4<T, ML> &m1,
      const gl_wrapper::matrix_4X4<T, ML> &expected,
      bool member_invert,
      T epsilon = 1e-8)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_transpose(const gl_wrapper::matrix_2X2<T, ML> &m1,
      bool member_trans)
    {
      bool ret = true;

      gl_wrapper::matrix_2X2<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_transpose(const gl_wrapper::matrix_3X3<T, ML> &m1,
      bool member_trans)
    {
      bool ret = true;

      gl_wrapper::matrix_3X3<T, ML> tmp;
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

    template <typename T, gl_wrapper::matrix_layout ML>
    static bool test_transpose(const gl_wrapper::matrix_4X4<T, ML> &m1,
      bool member_trans)
    {
      bool ret = true;

      gl_wrapper::matrix_4X4<T, ML> tmp;
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

/*
 * Start of actual tests.
 */
class matrix_tests : public CxxTest::TestSuite
{
public:
  /*! \brief This is a test for the default ctor in the matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_default_matrix_2X2_constructor()
  {
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1;
    TS_ASSERT(m1[0] == gl_wrapper::vector_2d<float>());
    TS_ASSERT(m1[1] == gl_wrapper::vector_2d<float>());

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2;
    TS_ASSERT(m2[0] == gl_wrapper::vector_2d<float>());
    TS_ASSERT(m2[1] == gl_wrapper::vector_2d<float>());

    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3;
    TS_ASSERT(m3[0] == gl_wrapper::vector_2d<double>());
    TS_ASSERT(m3[1] == gl_wrapper::vector_2d<double>());

    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4;
    TS_ASSERT(m4[0] == gl_wrapper::vector_2d<double>());
    TS_ASSERT(m4[1] == gl_wrapper::vector_2d<double>());
  }

  void test_default_matrix_3X3_constructor()
  {
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1;
    TS_ASSERT(m1[0] == gl_wrapper::vector_3d<float>());
    TS_ASSERT(m1[1] == gl_wrapper::vector_3d<float>());
    TS_ASSERT(m1[2] == gl_wrapper::vector_3d<float>());

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2;
    TS_ASSERT(m2[0] == gl_wrapper::vector_3d<float>());
    TS_ASSERT(m2[1] == gl_wrapper::vector_3d<float>());
    TS_ASSERT(m2[2] == gl_wrapper::vector_3d<float>());

    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3;
    TS_ASSERT(m3[0] == gl_wrapper::vector_3d<double>());
    TS_ASSERT(m3[1] == gl_wrapper::vector_3d<double>());
    TS_ASSERT(m3[2] == gl_wrapper::vector_3d<double>());

    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4;
    TS_ASSERT(m4[0] == gl_wrapper::vector_3d<double>());
    TS_ASSERT(m4[1] == gl_wrapper::vector_3d<double>());
    TS_ASSERT(m4[2] == gl_wrapper::vector_3d<double>());
  }

  void test_default_matrix_4X4_constructor()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1;
    TS_ASSERT(m1[0] == gl_wrapper::vector_4d<float>());
    TS_ASSERT(m1[1] == gl_wrapper::vector_4d<float>());
    TS_ASSERT(m1[2] == gl_wrapper::vector_4d<float>());
    TS_ASSERT(m1[3] == gl_wrapper::vector_4d<float>());

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2;
    TS_ASSERT(m2[0] == gl_wrapper::vector_4d<float>());
    TS_ASSERT(m2[1] == gl_wrapper::vector_4d<float>());
    TS_ASSERT(m2[2] == gl_wrapper::vector_4d<float>());
    TS_ASSERT(m2[3] == gl_wrapper::vector_4d<float>());

    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3;
    TS_ASSERT(m3[0] == gl_wrapper::vector_4d<double>());
    TS_ASSERT(m3[1] == gl_wrapper::vector_4d<double>());
    TS_ASSERT(m3[2] == gl_wrapper::vector_4d<double>());
    TS_ASSERT(m3[3] == gl_wrapper::vector_4d<double>());

    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4;
    TS_ASSERT(m4[0] == gl_wrapper::vector_4d<double>());
    TS_ASSERT(m4[1] == gl_wrapper::vector_4d<double>());
    TS_ASSERT(m4[2] == gl_wrapper::vector_4d<double>());
    TS_ASSERT(m4[3] == gl_wrapper::vector_4d<double>());
  }

  /*! \brief This is a test for the default ctor in the matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes which takes the identity flag
   */
  void test_matrix_2X2_identity_constructor()
  {
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(gl_wrapper::identity);
    TS_ASSERT(m1[0] == gl_wrapper::vector_2d<float>(1.0f, 0.0f));
    TS_ASSERT(m1[1] == gl_wrapper::vector_2d<float>(0.0f, 1.0f));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(gl_wrapper::identity);
    TS_ASSERT(m2[0] == gl_wrapper::vector_2d<float>(1.0f, 0.0f));
    TS_ASSERT(m2[1] == gl_wrapper::vector_2d<float>(0.0f, 1.0f));

    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3(gl_wrapper::identity);
    TS_ASSERT(m3[0] == gl_wrapper::vector_2d<double>(1.0, 0.0));
    TS_ASSERT(m3[1] == gl_wrapper::vector_2d<double>(0.0, 1.0));

    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4(gl_wrapper::identity);
    TS_ASSERT(m4[0] == gl_wrapper::vector_2d<double>(1.0, 0.0));
    TS_ASSERT(m4[1] == gl_wrapper::vector_2d<double>(0.0, 1.0));
  }

  void test_matrix_3X3_identity_constructor()
  {
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(gl_wrapper::identity);
    TS_ASSERT(m1[0] == gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f));
    TS_ASSERT(m1[1] == gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f));
    TS_ASSERT(m1[2] == gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(gl_wrapper::identity);
    TS_ASSERT(m2[0] == gl_wrapper::vector_3d<float>(1.0f, 0.0f, 0.0f));
    TS_ASSERT(m2[1] == gl_wrapper::vector_3d<float>(0.0f, 1.0f, 0.0f));
    TS_ASSERT(m2[2] == gl_wrapper::vector_3d<float>(0.0f, 0.0f, 1.0f));

    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3(gl_wrapper::identity);
    TS_ASSERT(m3[0] == gl_wrapper::vector_3d<double>(1.0, 0.0, 0.0));
    TS_ASSERT(m3[1] == gl_wrapper::vector_3d<double>(0.0, 1.0, 0.0));
    TS_ASSERT(m3[2] == gl_wrapper::vector_3d<double>(0.0, 0.0, 1.0));

    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4(gl_wrapper::identity);
    TS_ASSERT(m4[0] == gl_wrapper::vector_3d<double>(1.0, 0.0, 0.0));
    TS_ASSERT(m4[1] == gl_wrapper::vector_3d<double>(0.0, 1.0, 0.0));
    TS_ASSERT(m4[2] == gl_wrapper::vector_3d<double>(0.0, 0.0, 1.0));
  }

  void test_matrix_4X4_identity_constructor()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(gl_wrapper::identity);
    TS_ASSERT(m1[0] == gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f));
    TS_ASSERT(m1[1] == gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f));
    TS_ASSERT(m1[2] == gl_wrapper::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f));
    TS_ASSERT(m1[3] == gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(gl_wrapper::identity);
    TS_ASSERT(m2[0] == gl_wrapper::vector_4d<float>(1.0f, 0.0f, 0.0f, 0.0f));
    TS_ASSERT(m2[1] == gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f));
    TS_ASSERT(m2[2] == gl_wrapper::vector_4d<float>(0.0f, 0.0f, 1.0f, 0.0f));
    TS_ASSERT(m2[3] == gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f));

    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3(gl_wrapper::identity);
    TS_ASSERT(m3[0] == gl_wrapper::vector_4d<double>(1.0f, 0.0f, 0.0f, 0.0f));
    TS_ASSERT(m3[1] == gl_wrapper::vector_4d<double>(0.0f, 1.0f, 0.0f, 0.0f));
    TS_ASSERT(m3[2] == gl_wrapper::vector_4d<double>(0.0f, 0.0f, 1.0f, 0.0f));
    TS_ASSERT(m3[3] == gl_wrapper::vector_4d<double>(0.0f, 0.0f, 0.0f, 1.0f));

    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4(gl_wrapper::identity);
    TS_ASSERT(m4[0] == gl_wrapper::vector_4d<double>(1.0f, 0.0f, 0.0f, 0.0f));
    TS_ASSERT(m4[1] == gl_wrapper::vector_4d<double>(0.0f, 1.0f, 0.0f, 0.0f));
    TS_ASSERT(m4[2] == gl_wrapper::vector_4d<double>(0.0f, 0.0f, 1.0f, 0.0f));
    TS_ASSERT(m4[3] == gl_wrapper::vector_4d<double>(0.0f, 0.0f, 0.0f, 1.0f));
  }

  /*! \brief This is a test for the ctor in the matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes with can be construced
   * from the vector family of classes.
   */
  void test_matrix_2X2_vector_constructor()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    TS_ASSERT(m1[0] == gl_wrapper::vector_2d<float>(rand1, rand2));
    TS_ASSERT(m1[1] == gl_wrapper::vector_2d<float>(rand2, rand1));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    TS_ASSERT(m2[0] == gl_wrapper::vector_2d<float>(rand1, rand2));
    TS_ASSERT(m2[1] == gl_wrapper::vector_2d<float>(rand2, rand1));

    double rand3 = static_cast<double>(rand() / rand());
    double rand4 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3(
      gl_wrapper::vector_2d<double>(rand3, rand4),
      gl_wrapper::vector_2d<double>(rand4, rand3));
    TS_ASSERT(m3[0] == gl_wrapper::vector_2d<double>(rand3, rand4));
    TS_ASSERT(m3[1] == gl_wrapper::vector_2d<double>(rand4, rand3));

    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4(
      gl_wrapper::vector_2d<double>(rand3, rand4),
      gl_wrapper::vector_2d<double>(rand4, rand3));
    TS_ASSERT(m4[0] == gl_wrapper::vector_2d<double>(rand3, rand4));
    TS_ASSERT(m4[1] == gl_wrapper::vector_2d<double>(rand4, rand3));
  }

  void test_matrix_3X3_vector_constructor()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    TS_ASSERT(m1[0] == gl_wrapper::vector_3d<float>(rand1, rand2, rand3));
    TS_ASSERT(m1[1] == gl_wrapper::vector_3d<float>(rand2, rand3, rand1));
    TS_ASSERT(m1[2] == gl_wrapper::vector_3d<float>(rand3, rand1, rand2));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    TS_ASSERT(m2[0] == gl_wrapper::vector_3d<float>(rand1, rand2, rand3));
    TS_ASSERT(m2[1] == gl_wrapper::vector_3d<float>(rand2, rand3, rand1));
    TS_ASSERT(m2[2] == gl_wrapper::vector_3d<float>(rand3, rand1, rand2));

    double rand4 = static_cast<double>(rand() / rand());
    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3(
      gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
      gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
      gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    TS_ASSERT(m3[0] == gl_wrapper::vector_3d<double>(rand4, rand5, rand6));
    TS_ASSERT(m3[1] == gl_wrapper::vector_3d<double>(rand5, rand6, rand4));
    TS_ASSERT(m3[2] == gl_wrapper::vector_3d<double>(rand6, rand4, rand5));

    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4(
      gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
      gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
      gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    TS_ASSERT(m4[0] == gl_wrapper::vector_3d<double>(rand4, rand5, rand6));
    TS_ASSERT(m4[1] == gl_wrapper::vector_3d<double>(rand5, rand6, rand4));
    TS_ASSERT(m4[2] == gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
  }

  void test_matrix_4X4_vector_constructor()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());
    float rand4 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    TS_ASSERT(m1[0] == gl_wrapper::vector_4d<float>(rand1,rand2,rand3,rand4));
    TS_ASSERT(m1[1] == gl_wrapper::vector_4d<float>(rand2,rand3,rand4,rand1));
    TS_ASSERT(m1[2] == gl_wrapper::vector_4d<float>(rand3,rand4,rand1,rand2));
    TS_ASSERT(m1[3] == gl_wrapper::vector_4d<float>(rand4,rand1,rand2,rand3));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    TS_ASSERT(m2[0] == gl_wrapper::vector_4d<float>(rand1,rand2,rand3,rand4));
    TS_ASSERT(m2[1] == gl_wrapper::vector_4d<float>(rand2,rand3,rand4,rand1));
    TS_ASSERT(m2[2] == gl_wrapper::vector_4d<float>(rand3,rand4,rand1,rand2));
    TS_ASSERT(m2[3] == gl_wrapper::vector_4d<float>(rand4,rand1,rand2,rand3));

    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());
    double rand7 = static_cast<double>(rand() / rand());
    double rand8 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    TS_ASSERT(m3[0] == gl_wrapper::vector_4d<double>(rand5,rand6,rand7,rand8));
    TS_ASSERT(m3[1] == gl_wrapper::vector_4d<double>(rand6,rand7,rand8,rand5));
    TS_ASSERT(m3[2] == gl_wrapper::vector_4d<double>(rand7,rand8,rand5,rand6));
    TS_ASSERT(m3[3] == gl_wrapper::vector_4d<double>(rand8,rand5,rand6,rand7));

    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    TS_ASSERT(m4[0] == gl_wrapper::vector_4d<double>(rand5,rand6,rand7,rand8));
    TS_ASSERT(m4[1] == gl_wrapper::vector_4d<double>(rand6,rand7,rand8,rand5));
    TS_ASSERT(m4[2] == gl_wrapper::vector_4d<double>(rand7,rand8,rand5,rand6));
    TS_ASSERT(m4[3] == gl_wrapper::vector_4d<double>(rand8,rand5,rand6,rand7));
  }

  /*! \brief This is a test for the copy ctor in the matrix_2X2 and
   * matrix 3X3 matrix 4X4 classes
   */
  void test_matrix_2X2_copy_constructor()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1_copy(m1);
    TS_ASSERT(m1 == m1_copy);
    TS_ASSERT(!(m1 != m1_copy));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2_copy(m2);
    TS_ASSERT(m2 == m2_copy);
    TS_ASSERT(!(m2 != m2_copy));

    double rand3 = static_cast<double>(rand() / rand());
    double rand4 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3(
        gl_wrapper::vector_2d<double>(rand3, rand4),
        gl_wrapper::vector_2d<double>(rand4, rand3));
    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3_copy(m3);
    TS_ASSERT(m3 == m3_copy);
    TS_ASSERT(!(m3 != m3_copy));

    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4(
        gl_wrapper::vector_2d<double>(rand3, rand4),
        gl_wrapper::vector_2d<double>(rand4, rand3));
    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4_copy(m4);
    TS_ASSERT(m4 == m4_copy);
    TS_ASSERT(!(m4 != m4_copy));
  }

  void test_matrix_3X3_copy_constructor()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1_copy(m1);
    TS_ASSERT(m1 == m1_copy);
    TS_ASSERT(!(m1 != m1_copy));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2_copy(m2);
    TS_ASSERT(m2 == m2_copy);
    TS_ASSERT(!(m2 != m2_copy));

    double rand4 = static_cast<double>(rand() / rand());
    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3(
        gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
        gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
        gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3_copy(m3);
    TS_ASSERT(m3 == m3_copy);
    TS_ASSERT(!(m3 != m3_copy));

    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4(
        gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
        gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
        gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4_copy(m4);
    TS_ASSERT(m4 == m4_copy);
    TS_ASSERT(!(m4 != m4_copy));
  }

  void test_matrix_4X4_copy_constructor()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());
    float rand4 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1_copy(m1);
    TS_ASSERT(m1 == m1_copy);
    TS_ASSERT(!(m1 != m1_copy));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2_copy(m2);
    TS_ASSERT(m2 == m2_copy);
    TS_ASSERT(!(m2 != m2_copy));

    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());
    double rand7 = static_cast<double>(rand() / rand());
    double rand8 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3_copy(m3);
    TS_ASSERT(m3 == m3_copy);
    TS_ASSERT(!(m3 != m3_copy));

    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4_copy(m4);
    TS_ASSERT(m4 == m4_copy);
    TS_ASSERT(!(m4 != m4_copy));
  }

  /*! \brief This is a test for the assignment operator in the matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_copy_assignment_operator()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1_copy = m1;
    TS_ASSERT(m1 == m1_copy);
    TS_ASSERT(!(m1 != m1_copy));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2_copy = m2;
    TS_ASSERT(m2 == m2_copy);
    TS_ASSERT(!(m2 != m2_copy));

    double rand3 = static_cast<double>(rand() / rand());
    double rand4 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3(
        gl_wrapper::vector_2d<double>(rand3, rand4),
        gl_wrapper::vector_2d<double>(rand4, rand3));
    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3_copy = m3;
    TS_ASSERT(m3 == m3_copy);
    TS_ASSERT(!(m3 != m3_copy));

    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4(
        gl_wrapper::vector_2d<double>(rand3, rand4),
        gl_wrapper::vector_2d<double>(rand4, rand3));
    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4_copy = m4;
    TS_ASSERT(m4 == m4_copy);
    TS_ASSERT(!(m4 != m4_copy));
  }


  void test_matrix_3X3_copy_assignment_operator()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1_copy = m1;
    TS_ASSERT(m1 == m1_copy);
    TS_ASSERT(!(m1 != m1_copy));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2_copy = m2;
    TS_ASSERT(m2 == m2_copy);
    TS_ASSERT(!(m2 != m2_copy));

    double rand4 = static_cast<double>(rand() / rand());
    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3(
        gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
        gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
        gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3_copy = m3;
    TS_ASSERT(m3 == m3_copy);
    TS_ASSERT(!(m3 != m3_copy));

    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4(
        gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
        gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
        gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4_copy = m4;
    TS_ASSERT(m4 == m4_copy);
    TS_ASSERT(!(m4 != m4_copy));
  }

  void test_matrix_4X4_copy_assignment_operator()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());
    float rand4 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1_copy = m1;
    TS_ASSERT(m1 == m1_copy);
    TS_ASSERT(!(m1 != m1_copy));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2_copy = m2;
    TS_ASSERT(m2 == m2_copy);
    TS_ASSERT(!(m2 != m2_copy));

    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());
    double rand7 = static_cast<double>(rand() / rand());
    double rand8 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3_copy = m3;
    TS_ASSERT(m3 == m3_copy);
    TS_ASSERT(!(m3 != m3_copy));

    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4_copy = m4;
    TS_ASSERT(m4 == m4_copy);
    TS_ASSERT(!(m4 != m4_copy));
  }

  /*! \brief This is a test for the setters in the matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_setters()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    m1.vec0(m1.vec1());
    TS_ASSERT(m1.vec0() == m1.vec1());
    TS_ASSERT(m1.vec1() == gl_wrapper::vector_2d<float>(rand2, rand1));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
      gl_wrapper::vector_2d<float>(rand1, rand2),
      gl_wrapper::vector_2d<float>(rand2, rand1));
    m2.vec1(m2.vec0());
    TS_ASSERT(m2.vec0() == gl_wrapper::vector_2d<float>(rand1, rand2));
    TS_ASSERT(m2.vec1() == m2.vec0());

    double rand3 = static_cast<double>(rand() / rand());
    double rand4 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_2X2<double, gl_wrapper::column> m3(
        gl_wrapper::vector_2d<double>(rand3, rand4),
        gl_wrapper::vector_2d<double>(rand4, rand3));
    m3.vec1(m3.vec0());
    TS_ASSERT(m3.vec0() == gl_wrapper::vector_2d<double>(rand3, rand4));
    TS_ASSERT(m3.vec1() == m3.vec0());

    gl_wrapper::matrix_2X2<double, gl_wrapper::row> m4(
        gl_wrapper::vector_2d<double>(rand3, rand4),
        gl_wrapper::vector_2d<double>(rand4, rand3));
    m4.vec0(m4.vec1());
    TS_ASSERT(m4.vec0() == m4.vec1());
    TS_ASSERT(m4.vec1() == gl_wrapper::vector_2d<double>(rand4, rand3));
  }

  void test_matrix_3X3_setters()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    m1.vec0(m1.vec1());
    TS_ASSERT(m1.vec0() == m1.vec1());
    TS_ASSERT(m1.vec1() == gl_wrapper::vector_3d<float>(rand2, rand3, rand1));
    TS_ASSERT(m1.vec2() == gl_wrapper::vector_3d<float>(rand3, rand1, rand2));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
      gl_wrapper::vector_3d<float>(rand1, rand2, rand3),
      gl_wrapper::vector_3d<float>(rand2, rand3, rand1),
      gl_wrapper::vector_3d<float>(rand3, rand1, rand2));
    m2.vec1(m2.vec2());
    TS_ASSERT(m2.vec0() == gl_wrapper::vector_3d<float>(rand1, rand2, rand3));
    TS_ASSERT(m2.vec1() == m2.vec2());
    TS_ASSERT(m2.vec2() == gl_wrapper::vector_3d<float>(rand3, rand1, rand2));

    double rand4 = static_cast<double>(rand() / rand());
    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_3X3<double, gl_wrapper::column> m3(
        gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
        gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
        gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    m3.vec2(m3.vec0());
    TS_ASSERT(m3.vec0() == gl_wrapper::vector_3d<double>(rand4, rand5, rand6));
    TS_ASSERT(m3.vec1() == gl_wrapper::vector_3d<double>(rand5, rand6, rand4));
    TS_ASSERT(m3.vec2() == m3.vec0());

    gl_wrapper::matrix_3X3<double, gl_wrapper::row> m4(
        gl_wrapper::vector_3d<double>(rand4, rand5, rand6),
        gl_wrapper::vector_3d<double>(rand5, rand6, rand4),
        gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
    m4.vec0(m4.vec0());
    TS_ASSERT(m4.vec0() == m4.vec0());
    TS_ASSERT(m4.vec1() == gl_wrapper::vector_3d<double>(rand5, rand6, rand4));
    TS_ASSERT(m4.vec2() == gl_wrapper::vector_3d<double>(rand6, rand4, rand5));
  }

  void test_matrix_4X4_setters()
  {
    srand(static_cast<unsigned int>(time(NULL)));

    float rand1 = static_cast<float>(rand() / rand());
    float rand2 = static_cast<float>(rand() / rand());
    float rand3 = static_cast<float>(rand() / rand());
    float rand4 = static_cast<float>(rand() / rand());

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    m1.vec0(m1.vec3());
    TS_ASSERT(m1.vec0() == m1.vec3());
    TS_ASSERT(m1.vec1() ==
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1));
    TS_ASSERT(m1.vec2() ==
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2));
    TS_ASSERT(m1.vec3() ==
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4),
      gl_wrapper::vector_4d<float>(rand2, rand3, rand4, rand1),
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2),
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));
    m2.vec1(m2.vec0());
    TS_ASSERT(m2.vec0() ==
      gl_wrapper::vector_4d<float>(rand1, rand2, rand3, rand4));
    TS_ASSERT(m2.vec1() == m2.vec0());
    TS_ASSERT(m2.vec2() ==
      gl_wrapper::vector_4d<float>(rand3, rand4, rand1, rand2));
    TS_ASSERT(m2.vec3() ==
      gl_wrapper::vector_4d<float>(rand4, rand1, rand2, rand3));

    double rand5 = static_cast<double>(rand() / rand());
    double rand6 = static_cast<double>(rand() / rand());
    double rand7 = static_cast<double>(rand() / rand());
    double rand8 = static_cast<double>(rand() / rand());

    gl_wrapper::matrix_4X4<double, gl_wrapper::column> m3(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    m3.vec2(m3.vec0());
    TS_ASSERT(m3.vec0() ==
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8));
    TS_ASSERT(m3.vec1() ==
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5));
    TS_ASSERT(m3.vec2() == m3.vec0());
    TS_ASSERT(m3.vec3() ==
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));

    gl_wrapper::matrix_4X4<double, gl_wrapper::row> m4(
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8),
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5),
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6),
      gl_wrapper::vector_4d<double>(rand8, rand5, rand6, rand7));
    m4.vec3(m4.vec1());
    TS_ASSERT(m4.vec0() ==
      gl_wrapper::vector_4d<double>(rand5, rand6, rand7, rand8));
    TS_ASSERT(m4.vec1() ==
      gl_wrapper::vector_4d<double>(rand6, rand7, rand8, rand5));
    TS_ASSERT(m4.vec2() ==
      gl_wrapper::vector_4d<double>(rand7, rand8, rand5, rand6));
    TS_ASSERT(m4.vec3() ==
      m4.vec1());
  }

  /*! \brief This is a test for the member addition (+=) of matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_member_addition()
  {
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> Ir(gl_wrapper::identity);

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m1, Ic, true));

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m2;
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> I(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m2, Ic, true));
    // Unit test the tester
    TS_ASSERT(m1 == m2);

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m3;
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m4(
      gl_wrapper::vector_2d<float>(-0.3f, -0.2f),
      gl_wrapper::vector_2d<float>(0.0f, 0.1f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m3, m4, true));

    m3 = gl_wrapper::matrix_2X2<float, gl_wrapper::column>(
      gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m3, m4, true));

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m5(
      gl_wrapper::vector_2d<float>(FLT_MAX, 0.0f),
      gl_wrapper::vector_2d<float>(1.0f, FLT_MAX));
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m6(
      gl_wrapper::vector_2d<float>(0.0f, 0.0f),
      gl_wrapper::vector_2d<float>(1.0f, exp(1.0f)));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m5, m6, true));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m7;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m7, Ir, true));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m8;
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> rI(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m8, Ir, true));
    TS_ASSERT(m7 == m8);

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m9;
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m10(
        gl_wrapper::vector_2d<float>(-0.3f, -0.2f),
        gl_wrapper::vector_2d<float>(100.0f, -7e-2f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m9, m10, true));

    m9 = gl_wrapper::matrix_2X2<float, gl_wrapper::row>(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m9, m10, true));

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m11(
        gl_wrapper::vector_2d<float>(FLT_MAX, 0.0f),
        gl_wrapper::vector_2d<float>(1.0f, FLT_MAX));
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m12(
        gl_wrapper::vector_2d<float>(0.0f, 0.0f),
        gl_wrapper::vector_2d<float>(1.0f, exp(1.0f)));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m11, m12, true));

    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, true));
    }
  }

  void test_matrix_3X3_member_addition()
  {
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> Ir(gl_wrapper::identity);

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m1, Ic, true));

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m2;
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> I(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m2, Ic, true));
    // Unit test the tester
    TS_ASSERT(m1 == m2);

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m3;
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m4(
      gl_wrapper::vector_3d<float>(-0.3f, -0.2f, -0.1f),
      gl_wrapper::vector_3d<float>(0.0f, 0.1f, 0.2f),
      gl_wrapper::vector_3d<float>(100.0f, -7e-2f, 12.0f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m3, m4, true));

    m3 = gl_wrapper::matrix_3X3<float, gl_wrapper::column>(
      gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m3, m4, true));

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m5(
      gl_wrapper::vector_3d<float>(FLT_MAX, 0.0f, 0.4f),
      gl_wrapper::vector_3d<float>(1.0f, FLT_MAX, 0.7f),
      gl_wrapper::vector_3d<float>(2.0f, 1.1f, FLT_MAX - 0.7f));
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m6(
      gl_wrapper::vector_3d<float>(0.0f, 0.0f, 0.1f),
      gl_wrapper::vector_3d<float>(1.0f, exp(1.0f), 0.7f),
      gl_wrapper::vector_3d<float>(0.1f, static_cast<float>(M_PI), 0.7f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m5, m6, true));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m7;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m7, Ir, true));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m8;
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> rI(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m8, Ir, true));
    TS_ASSERT(m7 == m8);

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m9;
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m10(
        gl_wrapper::vector_3d<float>(-0.3f, -0.2f, -0.1f),
        gl_wrapper::vector_3d<float>(0.0f, 0.1f, 0.2f),
        gl_wrapper::vector_3d<float>(100.0f, -7e-2f, 12.0f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m9, m10, true));

    m9 = gl_wrapper::matrix_3X3<float, gl_wrapper::row>(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m9, m10, true));

    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m11(
        gl_wrapper::vector_3d<float>(FLT_MAX, 0.0f, 0.4f),
        gl_wrapper::vector_3d<float>(1.0f, FLT_MAX, 0.7f),
        gl_wrapper::vector_3d<float>(2.0f, 1.1f, FLT_MAX - 0.7f));
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m12(
        gl_wrapper::vector_3d<float>(0.0f, 0.0f, 0.1f),
        gl_wrapper::vector_3d<float>(1.0f, exp(1.0f), 0.7f),
        gl_wrapper::vector_3d<float>(0.1f, static_cast<float>(M_PI), 0.7f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m11, m12, true));

    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, true));
    }
  }

  void test_matrix_4X4_member_addition()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> Ir(gl_wrapper::identity);

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m1, Ic, true));

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m2;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m2, Ic, true));
    TS_ASSERT(m1 == m2);

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m3;
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m4(
      gl_wrapper::vector_4d<float>(-0.3f, -0.2f, -0.1f, 0.0f),
      gl_wrapper::vector_4d<float>(0.0f, 0.1f, 0.2f, 0.1f),
      gl_wrapper::vector_4d<float>(100.0f, -7e-2f, 12.0f, 100.0f),
      gl_wrapper::vector_4d<float>(100.0f, 7e-2f, -12.0f, -100.0f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m3, m4, true));

    m3 = gl_wrapper::matrix_4X4<float, gl_wrapper::column>(
      gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m3, m4, true));
    TS_ASSERT(m3 != m4);

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m5(
        gl_wrapper::vector_4d<float>(FLT_MAX, 0.0f, 0.4f, 1.4f),
        gl_wrapper::vector_4d<float>(1.0f, FLT_MAX, 0.7f, 2.4f),
        gl_wrapper::vector_4d<float>(2.0f, 1.1f, FLT_MAX - 0.7f, 3.4f),
        gl_wrapper::vector_4d<float>(2.0f, 1.1f, FLT_MAX - 0.7f, 5.4f));
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m6(
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.1f, 2.00f),
        gl_wrapper::vector_4d<float>(1.0f, exp(1.0f), 0.7f, 1.00f),
        gl_wrapper::vector_4d<float>(0.1f,static_cast<float>(M_PI),0.7f,3.0f),
        gl_wrapper::vector_4d<float>(0.1f,static_cast<float>(M_PI),0.7f,3.0f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m5, m6, true));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m7;
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m7, Ir, true));

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m8;
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> rI(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m8, Ir, true));
    TS_ASSERT(m7 == m8);

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m9;
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m10(
        gl_wrapper::vector_4d<float>(-0.3f, -0.2f, -0.1f, 0.1f),
        gl_wrapper::vector_4d<float>(0.0f, 0.1f, 0.2f, 0.1f),
        gl_wrapper::vector_4d<float>(100.0f, -7e-2f, 12.0f, 0.1f),
        gl_wrapper::vector_4d<float>(-10e-12f, 1.21f, 1.88f, 0.1f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m9, m10, true));

    m9 = gl_wrapper::matrix_4X4<float, gl_wrapper::row>(gl_wrapper::identity);
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m9, m10, true));
    TS_ASSERT(m9 != m10);

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m11(
        gl_wrapper::vector_4d<float>(FLT_MAX, 0.0f, 0.4f, 0.5f),
        gl_wrapper::vector_4d<float>(1.0f, FLT_MAX, 0.7f, 0.8f),
        gl_wrapper::vector_4d<float>(2.0f, 1.1f, FLT_MAX, 0.8f),
        gl_wrapper::vector_4d<float>(FLT_MAX, 0.0f, 0.0f, 1.0f));
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m12(
        gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.1f, FLT_MAX),
        gl_wrapper::vector_4d<float>(1.0f, exp(1.0f), 0.7f, 1.0f),
        gl_wrapper::vector_4d<float>(0.1f, (float)M_PI, 0.7f, FLT_MAX),
        gl_wrapper::vector_4d<float>(-1.0f, 0.0f, 1.0f, -1.0f));
    TS_ASSERT(internal::matrix_tester::test_matrix_addition(
      m11, m12, true));

    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, true));
    }
  }

  /*! \brief This is a test for the member subtraction (-=) of matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_member_subtraction()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[3], v[4]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im2(
          gl_wrapper::vector_2d<float>(v[5], v[6]),
          gl_wrapper::vector_2d<float>(v[7], v[8]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, true));
    }
  }


  void test_matrix_3X3_member_subtraction()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, true));
    }
  }

  void test_matrix_4X4_member_subtraction()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> ctest;
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> rtest;

    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
       im1, im2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, true));
    }
  }

  /*! \brief This is a test for the member multiplication (*=)
   * of matrix_2X2 and matrix_3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_member_multiplication()
  {
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> Ir(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1c(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m1r(gl_wrapper::identity);

    // See class above for def of test_matrix_multiplication
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1c, Ic, true));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1r, Ir, true));

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m2c(gl_wrapper::null);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2r(gl_wrapper::null);
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2c, m2c, true));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2r, m2r, true));

    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> m2(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_2X2<float, gl_wrapper::row> m1(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, true));
    }
  }

  void test_matrix_3X3_member_multiplication()
  {
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> Ir(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1c(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m1r(gl_wrapper::identity);

    // See class above for def of test_matrix_multiplication
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1c, Ic, true));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1r, Ir, true));

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m2c(gl_wrapper::null);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2r(gl_wrapper::null);
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2c, m2c, true));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2r, m2r, true));

    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> m2(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> m1(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, true));
    }
  }

  void test_matrix_4X4_member_multiplication()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> Ir(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1c(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m1r(gl_wrapper::identity);

    // See class above for def of test_matrix_multiplication
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1c, Ic, true));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1r, Ir, true));

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m2c(gl_wrapper::null);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2r(gl_wrapper::null);
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2c, m2c, true));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2r, m2r, true));

    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> m2(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> m1(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, true));
    }
  }

  /*! \brief This is a test for the member scalar multiplication (*=)
   * of matrix_2X2 and matrix_4X4 and matrix 4X4 classes
   */
  void test_matrix_2X2_member_scalar_multiplication()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
          v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
        gl_wrapper::vector_2d<float>(v[0], v[1]),
        gl_wrapper::vector_2d<float>(v[2], v[3]));

      float scalar = rand() /
        (0.1f + exp(static_cast<float>(rand() / static_cast<float>(rand()))));

      TS_ASSERT(internal::matrix_tester::test_scalar_matrix_multiplication(
        im1, scalar, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
          v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
        gl_wrapper::vector_2d<float>(v[0], v[1]),
        gl_wrapper::vector_2d<float>(v[2], v[3]));

      float scalar = rand() /
        (0.1f + exp(static_cast<float>(rand() / static_cast<float>(rand()))));

      TS_ASSERT(internal::matrix_tester::test_scalar_matrix_multiplication(
        im1, scalar, true));
    }
  }

  void test_matrix_3X3_member_scalar_multiplication()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
          v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
        gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
        gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
        gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      float scalar = rand() /
        (0.1f + exp(static_cast<float>(rand() / static_cast<float>(rand()))));

      TS_ASSERT(internal::matrix_tester::test_scalar_matrix_multiplication(
        im1, scalar, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
          v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
        gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
        gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
        gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      float scalar = rand() /
        (0.1f + exp(static_cast<float>(rand() / static_cast<float>(rand()))));

      TS_ASSERT(internal::matrix_tester::test_scalar_matrix_multiplication(
        im1, scalar, true));
    }
  }

  void test_matrix_4X4_member_scalar_multiplication()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
          v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
        gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
        gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
        gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
        gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      float scalar = rand() /
        (0.1f + exp(static_cast<float>(rand() / static_cast<float>(rand()))));

      TS_ASSERT(internal::matrix_tester::test_scalar_matrix_multiplication(
        im1, scalar, true));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
          v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
        gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
        gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
        gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
        gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      float scalar = rand() /
        (0.1f + exp(static_cast<float>(rand() / static_cast<float>(rand()))));

      TS_ASSERT(internal::matrix_tester::test_scalar_matrix_multiplication(
        im1, scalar, true));
    }
  }

  /*! \brief This is a test for the +operator defined outside of matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_addition_operator()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
        gl_wrapper::vector_2d<float>(v[0], v[1]),
        gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im2(
        gl_wrapper::vector_2d<float>(v[4], v[5]),
        gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
        gl_wrapper::vector_2d<float>(v[0], v[1]),
        gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im2(
        gl_wrapper::vector_2d<float>(v[4], v[5]),
        gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, false));
    }
  }

  void test_matrix_3X3_addition_operator()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, false));
    }
  }

  void test_matrix_4X4_addition_operator()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_addition(
        im1, im2, false));
    }
  }

  /*! \brief This is a test for the -operator defined outside of matrix_2X2 and
   * matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_subtraction_operator()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, false));
    }
  }

  void test_matrix_3X3_subtraction_operator()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, false));
    }
  }

  void test_matrix_4X4_subtraction_operator()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_matrix_subtraction(
        im1, im2, false));
    }
  }

  /*! \brief This is a test for the -operator defined outside of matrix_2X2 and
   * and matrix 3X3 and matrix 4X4 classes which is for the inverse of a matrix
   */
  void test_matrix_2X2_inverse_operator()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_inverse(im1));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[2 * 2 * 2];
      for (unsigned short j = 0; j < (2 * 2 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
          gl_wrapper::vector_2d<float>(v[0], v[1]),
          gl_wrapper::vector_2d<float>(v[2], v[3]));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im2(
          gl_wrapper::vector_2d<float>(v[4], v[5]),
          gl_wrapper::vector_2d<float>(v[6], v[7]));

      TS_ASSERT(internal::matrix_tester::test_inverse(im1));
    }
  }

  void test_matrix_3X3_inverse_operator()
  {
    // This set of tests cover random number cases
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_inverse(im1));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[3 * 3 * 2];
      for (unsigned short j = 0; j < (3 * 3 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
          gl_wrapper::vector_3d<float>(v[0], v[1], v[2]),
          gl_wrapper::vector_3d<float>(v[3], v[4], v[5]),
          gl_wrapper::vector_3d<float>(v[6], v[7], v[8]));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im2(
          gl_wrapper::vector_3d<float>(v[9], v[10], v[11]),
          gl_wrapper::vector_3d<float>(v[12], v[13], v[14]),
          gl_wrapper::vector_3d<float>(v[15], v[16], v[17]));

      TS_ASSERT(internal::matrix_tester::test_inverse(im1));
    }
  }

  void test_matrix_4X4_inverse_operator()
  {
    srand(static_cast<int>(time(NULL)));
    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_inverse(im1));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      float v[4 * 4 * 2];
      for (unsigned short j = 0; j < (4 * 4 * 2); ++j) {
        v[j] = rand() / 2.0f;
      }

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
          gl_wrapper::vector_4d<float>(v[0], v[1], v[2], v[3]),
          gl_wrapper::vector_4d<float>(v[4], v[5], v[6], v[7]),
          gl_wrapper::vector_4d<float>(v[8], v[9], v[10], v[11]),
          gl_wrapper::vector_4d<float>(v[12], v[13], v[14], v[15]));

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im2(
          gl_wrapper::vector_4d<float>(v[16], v[17], v[18], v[19]),
          gl_wrapper::vector_4d<float>(v[20], v[21], v[22], v[23]),
          gl_wrapper::vector_4d<float>(v[24], v[25], v[26], v[27]),
          gl_wrapper::vector_4d<float>(v[28], v[29], v[30], v[31]));

      TS_ASSERT(internal::matrix_tester::test_inverse(im1));
    }
  }

  /*! \brief This is a test for the member multiplication (*=)
   * of matrix_2X2 and matrix 3X3 and matrix 3X3 classes
   */
  void test_matrix_2X2_multiplication()
  {
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> Ir(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1c(gl_wrapper::identity);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m1r(gl_wrapper::identity);

    // See class above for def of test_matrix_multiplication
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1c, Ic, false));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1r, Ir, false));

    gl_wrapper::matrix_2X2<float, gl_wrapper::column> m2c(gl_wrapper::null);
    gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2r(gl_wrapper::null);
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2c, m2c, false));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2r, m2r, false));

    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      gl_wrapper::matrix_2X2<float, gl_wrapper::column> m2(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_2X2<float, gl_wrapper::row> m1(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, false));
    }
  }

  void test_matrix_3X3_multiplication()
  {
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> Ir(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1c(gl_wrapper::identity);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m1r(gl_wrapper::identity);

    // See class above for def of test_matrix_multiplication
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1c, Ic, false));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1r, Ir, false));

    gl_wrapper::matrix_3X3<float, gl_wrapper::column> m2c(gl_wrapper::null);
    gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2r(gl_wrapper::null);
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2c, m2c, false));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2r, m2r, false));

    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      gl_wrapper::matrix_3X3<float, gl_wrapper::column> m2(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> m1(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, false));
    }
  }

  void test_matrix_4X4_multiplication()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> Ic(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> Ir(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1c(gl_wrapper::identity);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m1r(gl_wrapper::identity);

    // See class above for def of test_matrix_multiplication
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1c, Ic, false));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m1r, Ir, false));

    gl_wrapper::matrix_4X4<float, gl_wrapper::column> m2c(gl_wrapper::null);
    gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2r(gl_wrapper::null);
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2c, m2c, false));
    TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
      m2r, m2r, false));

    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      gl_wrapper::matrix_4X4<float, gl_wrapper::column> m2(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, false));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> m1(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      TS_ASSERT(internal::matrix_tester::test_matrix_multiplication(
        m1, m2, false));
    }
  }

  /*! \brief This is a test for the vector multiplication (*=)
   * by matrix_3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_vector_2d_multiplication()
  {
    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      gl_wrapper::vector_2d<float> v1(rand()/f, rand()/f);

      TS_ASSERT(internal::matrix_tester::test_matrix_vector_multiplication(
        m1, v1));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_2X2<float, gl_wrapper::row> m1(
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f),
        gl_wrapper::vector_2d<float>(rand()/f, rand()/f));

      gl_wrapper::vector_2d<float> v1(rand()/f, rand()/f);

      TS_ASSERT(internal::matrix_tester::test_matrix_vector_multiplication(
        m1, v1));
    }
  }

  void test_matrix_3X3_vector_3d_multiplication()
  {
    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      gl_wrapper::vector_3d<float> v1(rand()/f, rand()/f, rand()/f);

      TS_ASSERT(internal::matrix_tester::test_matrix_vector_multiplication(
        m1, v1));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> m1(
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_3d<float>(rand()/f, rand()/f, rand()/f));

      gl_wrapper::vector_3d<float> v1(rand()/f, rand()/f, rand()/f);

      TS_ASSERT(internal::matrix_tester::test_matrix_vector_multiplication(
        m1, v1));
    }
  }

  void test_matrix_4X4_vector_4d_multiplication()
  {
    srand(static_cast<int>(time(NULL)));
    const float f = FLT_MAX;
    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      gl_wrapper::vector_4d<float> v1(rand()/f, rand()/f, rand()/f, rand()/f);

      TS_ASSERT(internal::matrix_tester::test_matrix_vector_multiplication(
        m1, v1));
    }

    for (unsigned short i = 0; i < 100; ++i) {
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> m1(
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f),
        gl_wrapper::vector_4d<float>(rand()/f, rand()/f, rand()/f, rand()/f)
      );

      gl_wrapper::vector_4d<float> v1(rand()/f, rand()/f, rand()/f, rand()/f);

      TS_ASSERT(internal::matrix_tester::test_matrix_vector_multiplication(
        m1, v1));
    }
  }

  /*! \brief This is a test for the transpose and transposed methods
   * of matrix_2X2 and matrix_3X3 and matrix_4X4 classes
   */
  void test_matrix_2X2_transposed()
  {
    TS_ASSERT(internal::matrix_tester::test_transpose(
      gl_wrapper::matrix_2X2<float, gl_wrapper::column>(gl_wrapper::identity),
      true));

    srand(static_cast<int>(time(NULL)));
    for (int i = 0; i < 100; ++i) {
      float d = FLT_MAX;
      gl_wrapper::matrix_2X2<float, gl_wrapper::column> im1(
        gl_wrapper::vector_2d<float>(rand()/d, rand()/d),
        gl_wrapper::vector_2d<float>(rand()/d, rand()/d));

      TS_ASSERT(internal::matrix_tester::test_transpose(im1, true));
      TS_ASSERT(internal::matrix_tester::test_transpose(im1, false));
    }

    for (int i = 0; i < 100; ++i) {
      float d = FLT_MAX;
      gl_wrapper::matrix_2X2<float, gl_wrapper::row> im1(
        gl_wrapper::vector_2d<float>(rand()/d, rand()/d),
        gl_wrapper::vector_2d<float>(rand()/d, rand()/d));

      TS_ASSERT(internal::matrix_tester::test_transpose(im1, true));
      TS_ASSERT(internal::matrix_tester::test_transpose(im1, false));
    }
  }

  void test_matrix_3X3_transposed()
  {
    TS_ASSERT(internal::matrix_tester::test_transpose(
      gl_wrapper::matrix_3X3<float, gl_wrapper::column>(gl_wrapper::identity),
      true));

    srand(static_cast<int>(time(NULL)));
    for (int i = 0; i < 100; ++i) {
      float d = FLT_MAX;
      gl_wrapper::matrix_3X3<float, gl_wrapper::column> im1(
        gl_wrapper::vector_3d<float>(rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_3d<float>(rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_3d<float>(rand()/d, rand()/d, rand()/d));

      TS_ASSERT(internal::matrix_tester::test_transpose(im1, true));
      TS_ASSERT(internal::matrix_tester::test_transpose(im1, false));
    }

    for (int i = 0; i < 100; ++i) {
      float d = FLT_MAX;
      gl_wrapper::matrix_3X3<float, gl_wrapper::row> im1(
        gl_wrapper::vector_3d<float>(rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_3d<float>(rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_3d<float>(rand()/d, rand()/d, rand()/d));

      TS_ASSERT(internal::matrix_tester::test_transpose(im1, true));
      TS_ASSERT(internal::matrix_tester::test_transpose(im1, false));
    }
  }

  void test_matrix_4X4_transposed()
  {
    TS_ASSERT(internal::matrix_tester::test_transpose(
      gl_wrapper::matrix_4X4<float, gl_wrapper::column>(gl_wrapper::identity),
      true));

    srand(static_cast<int>(time(NULL)));
    for (int i = 0; i < 100; ++i) {
      float d = FLT_MAX;
      gl_wrapper::matrix_4X4<float, gl_wrapper::column> im1(
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d)
      );

      TS_ASSERT(internal::matrix_tester::test_transpose(im1, true));
      TS_ASSERT(internal::matrix_tester::test_transpose(im1, false));
    }

    for (int i = 0; i < 100; ++i) {
      float d = FLT_MAX;
      gl_wrapper::matrix_4X4<float, gl_wrapper::row> im1(
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d),
        gl_wrapper::vector_4d<float>(rand()/d, rand()/d, rand()/d, rand()/d)
      );

      TS_ASSERT(internal::matrix_tester::test_transpose(im1, true));
      TS_ASSERT(internal::matrix_tester::test_transpose(im1, false));
    }
  }

  /*! \brief This is a test for calculating the determinant of a matrix_2X2
   * and matrix_3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_determinant()
  {
    // This initial matrix was derived from www.purplemath.com/modules/
    // determs.htm
    gl_wrapper::matrix_2X2<float, gl_wrapper::column> mc1(
      gl_wrapper::vector_2d<float>(1.0f, 3.0f),
    gl_wrapper::vector_2d<float>(2.0f, 4.0f));
    TS_ASSERT(mc1.determinant() == -2.0f);

    gl_wrapper::matrix_2X2<float, gl_wrapper::row> mr1(
      gl_wrapper::vector_2d<float>(1.0f, 2.0f),
    gl_wrapper::vector_2d<float>(3.0f, 4.0f));
    TS_ASSERT(mr1.determinant() == -2.0f);
  }

  void test_matrix_3X3_determinant()
  {
    // This initial matrix was derived from http://www.wikihow.com/
    // Find-the-Determinant-of-a-3X3-Matrix
    gl_wrapper::matrix_3X3<float, gl_wrapper::column> mc1(
      gl_wrapper::vector_3d<float>(1.0f, 2.0f, 4.0f),
      gl_wrapper::vector_3d<float>(5.0f, 4.0f, 6.0f),
      gl_wrapper::vector_3d<float>(3.0f, 7.0f, 2.0f));
    TS_ASSERT(mc1.determinant() == 74.0);


    gl_wrapper::matrix_3X3<float, gl_wrapper::row> mr1(
      gl_wrapper::vector_3d<float>(1.0f, 5.0f, 3.0f),
      gl_wrapper::vector_3d<float>(2.0f, 4.0f, 7.0f),
      gl_wrapper::vector_3d<float>(4.0f, 6.0f, 2.0f));
    TS_ASSERT(mr1.determinant() == 74.0);
  }

  void test_matrix_4X4_determinant()
  {
    gl_wrapper::matrix_4X4<float, gl_wrapper::column> mc1(
      gl_wrapper::vector_4d<float>(3.0, 0.8f, -0.142857143f, 0.0f),
      gl_wrapper::vector_4d<float>(0.0f, 0.0f, 0.0f, 1.0f),
      gl_wrapper::vector_4d<float>(-1.0, 1.0f, -5.0f, 0.0f),
      gl_wrapper::vector_4d<float>(0.0f, 2.0f, 0.0f, 0.0f));
    TS_ASSERT_DELTA(mc1.determinant(), 30.2857151, 1e-8);

    gl_wrapper::matrix_4X4<float, gl_wrapper::row> mr1(
      gl_wrapper::vector_4d<float>(3.0f, 0.0f, -1.0f, 0.0f),
      gl_wrapper::vector_4d<float>(0.8f, 0.0f, 1.0f, 2.0f),
      gl_wrapper::vector_4d<float>(-0.142857143f, 0.0f, -5.0f, 0.0f),
      gl_wrapper::vector_4d<float>(0.0f, 1.0f, 0.0f, 0.0f));
    TS_ASSERT_DELTA(mr1.determinant(), 30.2857151, 1e-8);
  }

  /*! \brief This is a test for the inverted and invert methods
   * of matrix_2X2 and and matrix 3X3 and matrix 4X4 classes
   */
  void test_matrix_2X2_inversion()
  {
    {
      const gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1(
        gl_wrapper::vector_2d<float>(-3, 4),
        gl_wrapper::vector_2d<float>(-6, 5));

      const gl_wrapper::matrix_2X2<float, gl_wrapper::column> m1I(
        gl_wrapper::vector_2d<float>(0.55556f, -0.44444f),
        gl_wrapper::vector_2d<float>(0.66667f, -0.33333f));

      bool inverted =
        internal::matrix_tester::test_inversion(m1, m1I, true, 1e-005f);

      TS_ASSERT(inverted);
    }

    {
      const gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2(
        gl_wrapper::vector_2d<float>(-3, -6),
        gl_wrapper::vector_2d<float>(4, 5));

      const gl_wrapper::matrix_2X2<float, gl_wrapper::row> m2I(
        gl_wrapper::vector_2d<float>(0.55556f, 0.66667f),
        gl_wrapper::vector_2d<float>(-0.44444f, -0.33333f));

      bool inverted =
        internal::matrix_tester::test_inversion(m2, m2I, true, 1e-005f);

      TS_ASSERT(inverted);
    }

    const gl_wrapper::matrix_2X2<float, gl_wrapper::column> m3(
      gl_wrapper::identity);
    TS_ASSERT_EQUALS(m3.inversion(), m3);
  }

  void test_matrix_3X3_inversion()
  {
    {
      const gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1(
        gl_wrapper::vector_3d<float>(-3, 4, -9),
        gl_wrapper::vector_3d<float>(-1, 2, -6),
        gl_wrapper::vector_3d<float>(-6, 5, 2));

      const gl_wrapper::matrix_3X3<float, gl_wrapper::column> m1I(
        gl_wrapper::vector_3d<float>(-2.61538f, 4.07692f, 0.46154f),
        gl_wrapper::vector_3d<float>(-2.92308f, 4.61538f, 0.69231f),
        gl_wrapper::vector_3d<float>(-0.53846f, 0.69231f, 0.15385f));

      bool inverted =
        internal::matrix_tester::test_inversion(m1, m1I, true, 1e-005f);

      TS_ASSERT(inverted);
    }

    {
      const gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2(
        gl_wrapper::vector_3d<float>(-3, -1, -6),
        gl_wrapper::vector_3d<float>(4, 2, 5),
        gl_wrapper::vector_3d<float>(-9, -6, 2));

      const gl_wrapper::matrix_3X3<float, gl_wrapper::row> m2I(
        gl_wrapper::vector_3d<float>(-2.61538f, -2.92308f, -0.53846f),
        gl_wrapper::vector_3d<float>(4.07692f, 4.61538f, 0.69231f),
        gl_wrapper::vector_3d<float>(0.46154f, 0.69231f, 0.15385f));

      bool inverted =
        internal::matrix_tester::test_inversion(m2, m2I, true, 1e-005f);

      TS_ASSERT(inverted);
    }

    const gl_wrapper::matrix_3X3<float, gl_wrapper::column> m3(
      gl_wrapper::identity);
    TS_ASSERT_EQUALS(m3.inversion(), m3);
  }

  void test_matrix_4X4_inversion()
  {
    {
      const gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1(
        gl_wrapper::vector_4d<float>(-3, 4, 4, -9),
        gl_wrapper::vector_4d<float>(-1, 2, 3, -6),
        gl_wrapper::vector_4d<float>(-6, 5, -4, 2),
        gl_wrapper::vector_4d<float>(-1, -1, 1, 1));

      const gl_wrapper::matrix_4X4<float, gl_wrapper::column> m1I(
        gl_wrapper::vector_4d<float>(-3.000000f,4.692808f,0.538462f,0.076923f),
        gl_wrapper::vector_4d<float>(-6.000000f,9.538462f,1.307692f,0.615385f),
        gl_wrapper::vector_4d<float>(-5.000000f,8.000000f,1.000000f,1.000000f),
        gl_wrapper::vector_4d<float>(-4.000000f,6.230769f,0.846154f,0.692308f));

      bool inverted =
        internal::matrix_tester::test_inversion(m1, m1I, true, 1e-003f);

      TS_ASSERT(inverted);
    }

    {
      const gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2(
        gl_wrapper::vector_4d<float>(-3, -1, -6, -1),
        gl_wrapper::vector_4d<float>(4, 2, 5, -1),
        gl_wrapper::vector_4d<float>(4, 3, -4, 1),
        gl_wrapper::vector_4d<float>(-9, -6, 2, 1));

      const gl_wrapper::matrix_4X4<float, gl_wrapper::row> m2I(
        gl_wrapper::vector_4d<float>(-3.00000f,-6.00000f,-5.00000f,-4.00000f),
        gl_wrapper::vector_4d<float>(4.692308f,9.538462f,8.000000f,6.230769f),
        gl_wrapper::vector_4d<float>(0.538462f,1.307962f,1.000000f,0.846154f),
        gl_wrapper::vector_4d<float>(0.076923f,0.615385f,1.000000f,0.692308f));

      bool inverted =
        internal::matrix_tester::test_inversion(m2, m2I, true, 1e-003f);

      TS_ASSERT(inverted);
    }

    const gl_wrapper::matrix_4X4<float, gl_wrapper::column> m3(
      gl_wrapper::identity);
    TS_ASSERT_EQUALS(m3.inversion(), m3);
  }
};

#endif
