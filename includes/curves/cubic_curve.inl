namespace opengl_math
{
  namespace
  {
    template<typename realT>
    matrix_4X4<realT, column> catmul_rom()
    {
      return matrix_4X4<realT, column>(
        vector_4d<realT>(realT(-0.5), realT(1.5), realT(-1.5), realT(0.5)),
        vector_4d<realT>(realT(1), realT(-2.5), realT(2), realT(-0.5)),
        vector_4d<realT>(realT(-0.5), realT(0), realT(0.5), realT(0)),
        vector_4d<realT>(realT(0), realT(1), realT(0), realT(0)));
    }

    template<typename realT>
    matrix_4X4<realT, column> bezier()
    {
      return matrix_4X4<realT, column>(
        vector_4d<realT>(realT(-1), realT(3), realT(-3), realT(1)),
        vector_4d<realT>(realT(3), realT(-6), realT(3), realT(0)),
        vector_4d<realT>(realT(-3), realT(3), realT(0), realT(0)),
        vector_4d<realT>(realT(1), realT(0), realT(0), realT(0)));
    }

    template<typename realT>
    matrix_4X4<realT, column> bezier_inverse()
    {
      return matrix_4X4<realT, column>(
        vector_4d<realT>(realT(0), realT(0), realT(0), realT(1)),
        vector_4d<realT>(realT(0), realT(0), realT(1 / realT(3)), realT(1)),
        vector_4d<realT>(realT(0), realT(1 / realT(3)), realT(2 / realT(3)),
          realT(1)),
        vector_4d<realT>(realT(1), realT(1), realT(1), realT(1)));
    }

    template<typename realT>
    matrix_4X4<realT, column> hermite()
    {
      return matrix_4X4<realT, column>(
        vector_4d<realT>(realT(2), realT(-2), realT(1), realT(1)),
        vector_4d<realT>(realT(-3), realT(3), realT(-2), realT(-1)),
        vector_4d<realT>(realT(0), realT(0), realT(1), realT(0)),
        vector_4d<realT>(realT(1), realT(0), realT(0), realT(0)));
    }

    template<typename realT>
    matrix_4X4<realT, column> hermite_inverse()
    {
      return matrix_4X4<realT, column>(
        vector_4d<realT>(realT(0), realT(0), realT(0), realT(1)),
        vector_4d<realT>(realT(1), realT(1), realT(1), realT(1)),
        vector_4d<realT>(realT(0), realT(0), realT(1), realT(0)),
        vector_4d<realT>(realT(3), realT(2), realT(1), realT(0)));
    }
  }

  template<typename realT>
  cubic_curve<realT>::cubic_curve()
    : m_cubic(identity)
  {}

  template<typename realT>
  void cubic_curve<realT>::set_hermite(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const vector_3d<realT> &t0, const vector_3d<realT> &t1)
  {
    // Build geometry matrix
    matrix_4X4<realT, column> geom;
    geom.a.Set(p0, 0.0f);
    geom.b.Set(p1, 0.0f);
    geom.c.Set(t0, 0.0f);
    geom.d.Set(t1, 0.0f);

    // Compute cubic coefficients
    matrix_4X4<realT, column> cube;
    cube.Dot(NavCore::Math::Matrix44Impl<realT>::cHermite, geom);
  }

  template<typename realT>
  void cubic_curve<realT>::set_bezier(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3)
  {
    // Build geometry matrix
    matrix_4X4<realT, column> geom;
    geom.a.Set(p0, 0.0);
    geom.b.Set(p1, 0.0);
    geom.c.Set(p2, 0.0);
    geom.d.Set(p3, 0.0);

    // Compute cubic coefficients
    matrix_4X4<realT, column> cube;
    cube.Dot(NavCore::Math::Matrix44Impl<realT>::cBezier, geom);
  }

  template<typename realT>
  void cubic_curve<realT>::set_catmull_rom(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3)
  {
    // Build geometry matrix
    matrix_4X4<realT, column> geom;
    geom.a.Set(p0, 0.0);
    geom.b.Set(p1, 0.0);
    geom.c.Set(p2, 0.0);
    geom.d.Set(p3, 0.0);

    // Compute cubic coefficients
    matrix_4X4<realT, column> cube;
    cube.Dot(NavCore::Math::Matrix44Impl<realT>::cCatmulRom, geom);
  }

  template<typename realT>
  point_3d<realT> cubic_curve<realT>::evaluate_position(realT t) const
  {
    vector_4d<realT> vs(t * t * t, t * t, t, realT(1));
    vector_4d<realT> trans = m_cubic * vs;
    point_3d ret(trans.x(), trans.y(), trans.z());
    return ret;
  }

  template<typename realT>
  vector_3d<realT> cubic_curve<realT>::evaluate_tangent(realT t) const
  {
    vector_4d<realT> vs(realT(3.0f) * squared(t), realT(2.0) * t, 
      realT(1.0f), realT(1));
    return m_cubic * vs;
  }

  template<typename realT>
  curve_sample_3d<realT> cubic_curve<realT>::evaluate(realT t) const
  {
    curve_sample_3d<realT> out_sample;
    out_sample.m_position = evaluate_position(t);
    out_sample.m_tangent = evaluate_tangent(t);
    out_sample.m_parameter = t;

    return out_sample;
  }

  template<typename realT>
  std::vector<realT> cubic_curve<realT>::compute_sample_values(
    std::size_t sample_count) const
  {
    return curve_3d<realT>::compute_sample_values(sample_count);
  }

  template<typename realT>
  std::vector<curve_sample_3d<realT>>
  cubic_curve<realT>::compute_samples_adaptive(
      const tessellation_quality<realT>& quality) const
  {
    return curve_3d<realT>::compute_samples_adaptive(quality);
  }
}
