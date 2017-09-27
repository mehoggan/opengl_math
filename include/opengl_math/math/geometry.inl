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

  template<typename T, angle_mode AM>
  spherical_coordinates<T, AM>::spherical_coordinates(T theta, T phi,
    T radius) :
    _theta(theta),
    _phi(phi),
    _radius(radius)
  {};

  template<typename T, angle_mode AM>
  T spherical_coordinates<T, AM>::theta() const
  {
    return _theta;
  }

  template<typename T, angle_mode AM>
  T spherical_coordinates<T, AM>::phi() const
  {
    return _phi;
  }

  template<typename T, angle_mode AM>
  T spherical_coordinates<T, AM>::radius() const
  {
    return _radius;
  }

  template<typename T, angle_mode AM>
  angle_mode spherical_coordinates<T, AM>::get_angle_mode() const
  {
    return AM;
  }

  template<typename T, angle_mode AM>
  point_3d<T> spherical_coordinates_to_cartesian(
    const spherical_coordinates<T, AM> &coords)
  {
    T theta;
    T phi;
    if (AM == degrees) {
      theta = degrees_to_radians(coords.theta());
      phi = degrees_to_radians(coords.phi());
    } else {
      theta = coords.theta();
      phi = coords.phi();
    }
    T x = coords.radius() * std::cos(phi) * std::cos(theta);
    T y = coords.radius() * std::sin(phi);
    T z = coords.radius() * std::cos(phi) * std::sin(theta);
    point_3d<T> ret(x, y, z);

    return ret;
  }

  template<typename T, angle_mode AM>
  spherical_coordinates<T, AM> cartesian_coordinates_to_spherical(
    const point_3d<T> p)
  {
    T x_squared = p.x() * p.x();
    T y_squared = p.y() * p.y();
    T z_squared = p.z() * p.z();
    T radius = std::sqrt(x_squared + y_squared + z_squared);
    T phi = std::asin(p.y() / radius);
    T theta = std::acos(p.x() / (radius * std::cos(phi)));

    if (AM == degrees) {
      theta = radians_to_degrees(theta);
      phi = radians_to_degrees(phi);
    }

    return spherical_coordinates<T, AM>(theta, phi, radius);
  }
}
