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
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "opengl_math/primitives/vectors/type_vector_4d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"
#include "opengl_math/primitives/vectors/type_vector_2d.h"
#include "opengl_math/primitives/points/type_point_2d.h"
#include "opengl_math/primitives/points/type_point_3d.h"

#include <cmath>

namespace opengl_math
{
  /*! \brief method that returns a normalized 2d vector
   */
  template <typename T>
  vector_2d<T> norm(const vector_2d<T> &v)
  {
    vector_2d<T> u = v;
    u.normalize();
    return u;
  }

  /*! \brief method that returns a normalized 3d vector
   */
  template <typename T>
  vector_3d<T> norm(const vector_3d<T> &v)
  {
    vector_3d<T> u = v;
    u.normalize();
    return u;
  }

  /*! \brief method that returns a normalized 3d vector
  */
  template <typename T>
  vector_4d<T> norm(const vector_4d<T> &v)
  {
    vector_4d<T> u = v;
    u.normalize();
    return u;
  }

  /*! \brief method that returns the angle between two 2d vectors
   */
  template <typename T>
  T angle_between(const vector_2d<T> &v1, const vector_2d<T> &v2)
  {
    vector_2d<T> n1 = norm(v1);
    vector_2d<T> n2 = norm(v2);
    return std::acos(n1.dot(n2));
  }

  /*! \brief method that returns the angle between two 3d vectors
   */
  template <typename T>
  T angle_between(const vector_3d<T> &v1, const vector_3d<T> &v2)
  {
    vector_3d<T> n1 = norm(v1);
    vector_3d<T> n2 = norm(v2);
    return std::acos(n1.dot(n2));
  }

  /*! \brief given two points it returns a vector_2d
   */
  template <typename T>
  vector_2d<T> operator-(const point_2d<T> &p1, const point_2d<T> &p2)
  {
    return vector_2d<T>(p1.x() - p2.x(), p1.y() - p2.y());
  }

  /*! \brief given two points it returns a vector_3d
   */
  template <typename T>
  vector_3d<T> operator-(const point_3d<T> &p1, const point_3d<T> &p2)
  {
    return vector_3d<T>(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
  }

  /*!\brief compute the euclidean distance between two vectors.
   */
  template <typename T>
  T distance(const vector_2d<T> &v1, const vector_2d<T> &v2)
  {
    T a = v1.x() - v2.x();
    T b = v1.y() - v2.y();
    return std::sqrt(a * a + b * b);
  }

  /*!\brief compute the euclidean distance between two vectors.
   */
  template <typename T>
  T distance(const vector_3d<T> &v1, const vector_3d<T> &v2)
  {
    T a = v1.x() - v2.x();
    T b = v1.y() - v2.y();
    T c = v1.z() - v2.z();
    return std::sqrt(a * a + b * b + c * c);
  }

  /*!\brief compute the euclidean distance between two vectors.
   */
  template <typename T>
  T distance(const vector_4d<T> &v1, const vector_4d<T> &v2)
  {
    T a = v1.x() - v2.x();
    T b = v1.y() - v2.y();
    T c = v1.z() - v2.z();
    T d = v1.w() - v2.w();
    return std::sqrt(a * a + b * b + c * c + d * d);
  }
}
#endif
