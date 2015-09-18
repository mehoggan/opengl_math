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
    T clamp_texcoord_3d(const T &val)
    {
      T ret(0);
      ret = (val > T(1)) ? T(1) : (val < T(0)) ? T(0) : val;

      return ret;
    }
  }

  /// Constructors
  template <typename T>
  texcoord_3d<T>::texcoord_3d() :
    _s(T(0)),
    _t(T(0)),
    _r(T(0))
  {}

  template <typename T>
  texcoord_3d<T>::texcoord_3d(const T &s, const T &t, const T &r) :
    _s(clamp_texcoord_3d<T>(s)),
    _t(clamp_texcoord_3d<T>(t)),
    _r(clamp_texcoord_3d<T>(r))
  {}

  /// Copy constructor
  template <typename T>
  texcoord_3d<T>::texcoord_3d(const texcoord_3d<T> &rhs) :
    _s(rhs._s),
    _t(rhs._t),
    _r(rhs._r)
  {}

  /// Assignment operator
  template <typename T>
  texcoord_3d<T> &texcoord_3d<T>::operator=(texcoord_3d<T> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Sub-index operator
  template <typename T>
  T &texcoord_3d<T>::operator[](unsigned short index)
  {
    assert(index < 3);

    switch(index)
    {
      case(0): return _s;
      case(1): return _t;
      case(2): return _r;
      default: return _s;
    }
  }

  template <typename T>
  const T &texcoord_3d<T>::operator[](unsigned short index) const
  {
    assert(index < 3);

    switch(index)
    {
      case(0): return _s;
      case(1): return _t;
      case(2): return _r;
      default: return _s;
    }
  }

  /// Setters
  template <typename T>
  void texcoord_3d<T>::s(const T &s)
  {
    _s = clamp_texcoord_3d<T>(s);
  }

  template <typename T>
  void texcoord_3d<T>::t(const T &t)
  {
    _t = clamp_texcoord_3d<T>(t);
  }

  template <typename T>
  void texcoord_3d<T>::r(const T &r)
  {
    _r = clamp_texcoord_3d<T>(r);
  }

  template <typename T>
  void texcoord_3d<T>::s_and_t_and_r(const T &s, const T &t, const T &r)
  {
    _s = clamp_texcoord_3d<T>(s);
    _t = clamp_texcoord_3d<T>(t);
    _r = clamp_texcoord_3d<T>(r);
  }

  /// Getters
  template <typename T>
  T& texcoord_3d<T>::sref()
  {
    return _s;
  }

  template <typename T>
  T& texcoord_3d<T>::tref()
  {
    return _t;
  }

  template <typename T>
  T& texcoord_3d<T>::rref()
  {
    return _r;
  }

  /// Getters
  template <typename T>
  T texcoord_3d<T>::s() const
  {
    return _s;
  }

  template <typename T>
  T texcoord_3d<T>::t() const
  {
    return _t;
  }

  template <typename T>
  T texcoord_3d<T>::r() const
  {
    return _r;
  }

  /// Copy and swap idiom
  template <typename T>
  void swap(texcoord_3d<T> &lhs, texcoord_3d<T> &rhs)
  {
    std::swap(lhs.sref(), rhs.sref());
    std::swap(lhs.tref(), rhs.tref());
    std::swap(lhs.rref(), rhs.rref());
  }

  /// Comparison operators
  template <typename T>
  bool operator==(const texcoord_3d<T> &lhs, const texcoord_3d<T> &rhs)
  {
    return (lhs.s() == rhs.s() && lhs.t() == rhs.t() && lhs.r() == rhs.r());
  }

  template <typename T>
  bool operator!=(const texcoord_3d<T> &lhs, const texcoord_3d<T> &rhs)
  {
    return (lhs.s() != rhs.s() || lhs.t() != rhs.t() || lhs.r() != rhs.r());
  }

  /// Output operators
  template <typename T>
  std::ostream &operator<<(std::ostream &out, const texcoord_3d<T> &rhs)
  {
    return out << "(" << rhs.s() << ", " << rhs.r() << ", " << rhs.t() << ")";
  }

  typedef texcoord_3d<float> tex3f;
  typedef texcoord_3d<double> tex3d;
}
