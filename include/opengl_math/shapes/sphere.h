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
#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/shapes/enumerations.h"

#include <iterator>
#include <vector>

namespace opengl_math
{
  template<typename T, typename I>
  class subdivided_tessellated_triangle_data
  {
  public:
    subdivided_tessellated_triangle_data(generator_mode mode = fill);

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
    const subdivided_tessellated_triangle_data<T, I> &data)
  {
    out << "points = ";
    std::copy(data._points.begin(), data._points.end(),
      std::ostream_iterator<point_3d<T>>(out, " "));

    out << std::endl << "indices = ";
    std::copy(data._indices.begin(), data._indices.end(),
      std::ostream_iterator<I>(out, " "));

    return out;
  }

  template<typename realT, typename indexT>
  class sphere_generator
  {
  public:
    sphere_generator();
    virtual ~sphere_generator();

    virtual void generate(
      subdivided_tessellated_triangle_data<realT, indexT> &output) const = 0;
  };

  template<typename realT, typename indexT>
  class octahedron_generator : public sphere_generator<realT, indexT>
  {
  public:
    octahedron_generator();
    virtual ~octahedron_generator();

    virtual void generate(
      subdivided_tessellated_triangle_data<realT, indexT> &output) const
        override;
  };

  template<typename realT, typename indexT>
  class spherical_coordinate_generator :
    public sphere_generator<realT, indexT>
  {
  public:
    spherical_coordinate_generator();
    virtual ~spherical_coordinate_generator();

    virtual void generate(
      subdivided_tessellated_triangle_data<realT, indexT> &output) const
        override;
  };

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT = octahedron_generator
  >
  class sphere
  {
  public:
    explicit sphere(realT radius);

    void generate(
      subdivided_tessellated_triangle_data<realT, indexT> &output) const;

    realT radius() const;

  private:
    realT _radius;
  };
}
#include "sphere.inl"
#endif

