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
#ifndef MATH_GEOMETRY_H_INCLUDED
#define MATH_GEOMETRY_H_INCLUDED

#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"

#include <cmath>
#include <limits>
#include <vector>

namespace opengl_math
{
  template<typename T, typename I>
  struct subdivided_tessellated_triangle_data
  {
    std::vector<opengl_math::point_3d<T>> points_3d_;
    std::vector<I> indices_;
  };

  template<typename T>
  bool points_of_triangle_are_collinear(
    const opengl_math::point_3d<T> &p1,
    const opengl_math::point_3d<T> &p2,
    const opengl_math::point_3d<T> &p3,
    float epsilon = std::numeric_limits<float>::epsilon());

  template<typename T, typename I>
  subdivided_tessellated_triangle_data<T, I>
  tessellate_triangle_by_subdivision(
    const opengl_math::point_3d<T> &p1,
    const opengl_math::point_3d<T> &p2,
    const opengl_math::point_3d<T> &p3,
    std::size_t subdivision_count
  );
}
#include "geometry.inl"
#endif
