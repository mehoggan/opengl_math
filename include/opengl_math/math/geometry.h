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

#include "opengl_math/math/trig.h"
#include "opengl_math/math/vector.h"
#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"
#include "opengl_math/shapes/line.h"
#include "opengl_math/shapes/triangle.h"

#include <cmath>
#include <iterator>
#include <limits>
#include <unordered_map>
#include <vector>

namespace opengl_math
{
  template<typename T>
  bool points_of_triangle_are_collinear(
    const triangle<T> &tri,
    float epsilon = std::numeric_limits<float>::epsilon());

  template<typename T>
  point_3d<T> centroid_of_triangle(const triangle<T> &tri);

  template<typename T>
  point_3d<T> midpoint_of_line(const line<T> &line);

  template<typename T>
  point_3d<T> spherical_coordinates_to_cartesian(T theta, T phi, T radius);

  template<typename T, angle_mode AM>
  struct spherical_coordinates
  {
    public:
    spherical_coordinates(T theta, T phi, T radius);

    T theta() const;
    T phi() const;
    T radius() const;
    angle_mode get_angle_mode() const;

    private:
    T _theta;
    T _phi;
    T _radius;
  };

  template<typename T, angle_mode AM>
  point_3d<T> spherical_coordinates_to_cartesian(
    const spherical_coordinates<T, AM> &coords);

  template<typename T, angle_mode AM>
  spherical_coordinates<T, AM> cartesian_coordinates_to_spherical(
    const point_3d<T> p);
}
#include "geometry.inl"
#endif
