namespace opengl_math
{
  template<typename T>
  bool points_of_triangle_are_collinear(
    const opengl_math::point_3d<T> &p1,
    const opengl_math::point_3d<T> &p2,
    const opengl_math::point_3d<T> &p3,
    float epsilon)
  {
    opengl_math::vector_3d<T> v1 = p2 - p1;
    opengl_math::vector_3d<T> v2 = p3 - p1;

    T area = v1.cross(v2).magnitude();

    bool is_polygon = (area > epsilon);

    return !is_polygon;
  }

  template<typename T, typename I>
  subdivided_tessellated_triangle_data<T, I>
  tessellate_triangle_by_subdivision(
    const opengl_math::point_3d<T> &p1,
    const opengl_math::point_3d<T> &p2,
    const opengl_math::point_3d<T> &p3,
    std::size_t subdivision_count
  )
  {
    subdivided_tessellated_triangle_data<T, I> ret;

    if (points_of_triangle_are_collinear<T>(p1, p2, p3)) {
    }

    return ret;
  }
}
