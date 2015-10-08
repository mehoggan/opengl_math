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
  matrix_2X2<T, ML>::matrix_2X2(matrix_type type)
  {
    if (type == null) {
      _v0 = vector_2d<T>();
      _v1 = vector_2d<T>();
    } else if (type == identity) {
      _v0 = vector_2d<T>(T(1.0), T(0.0));
      _v1 = vector_2d<T>(T(0.0), T(1.0));
    }
  }

  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML>::matrix_2X2(const vector_2d<T> &v0,
    const vector_2d<T> &v1) :
    _v0(v0),
    _v1(v1)
  {}

  /// Copy constructor
  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML>::matrix_2X2(const matrix_2X2<T, ML> &rhs) :
    _v0(rhs._v0),
    _v1(rhs._v1)
  {}

  /// Assignment operator
  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML> &matrix_2X2<T, ML>::operator=(matrix_2X2<T, ML> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Sub-index operator
  template <typename T, matrix_layout ML>
  vector_2d<T> &matrix_2X2<T, ML>::operator[](unsigned short index)
  {
    assert(index < 2);

    switch(index)
    {
      case(0): return _v0;
      case(1): return _v1;
      default: return _v0;
    }
    return _v0;
  }

  template <typename T, matrix_layout ML>
  const vector_2d<T> &matrix_2X2<T, ML>::operator[](unsigned short index) const
  {
    assert(index < 2);

    switch(index)
    {
      case(0): return _v0;
      case(1): return _v1;
      default: return _v0;
    }
    return _v0;
  }

  /// Setters
  template <typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::vec0(const vector_2d<T> &v0)
  {
    _v0 = v0;
  }

  template <typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::vec1(const vector_2d<T> &v1)
  {
    _v1 = v1;
  }

  /// Getters
  template <typename T, matrix_layout ML>
  vector_2d<T> matrix_2X2<T, ML>::vec0() const
  {
    return _v0;
  }

  template <typename T, matrix_layout ML>
  vector_2d<T> matrix_2X2<T, ML>::vec1() const
  {
    return _v1;
  }

  template <typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::operator+=(const matrix_2X2 &rhs)
  {
    _v0 += rhs._v0;
    _v1 += rhs._v1;
  }

  template <typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::operator-=(const matrix_2X2 &rhs)
  {
    _v0 -= rhs._v0;
    _v1 -= rhs._v1;
  }

  template <typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::operator*=(const matrix_2X2 &rhs)
  {
    if (ML == column) {
      /* [col][row] */
      vector_2d<T> v0(
        _v0[0]*rhs[0][0]+_v1[0]*rhs[0][1],
        _v0[1]*rhs[0][0]+_v1[1]*rhs[0][1]);
      vector_2d<T>v1(
        _v0[0]*rhs[1][0]+_v1[0]*rhs[1][1],
        _v0[1]*rhs[1][0]+_v1[1]*rhs[1][1]);
      /* construct matrix using column vectors */
      (*this) = matrix_2X2<T, ML>(v0, v1);
    } else if (ML == row) {
      /* [row][col] */
      vector_2d<T> v0(
        _v0[0]*rhs[0][0]+_v0[1]*rhs[1][0],
        _v0[0]*rhs[0][1]+_v0[1]*rhs[1][1]);
      vector_2d<T> v1(
        _v1[0]*rhs[0][0]+_v1[1]*rhs[1][0],
        _v1[0]*rhs[0][1]+_v1[1]*rhs[1][1]);
      /* construct matrix using row vectors */
      (*this) = matrix_2X2<T, ML>(v0, v1);
    }
  }

  template <typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::operator*=(const T &rhs)
  {
      _v0 *= rhs;
      _v1 *= rhs;
  }

  template <typename U, matrix_layout ML>
  void swap(matrix_2X2<U, ML> &lhs, matrix_2X2<U, ML> &rhs)
  {
    std::swap(lhs[0], rhs[0]);
    std::swap(lhs[1], rhs[1]);
  }

  /// Arithmetic operators
  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML> operator+(const matrix_2X2<T, ML> &m1,
    const matrix_2X2<T, ML> &m2)
  {
    return matrix_2X2<T, ML>(
      m1.vec0() + m2.vec0(),
      m1.vec1() + m2.vec1());
  }

  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML> operator-(const matrix_2X2<T, ML> &m1,
    const matrix_2X2<T, ML> &m2)
  {
    return matrix_2X2<T, ML>(
      m1.vec0() - m2.vec0(),
      m1.vec1() - m2.vec1());
  }

  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML> operator-(const matrix_2X2<T, ML> &m1)
  {
    return matrix_2X2<T, ML>(-m1.vec0(), -m1.vec1());
  }

  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML> operator*(const T &s, const matrix_2X2<T, ML> &m1)
  {
    return matrix_2X2<T, ML>(
      s * m1.vec0(),
      s * m1.vec1());
  }

  template <typename T, matrix_layout ML>
  matrix_2X2<T, ML> operator*(const matrix_2X2<T, ML> &m1,
    const matrix_2X2<T, ML> &m2)
  {
    if (ML == column) {
      /* [col][row] */
      vector_2d<T> v0(
        m1[0][0]*m2[0][0]+m1[1][0]*m2[0][1],
        m1[0][1]*m2[0][0]+m1[1][1]*m2[0][1]);
      vector_2d<T>v1(
        m1[0][0]*m2[1][0]+m1[1][0]*m2[1][1],
        m1[0][1]*m2[1][0]+m1[1][1]*m2[1][1]);
      /* construct matrix using column vectors */
      return matrix_2X2<T, ML>(v0, v1);
    } else if (ML == row) {
      /* [row][col] */
      vector_2d<T> v0(
        m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0],
        m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1]);
      vector_2d<T> v1(
        m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0],
        m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1]);
      /* construct matrix using row vectors */
      return matrix_2X2<T, ML>(v0, v1);
    }
  }

  /*! \brief This function returns the product of a 2d vector multiplied by a
   * 2 X 2 matrix
   */
  template <typename T, matrix_layout ML>
  vector_2d<T> operator*(const matrix_2X2<T, ML> &m, const vector_2d<T> &v)
  {
    if (ML == column) {
      /* [col][row] */
      return vector_2d<T>(
        m[0][0] * v[0] + m[1][0] * v[1],
        m[0][1] * v[0] + m[1][1] * v[1]);
    } else {
      /* [row][col] */
      return vector_2d<T>(
        m[0][0] * v[0] + m[0][1] * v[1],
        m[1][0] * v[0] + m[1][1] * v[1]);
    }
  }

  /*! \brief This function returns the product of a 2d vector multiplied by a
  * 2 X 2 matrix
  */
  template <typename T, matrix_layout ML>
  vector_2d<T> operator*(const vector_2d<T> &v, const matrix_2X2<T, ML> &m)
  {
    if (ML == column) {
      /* [col][row] */
      return vector_2d<T>(
        v[0] * m[0][0] + v[1] * m[0][1],
        v[0] * m[1][0] + v[1] * m[1][1]);;
    }
    else {
      /* [row][col] */
      return vector_2d<T>(
        v[0] * m[0][0] + v[1] * m[1][0],
        v[0] * m[0][1] + v[1] * m[1][1]);
    }
  }

  /// Output operators (Output works with Octave and Matlab)
  template <typename T, matrix_layout ML>
  std::ostream &operator<<(std::ostream &out, const matrix_2X2<T, ML> &rhs)
  {
    if (ML == row) {
      return out << "[" << rhs.vec0() << "; " << rhs.vec1() << "]";
    } else if (ML == column) {
      return out
        << "["
        << rhs.vec0().x() << ", " << rhs.vec1().x() << "; "
        << rhs.vec0().y() << ", " << rhs.vec1().y() << "; "
        << "]";
    }
  }

  template<typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::transpose()
  {
    (*this) = transposed();
  }

  template<typename T, matrix_layout ML>
  matrix_2X2<T, ML> matrix_2X2<T, ML>::transposed() const
  {
    return matrix_2X2<T, ML>(
      vector_2d<T>(_v0[0], _v1[0]),
      vector_2d<T>(_v0[1], _v1[1]));
  }

  template<typename T, matrix_layout ML>
  T matrix_2X2<T, ML>::determinant() const
  {
    T det(0);
    if (ML == column) {
        det = _v0[0] * _v1[1] - _v0[1] * _v1[0];
    } else {
        det = _v0[0] * _v1[1] - _v1[0] * _v0[1];
    }

    return det;
  }

  template<typename T, matrix_layout ML>
  matrix_2X2<T, ML> matrix_2X2<T, ML>::adjugate() const
  {
    matrix_2X2<T, ML> adjugate(null);

    // NOTE: This algorithm works the same on both row and column layouts
    // indicies.
    adjugate[0][0] = _v1[1];
    adjugate[0][1] = -_v0[1];
    adjugate[1][0] = -_v1[0];
    adjugate[1][1] = _v0[0];

    return adjugate;
  }

  template<typename T, matrix_layout ML>
  void matrix_2X2<T, ML>::inverse()
  {
    (*this) = inversion();
  }

  template<typename T, matrix_layout ML>
  matrix_2X2<T, ML> matrix_2X2<T, ML>::inversion() const
  {
    return ((1 / determinant()) * adjugate());
  }

  /// Returns a 9 element array in OpenGL format
  template<typename T, matrix_layout ML>
  const T *matrix_2X2<T, ML>::to_gl_matrix()
  {
    switch(ML)
    {
    case(column) :{
      _gl_matrix[0] = _v0[0];
      _gl_matrix[1] = _v0[1];
      _gl_matrix[2] = _v1[0];
      _gl_matrix[3] = _v1[1];
    }
      break;
    case(row) :{
      _gl_matrix[0] = _v0[0];
      _gl_matrix[1] = _v1[0];
      _gl_matrix[2] = _v0[1];
      _gl_matrix[3] = _v1[1];
    }
      break;
    }

    return _gl_matrix;
  }

  template<typename T, matrix_layout ML>
  bool operator==(const matrix_2X2<T, ML> &lhs, const matrix_2X2<T, ML> &rhs)
  {
    return (lhs.vec0() == rhs.vec0() && lhs.vec1() == rhs.vec1());
  }

  template<typename T, matrix_layout ML1, matrix_layout ML2>
  bool operator==(const matrix_2X2<T, ML1> &lhs, const matrix_2X2<T, ML2> &rhs)
  {
    const matrix_2X2<T, ML2> rhs_t = rhs.transposed();

    return (lhs.vec0() == rhs_t.vec0() && lhs.vec1() == rhs_t.vec1());
  }

  template<typename T, matrix_layout ML>
  bool operator!=(const matrix_2X2<T, ML> &lhs, const matrix_2X2<T, ML> &rhs)
  {
    return (lhs.vec0() != rhs.vec0() || lhs.vec1() != rhs.vec1());
  }
}
