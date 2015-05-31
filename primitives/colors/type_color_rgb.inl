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
namespace gl_wrapper
{
  namespace
  {
    template <typename T>
    T clamp_rgb(const T &val)
    {
      assert(val <= T(255) && __FILE__);
      assert(val >= T(0) && __FILE__);
      return (val > T(1)) ? (val / T(255)) : (val);
    }
  }

  /// Constructors
  template <typename T>
  color_rgb<T>::color_rgb() :
    _r(T(0)),
    _g(T(0)),
    _b(T(0))
  {}

  template <typename T>
  color_rgb<T>::color_rgb(const T &r, const T &g, const T &b) :
    _r(clamp_rgb<T>(r)),
    _g(clamp_rgb<T>(g)),
    _b(clamp_rgb<T>(b))
  {}

  /// Copy constructor
  template <typename T>
  color_rgb<T>::color_rgb(const color_rgb &rhs) :
    _r(rhs._r),
    _g(rhs._g),
    _b(rhs._b)
  {}

  /// Assignment operator
  template <typename T>
  color_rgb<T> &color_rgb<T>::operator=(color_rgb rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Setters
  template <typename T>
  void color_rgb<T>::r(const T &r)
  {
    _r = clamp_rgb<T>(r);
  }

  template <typename T>
  void color_rgb<T>::g(const T &g)
  {
    _g = clamp_rgb<T>(g);
  }

  template <typename T>
  void color_rgb<T>::b(const T &b)
  {
    _b = clamp_rgb<T>(b);
  }

  template <typename T>
  void color_rgb<T>::rgb(const T &r, const T &g, const T &b)
  {
    _r = clamp_rgb<T>(r);
    _g = clamp_rgb<T>(g);
    _b = clamp_rgb<T>(b);
  }

  /// Getters
  template <typename T>
  T& color_rgb<T>::rref()
  {
    return _r;
  }

  template <typename T>
  T& color_rgb<T>::gref()
  {
    return _g;
  }

  template <typename T>
  T& color_rgb<T>::bref()
  {
    return _b;
  }

  template <typename T>
  T color_rgb<T>::r() const
  {
    return _r;
  }

  template <typename T>
  T color_rgb<T>::g() const
  {
    return _g;
  }

  template <typename T>
  T color_rgb<T>::b() const
  {
    return _b;
  }

  template <typename U>
  void swap(color_rgb<U> &lhs, color_rgb<U> &rhs)
  {
    std::swap(lhs.rref(), rhs.rref());
    std::swap(lhs.gref(), rhs.gref());
    std::swap(lhs.bref(), rhs.bref());
  }

  /// Comparison operators
  template <typename T>
  bool operator==(const color_rgb<T> &lhs, const color_rgb<T> &rhs)
  {
    return (lhs.r() == rhs.r() && lhs.g() == rhs.g() && lhs.b() == rhs.b());
  }

  template <typename T>
  bool operator!=(const color_rgb<T> &lhs, const color_rgb<T> &rhs)
  {
    return (lhs.r() != rhs.r() || lhs.g() != rhs.g() || lhs.b() != rhs.b());
  }

  /// Output operators
  template <typename T>
  std::ostream &operator<<(std::ostream &out, const color_rgb<T> &rhs)
  {
    return out << "(" << rhs.r() << ", " << rhs.g() << ", " << rhs.b() << ")";
  }

  typedef color_rgb<float> color3f;
  typedef color_rgb<double> color3d;
}
