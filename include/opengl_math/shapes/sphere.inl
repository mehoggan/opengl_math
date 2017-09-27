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
namespace opengl_math
{
  template<typename realT, typename indexT>
  sphere_generator<realT, indexT>::sphere_generator()
  {}

  template<typename realT, typename indexT>
  sphere_generator<realT, indexT>::~sphere_generator()
  {}

  template<typename realT, typename indexT>
  octahedron_generator<realT, indexT>::octahedron_generator(
    realT radius,
    std::size_t subdivision_count) :
    _radius(radius),
    _subdivision_count(subdivision_count)
  {}

  template<typename realT, typename indexT>
  octahedron_generator<realT, indexT>::~octahedron_generator()
  {}

  template<typename realT, typename indexT>
  void octahedron_generator<realT, indexT>::generate(
    tessellated_triangle_data<realT, indexT> &output) const
  {
    const opengl_math::point_3d<realT> points[6] = {
      opengl_math::point_3d<realT>(realT(+0.0), -_radius, realT(+0.0)),
      opengl_math::point_3d<realT>(realT(+0.0), realT(+0.0), +_radius),
      opengl_math::point_3d<realT>(+_radius, realT(+0.0), realT(+0.0)),
      opengl_math::point_3d<realT>(realT(+0.0), realT(+0.0), -_radius),
      opengl_math::point_3d<realT>(-_radius, realT(+0.0), realT(+0.0)),
      opengl_math::point_3d<realT>(realT(+0.0), +_radius, realT(+0.0))
    };
    const std::vector<opengl_math::triangle<realT>> octahedron_tris = {
      opengl_math::triangle<realT>(points[0], points[1], points[2]),
      opengl_math::triangle<realT>(points[5], points[1], points[2]),
      opengl_math::triangle<realT>(points[0], points[3], points[2]),
      opengl_math::triangle<realT>(points[5], points[2], points[3]),
      opengl_math::triangle<realT>(points[0], points[3], points[4]),
      opengl_math::triangle<realT>(points[5], points[3], points[4]),
      opengl_math::triangle<realT>(points[0], points[4], points[1]),
      opengl_math::triangle<realT>(points[5], points[4], points[1])
    };
    std::uint32_t current_index = 0;
    opengl_math::tessellate_triangles_by_midpoint_subdivision<float>(
      octahedron_tris, 0, current_index, output);
  }

  template<typename realT, typename indexT>
  realT octahedron_generator<realT, indexT>::radius() const
  {
    return _radius;
  }

  template<typename realT, typename indexT>
  spherical_coordinate_generator
  <
    realT,
    indexT
  >::spherical_coordinate_generator(realT radius,
    realT horizontal_angle_delta, realT vertical_angle_delta) :
    _horizontal_angle_delta(horizontal_angle_delta),
    _vertical_angle_delta(vertical_angle_delta),
    _radius(radius)
  {}

  template<typename realT, typename indexT>
  spherical_coordinate_generator
  <
    realT,
    indexT
  >::~spherical_coordinate_generator()
  {}

  template<typename realT, typename indexT>
  void spherical_coordinate_generator
  <
    realT,
    indexT
  >::generate(tessellated_triangle_data<realT, indexT> &output)
  const
  {}

  template<typename realT, typename indexT>
  realT spherical_coordinate_generator<realT, indexT>::radius() const
  {
    return _radius;
  }

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT
  >
  sphere<realT, indexT, genT>::sphere(const genT<realT, indexT> &generator) :
    _generator(generator)
  {}

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT
  >
  void sphere<realT, indexT, genT>::generate(
    tessellated_triangle_data<realT, indexT> &output) const
  {
    _generator.generate(output);
  }

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT
  >
  realT sphere<realT, indexT, genT>::radius() const
  {
    return _generator.radius();
  }
}
