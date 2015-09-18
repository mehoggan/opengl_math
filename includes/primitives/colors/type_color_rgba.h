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
#ifndef COLORRGBA_H_INCLUDED
#define COLORRGBA_H_INCLUDED

#include "math/clamp.h"

#include <cassert>

namespace opengl_math
{
  /*! \class Color 3D class abstract class to rerpesnt a rgba or bgr color
   * 3D space.
   *  \brief This class defines a rgba or bgr color
   */
  template <typename T>
  class color_rgba
  {
  public:
    /// The first element in the ordered pair
    T _r;

    /// The second element in the ordered pair
    T _g;

    /// The third element in the ordered pair
    T _b;

    /// The fourt element in the ordered pair
    T _a;

  public:
    /*! \brief default constructor sets both elements using default constructor
     */
    color_rgba();

    /*! \brief constructor sets both elements to the paramaters provided
     */
    color_rgba(const T &r, const T &g, const T &b, const T &a);

    /*! \brief copy constructor
     */
    color_rgba(const color_rgba &rhs);

    /*! \brief assignment uses copy-swap idiom
     */
    color_rgba &operator=(color_rgba rhs);

    /*! \brief setter for r element
     */
    void r(const T &r);

    /*! \brief setter for g element
     */
    void g(const T &g);

    /*! \brief setter for b element
     */
    void b(const T &b);

    /*! \brief setter for a element
     */
    void a(const T &a);

    /*! \brief setter for both r and g and b element
     */
    void rgba(const T &r, const T &g, const T &b, const T &a);

    /*! \brief getter for r element returns a reference to r of type T
     */
    T& rref();

    /*! \brief getter for g element returns a reference to g of type T
     */
    T& gref();

    /*! \brief getter for b element returns a reference to b of type T
     */
    T& bref();

    /*! \brief getter for a element returns a reference to a of type T
     */
    T& aref();

    /*! \brief getter for r element returns a copy of r of type T
     */
    T r() const;

    /*! \brief getter for g element returns a copy of g of type T
     */
    T g() const;

    /*! \brief getter for b element returns a copy of b of type T
     */
    T b() const;

    /*! \brief getter for a element returns a copy of a of type T
     */
    T a() const;

    /*! \brief get the dimension of this
     */
    static const size_t dimension = 4;
  };
}
#include "type_color_rgba.inl"
#endif
