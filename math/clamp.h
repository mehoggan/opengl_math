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
#ifndef CLAMP_H_INCLUDED
#define CLAMP_H_INCLUDED

namespace gl_wrapper
{
  namespace core
  {
    namespace math
    {
      template<typename T>
      void clamp(T &a, const T min, const T max)
      {
        (a < min) ? (a = min) : (a > max) ? (a = max) : (a = a);
      }

      template<typename T>
      void clamp_pair(T &a, T &b, const T min, const T max)
      {
        clamp(a, min, max);
        clamp(b, min, max);
      }

      template<typename T>
      void clamp_triplet(T &a, T &b, T &c, const T min, const T max)
      {
        clamp(a, min, max);
        clamp(b, min, max);
        clamp(c, min, max);
      }

      template<typename T>
      void clamp_quad(T &a, T &b, T &c, T &d, const T min, const T max)
      {
        clamp(a, min, max);
        clamp(b, min, max);
        clamp(c, min, max);
        clamp(d, min, max);
      }
    }
  }
}
#endif//CLAMP_H
