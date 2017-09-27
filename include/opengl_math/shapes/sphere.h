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
#include "opengl_math/tessellation/tessellated_triangle_data.h"
#include "opengl_math/tessellation/tessellation_ops.h"

#include <iterator>
#include <vector>

namespace opengl_math
{
  template<typename realT, typename indexT>
  class sphere_generator
  {
  public:
    sphere_generator();
    virtual ~sphere_generator();

    virtual void generate(
      tessellated_triangle_data<realT, indexT> &output) const = 0;
  };

  template<typename realT, typename indexT>
  class octahedron_generator : public sphere_generator<realT, indexT>
  {
  public:
    explicit octahedron_generator(realT radius,
      std::size_t subdivision_count);
    virtual ~octahedron_generator();

    virtual void generate(
      tessellated_triangle_data<realT, indexT> &output) const
        override;

    realT radius() const;

  private:
    realT _radius;
    std::size_t _subdivision_count;
  };

  template<typename realT, typename indexT>
  class spherical_coordinate_generator :
    public sphere_generator<realT, indexT>
  {
  public:
    spherical_coordinate_generator(realT radius_,
      realT horizontal_angle_delta, realT vertical_angle_delta);
    virtual ~spherical_coordinate_generator();

    virtual void generate(
      tessellated_triangle_data<realT, indexT> &output) const
        override;

    realT radius() const;

  private:
    realT _horizontal_angle_delta;
    realT _vertical_angle_delta;
    realT _radius;
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
    explicit sphere(const genT<realT, indexT> &generator);

    void generate(
      tessellated_triangle_data<realT, indexT> &output) const;

    realT radius() const;

  private:
    genT<realT, indexT> _generator;
  };
}
#include "sphere.inl"
#endif

