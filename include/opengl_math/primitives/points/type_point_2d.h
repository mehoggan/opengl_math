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
#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

#include <ostream>

namespace opengl_math
{
  /*! \class Point 2D class geometry based
   *  \brief This class defines a 2D point
   */
  template <typename T>
  class point_2d
  {
  public:
    /// The first element in the ordered pair
    T _x;

    /// The second element in the ordered pair
    T _y;

  public:
    /*! \brief default constructor sets both elements using default
     * constructor.
     */
    point_2d();

    /*! \brief constructor sets both elements to the paramaters provided
     */
    point_2d(const T &x, const T &y);

    /*! \brief copy constructor
     */
    point_2d(const point_2d &rhs);

    /*! \brief assignment uses copy-swap idiom
     */
    point_2d &operator=(point_2d rhs);

    /*! \brief setter for x element
     */
    void x(const T &x);

    /*! \brief setter for y element
     */
    void y(const T &y);

    /*! \brief setter for both x and y element
     */
    void x_and_y(const T &x, const T &y);

    /*! \brief getter for x element returns a reference to x of type T
     */
    T& xref();

    /*! \brief getter for y element returns a reference to y of type T
     */
    T& yref();

    /*! \brief getter for x element returns a copy of x of type T
     */
    T x() const;

    /*! \brief getter for y element returns a copy of y of type T
     */
    T y() const;

    /*! \brief get the dimension of this
     */
    static const size_t dimension = 2;
  };
}
#include "type_point_2d.inl"
#endif
