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
  octahedron_generator<realT, indexT>::octahedron_generator()
  {}

  template<typename realT, typename indexT>
  octahedron_generator<realT, indexT>::~octahedron_generator()
  {}

  template<typename realT, typename indexT>
  void octahedron_generator<realT, indexT>::generate(
    subdivided_tessellated_triangle_data<realT, indexT> &output) const
  {}

  template<typename realT, typename indexT>
  spherical_coordinate_generator
  <
    realT,
    indexT
  >::spherical_coordinate_generator()
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
  >::generate(subdivided_tessellated_triangle_data<realT, indexT> &output)
  const
  {}

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT
  >
  sphere<realT, indexT, genT>::sphere(realT radius) :
    _radius(radius)
  {}

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT
  >
  void sphere<realT, indexT, genT>::generate(
    subdivided_tessellated_triangle_data<realT, indexT> &output,
    std::size_t subdivisions) const
  {}

  template
  <
    typename realT,
    typename indexT,
    template<typename, typename> class genT
  >
  realT sphere<realT, indexT, genT>::radius() const
  {
    return _radius;
  }
}
