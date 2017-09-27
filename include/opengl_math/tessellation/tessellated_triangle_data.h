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
#ifndef TESSELLATED_TRIANGLE_DATA_H_INCLUDED
#define TESSELLATED_TRIANGLE_DATA_H_INCLUDED

#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/tessellation/enumerations.h"

#include <iterator>
#include <vector>

namespace opengl_math
{
  template<typename T, typename I>
  class tessellated_triangle_data
  {
  public:
    tessellated_triangle_data(generator_mode mode = fill);

    std::vector<point_3d<T>> &points();
    std::vector<I> &indices();
    generator_mode mode() const;

  private:
    std::vector<point_3d<T>> _points;
    std::vector<I> _indices;
    generator_mode _mode;
  };

  template<typename T, typename I>
  inline std::ostream &operator<<(std::ostream &out,
    const tessellated_triangle_data<T, I> &data)
  {
    out << "points = ";
    std::copy(data._points.begin(), data._points.end(),
      std::ostream_iterator<point_3d<T>>(out, " "));

    out << std::endl << "indices = ";
    std::copy(data._indices.begin(), data._indices.end(),
      std::ostream_iterator<I>(out, " "));

    return out;
  }
}
#include "tessellated_triangle_data.inl"
#endif
