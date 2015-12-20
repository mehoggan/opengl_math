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
#ifndef AXIS_ALIGNED_2D_H_INCLUDED
#define AXIS_ALIGNED_2D_H_INCLUDED

#include "math/numbers.h"
#include "primitives/points/type_point_2d.h"

#include <iostream>
#include <limits>

namespace opengl_math
{
  /*! \class Axis aligned bounding box
   */
  template <typename T>
  class axis_aligned_2d
  {
  private:
    point_2d<T> _lower_left;
    point_2d<T> _upper_right;

  public:
    /*! \brief default constructor which constructs an invalid axis aligned
     * bounding box.
     */
    axis_aligned_2d();

    /*! \brief constructor which takes 2 points and constructs a bounding box
     * which includes the points.
     */
    axis_aligned_2d(const point_2d<T> &p1, const point_2d<T> &p2);

    /*! \brief constructor which takes the lower left corner and two floats
     * which represent the width and height of the axis aligned bounding box.
     */
    axis_aligned_2d(const point_2d<T> &ll, const T &width, const T &height);

    /*! \brief copy constructor
     */
    axis_aligned_2d(const axis_aligned_2d &rhs);

    /*! \brief assignment uses copy-swap idiom
     */
    axis_aligned_2d &operator=(axis_aligned_2d rhs);

    /*! \brief returns true if the values stored in _lower_left and
     * _upper_right are valid values.
     */
    bool is_valid() const;

    /*! \brief grows the bounding box to encompass the point specified in p
     */
    void grow_to_contain(const point_2d<T> &p);

    /*! \brief tells if point is in bounding box. All sides inclusive.
    */
    bool contains(const point_2d<T>& p) const;

    /*! \brief reference to the lower left corner.
     */
    point_2d<T> &r_ll();

    /*! \brief reference to the upper right corner.
     */
    point_2d<T> &r_ur();

    /*! \brief return the difference between ur.x() and ll.x()
     */
    T width() const;

    /*! \brief return the difference between ur.y() and ll.y()
     */
    T height() const;

    /*! \brief return a point roughly at the middle of the axis aligned box
     */
    point_2d<T> center() const;

    /*! \brief comparison operator
     */
    template <typename U>
    friend bool operator==(const axis_aligned_2d<U> &lhs,
      const axis_aligned_2d<U> &rhs)
    {
      return (lhs._lower_left == rhs._lower_left) &&
        (lhs._upper_right == rhs._upper_right);
    }
  };

  template <typename U>
  void swap(axis_aligned_2d<U> &lhs, axis_aligned_2d<U> &rhs)
  {
    std::swap(lhs.r_ll().xref(), rhs.r_ll().xref());
    std::swap(lhs.r_ll().yref(), rhs.r_ll().yref());
    std::swap(lhs.r_ur().xref(), rhs.r_ur().xref());
    std::swap(lhs.r_ur().yref(), rhs.r_ur().yref());
  }
}
#include "axis_aligned_2d.inl"
#endif
