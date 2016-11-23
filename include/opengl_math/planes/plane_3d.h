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
#ifndef TYPE_PLANE_3D_H_INCLUDED
#define TYPE_PLANE_3D_H_INCLUDED

#include "opengl_math/combinatorics/algorithms.h"
#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/primitives/vectors/type_vector_2d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"
#include "opengl_math/primitives/vectors/type_vector_4d.h"

namespace opengl_math
{
  /*! \class 3D Plane a CG based representation of a matrix which supports
   * both row and column based representations.
   */
  template<typename T>
  class plane_3d
  {
  private:
    /// The first row or column in (*thiS) matrix
    vector_4d<T> _coefficients;

  public:
    /*! \brief default constructor which constructs an invalid plane.
     */
    plane_3d();

    /*! \brief constructor which takes 4 type T and assigns them
     * to the components of _coefficients.
     */
    plane_3d(const T &a, const T &b, const T &c, const T &d);

    /*! \brief constructor which takes 4d vector of type T and assigns its
     * components to _coefficients. Note explicit not used so you can cast
     * implicitly from a vector to a plane.
     */
    plane_3d(const vector_4d<T> &coefficients);

    /*! \brief copy constructor
     */
    plane_3d(const plane_3d &rhs);

    /*! \brief assignment
     */
    plane_3d &operator=(plane_3d rhs);

    /*! \brief setter for coefficient (a)
     */
    void a(const T &A);

    /*! \brief setter for coefficient (b)
     */
    void b(const T &B);

    /*! \brief setter for coefficient (c)
     */
    void c(const T &C);

    /*! \brief setter for coefficient (d)
     */
    void d(const T &D);

    /*! \brief getter for coefficient (a)
     */
    T a() const;

    /*! \brief getter for coefficient (b)
     */
    T b() const;

    /*! \brief getter for coefficient (c)
     */
    T c() const;

    /*! \brief getter for coefficient (d)
     */
    T d() const;

    /*! \brief get the normal of this plane
     */
    vector_3d<T> normal(bool normalize = true) const;

    /*! \brief distance from point
     */
    T distance_from_point(const point_3d<T> &p) const;

    /*! \brief is the plane valid?
     */
    bool is_valid() const;

    template<typename U>
    friend bool operator==(const plane_3d<U> &lhs, const plane_3d<U> &rhs)
    {
      return (lhs.a() == rhs.a()) && (lhs.b() == rhs.b()) &&
        (lhs.c() == rhs.c()) && (lhs.d() == rhs.d());
    }

    template<typename U>
    friend bool operator!=(const plane_3d<U> &lhs, const plane_3d<U> &rhs)
    {
      return !(lhs == rhs);
    }

    template <typename U>
    friend void swap(plane_3d<U> &lhs, plane_3d<U> &rhs)
    {
      swap(lhs._coefficients, rhs._coefficients);
    }
  };
}
#include "plane_3d.inl"
#endif
