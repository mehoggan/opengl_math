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
