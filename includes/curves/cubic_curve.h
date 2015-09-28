#ifndef CUBIC_CURVE_H_INCLUDED
#define CUBIC_CURVE_H_INCLUDED

#include "curves/curve_3d.h"

#include "curves/tessellation_quality.h"
#include "curves/curve_sample_3d.h"

#include "matrices/type_matrix_4X4.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include <vector>

namespace opengl_math
{
  template<typename realT>
  class cubic_curve : public curve_3d<realT>
  {
  public:
    cubic_curve();

    void set_hermite(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const vector_3d<realT> &t0, const vector_3d<realT> &t1);

    void set_bezier(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const point_3d<realT> &p2, const point_3d<realT> &p3);

    void set_catmull_rom(
      const point_3d<realT> &p0, const point_3d<realT> &p1,
      const point_3d<realT> &p2, const point_3d<realT> &p3);

    const matrix_4X4<realT, column> &get_matrix() const { return m_cubic; }

    virtual point_3d<realT> evaluate_position(realT t) const;

    virtual vector_3d<realT> evaluate_tangent(realT t) const;

    virtual curve_sample_3d<realT> evaluate(realT t) const;

    virtual std::vector<realT> compute_sample_values(
      std::size_t sample_count = 2) const;

    virtual std::vector<curve_sample_3d<realT>> compute_samples_adaptive(
      const tessellation_quality<realT>& quality =
      tessellation_quality<realT>::default_quality) const;

  private:
    matrix_4X4<realT, column> m_cubic;
  };
}
#include "cubic_curve.inl"
#endif
