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
  axis_aligned_2d<T>::axis_aligned_2d() :
    _lower_left(std::numeric_limits<T>::max(),
      std::numeric_limits<T>::max()),
    _upper_right(-std::numeric_limits<T>::max(),
      -std::numeric_limits<T>::max())
  {}

  template <typename T>
  axis_aligned_2d<T>::axis_aligned_2d(const point_2d<T> &p1,
    const point_2d<T> &p2)
  {
    (*this) = axis_aligned_2d();

    grow_to_contain(p1);
    grow_to_contain(p2);
  }

  template <typename T>
  axis_aligned_2d<T>::axis_aligned_2d(const point_2d<T> &ll,
    const T &width, const T &height)
  {
    (*this) = axis_aligned_2d();

    grow_to_contain(ll);
    grow_to_contain(point_2d<T>(ll.x() + width, ll.y() + height));
  }

  template <typename T>
  axis_aligned_2d<T>::axis_aligned_2d(const axis_aligned_2d<T> &rhs) :
    _lower_left(rhs._lower_left),
    _upper_right(rhs._upper_right)
  {}

  template <typename T>
  axis_aligned_2d<T> &axis_aligned_2d<T>::operator=(axis_aligned_2d<T> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  template <typename T>
  bool axis_aligned_2d<T>::is_valid() const
  {
    return (_lower_left.x() < _upper_right.x()) &&
      (_lower_left.y() < _upper_right.y());
  }

  template <typename T>
  void axis_aligned_2d<T>::grow_to_contain(const point_2d<T> &p)
  {
    const auto ll = point_2d<T>(min(p.x(), _lower_left.x()),
      min(p.y(), _lower_left.y()));
    const auto ur = point_2d<T>(max(p.x(), _upper_right.x()),
      max(p.y(), _upper_right.y()));

    _lower_left = ll;
    _upper_right = ur;
  }

  template <typename T>
  bool axis_aligned_2d<T>::contains(const point_2d<T>& p) const
  {
    return (p.x() >= _lower_left.x() && p.y() >= _lower_left.y()) &&
      (p.x() <= _upper_right.x() && p.y() <= _upper_right.y());
  }

  template <typename T>
  point_2d<T> &axis_aligned_2d<T>::r_ll()
  {
    return _lower_left;
  }

  template <typename T>
  point_2d<T> &axis_aligned_2d<T>::r_ur()
  {
    return _upper_right;
  }

  template <typename T>
  T axis_aligned_2d<T>::width() const
  {
    return _upper_right.x() - _lower_left.x();
  }

  template <typename T>
  T axis_aligned_2d<T>::height() const
  {
    return _upper_right.y() - _lower_left.y();
  }

  template <typename T>
  point_2d<T> axis_aligned_2d<T>::center() const
  {
    return opengl_math::point_2d<T>((_lower_left.x() + _upper_right.x()) / 2.0f,
      (_lower_left.y() + _upper_right.y()) / 2.0f);
  }
}
