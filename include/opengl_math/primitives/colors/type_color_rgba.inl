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
  namespace
  {
    template <typename T>
    T clamp_rgba(const T &val)
    {
      assert(val <= T(255) && __FILE__);
      assert(val >= T(0) && __FILE__);
      return (val > T(1)) ? (val / T(255)) : (val);
    }
  }

  /// Constructors
  template <typename T>
  color_rgba<T>::color_rgba() :
    _r(T(0)),
    _g(T(0)),
    _b(T(0)),
    _a(T(0))
  {}

  template <typename T>
  color_rgba<T>::color_rgba(const T &r, const T &g, const T &b, const T &a) :
    _r(clamp_rgba(r)),
    _g(clamp_rgba(g)),
    _b(clamp_rgba(b)),
    _a(clamp_rgba(a))
  {}

  /// Copy constructor
  template <typename T>
  color_rgba<T>::color_rgba(const color_rgba &rhs) :
    _r(rhs._r),
    _g(rhs._g),
    _b(rhs._b),
    _a(rhs._a)
  {}

  /// Assignment operator
  template <typename T>
  color_rgba<T> &color_rgba<T>::operator=(color_rgba<T> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Setters
  template <typename T>
  void color_rgba<T>::r(const T &r)
  {
    _r = clamp_rgba(r);
  }

  template <typename T>
  void color_rgba<T>::g(const T &g)
  {
    _g = clamp_rgba(g);
  }

  template <typename T>
  void color_rgba<T>::b(const T &b)
  {
    _b = clamp_rgba(b);
  }

  template <typename T>
  void color_rgba<T>::a(const T &a)
  {
    _a = clamp_rgba(a);
  }

  template <typename T>
  void color_rgba<T>::rgba(const T &r, const T &g, const T &b,
    const T &a)
  {
    _r = clamp_rgba(r);
    _g = clamp_rgba(g);
    _b = clamp_rgba(b);
    _a = clamp_rgba(a);
  }

  /// Getters
  template <typename T>
  T& color_rgba<T>::rref()
  {
    return _r;
  }

  template <typename T>
  T& color_rgba<T>::gref()
  {
    return _g;
  }

  template <typename T>
  T& color_rgba<T>::bref()
  {
    return _b;
  }

  template <typename T>
  T& color_rgba<T>::aref()
  {
    return _a;
  }

  /// Getters
  template <typename T>
  T color_rgba<T>::r() const
  {
    return _r;
  }

  template <typename T>
  T color_rgba<T>::g() const
  {
    return _g;
  }

  template <typename T>
  T color_rgba<T>::b() const
  {
    return _b;
  }

  template <typename T>
  T color_rgba<T>::a() const
  {
    return _a;
  }

  template <typename U>
  void swap(color_rgba<U> &lhs, color_rgba<U> &rhs)
  {
    std::swap(lhs.rref(), rhs.rref());
    std::swap(lhs.gref(), rhs.gref());
    std::swap(lhs.bref(), rhs.bref());
    std::swap(lhs.aref(), rhs.aref());
  }

  /// Comparison operators
  template <typename T>
  bool operator==(const color_rgba<T> &lhs, const color_rgba<T> &rhs)
  {
    return (lhs.r() == rhs.r() && lhs.g() == rhs.g() && lhs.b() == rhs.b() &&
      lhs.a() == rhs.a());
  }

  template <typename T>
  bool operator!=(const color_rgba<T> &lhs, const color_rgba<T> &rhs)
  {
    return (lhs.r() != rhs.r() || lhs.g() != rhs.g() || lhs.b() != rhs.b() ||
      lhs.a() != rhs.a());
  }

  /// Output operators
  template <typename T>
  std::ostream &operator<<(std::ostream &out, const color_rgba<T> &rhs)
  {
    return out << "(" << rhs.r() << ", " << rhs.g() << ", " << rhs.b() << ", "
      << rhs.a() << ")";
  }

  typedef color_rgba<float> color4f;
  typedef color_rgba<double> color4d;
}
