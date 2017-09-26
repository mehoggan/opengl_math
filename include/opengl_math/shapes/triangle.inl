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
  triangle<T>::triangle(const point_3d<T> &p0, const point_3d<T> &p1,
    const point_3d<T> &p2) :
    _p0(p0),
    _p1(p1),
    _p2(p2)
  {}

  template<typename T>
  const point_3d<T> triangle<T>::p0() const
  {
    return _p0;
  }

  template<typename T>
  const point_3d<T> triangle<T>::p1() const
  {
    return _p1;
  }

  template<typename T>
  const point_3d<T> triangle<T>::p2() const
  {
    return _p2;
  }
}
