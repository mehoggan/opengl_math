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
#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "opengl_math/primitives/points/type_point_3d.h"

namespace opengl_math
{
  template<typename T>
  class triangle
  {
  public:
    triangle(const point_3d<T> &p0, const point_3d<T> &p1,
      const point_3d<T> &p2);

    const point_3d<T> p0() const;
    const point_3d<T> p1() const;
    const point_3d<T> p2() const;

  private:
    point_3d<T> _p0;
    point_3d<T> _p1;
    point_3d<T> _p2;
  };
}
#include "triangle.inl"
#endif
