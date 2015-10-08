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
#ifndef ALGEBRA_H_INCLUDED
#define ALGEBRA_H_INCLUDED

#include "primitives/vectors/type_vector_2d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/points/type_point_2d.h"
#include "primitives/points/type_point_3d.h"

#include <string>
#include <type_traits>
//#include <typeinfo.h>

namespace opengl_math
{
  template<typename T>
  inline T lerp(const T &percent, const T &a, const T &b)
  {
    static_assert(std::is_floating_point<T>::value,
      "Non float type provide to lerp");
    return a + (b - a) * percent;
  }

  template<typename T>
  inline vector_2d<T> lerp(const T &percent,
    const vector_2d<T>& a, const vector_2d<T>& b)
  {
    static_assert(std::is_floating_point<T>::value,
      "Non float type provide to lerp");
    T p = max(min(percent, T(1)), T(0));
    return vector_2d<T>(
      lerp(p, a.x(), b.x()),
      lerp(p, a.y(), b.y()));
  }

  template<typename T>
  inline vector_3d<T> lerp(const T &percent,
    const vector_3d<T>& a, const vector_3d<T>& b)
  {
    static_assert(std::is_floating_point<T>::value,
      "Non float type provide to lerp");
    T p = max(min(percent, T(1)), T(0));
    return vector_3d<T>(
      lerp(p, a.x(), b.x()),
      lerp(p, a.y(), b.y()),
      lerp(p, a.z(), b.z()));
  }

  template<typename T>
  inline point_2d<T> lerp(const T &percent,
    const point_2d<T>& a, const point_2d<T>& b)
  {
    static_assert(std::is_floating_point<T>::value,
      "Non float type provide to lerp");
    T p = max(min(percent, T(1)), T(0));
    return point_2d<T>(
      lerp(p, a.x(), b.x()),
      lerp(p, a.y(), b.y()));
  }

  template<typename T>
  inline point_3d<T> lerp(const T &percent,
    const point_3d<T>& a, const point_3d<T>& b)
  {
    static_assert(std::is_floating_point<T>::value,
      "Non float type provide to lerp");
    T p = max(min(percent, T(1)), T(0));
    return point_3d<T>(
      lerp(p, a.x(), b.x()),
      lerp(p, a.y(), b.y()),
      lerp(p, a.z(), b.z()));
  }
}
#endif
