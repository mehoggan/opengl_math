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
#ifndef CONVERSIONS_H_INCLUDED
#define CONVERSIONS_H_INCLUDED

#include "primitives/colors/type_color_rgb.h"
#include "primitives/colors/type_color_rgba.h"
#include "primitives/conversions.h"
#include "primitives/points/type_point_2d.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/texcoords/type_texcoord_2d.h"
#include "primitives/texcoords/type_texcoord_3d.h"
#include "primitives/texcoords/type_texcoord_4d.h"
#include "primitives/vectors/type_vector_2d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

namespace opengl_math
{
  template<typename T>
  inline vector_3d<T> vector3d_from_point3d(const point_3d<T> &in)
  {
    return vector_3d<T>(in.x(), in.y(), in.z());
  }

  template<typename T>
  inline point_3d<T> point3d_from_vector3d(const vector_3d<T> &in)
  {
    return point_3d<T>(in.x(), in.y(), in.z());
  }
};
#endif