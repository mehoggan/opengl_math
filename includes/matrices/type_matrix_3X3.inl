/* Copyright (C)
 *
 * Copyright 2013 Matthew Everett Hoggan
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writting, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
namespace opengl_math
{
  /// Constructors
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML>::matrix_3X3(matrix_type type)
  {
    if (type == null) {
      _v0 = vector_3d<T>();
      _v1 = vector_3d<T>();
      _v2 = vector_3d<T>();
    } else if (type == identity) {
      _v0 = vector_3d<T>(T(1.0), T(0.0), T(0.0));
      _v1 = vector_3d<T>(T(0.0), T(1.0), T(0.0));
      _v2 = vector_3d<T>(T(0.0), T(0.0), T(1.0));
    }
  }

  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML>::matrix_3X3(const vector_3d<T> &v0, const vector_3d<T> &v1,
    const vector_3d<T> &v2) :
    _v0(v0),
    _v1(v1),
    _v2(v2)
  {}

  /// Copy constructor
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML>::matrix_3X3(const matrix_3X3<T, ML> &rhs) :
    _v0(rhs._v0),
    _v1(rhs._v1),
    _v2(rhs._v2)
  {}

  /// Assignment operator
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> &matrix_3X3<T, ML>::operator=(matrix_3X3<T, ML> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Sub-index operator
  template <typename T, matrix_layout ML>
  vector_3d<T> &matrix_3X3<T, ML>::operator[](unsigned short index)
  {
    assert(index < 3);

    switch(index)
    {
      case(0): return _v0;
      case(1): return _v1;
      case(2): return _v2;
      default: return _v0;
    }
    return _v0;
  }

  template <typename T, matrix_layout ML>
  const vector_3d<T> &matrix_3X3<T, ML>::operator[](unsigned short index) const
  {
    assert(index < 3);

    switch(index)
    {
      case(0): return _v0;
      case(1): return _v1;
      case(2): return _v2;
      default: return _v0;
    }
    return _v0;
  }

  /// Setters
  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::vec0(const vector_3d<T> &v0)
  {
    _v0 = v0;
  }

  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::vec1(const vector_3d<T> &v1)
  {
    _v1 = v1;
  }

  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::vec2(const vector_3d<T> &v2)
  {
    _v2 = v2;
  }

  /// Getters
  template <typename T, matrix_layout ML>
  vector_3d<T> matrix_3X3<T, ML>::vec0() const
  {
    return _v0;
  }

  template <typename T, matrix_layout ML>
  vector_3d<T> matrix_3X3<T, ML>::vec1() const
  {
    return _v1;
  }

  template <typename T, matrix_layout ML>
  vector_3d<T> matrix_3X3<T, ML>::vec2() const
  {
    return _v2;
  }

  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::operator+=(const matrix_3X3 &rhs)
  {
    _v0 += rhs._v0;
    _v1 += rhs._v1;
    _v2 += rhs._v2;
  }

  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::operator-=(const matrix_3X3 &rhs)
  {
    _v0 -= rhs._v0;
    _v1 -= rhs._v1;
    _v2 -= rhs._v2;
  }

  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::operator*=(const matrix_3X3 &rhs)
  {
    if (ML == column) {
      /* [col][row] */
      vector_3d<T> v0(
        _v0[0]*rhs[0][0]+_v1[0]*rhs[0][1]+_v2[0]*rhs[0][2],
        _v0[1]*rhs[0][0]+_v1[1]*rhs[0][1]+_v2[1]*rhs[0][2],
        _v0[2]*rhs[0][0]+_v1[2]*rhs[0][1]+_v2[2]*rhs[0][2]);
      vector_3d<T>v1(
        _v0[0]*rhs[1][0]+_v1[0]*rhs[1][1]+_v2[0]*rhs[1][2],
        _v0[1]*rhs[1][0]+_v1[1]*rhs[1][1]+_v2[1]*rhs[1][2],
        _v0[2]*rhs[1][0]+_v1[2]*rhs[1][1]+_v2[2]*rhs[1][2]);
      vector_3d<T>v2(
        _v0[0]*rhs[2][0]+_v1[0]*rhs[2][1]+_v2[0]*rhs[2][2],
        _v0[1]*rhs[2][0]+_v1[1]*rhs[2][1]+_v2[1]*rhs[2][2],
        _v0[2]*rhs[2][0]+_v1[2]*rhs[2][1]+_v2[2]*rhs[2][2]);
      /* construct matrix using column vectors */
      (*this) = matrix_3X3<T, ML>(v0, v1, v2);
    } else if (ML == row) {
      /* [row][col] */
      vector_3d<T> v0(
        _v0[0]*rhs[0][0]+_v0[1]*rhs[1][0]+_v0[2]*rhs[2][0],
        _v0[0]*rhs[0][1]+_v0[1]*rhs[1][1]+_v0[2]*rhs[2][1],
        _v0[0]*rhs[0][2]+_v0[1]*rhs[1][2]+_v0[2]*rhs[2][2]);
      vector_3d<T> v1(
        _v1[0]*rhs[0][0]+_v1[1]*rhs[1][0]+_v1[2]*rhs[2][0],
        _v1[0]*rhs[0][1]+_v1[1]*rhs[1][1]+_v1[2]*rhs[2][1],
        _v1[0]*rhs[0][2]+_v1[1]*rhs[1][2]+_v1[2]*rhs[2][2]);
      vector_3d<T> v2(
        _v2[0]*rhs[0][0]+_v2[1]*rhs[1][0]+_v2[2]*rhs[2][0],
        _v2[0]*rhs[0][1]+_v2[1]*rhs[1][1]+_v2[2]*rhs[2][1],
        _v2[0]*rhs[0][2]+_v2[1]*rhs[1][2]+_v2[2]*rhs[2][2]);
      /* construct matrix using row vectors */
      (*this) = matrix_3X3<T, ML>(v0, v1, v2);
    }
  }

  template <typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::operator*=(const T &rhs)
  {
      _v0 *= rhs;
      _v1 *= rhs;
      _v2 *= rhs;
  }

  template <typename U, matrix_layout ML>
  void swap(matrix_3X3<U, ML> &lhs, matrix_3X3<U, ML> &rhs)
  {
    std::swap(lhs[0], rhs[0]);
    std::swap(lhs[1], rhs[1]);
    std::swap(lhs[2], rhs[2]);
  }

  /// Arithmetic operators
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> operator+(const matrix_3X3<T, ML> &m1,
    const matrix_3X3<T, ML> &m2)
  {
    return matrix_3X3<T, ML>(
      m1.vec0() + m2.vec0(),
      m1.vec1() + m2.vec1(),
      m1.vec2() + m2.vec2());
  }

  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> operator-(const matrix_3X3<T, ML> &m1,
    const matrix_3X3<T, ML> &m2)
  {
    return matrix_3X3<T, ML>(
      m1.vec0() - m2.vec0(),
      m1.vec1() - m2.vec1(),
      m1.vec2() - m2.vec2());
  }

  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> operator-(const matrix_3X3<T, ML> &m1)
  {
    return matrix_3X3<T, ML>(-m1.vec0(), -m1.vec1(), -m1.vec2());
  }

  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> operator*(const T &s, const matrix_3X3<T, ML> &m1)
  {
    return matrix_3X3<T, ML>(
      s * m1.vec0(),
      s * m1.vec1(),
      s * m1.vec2());
  }

  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> operator*(const matrix_3X3<T, ML> &m1,
    const matrix_3X3<T, ML> &m2)
  {
    if (ML == column) {
      /* [col][row] */
      vector_3d<T> v0(
        m1[0][0]*m2[0][0]+m1[1][0]*m2[0][1]+m1[2][0]*m2[0][2],
        m1[0][1]*m2[0][0]+m1[1][1]*m2[0][1]+m1[2][1]*m2[0][2],
        m1[0][2]*m2[0][0]+m1[1][2]*m2[0][1]+m1[2][2]*m2[0][2]);
      vector_3d<T>v1(
        m1[0][0]*m2[1][0]+m1[1][0]*m2[1][1]+m1[2][0]*m2[1][2],
        m1[0][1]*m2[1][0]+m1[1][1]*m2[1][1]+m1[2][1]*m2[1][2],
        m1[0][2]*m2[1][0]+m1[1][2]*m2[1][1]+m1[2][2]*m2[1][2]);
      vector_3d<T>v2(
        m1[0][0]*m2[2][0]+m1[1][0]*m2[2][1]+m1[2][0]*m2[2][2],
        m1[0][1]*m2[2][0]+m1[1][1]*m2[2][1]+m1[2][1]*m2[2][2],
        m1[0][2]*m2[2][0]+m1[1][2]*m2[2][1]+m1[2][2]*m2[2][2]);
      /* construct matrix using column vectors */
      return matrix_3X3<T, ML>(v0, v1, v2);
    } else if (ML == row) {
      /* [row][col] */
      vector_3d<T> v0(
        m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0]+m1[0][2]*m2[2][0],
        m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1]+m1[0][2]*m2[2][1],
        m1[0][0]*m2[0][2]+m1[0][1]*m2[1][2]+m1[0][2]*m2[2][2]);
      vector_3d<T> v1(
        m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0]+m1[1][2]*m2[2][0],
        m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1]+m1[1][2]*m2[2][1],
        m1[1][0]*m2[0][2]+m1[1][1]*m2[1][2]+m1[1][2]*m2[2][2]);
      vector_3d<T> v2(
        m1[2][0]*m2[0][0]+m1[2][1]*m2[1][0]+m1[2][2]*m2[2][0],
        m1[2][0]*m2[0][1]+m1[2][1]*m2[1][1]+m1[2][2]*m2[2][1],
        m1[2][0]*m2[0][2]+m1[2][1]*m2[1][2]+m1[2][2]*m2[2][2]);
      /* construct matrix using row vectors */
      return matrix_3X3<T, ML>(v0, v1, v2);
    }
  }

  /*! \brief This function returns the product of a 3d vector multiplied by a
   * 3 X 3 matrix
   */
  template <typename T, matrix_layout ML>
  vector_3d<T> operator*(const matrix_3X3<T, ML> &m, const vector_3d<T> &v)
  {
    if (ML == column) {
      /* [col][row] */
      return vector_3d<T>(
        m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2],
        m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2],
        m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2]);
    } else {
      /* [row][col] */
      return vector_3d<T>(
        m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2],
        m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2],
        m[2][1] * v[0] + m[2][1] * v[1] + m[2][2] * v[2]);
    }
  }

  /*! \brief This function returns the product of a 3 X 3 matrix multiplied by a
  * 3d vector
  */
  template <typename T, matrix_layout ML>
  vector_3d<T> operator*(const vector_3d<T> &v, const matrix_3X3<T, ML> &m)
  {
    if (ML == column) {
      /* [col][row] */
      return vector_3d<T>(
        v[0] * m[0][0] + v[1] * m[0][1] * + v[2] * m[0][2],
        v[0] * m[1][0] + v[1] * m[1][1] * + v[2] * m[1][2],
        v[0] * m[2][0] + v[1] * m[2][1] * + v[2] * m[2][2]);
    } else {
      /* [row][col] */
      return vector_3d<T>(
        v[0] * m[0][0] + v[1] * m[1][0] + v[2] * m[2][0],
        v[0] * m[0][1] + v[1] * m[1][1] + v[2] * m[2][1],
        v[0] * m[0][2] + v[1] * m[1][2] + v[2] * m[2][2]);
    }
  }

  /// Output operators (Output works with Octave and Matlab)
  template <typename T, matrix_layout ML>
  std::ostream &operator<<(std::ostream &out, const matrix_3X3<T, ML> &rhs)
  {
    if (ML == row) {
      return out << "[" << rhs.vec0() << "; " << rhs.vec1() << "; " <<
        rhs.vec2() << "]";
    } else if (ML == column) {
      return out
        << "["
        << rhs.vec0().x() << ", " << rhs.vec1().x() << ", "
        << rhs.vec2().x() << "; "
        << rhs.vec0().y() << ", " << rhs.vec1().y() << ", "
        << rhs.vec2().y() << "; "
        << rhs.vec0().z() << ", " << rhs.vec1().z() << ", "
        << rhs.vec2().z()
        << "]";
    }
  }

  template<typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::transpose()
  {
    (*this) = transposed();
  }

  template<typename T, matrix_layout ML>
  matrix_3X3<T, ML> matrix_3X3<T, ML>::transposed() const
  {
    return matrix_3X3(
      vector_3d<T>(_v0[0], _v1[0], _v2[0]),
      vector_3d<T>(_v0[1], _v1[1], _v2[1]),
      vector_3d<T>(_v0[2], _v1[2], _v2[2]));
  }

  template<typename T, matrix_layout ML>
  T matrix_3X3<T, ML>::determinant() const
  {
    T scalar0(0);
    T scalar1(0);
    T scalar2(0);
    T det0(0);
    T det1(0);
    T det2(0);

    if (ML == column) {
      scalar0 = _v0[0];
      det0 = matrix_2X2<T, ML>(
        vector_2d<T>(_v1[1], _v1[2]),
        vector_2d<T>(_v2[1], _v2[2])).determinant();

      scalar1 = _v1[0];
      det1 = matrix_2X2<T, ML>(
        vector_2d<T>(_v0[1], _v0[2]),
        vector_2d<T>(_v2[1], _v2[2])).determinant();

      scalar2 = _v2[0];
      det2 = matrix_2X2<T, ML>(
        vector_2d<T>(_v0[1], _v0[2]),
        vector_2d<T>(_v1[1], _v1[2])).determinant();
    } else {
      scalar0 = _v0[0];
      det0 = matrix_2X2<T, ML>(
        vector_2d<T>(_v1[1], _v1[2]),
        vector_2d<T>(_v2[1], _v2[2])).determinant();

      scalar1 = _v0[1];
      det1 = matrix_2X2<T, ML>(
        vector_2d<T>(_v1[0], _v1[2]),
        vector_2d<T>(_v2[0], _v2[2])).determinant();

      scalar2 = _v0[2];
      det2 = matrix_2X2<T, ML>(
        vector_2d<T>(_v1[0], _v1[1]),
        vector_2d<T>(_v2[0], _v2[1])).determinant();
    }

    T det = scalar0 * det0 - scalar1 * det1 + scalar2 * det2;
    return det;
  }

  template<typename T, matrix_layout ML>
  matrix_3X3<T, ML> matrix_3X3<T, ML>::adjugate() const
  {
    matrix_3X3<T, ML> adjugate(null);

    // NOTE: This algorithm works the same on both row and column layouts
    // indicies.
    // Column 0 or Row 0 Based on ML type
    adjugate[0][0] = matrix_2X2<T, ML>(
      vector_2d<T>(_v1[1], _v2[1]),
      vector_2d<T>(_v1[2], _v2[2])).determinant();
    adjugate[0][1] = -1 * matrix_2X2<T, ML>(
      vector_2d<T>(_v0[1], _v2[1]),
      vector_2d<T>(_v0[2], _v2[2])).determinant();
    adjugate[0][2] = matrix_2X2<T, ML>(
      vector_2d<T>(_v0[1], _v1[1]),
      vector_2d<T>(_v0[2], _v1[2])).determinant();

    // Column 1 or Row 1 Based on ML type
    adjugate[1][0] = -1 * matrix_2X2<T, ML>(
      vector_2d<T>(_v1[0], _v2[0]),
      vector_2d<T>(_v1[2], _v2[2])).determinant();
    adjugate[1][1] = matrix_2X2<T, ML>(
      vector_2d<T>(_v0[0], _v2[0]),
      vector_2d<T>(_v0[2], _v2[2])).determinant();
    adjugate[1][2] = -1 * matrix_2X2<T, ML>(
      vector_2d<T>(_v0[0], _v1[0]),
      vector_2d<T>(_v0[2], _v1[2])).determinant();

    // Column 2 or Row 2 Based on ML type
    adjugate[2][0] = matrix_2X2<T, ML>(
      vector_2d<T>(_v1[0], _v2[0]),
      vector_2d<T>(_v1[1], _v2[1])).determinant();
    adjugate[2][1] = -1 * matrix_2X2<T, ML>(
      vector_2d<T>(_v0[0], _v2[0]),
      vector_2d<T>(_v0[1], _v2[1])).determinant();
    adjugate[2][2] = matrix_2X2<T, ML>(
      vector_2d<T>(_v0[0], _v1[0]),
      vector_2d<T>(_v0[1], _v1[1])).determinant();

    return adjugate;
  }

  template<typename T, matrix_layout ML>
  void matrix_3X3<T, ML>::inverse()
  {
    (*this) = inversion();
  }

  template<typename T, matrix_layout ML>
  matrix_3X3<T, ML> matrix_3X3<T, ML>::inversion() const
  {
    return ((1 / determinant()) * adjugate());
  }

  /// Returns a 9 element array in OpenGL format
  template<typename T, matrix_layout ML>
  const T *matrix_3X3<T, ML>::to_gl_matrix()
  {
    switch(ML)
    {
    case(column) :{
      _gl_matrix[0] = _v0[0];
      _gl_matrix[1] = _v0[1];
      _gl_matrix[2] = _v0[2];
      _gl_matrix[3] = _v1[0];
      _gl_matrix[4] = _v1[1];
      _gl_matrix[5] = _v1[2];
      _gl_matrix[6] = _v2[0];
      _gl_matrix[7] = _v2[1];
      _gl_matrix[8] = _v2[2];
    }
      break;
    case(row) :{
      _gl_matrix[0] = _v0[0];
      _gl_matrix[1] = _v1[0];
      _gl_matrix[2] = _v2[0];
      _gl_matrix[3] = _v0[1];
      _gl_matrix[4] = _v1[1];
      _gl_matrix[5] = _v2[1];
      _gl_matrix[6] = _v0[2];
      _gl_matrix[7] = _v1[2];
      _gl_matrix[8] = _v2[2];
    }
      break;
    }

    return _gl_matrix;
  }

  template<typename T, matrix_layout ML>
  bool operator==(const matrix_3X3<T, ML> &lhs, const matrix_3X3<T, ML> &rhs)
  {
    return (lhs.vec0() == rhs.vec0() && lhs.vec1() == rhs.vec1() &&
        lhs.vec2() == rhs.vec2());
  }

  template<typename T, matrix_layout ML1, matrix_layout ML2>
  bool operator==(const matrix_3X3<T, ML1> &lhs, const matrix_3X3<T, ML2> &rhs)
  {
    const matrix_3X3<T, ML2> rhs_t = rhs.transposed();

    return (lhs.vec0() == rhs_t.vec0() && lhs.vec1() == rhs_t.vec1() &&
        lhs.vec2() == rhs_t.vec2());
  }

  template<typename T, matrix_layout ML>
  bool operator!=(const matrix_3X3<T, ML> &lhs, const matrix_3X3<T, ML> &rhs)
  {
    return (lhs.vec0() != rhs.vec0() || lhs.vec1() != rhs.vec1() ||
        lhs.vec2() != rhs.vec2());
  }
}
