#ifndef CUBIC_CURVE_H_INCLUDED
#define CUBIC_CURVE_H_INCLUDED

#include "core/enumerations.h"
#include "curves/curve_sample_3d.h"
#include "math/algebra.h"
#include "math/numbers.h"
#include "math/vector.h"
#include "matrices/type_matrix_4X4.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include <cassert>
#include <cstdint>
#include <vector>

namespace opengl_math
{
  template<typename realT, matrix_layout ML>
  class cubic_curve
  {
  public:
    enum class type
    {
      bezier,
      hermite,
      catmullrom
    };

  public:
    cubic_curve(type impl = type::hermite);

    cubic_curve(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const vector_3d<realT> &t0, const vector_3d<realT> &t1);

    cubic_curve(type impl,
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const point_3d<realT> &p2, const point_3d<realT> &p3);

    type get_type() const;

    void set_hermite(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const vector_3d<realT> &t0, const vector_3d<realT> &t1);

    void set_bezier(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const point_3d<realT> &p2, const point_3d<realT> &p3);

    void set_catmullrom(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const point_3d<realT> &p2, const point_3d<realT> &p3);

    const matrix_4X4<realT, ML> &get_matrix() const {return _cubic;}

    curve_sample_3d<realT> evaluate(realT t) const;

    point_3d<realT> evaluate_position(realT t) const;

    vector_3d<realT> evaluate_tangent(realT t) const;

    std::vector<realT> compute_sample_values(std::size_t samples = 2) const;

    std::vector<curve_sample_3d<realT>> compute_samples_adaptive(
      realT chordalTol) const;

    std::vector<curve_sample_3d<realT>> compute_samples_uniform(
      size_t sample_count = 2) const;

  private:
    matrix_4X4<realT, ML> _cubic;
    type _impl;
  };
}
#include "cubic_curve.inl"
#endif
