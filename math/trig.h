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
#ifndef TRIG_H_INCLUDED
#define TRIG_H_INCLUDED

#include <cmath>

namespace gl_wrapper
{
  namespace core
  {
    namespace math
    {
      /*! \brief this enum tells the api that parameter is either in radians
       * or degrees
       */
      enum angle_mode {degrees = 0, radians = 1};

      /*! \brief this method returns a value of pi witth percision of type T
       */
      template <typename T>
      T pi()
      {
        static T pi_val = std::atan(T(1)) * T(4);
        return pi_val;
      }

      /*! \brief this method returns a value of pi/2 witth percision of type T
       */
      template <typename T>
      T pi_2()
      {
        static T pi_2_val = (std::atan(T(1)) * T(4)) / T(2);
        return pi_2_val;
      }

      /*! \brief this method converts an angle given in radians to a angle given
       * in degrees
       */
      template <typename T>
      T degrees_to_radians(const T &angle)
      {
        return angle * (T(pi<T>()) / T(180));
      }

      /*! \brief this method converts an angle given in radians to a angle given
       * in degrees
       */
      template <typename T>
      T radians_to_degrees(const T &angle)
      {
        return angle * (T(180) / pi<T>());
      }

      /*! \brief this method returns the cos of an angle. User can specify if it
       * is in degrees or radians.
       */
      template <typename T, angle_mode AM>
      T cos(const T &angle)
      {
        return (AM == radians) ?
          std::cos(angle) :
          std::cos(degrees_to_radians(angle));
      }

      /*! \brief this method returns the angle give the ratio of adjacent over
       * hypotenuse. User can specify if it is in degrees or radians.
       */
      template <typename T, angle_mode AM>
      T acos(const T &ratio)
      {
        return (AM == radians) ?
          std::acos(ratio) :
          radians_to_degrees(std::acos(ratio));
      }

      /*! \brief this method returns the sin of an angle. User can specify if it
       * is in degrees or radians.
       */
      template <typename T, angle_mode AM>
      T sin(const T &angle)
      {
        return (AM == radians) ?
          std::sin(angle) :
          std::sin(degrees_to_radians(angle));
      }

      /*! \brief this method returns the angle give the ratio of opposite over
       * hypotenuse. User can specify if it is in degrees or radians.
       */
      template <typename T, angle_mode AM>
      T asin(const T &ratio)
      {
        return (AM == radians) ?
          std::asin(ratio) :
          radians_to_degrees(std::asin(ratio));
      }

      /*! \brief this method returns the tan of an angle. User can specify if it
       * is in degrees or radians.
       */
      template <typename T, angle_mode AM>
      T tan(const T &angle)
      {
        return (AM == radians) ?
          std::tan(angle) :
          std::tan(degrees_to_radians(angle));
      }

      /*! \brief this method returns the cot of an angle. User can specify if it
       * is in degrees or radians.
       */
      template <typename T, angle_mode AM>
      T cot(const T &angle)
      {
        return (AM == radians) ?
          std::tan(pi_2<T>() - angle) :
          std::tan(pi_2<T>() - degrees_to_radians(angle));
      }
    }
  }
}
#endif
