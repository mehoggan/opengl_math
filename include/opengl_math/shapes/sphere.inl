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
  >::spherical_coordinate_generator(realT radius, realT theta_angle_delta,
    realT phi_angle_delta, angle_mode mode) :
    _theta_angle_delta(theta_angle_delta),
    _phi_angle_delta(phi_angle_delta),
    _radius(radius),
    _mode(mode)
  {
    if (mode == radians) {
      _theta_angle_delta = radians_to_degrees<realT>(_theta_angle_delta);
      _phi_angle_delta = radians_to_degrees<realT>(_phi_angle_delta);
    }
  }

  template<typename realT, typename indexT>
  spherical_coordinate_generator
  <
    realT,
    indexT
  >::~spherical_coordinate_generator()
  {}

  namespace detail
  {
    template<typename realT>
    std::tuple<bool, std::size_t> vector_contains_point(
      const std::vector<point_3d<realT>> &points, const point_3d<realT> &p)
    {
      std::size_t index = 0;
      auto it = std::find_if(points.begin(), points.end(),
        [&](const point_3d<realT> &p_0) {
          vector_3d<realT> v(p.x(), p.y(), p.z());
          vector_3d<realT> v_0(p_0.x(), p_0.y(), p_0.z());
          bool ret = false;
          // epsilon based on precesion of std trig functions.
          if (vector_3d_float_equals(v, v_0, realT(0.000001))) {
            ret = true;
          }
          ++index;
          return ret;
        }
      );

      if (it == std::end(points)) {
        assert(index == points.size());
      } else {
        assert(points[index] == (*it));
      }

      return (it == std::end(points));
    }
  }

  template<typename realT, typename indexT>
  void spherical_coordinate_generator
  <
    realT,
    indexT
  >::generate(tessellated_triangle_data<realT, indexT> &output) const
  {
    indexT current_index = 0;
    realT phi_angle(-90.0);
    while (phi_angle <= realT(+90.0)) {
      realT theta_angle(+0.0);
      while (theta_angle <= realT(+360.0)) {
        spherical_coordinates<realT, degrees> sc(theta_angle, phi_angle,
          _radius);
        point_3d<realT> p =
          spherical_coordinates_to_cartesian<realT, degrees>(sc);

        std::tuple<bool, std::size_t> find_data =
          detail::vector_contains_point(output.points(), p);
        if (!std::get<0>(find_data)) {
          output.points().push_back(p);
          output.indices().push_back(current_index);
          ++current_index;
        } else {
          output.indices().push_back(indexT(std::get<1>(find_data)));
        }

        theta_angle += _theta_angle_delta;
      }
      phi_angle += _phi_angle_delta;
    }
  }

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
