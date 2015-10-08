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
#ifndef NUMBERS_H_INCLUDED
#define NUMBERS_H_INCLUDED

#include "core/platform.h"
#include "math/trig.h"
#include "primitives/points/type_point_2d.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_2d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include <cmath>

#ifdef __OPENGL_MATH_WINDOWS__
    #undef min
    #undef max
#endif

namespace opengl_math
{
  template<typename T>
  inline T squared(const T &val)
  {
    return val * val;
  }

  template<typename T>
  inline T min(const T &lhs, const T &rhs)
  {
    return (lhs >= rhs) ? rhs : lhs;
  }

  template<typename T>
  inline T max(const T &lhs, const T &rhs)
  {
    return (lhs < rhs) ? rhs : lhs;
  }

  template<typename T>
  inline T abs(const T &lhs, const T &rhs)
  {
    return max(lhs, rhs) - min(lhs, rhs);
  }

  template<typename T>
  inline T abs(const T &val)
  {
    return (val < 0) ? -val : val;
  }

  template<typename T>
  T gcd(T lhs, T rhs);

  template<>
  inline short gcd<short>(short lhs, short rhs)
  {
    short zero = static_cast<short>(0);
    short result = 1;
    while (true) {
      if (lhs == zero) {
        result = rhs;
        break;
      }
      rhs %= lhs;

      if (rhs == zero) {
        result = lhs;
        break;
      }
      lhs %= rhs;
    }

    return abs(result);
  }

  template<>
  inline unsigned short gcd<unsigned short>(unsigned short lhs,
    unsigned short rhs)
  {
    if (lhs && rhs) {
      unsigned short shifts = 0;

      while (!(lhs & 1u) && !(rhs & 1u)) {
        ++shifts;
        lhs >>= 1;
        rhs >>= 1;
      }

      unsigned short r[] = {lhs, rhs};
      unsigned short which = static_cast<bool>(lhs & 1u);

      do
      {
        while (!(r[which] & 1u)) {
          r[which] >>= 1;
        }
        if (r[!which] > r[which]) {
            which ^= 1u;
        }
        r[which] -= r[!which];
      } while (r[which]);

      return r[!which] << shifts;
    } else {
      return lhs + rhs;
    }
  }

  template<>
  inline int gcd<int>(int lhs, int rhs)
  {
    int zero = static_cast<int>(0);
    int result = 1;
    while (true) {
      if (lhs == zero) {
        result = rhs;
        break;
      }
      rhs %= lhs;

      if (rhs == zero) {
        result = lhs;
        break;
      }
      lhs %= rhs;
    }

    return abs(result);
  }

  template<>
  inline unsigned int gcd<unsigned int>(unsigned int lhs,
    unsigned int rhs)
  {
    if (lhs && rhs) {
      unsigned int shifts = 0;

      while (!(lhs & 1u) && !(rhs & 1u)) {
        ++shifts;
        lhs >>= 1;
        rhs >>= 1;
      }

      unsigned int r[] = {lhs, rhs};
      unsigned int which = static_cast<bool>(lhs & 1u);

      do
      {
        while (!(r[which] & 1u)) {
          r[which] >>= 1;
        }
        if (r[!which] > r[which]) {
            which ^= 1u;
        }
        r[which] -= r[!which];
      } while (r[which]);

      return r[!which] << shifts;
    } else {
      return lhs + rhs;
    }
  }

  template<>
  inline long gcd<long>(long lhs, long rhs)
  {
    long zero = static_cast<long>(0l);
    long result = 1l;
    while (true) {
      if (lhs == zero) {
        result = rhs;
        break;
      }
      rhs %= lhs;

      if (rhs == zero) {
        result = lhs;
        break;
      }
      lhs %= rhs;
    }

    return abs(result);
  }

  template<>
  inline unsigned long gcd<unsigned long>(unsigned long lhs,
    unsigned long rhs)
  {
    if (lhs && rhs) {
      unsigned long shifts = 0ul;

      while (!(lhs & 1ul) && !(rhs & 1ul)) {
        ++shifts;
        lhs >>= 1;
        rhs >>= 1;
      }

      unsigned long r[] = {lhs, rhs};
      unsigned long which = static_cast<bool>(lhs & 1ul);

      do
      {
        while (!(r[which] & 1ul)) {
          r[which] >>= 1;
        }
        if (r[!which] > r[which]) {
            which ^= 1ul;
        }
        r[which] -= r[!which];
      } while (r[which]);

      return r[!which] << shifts;
    } else {
      return lhs + rhs;
    }
  }

  template<>
  inline long long gcd<long long>(long long lhs, long long rhs)
  {
    long long zero = static_cast<long long>(0ll);
    long long result = 1ll;
    while (true) {
      if (lhs == zero) {
        result = rhs;
        break;
      }
      rhs %= lhs;

      if (rhs == zero) {
        result = lhs;
        break;
      }
      lhs %= rhs;
    }

    return abs(result);
  }

  template<>
  inline unsigned long long  gcd<unsigned long long>(unsigned long long lhs,
    unsigned long long rhs)
  {
    if (lhs && rhs) {
      unsigned long long shifts = 0ull;

      while (!(lhs & 1ull) && !(rhs & 1ull)) {
        ++shifts;
        lhs >>= 1;
        rhs >>= 1;
      }

      unsigned long long r[] = {lhs, rhs};
      unsigned long long which = static_cast<bool>(lhs & 1ull);

      do
      {
        while (!(r[which] & 1ull)) {
          r[which] >>= 1;
        }
        if (r[!which] > r[which]) {
            which ^= 1ull;
        }
        r[which] -= r[!which];
      } while (r[which]);

      return r[!which] << shifts;
    } else {
      return lhs + rhs;
    }
  }

  template<typename T>
  bool float_equals(T val1, T val2, T epsilon);

  template<>
  inline bool float_equals<float>(float val1, float val2, float epsilon)
  {
    float diff = abs(val1, val2);
    return (val1 == val2) || diff <= epsilon;
  }

  template<>
  inline bool float_equals<double>(double val1, double val2, double epsilon)
  {
    double diff = abs(val1, val2);
    return (val1 == val2) || diff <= epsilon;
  }

  template<>
  inline bool float_equals<long double>(long double val1, long double val2,
    long double epsilon)
  {
    long double diff = abs(val1, val2);
    return (val1 == val2) || diff <= epsilon;
  }

  template<typename T>
  bool vector_2d_float_equals(const vector_2d<T> &lhs,
    const vector_2d<T> &rhs, T epsilon)
  {
    bool ret = true;
    ret &= float_equals<T>(lhs.x(), rhs.x(), epsilon);
    ret &= float_equals<T>(lhs.y(), rhs.y(), epsilon);
    return ret;
  }

  template<typename T>
  bool vector_3d_float_equals(const vector_3d<T> &lhs,
    const vector_3d<T> &rhs, T epsilon)
  {
    bool ret = true;
    ret &= float_equals<T>(lhs.x(), rhs.x(), epsilon);
    ret &= float_equals<T>(lhs.y(), rhs.y(), epsilon);
    ret &= float_equals<T>(lhs.z(), rhs.z(), epsilon);
    return ret;
  }

  template<typename T>
  bool vector_4d_float_equals(const vector_4d<T> &lhs,
    const vector_4d<T> &rhs, T epsilon)
  {
    bool ret = true;
    ret &= float_equals<T>(lhs.x(), rhs.x(), epsilon);
    ret &= float_equals<T>(lhs.y(), rhs.y(), epsilon);
    ret &= float_equals<T>(lhs.z(), rhs.z(), epsilon);
    ret &= float_equals<T>(lhs.w(), rhs.w(), epsilon);
    return ret;
  }

  template<typename T>
  bool point_2d_float_equals(const point_2d<T> &lhs,
    const point_2d<T> &rhs, T epsilon)
  {
    bool ret = true;
    ret &= float_equals<T>(lhs.x(), rhs.x(), epsilon);
    ret &= float_equals<T>(lhs.y(), rhs.y(), epsilon);
    return ret;
  }

  template<typename T>
  bool point_3d_float_equals(const point_3d<T> &lhs,
    const point_3d<T> &rhs, T epsilon)
  {
    bool ret = true;
    ret &= float_equals<T>(lhs.x(), rhs.x(), epsilon);
    ret &= float_equals<T>(lhs.y(), rhs.y(), epsilon);
    ret &= float_equals<T>(lhs.z(), rhs.z(), epsilon);
    return ret;
  }
}

#endif
