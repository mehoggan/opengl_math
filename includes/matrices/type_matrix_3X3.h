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
#ifndef TYPE_MATRIX_3X3_H_INCLUDED
#define TYPE_MATRIX_3X3_H_INCLUDED

#include "core/enumerations.h"
#include "matrices/type_matrix_2X2.h"
#include "primitives/vectors/type_vector_3d.h"

namespace opengl_math
{
  /*! \class Matrix 3X3 a CG based representation of a matrix which supports
   * both row and column based representations.
   */
  template<typename T, matrix_layout ML = column>
  class matrix_3X3
  {
  private:
    /// The first row or column in (*thiS) matrix
    vector_3d<T> _v0;

    /// The second row or column in (*thiS) matrix
    vector_3d<T> _v1;

    /// The third row or column in (*thiS) matrix
    vector_3d<T> _v2;

    /// Holding place for to_gl_matrix
    T _gl_matrix[9];

  public:
    /*! \brief default constructor which constructs the identity matrix or a
     * matrix all initialized to zero based on the matrix type passed in.
     */
    matrix_3X3(matrix_type type = null);

    /*! \brief constructor which takes 4 vectors of type T and assigns them
     * to the member varables v1 - v4
     */
    matrix_3X3(const vector_3d<T> &v0, const vector_3d<T> &v1,
      const vector_3d<T> &v2);

    /*! \brief copy constructor
     */
    matrix_3X3(const matrix_3X3 &rhs);

    /*! \brief assignment
     */
    matrix_3X3 &operator=(matrix_3X3 rhs);

    /*! \brief index operator which returns a reference to one of the inner
     * vector_3d<T>s
     */
    vector_3d<T> &operator[](unsigned short index);

    /*! \brief index operator which returns a const reference to one of the
     * inner vector_3d<T>s
     */
    const vector_3d<T> &operator[](unsigned short index) const;

    /*! \brief setter for memeber vector_3d<T> v0
     */
    void vec0(const vector_3d<T> &v0);

    /*! \brief setter for memeber vector_3d<T> v1
     */
    void vec1(const vector_3d<T> &v1);

    /*! \brief setter for memeber vector_3d<T> v2
     */
    void vec2(const vector_3d<T> &v2);

    /*! \brief getter for memeber vector_3d<T> v0
     */
    vector_3d<T> vec0() const;

    /*! \brief getter for memeber vector_3d<T> v1
     */
    vector_3d<T> vec1() const;

    /*! \brief getter for memeber vector_3d<T> v2
     */
    vector_3d<T> vec2() const;

    /*! \brief add a matrix from this matrix
     */
    void operator+=(const matrix_3X3 &rhs);

    /*! \brief subtract a matrix from this matrix
     */
    void operator-=(const matrix_3X3 &rhs);

    /*! \brief multiply this matrix by another matrix
     */
    void operator*=(const matrix_3X3 &rhs);

    /*! \brief multiply this matrix by scalar
     */
    void operator*=(const T &rhs);

    /*! \brief transpose this matrix
     */
    void transpose();

    /*! \brief return an inverted version of this matrix
     */
    matrix_3X3 transposed() const;

    /*! \brief return a scalar value of type T which is the
     * determinant of the matrix
     */
    T determinant() const;

    /*! \brief return the adjugate (adjoint) of the matrix by copy
     */
    matrix_3X3 adjugate() const;

    /*! \brief invert this matrix
     */
    void inverse();

    /*! \brief return an inverted version of this matrix
     */
    matrix_3X3 inversion() const;

    /*! \brief obtain a GL matrix
     */
    const T *to_gl_matrix();
  };

  template <typename U, matrix_layout ML>
  void swap(matrix_3X3<U, ML> &lhs, matrix_3X3<U, ML> &rhs);
}
#include "type_matrix_3X3.inl"
#endif
