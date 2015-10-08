#ifndef CURVE_H_INCLUDED
#define CURVE_H_INCLUDED

#include "curves/curve_sample_3d.h"
#include "curves/tessellation_quality.h"
#include "math/algebra.h"
#include "math/numbers.h"
#include "math/vector.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"

#include <cassert>
#include <cstdint>
#include <vector>

namespace opengl_math
{
  template<typename realT>
  class curve_3d
  {
  public:
    curve_3d();

    virtual ~curve_3d();

    virtual point_3d<realT> evaluate_position(realT t) const = 0;

    virtual vector_3d<realT> evaluate_tangent(realT t) const = 0;

    virtual curve_sample_3d<realT> evaluate(realT t) const;

    virtual std::vector<realT> compute_sample_values(
      std::size_t sample_count = 2) const;

    virtual std::vector<curve_sample_3d<realT>> compute_samples_adaptive(
      const tessellation_quality<realT> &quality =
        tessellation_quality<realT>::default_quality) const;

    virtual std::vector<curve_sample_3d<realT>> compute_samples_uniform(
      size_t sample_count = 2) const;
  };
}
#include "curve_3d.inl"
#endif
