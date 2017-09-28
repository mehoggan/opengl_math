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
  namespace detail
  {
    template<typename T, typename I>
    void update_tessellated_triangle_data(const point_3d<T> &p,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      tessellated_triangle_data<T, I> &out)
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

    template<typename T, typename I>
    void update_tessellated_wireframe_triangle_data(
      const line<T> &l,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      tessellated_triangle_data<T, I> &out)
    {
      update_tessellated_triangle_data(l.p0(), current_index,
        point_to_index_map, out);
      update_tessellated_triangle_data(l.p1(), current_index,
        point_to_index_map, out);
    };

    template<typename realT, typename indexT>
    void update_tessellated_triangle_data_from_triangle(
      const triangle<realT> &tri,
      indexT &current_index,
      std::unordered_map<point_3d<realT>, indexT> &point_to_index_map,
      tessellated_triangle_data<realT, indexT> &out)
    {
      if (out.mode() == fill) {
        update_tessellated_triangle_data(tri.p0(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data(tri.p1(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data(tri.p2(), current_index,
          point_to_index_map, out);
      } else {
        line<realT> l0(tri.p0(), tri.p1());
        line<realT> l1(tri.p1(), tri.p2());
        line<realT> l2(tri.p2(), tri.p0());
        update_tessellated_wireframe_triangle_data<realT, indexT>(l0,
          current_index, point_to_index_map, out);
        update_tessellated_wireframe_triangle_data<realT, indexT>(l1,
          current_index, point_to_index_map, out);
        update_tessellated_wireframe_triangle_data<realT, indexT>(l2,
          current_index, point_to_index_map, out);
      }
    }

    template<typename T, typename I>
    void handle_base_case(
      const triangle<T> &tri,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      tessellated_triangle_data<T, I> &out)
    {
      if (out.mode() == fill) {
        update_tessellated_triangle_data<T, I>(tri.p0(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri.p1(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri.p2(), current_index,
          point_to_index_map, out);
      } else {
        line<T> l0(tri.p0(), tri.p1());
        line<T> l1(tri.p1(), tri.p2());
        line<T> l2(tri.p2(), tri.p0());
        update_tessellated_wireframe_triangle_data<T, I>(l0, current_index,
          point_to_index_map, out);
        update_tessellated_wireframe_triangle_data<T, I>(l1, current_index,
          point_to_index_map, out);
        update_tessellated_wireframe_triangle_data<T, I>(l2, current_index,
          point_to_index_map, out);
      }
    };

    template<typename T, typename I>
    void tessellate_triangle_by_subdivision(
      const triangle<T> &tri,
      std::size_t subdivision_count,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      tessellated_triangle_data<T, I> &out)
    {
      if (subdivision_count == 0 &&
        !points_of_triangle_are_collinear<T>(tri)) {
        handle_base_case(tri, current_index, point_to_index_map, out);
      } else if (!points_of_triangle_are_collinear<T>(tri)) {
        point_3d<T> centroid = centroid_of_triangle(tri);

        triangle<T> tri_0(tri.p0(), centroid, tri.p2());
        triangle<T> tri_1(tri.p0(), tri.p1(), centroid);
        triangle<T> tri_2(tri.p1(), tri.p2(), centroid);

        tessellate_triangle_by_subdivision(tri_0, subdivision_count - 1,
          current_index, point_to_index_map, out);
        tessellate_triangle_by_subdivision(tri_1, subdivision_count - 1,
          current_index, point_to_index_map, out);
        tessellate_triangle_by_subdivision(tri_2, subdivision_count - 1,
          current_index, point_to_index_map, out);
      }
    }

    template<typename T, typename I>
    void tessellate_triangle_by_midpoint_subdivision(
      const triangle<T> &tri,
      std::size_t subdivision_count,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      tessellated_triangle_data<T, I> &out)
    {
      if (subdivision_count == 0 &&
        !points_of_triangle_are_collinear<T>(tri)) {
        handle_base_case(tri, current_index, point_to_index_map, out);
      } else if (!points_of_triangle_are_collinear<T>(tri)) {
        line<T> side_0(tri.p0(), tri.p1());
        line<T> side_1(tri.p1(), tri.p2());
        line<T> side_2(tri.p2(), tri.p0());

        point_3d<T> midpoint_0 = midpoint_of_line(side_0);
        point_3d<T> midpoint_1 = midpoint_of_line(side_1);
        point_3d<T> midpoint_2 = midpoint_of_line(side_2);

        triangle<T> tri_0(tri.p0(), midpoint_0, midpoint_2);
        triangle<T> tri_1(midpoint_0, tri.p1(), midpoint_1);
        triangle<T> tri_2(midpoint_0, midpoint_1, midpoint_2);
        triangle<T> tri_3(midpoint_2, midpoint_1, tri.p2());

        tessellate_triangle_by_midpoint_subdivision(tri_0,
          subdivision_count - 1, current_index, point_to_index_map, out);
        tessellate_triangle_by_midpoint_subdivision(tri_1,
          subdivision_count - 1, current_index, point_to_index_map, out);
        tessellate_triangle_by_midpoint_subdivision(tri_2,
          subdivision_count - 1, current_index, point_to_index_map, out);
        tessellate_triangle_by_midpoint_subdivision(tri_3,
          subdivision_count - 1, current_index, point_to_index_map, out);
      }
    }
  }

  template<typename T, typename I>
  void tessellate_triangle_by_subdivision(
    const triangle<T> &tri,
    std::size_t subdivision_count,
    I &current_index,
    tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    detail::tessellate_triangle_by_subdivision(tri, subdivision_count,
      current_index, point_to_index_map, out);
  }

  template<typename T, typename I>
  void tessellate_triangles_by_subdivision(
    const std::vector<triangle<T>> &tris,
    std::size_t subdivision_count,
    I &current_index,
    tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    for (const auto &tri : tris) {
      detail::tessellate_triangle_by_subdivision(tri, subdivision_count,
        current_index, point_to_index_map, out);
    }
  }

  template<typename T, typename I>
  void tessellate_triangle_by_midpoint_subdivision(
    const triangle<T> &tri,
    std::size_t subdivision_count,
    I &current_index,
    tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    detail::tessellate_triangle_by_midpoint_subdivision(tri,
      subdivision_count, current_index, point_to_index_map, out);
  }

  template<typename T, typename I>
  void tessellate_triangles_by_midpoint_subdivision(
    const std::vector<triangle<T>> &tris,
    std::size_t subdivision_count,
    I &current_index,
    tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    for (const auto &tri : tris) {
      detail::tessellate_triangle_by_midpoint_subdivision(
        tri, subdivision_count, current_index, point_to_index_map, out);
    }
  }
}
