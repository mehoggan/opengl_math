namespace opengl_math
{
  namespace
  {
    template<typename realT, matrix_layout ML>
    matrix_4X4<realT, ML> catmul_rom()
    {
      if (ML == column) {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(-0.5), realT(+1.5), realT(-1.5), realT(+0.5)),
          vector_4d<realT>(realT(+1.0), realT(-2.5), realT(+2.0), realT(-0.5)),
          vector_4d<realT>(realT(-0.5), realT(+0.0), realT(+0.5), realT(+0.0)),
          vector_4d<realT>(realT(+0.0), realT(+1.0), realT(+0.0), realT(+0.0)));
      } else {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(-0.5), realT(+1.0), realT(-0.5), realT(+0.0)),
          vector_4d<realT>(realT(+1.5), realT(-2.5), realT(+0.0), realT(+1.0)),
          vector_4d<realT>(realT(-1.5), realT(+2.0), realT(+0.5), realT(+0.0)),
          vector_4d<realT>(realT(+0.5), realT(-0.5), realT(+0.0), realT(+0.0)));
      }
    }

    template<typename realT, matrix_layout ML>
    matrix_4X4<realT, ML> bezier()
    {
      if (ML == column) {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(-1.0), realT(+3.0), realT(-3.0), realT(+1.0)),
          vector_4d<realT>(realT(+3.0), realT(-6.0), realT(+3.0), realT(+0.0)),
          vector_4d<realT>(realT(-3.0), realT(+3.0), realT(+0.0), realT(+0.0)),
          vector_4d<realT>(realT(+1.0), realT(+0.0), realT(+0.0), realT(+0.0)));
      } else {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(-1.0), realT(+3.0), realT(-3.0), realT(+1.0)),
          vector_4d<realT>(realT(+3.0), realT(-6.0), realT(+3.0), realT(+0.0)),
          vector_4d<realT>(realT(-3.0), realT(+3.0), realT(+0.0), realT(+0.0)),
          vector_4d<realT>(realT(+1.0), realT(+0.0), realT(+0.0), realT(+0.0)));
      }
    }

    template<typename realT, matrix_layout ML>
    matrix_4X4<realT, ML> bezier_inverse()
    {
      const realT val0 = 1 / realT(3.0);
      const realT val1 = 2 / realT(3.0);
      if (ML == column) {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+0.0), realT(+1.0)),
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(val0), realT(+1.0)),
          vector_4d<realT>(realT(+0.0), realT(val0), realT(val1), realT(+1.0)),
          vector_4d<realT>(realT(+1.0), realT(+1.0), realT(+1.0), realT(+1.0)));
      } else {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+0.0), realT(+1.0)),
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(val0), realT(+1.0)),
          vector_4d<realT>(realT(+0.0), realT(val0), realT(val1), realT(+1.0)),
          vector_4d<realT>(realT(+1.0), realT(+1.0), realT(+1.0), realT(+1.0)));
      }
    }

    template<typename realT, matrix_layout ML>
    matrix_4X4<realT, ML> hermite()
    {
      if (ML == column) {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(+2.0), realT(-2.0), realT(+1.0), realT(+1.0)),
          vector_4d<realT>(realT(-3.0), realT(+3.0), realT(-2.0), realT(-1.0)),
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+1.0), realT(+0.0)),
          vector_4d<realT>(realT(+1.0), realT(+0.0), realT(+0.0), realT(+0.0)));
      } else {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(+2.0), realT(-3.0), realT(+0.0), realT(+1.0)),
          vector_4d<realT>(realT(-2.0), realT(+3.0), realT(+0.0), realT(+0.0)),
          vector_4d<realT>(realT(+1.0), realT(-2.0), realT(+1.0), realT(+0.0)),
          vector_4d<realT>(realT(+1.0), realT(-1.0), realT(+0.0), realT(+0.0)));
      }
    }

    template<typename realT, matrix_layout ML>
    matrix_4X4<realT, ML> hermite_inverse()
    {
      if (ML == column) {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+0.0), realT(+1.0)),
          vector_4d<realT>(realT(+1.0), realT(+1.0), realT(+1.0), realT(+1.0)),
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+1.0), realT(+0.0)),
          vector_4d<realT>(realT(+3.0), realT(+2.0), realT(+1.0), realT(+0.0)));
      } else {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(+0.0), realT(+1.0), realT(+0.0), realT(+3.0)),
          vector_4d<realT>(realT(+0.0), realT(+1.0), realT(+0.0), realT(+2.0)),
          vector_4d<realT>(realT(+0.0), realT(+1.0), realT(+1.0), realT(+1.0)),
          vector_4d<realT>(realT(+1.0), realT(+1.0), realT(+0.0), realT(+0.0)));
      }
    }
  }

  template<typename realT, matrix_layout ML>
  cubic_curve<realT, ML>::cubic_curve()
    : m_cubic(identity)
  {}

  template<typename realT, matrix_layout ML>
  void cubic_curve<realT, ML>::set_hermite(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const vector_3d<realT> &t0, const vector_3d<realT> &t1)
  {
    matrix_4X4<realT, ML> geom(
      vector_4d<realT>(p0.x(), p0.y(), p0.z(), realT(0)),
      vector_4d<realT>(p1.x(), p1.y(), p1.z(), realT(0)),
      vector_4d<realT>(t0.x(), t0.y(), t0.z(), realT(0)),
      vector_4d<realT>(t1.x(), t1.y(), t1.z(), realT(0)));

    m_cubic = hermite<realT, ML>() * geom;
  }

  template<typename realT, matrix_layout ML>
  void cubic_curve<realT, ML>::set_bezier(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3)
  {
    matrix_4X4<realT, ML> geom(
      vector_4d<realT>(p0.x(), p0.y(), p0.z(), realT(0)),
      vector_4d<realT>(p1.x(), p1.y(), p1.z(), realT(0)),
      vector_4d<realT>(p2.x(), p2.y(), p2.z(), realT(0)),
      vector_4d<realT>(p3.x(), p3.y(), p3.z(), realT(0)));

    if (ML == row) {
      m_cubic = bezier<realT, ML>() * geom;
    } else {
      m_cubic =  geom * bezier<realT, ML>();
    }
  }

  template<typename realT, matrix_layout ML>
  void cubic_curve<realT, ML>::set_catmull_rom(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3)
  {
    matrix_4X4<realT, ML> geom(
      vector_4d<realT>(p0.x(), p0.y(), p0.z(), realT(0)),
      vector_4d<realT>(p1.x(), p1.y(), p1.z(), realT(0)),
      vector_4d<realT>(p2.x(), p2.y(), p2.z(), realT(0)),
      vector_4d<realT>(p3.x(), p3.y(), p3.z(), realT(0)));

    m_cubic = catmul_rom<realT, ML>() * geom;
  }

  template<typename realT, matrix_layout ML>
  point_3d<realT> cubic_curve<realT, ML>::evaluate_position(realT t) const
  {
    vector_4d<realT> vs(t * t * t, t * t, t, realT(0));

    if (ML == row) {
      vector_4d<realT> trans = vs * m_cubic;
      point_3d<realT> ret(trans.x(), trans.y(), trans.z());
      return ret;
    } else {
      vector_4d<realT> trans = m_cubic * vs;
      point_3d<realT> ret(trans.x(), trans.y(), trans.z());
      return ret;
    }
  }

  template<typename realT, matrix_layout ML>
  vector_3d<realT> cubic_curve<realT, ML>::evaluate_tangent(realT t) const
  {
    vector_4d<realT> vs(
      realT(+3.0) * squared(t),
      realT(+2.0) * t,
      realT(+1.0),
      realT(+1.0));

    if (ML == row) {
      vector_4d<realT> tmp = vs * m_cubic;
      return vector_3d<realT>(tmp.x(), tmp.y(), tmp.z());
    } else {
      vector_4d<realT> tmp = m_cubic * vs;
      return vector_3d<realT>(tmp.x(), tmp.y(), tmp.z());
    }
  }
}
