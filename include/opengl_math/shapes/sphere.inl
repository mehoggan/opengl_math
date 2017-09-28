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
    realT horizontal_angle_delta, realT vertical_angle_delta,
    angle_mode mode) :
    _horizontal_angle_delta(horizontal_angle_delta),
    _vertical_angle_delta(vertical_angle_delta),
    _radius(radius),
    _mode(mode)
  {
    if (mode == radians) {
      _horizontal_angle_delta = radians_to_degrees<realT>(
        _horizontal_angle_delta);
      _vertical_angle_delta = radians_to_degrees<realT>(
        _vertical_angle_delta);
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
    template<typename realT, typename indexT>
    void update_tessellated_spherical_triangle_data(
      const point_3d<realT> &p,
      indexT &current_index,
      std::unordered_map<point_3d<realT>, indexT> &point_to_index_map,
      tessellated_triangle_data<realT, indexT> &out)
    {
      auto it_p = point_to_index_map.find(p);
      if (it_p == point_to_index_map.end()) {
        point_to_index_map[p] = current_index;
        out.points().push_back(p);
        out.indices().push_back(current_index);
        ++current_index;
      } else {
        out.indices().push_back(it_p->second);
      }
    }

    template<typename realT, typename indexT>
    void update_tessellated_wireframe_spherical_triangle_data(
      const line<realT> &l,
      indexT &current_index,
      std::unordered_map<point_3d<realT>, indexT> &point_to_index_map,
      tessellated_triangle_data<realT, indexT> &out)
    {
      update_tessellated_triangle_data(l.p0(), current_index,
        point_to_index_map, out);
      update_tessellated_triangle_data(l.p1(), current_index,
        point_to_index_map, out);
    };

    template<typename realT, typename indexT>
    void update_tessellated_spherical_triangle_data_from_triangle(
      const triangle<realT> &tri,
      indexT &current_index,
      std::unordered_map<point_3d<realT>, indexT> &point_to_index_map,
      tessellated_triangle_data<realT, indexT> &out)
    {
      if (out.mode() == fill) {
        update_tessellated_spherical_triangle_data(tri.p0(),
          current_index, point_to_index_map, out);
        update_tessellated_spherical_triangle_data(tri.p1(),
          current_index, point_to_index_map, out);
        update_tessellated_spherical_triangle_data(tri.p2(),
          current_index, point_to_index_map, out);
      } else {
        line<realT> l0(tri.p0(), tri.p1());
        line<realT> l1(tri.p1(), tri.p2());
        line<realT> l2(tri.p2(), tri.p0());
        update_tessellated_wireframe_spherical_triangle_data<realT, indexT>(
          l0, current_index, point_to_index_map, out);
        update_tessellated_wireframe_spherical_triangle_data<realT, indexT>(
          l1, current_index, point_to_index_map, out);
        update_tessellated_wireframe_spherical_triangle_data<realT, indexT>(
          l2, current_index, point_to_index_map, out);
      }
    }
  }

  template<typename realT, typename indexT>
  void spherical_coordinate_generator
  <
    realT,
    indexT
  >::generate(tessellated_triangle_data<realT, indexT> &output) const
  {
    realT vertical_angle(-90.0);
    realT horizontal_angle(+0.0);

    std::unordered_map<point_3d<realT>, indexT> point_to_index_map;

    indexT current_index;

    while (vertical_angle <= (realT(+90.0) - _vertical_angle_delta)) {
      while (horizontal_angle <= (realT(+360.0) - _horizontal_angle_delta)) {

        spherical_coordinates<realT, degrees> ll(
          horizontal_angle,
          vertical_angle,
          _radius);
        spherical_coordinates<realT, degrees> lr(
          horizontal_angle + _horizontal_angle_delta,
          vertical_angle,
          _radius);
        spherical_coordinates<realT, degrees> ur(
          horizontal_angle + _horizontal_angle_delta,
          vertical_angle + _vertical_angle_delta,
          _radius);
        spherical_coordinates<realT, degrees> ul(
          horizontal_angle,
          vertical_angle + _vertical_angle_delta,
          _radius);

        point_3d<realT> ll_p =
          spherical_coordinates_to_cartesian<realT, degrees>(ll);
        point_3d<realT> lr_p =
          spherical_coordinates_to_cartesian<realT, degrees>(lr);
        point_3d<realT> ur_p =
          spherical_coordinates_to_cartesian<realT, degrees>(ur);
        point_3d<realT> ul_p =
          spherical_coordinates_to_cartesian<realT, degrees>(ul);

        // At bottom and top of sphere there is only one triangle.
        if (ll_p == lr_p) {
          triangle<realT> tri(ll_p, ur_p, ul_p);
          detail::update_tessellated_spherical_triangle_data_from_triangle(
            tri, current_index, point_to_index_map, output);
        } else if (ur_p == ul_p) {
          triangle<realT> tri(ll_p, lr_p, ur_p);
          detail::update_tessellated_spherical_triangle_data_from_triangle(
            tri, current_index, point_to_index_map, output);
        } else {
          triangle<realT> left_tri(ll_p, ur_p, ul_p);
          detail::update_tessellated_spherical_triangle_data_from_triangle(
            left_tri, current_index, point_to_index_map, output);
          triangle<realT> right_tri(ll_p, lr_p, ur_p);
          detail::update_tessellated_spherical_triangle_data_from_triangle(
            right_tri, current_index, point_to_index_map, output);
        }

        horizontal_angle += _horizontal_angle_delta;
      }
      vertical_angle += _vertical_angle_delta;
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
