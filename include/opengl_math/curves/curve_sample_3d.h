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
#ifndef CURVE_SAMPLE_3D_H_INCLUDED
#define CURVE_SAMPLE_3D_H_INCLUDED

#include "opengl_math/math/numbers.h"
#include "opengl_math/matrices/type_matrix_4X4.h"
#include "opengl_math/primitives/points/type_point_3d.h"
#include "opengl_math/primitives/vectors/type_vector_3d.h"

#include <limits>

namespace opengl_math
{
  template<typename realT>
  struct curve_sample_3d
  {
  public:
    curve_sample_3d();

    curve_sample_3d(const point_3d<realT> &position,
      const vector_3d<realT> &tangent, realT parameter);

    void normalize_tangent();

    point_3d<realT> _position;
    vector_3d<realT> _tangent;
    realT _parameter;

    friend
    bool operator<(const curve_sample_3d &lhs, const curve_sample_3d& rhs)
    {
      return lhs._parameter < rhs._parameter;
    }
  };
}
#include "curve_sample_3d.inl"
#endif
