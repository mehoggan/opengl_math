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
  triangle<T>::triangle(const point_3d<T> &p1, const point_3d<T> &p2,
    const point_3d<T> &p3) :
    _p1(p1),
    _p2(p2),
    _p3(p3)
  {}

  template<typename T>
  bool points_of_triangle_are_collinear(
    const triangle<T> &tri,
    float epsilon)
  {
    vector_3d<T> v1 = tri._p2 - tri._p1;
    vector_3d<T> v2 = tri._p3 - tri._p1;

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
        out._points.push_back(p);
        out._indices.push_back(current_index);
        ++current_index;
      } else {
        out._indices.push_back(it_p->second);
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
      if (subdivision_count == 0) {
        update_tessellated_triangle_data<T, I>(tri._p1, current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri._p2, current_index,
          point_to_index_map, out);
        update_tessellated_triangle_data<T, I>(tri._p3, current_index,
          point_to_index_map, out);
      }

      if (!points_of_triangle_are_collinear<T>(tri)) {
        // TODO: Calculate centroid.
        // TODO: Instantiate 3 triangles with the centroid
        // TODO: Recursivlly call tessellate_triangle_by_subdivision on each
        // new triangle subtracting 1 from subdivision each time.
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
}
