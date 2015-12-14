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
  template <typename T>
  plane_3d<T>::plane_3d()
  {}

  template <typename T>
  plane_3d<T>::plane_3d(const T &a, const T &b, const T &c, const T &d) :
    _coefficients(a, b, c, d)
  {}

  template <typename T>
  plane_3d<T>::plane_3d(const vector_4d<T> &coefficients) :
    _coefficients(coefficients)
  {}

  template <typename T>
  plane_3d<T>::plane_3d(const plane_3d &rhs) :
    _coefficients(rhs._coefficients)
  {}

  template <typename T>
  plane_3d<T> &plane_3d<T>::operator=(plane_3d rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  template <typename T>
  void plane_3d<T>::a(const T &A)
  {
    _coefficients[0] = A;
  }

  template <typename T>
  void plane_3d<T>::b(const T &B)
  {
    _coefficients[1] = B;
  }

  template <typename T>
  void plane_3d<T>::c(const T &C)
  {
    _coefficients[2] = C;
  }

  template <typename T>
  void plane_3d<T>::d(const T &D)
  {
    _coefficients[3] = D;
  }

  template <typename T>
  T plane_3d<T>::a() const
  {
    return _coefficients[0];
  }

  template <typename T>
  T plane_3d<T>::b() const
  {
    return _coefficients[1];
  }

  template <typename T>
  T plane_3d<T>::c() const
  {
    return _coefficients[2];
  }

  template <typename T>
  T plane_3d<T>::d() const
  {
    return _coefficients[3];
  }

  template <typename T>
  vector_3d<T> plane_3d<T>::normal(bool normalize) const
  {
    vector_3d<T> normal(a(), b(), c());
    if (normalize) {
      normal.normalize();
    }
    return normal;
  }

  // See: http://mathworld.wolfram.com/Point-PlaneDistance.html
  template <typename T>
  T plane_3d<T>::distance_from_point(const point_3d<T> &p) const
  {
    vector_3d<T> norm = normal(true);
    return norm.x() * p.x() + norm.y() * p.y() + norm.z() * p.z() + d();
  }

  template <typename T>
  bool plane_3d<T>::is_valid() const
  {
    // We look at all three components of the planes normal vector.
    // If there are two or more 0 components then the plane is not valid.
    bool valid = true;
    vector_4d<T> c = _coefficients;
    std::sort(&c.xref(), &c.wref());
    using i_t = unsigned short;
    const i_t size = 2;
    const i_t N = 3;
    do {
      bool a = (c[0] != 0);
      bool b = (c[1] != 0);
      valid &= (a || b);
    } while (valid && combinatorics::n_cr_k<vector_4d<T>, N, i_t>(c, size));

    return valid;
  }
}
