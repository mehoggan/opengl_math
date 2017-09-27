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
  template<typename T>
  bool points_of_triangle_are_collinear(
    const triangle<T> &tri,
    float epsilon)
  {
    vector_3d<T> v1 = tri.p1() - tri.p0();
    vector_3d<T> v2 = tri.p2() - tri.p0();

    T area = v1.cross(v2).magnitude();

    bool is_polygon = (area > epsilon);

    return !is_polygon;
  }

  namespace detail
  {
    template<typename T, typename I>
    void update_tessellated_triangle_data(const point_3d<T> &p,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      subdivided_tessellated_triangle_data<T, I> &out)
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
    void tessellate_triangle_by_subdivision(
      const triangle<T> &tri,
      std::size_t subdivision_count,
      I &current_index,
      std::unordered_map<point_3d<T>, I> &point_to_index_map,
      subdivided_tessellated_triangle_data<T, I> &out)
    {
      if (subdivision_count == 0 &&
        !points_of_triangle_are_collinear<T>(tri)) {
        update_tessellated_triangle_data<T, I>(tri.p0(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri.p1(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri.p2(), current_index,
          point_to_index_map, out);
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
      subdivided_tessellated_triangle_data<T, I> &out)
    {
      if (subdivision_count == 0 &&
        !points_of_triangle_are_collinear<T>(tri)) {
        update_tessellated_triangle_data<T, I>(tri.p0(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri.p1(), current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri.p2(), current_index,
          point_to_index_map, out);
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
    subdivided_tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    detail::tessellate_triangle_by_subdivision(tri, subdivision_count,
      current_index, point_to_index_map, out);
  }

  template<typename T, typename I>
  void tessellate_triangles_by_subdivision(
    std::vector<triangle<T>> &tris,
    std::size_t subdivision_count,
    I &current_index,
    subdivided_tessellated_triangle_data<T, I> &out)
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
    subdivided_tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    detail::tessellate_triangle_by_midpoint_subdivision(tri,
      subdivision_count, current_index, point_to_index_map, out);
  }

  template<typename T, typename I>
  void tessellate_triangles_by_midpoint_subdivision(
    std::vector<triangle<T>> &tris,
    std::size_t subdivision_count,
    I &current_index,
    subdivided_tessellated_triangle_data<T, I> &out)
  {
    std::unordered_map<point_3d<T>, I> point_to_index_map;
    for (const auto &tri : tris) {
      detail::tessellate_triangle_by_midpoint_subdivision(
        tri, subdivision_count, current_index, point_to_index_map, out);
    }
  }

  template<typename T>
  point_3d<T> centroid_of_triangle(const triangle<T> &tri)
  {
    const T x1 = tri.p0()._x;
    const T x2 = tri.p1()._x;
    const T x3 = tri.p2()._x;

    const T y1 = tri.p0()._y;
    const T y2 = tri.p1()._y;
    const T y3 = tri.p2()._y;

    const T z1 = tri.p0()._z;
    const T z2 = tri.p1()._z;
    const T z3 = tri.p2()._z;

    const point_3d<T> centroid((x1 + x2 + x3) / 3.0, (y1 + y2 + y3) / 3.0,
      (z1 + z2 + z3) / T(3.0));

    return centroid;
  }

  template<typename T>
  point_3d<T> midpoint_of_line(const line<T> &line)
  {
    return point_3d<T>(
      (line.p0()._x + line.p1()._x) / T(2.0),
      (line.p0()._y + line.p1()._y) / T(2.0),
      (line.p0()._z + line.p1()._z) / T(2.0));
  }
}
