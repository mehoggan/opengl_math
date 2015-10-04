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
  template<typename realT, matrix_layout ML>
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

    const matrix_4X4<realT, ML> &get_matrix() const {return _cubic;}

    virtual point_3d<realT> evaluate_position(realT t) const;

    virtual vector_3d<realT> evaluate_tangent(realT t) const;

  private:
    matrix_4X4<realT, ML> _cubic;
  };
}
#include "cubic_curve.inl"
#endif
