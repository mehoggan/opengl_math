namespace opengl_math
{
  namespace
  {
    template<typename realT, matrix_layout ML>
    matrix_4X4<realT, ML> catmulrom()
    {
      if (ML == column) {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(-0.5), realT(+1.5), realT(-1.5), realT(+0.5)),
          vector_4d<realT>(realT(+1.0), realT(-2.5), realT(+2.0), realT(-0.5)),
          vector_4d<realT>(realT(-0.5), realT(+0.0), realT(+0.5), realT(+0.0)),
          vector_4d<realT>(realT(+0.0), realT(+1.0), realT(+0.0), realT(+0.0)));
      } else {
        return matrix_4X4<realT, ML>(
          vector_4d<realT>(realT(-0.5), realT(+1.5), realT(-1.5), realT(+0.5)),
          vector_4d<realT>(realT(+1.0), realT(-2.5), realT(+2.0), realT(-0.5)),
          vector_4d<realT>(realT(-0.5), realT(+0.0), realT(+0.5), realT(+0.0)),
          vector_4d<realT>(realT(+0.0), realT(+1.0), realT(+0.0), realT(+0.0)));;
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
          vector_4d<realT>(realT(+2.0), realT(-2.0), realT(+1.0), realT(+1.0)),
          vector_4d<realT>(realT(-3.0), realT(+3.0), realT(-2.0), realT(-1.0)),
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+1.0), realT(+0.0)),
          vector_4d<realT>(realT(+1.0), realT(+0.0), realT(+0.0), realT(+0.0)));
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
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+0.0), realT(+1.0)),
          vector_4d<realT>(realT(+1.0), realT(+1.0), realT(+1.0), realT(+1.0)),
          vector_4d<realT>(realT(+0.0), realT(+0.0), realT(+1.0), realT(+0.0)),
          vector_4d<realT>(realT(+3.0), realT(+2.0), realT(+1.0), realT(+0.0)));
      }
    }
  }

  template<typename realT, matrix_layout ML>
  cubic_curve<realT, ML>::cubic_curve(type impl) :
    _cubic(identity),
    _impl(impl)
  {}

  template<typename realT, matrix_layout ML>
  cubic_curve<realT, ML>::cubic_curve(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const vector_3d<realT> &t0, const vector_3d<realT> &t1) :
    _cubic(identity)
  {
    this->set_hermite(p0, p1, t0, t1);
  }

  template<typename realT, matrix_layout ML>
  cubic_curve<realT, ML>::cubic_curve(type impl,
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3) :
    _cubic(identity)
  {
    matrix_4X4<realT, ML> geom;
    matrix_4X4<realT, ML> mimpl;

    switch(impl) {
    case type::bezier: {
      this->set_bezier(p0, p1, p2, p3);
    }
      break;
    case type::hermite: {
      this->set_hermite(p0, p3, p2 - p0, p3 - p1);
    }
      break;
    case type::catmullrom: {
      this->set_catmullrom(p0, p1, p2, p3);
    }
      break;
    }
  }

  template<typename realT, matrix_layout ML>
  typename cubic_curve<realT, ML>::type cubic_curve<realT, ML>::get_type() const
  {
    return _impl;
  }

  template<typename realT, matrix_layout ML>
  void cubic_curve<realT, ML>::set_hermite(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const vector_3d<realT> &t0, const vector_3d<realT> &t1)
  {
    _impl = type::hermite;
    matrix_4X4<realT, ML> geom(
      vector_4d<realT>(p0.x(), p0.y(), p0.z(), realT(0)),
      vector_4d<realT>(p1.x(), p1.y(), p1.z(), realT(0)),
      vector_4d<realT>(t0.x(), t0.y(), t0.z(), realT(0)),
      vector_4d<realT>(t1.x(), t1.y(), t1.z(), realT(0)));

    if (ML == row) {
      _cubic = hermite<realT, ML>() * geom;
    } else {
      _cubic = geom * hermite<realT, ML>();
    }
  }

  template<typename realT, matrix_layout ML>
  void cubic_curve<realT, ML>::set_bezier(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3)
  {
    _impl = type::bezier;
    matrix_4X4<realT, ML> geom(
      vector_4d<realT>(p0.x(), p0.y(), p0.z(), realT(0)),
      vector_4d<realT>(p1.x(), p1.y(), p1.z(), realT(0)),
      vector_4d<realT>(p2.x(), p2.y(), p2.z(), realT(0)),
      vector_4d<realT>(p3.x(), p3.y(), p3.z(), realT(0)));

    if (ML == row) {
      _cubic = bezier<realT, ML>() * geom;
    } else {
      _cubic = geom * bezier<realT, ML>();
    }
  }

  template<typename realT, matrix_layout ML>
  void cubic_curve<realT, ML>::set_catmullrom(
    const point_3d<realT> &p0, const point_3d<realT> &p1,
    const point_3d<realT> &p2, const point_3d<realT> &p3)
  {
    _impl = type::catmullrom;
    matrix_4X4<realT, ML> geom(
      vector_4d<realT>(p0.x(), p0.y(), p0.z(), realT(0)),
      vector_4d<realT>(p1.x(), p1.y(), p1.z(), realT(0)),
      vector_4d<realT>(p2.x(), p2.y(), p2.z(), realT(0)),
      vector_4d<realT>(p3.x(), p3.y(), p3.z(), realT(0)));

    if (ML == row) {
      _cubic = catmulrom<realT, ML>() * geom;
    } else {
      _cubic = geom * catmulrom<realT, ML>();
    }
  }

  template<typename realT, matrix_layout ML>
  point_3d<realT> cubic_curve<realT, ML>::evaluate_position(realT t) const
  {
    vector_4d<realT> vs(t * t * t, t * t, t, realT(1));

    if (ML == row) {
      vector_4d<realT> trans = vs * _cubic;
      point_3d<realT> ret(trans.x(), trans.y(), trans.z());
      return ret;
    } else {
      vector_4d<realT> trans = _cubic * vs;
      point_3d<realT> ret(trans.x(), trans.y(), trans.z());
      return ret;
    }
  }

  template<typename realT, matrix_layout ML>
  vector_3d<realT> cubic_curve<realT, ML>::evaluate_tangent(realT t) const
  {
    vector_4d<realT> vs(
      realT(+3) * squared(t),
      realT(+2) * t,
      realT(+1),
      realT(+0));

    if (ML == row) {
      vector_4d<realT> tmp = vs * _cubic;
      return vector_3d<realT>(tmp.x(), tmp.y(), tmp.z());
    } else {
      vector_4d<realT> tmp = _cubic * vs;
      return vector_3d<realT>(tmp.x(), tmp.y(), tmp.z());
    }
  }

  template<typename realT, matrix_layout ML>
  curve_sample_3d<realT> cubic_curve<realT, ML>::evaluate(realT t) const
  {
    curve_sample_3d<realT> out_sample;
    out_sample._position = evaluate_position(t);
    out_sample._tangent = evaluate_tangent(t);
    out_sample._parameter = t;

    return out_sample;
  }

  template<typename realT, matrix_layout ML>
  std::vector<realT>
  cubic_curve<realT, ML>::compute_sample_values(std::size_t sample_count) const
  {
    sample_count = max<std::size_t>(sample_count, static_cast<size_t>(2));

    std::vector<realT> out_samples;
    out_samples.reserve(sample_count);
    out_samples.push_back(realT(0.0f));
    for (size_t i = 1; i < sample_count - 1; ++i) {
      out_samples.push_back(static_cast<realT>(i) / (sample_count - realT(1)));
    }
    out_samples.push_back(realT(1.0));

    return out_samples;
  }

  template<typename realT, matrix_layout ML>
  std::vector<curve_sample_3d<realT>>
  cubic_curve<realT, ML>::compute_samples_uniform(
    std::size_t sample_count) const
  {
    sample_count = max(sample_count, static_cast<size_t>(2));

    std::vector<curve_sample_3d<realT>> out_samples;
    out_samples.reserve(sample_count);

    for (std::size_t i = 0; i < sample_count; ++i) {
      realT t = static_cast<realT>(i) / static_cast<realT>(sample_count - 1);
      curve_sample_3d<realT> sample = this->evaluate(t);
      out_samples.push_back(sample);
    }

    return out_samples;
  }

  namespace
  {
    template<typename realT, matrix_layout ML>
    realT chordal_distance_squared_from_secant(
      const cubic_curve<realT, ML> &curve,
      const curve_sample_3d<realT> &point0,
      const curve_sample_3d<realT> &point1,
      realT percent)
    {
      point_3d<realT> sec_pos = lerp<realT>(realT(percent), point0._position,
        point1._position);

      curve_sample_3d<realT> pos = curve.evaluate(point0._parameter +
        (percent * (point1._parameter - point0._parameter)));

      return squared((pos._position - sec_pos).magnitude());
    }

    const unsigned short max_depth = 10;

    template<typename realT, matrix_layout ML>
    bool is_of_good_quality(
      const cubic_curve<realT, ML> &curve,
      const curve_sample_3d<realT> &p0,
      const realT mid_t,
      const curve_sample_3d<realT> &p1,
      realT chordalTol,
      const unsigned short depth)
    {
      realT curr_chordal_tol = chordal_distance_squared_from_secant(curve,
        p0, p1, mid_t);
      realT chordal_tol_sq = squared(chordalTol);
      bool chordal_tol_good = (curr_chordal_tol <= chordal_tol_sq);
      bool is_good = chordal_tol_good;

      if (depth > max_depth) {
        is_good = true;
      } else if (is_good) {
        vector_3d<realT> secant = p1._position - p0._position;
        realT epsilon = std::numeric_limits<realT>::epsilon();
        if (vector_3d_float_equals(secant, vector_3d<realT>(), epsilon) ||
          vector_3d_float_equals(p0._tangent, vector_3d<realT>(), epsilon)) {
          is_good = true;
        } else {
          vector_3d<realT> tangent = p0._tangent;
          secant.normalize();
          tangent.normalize();

          point_3d<realT> a = point3d_from_vector3d(secant);
          point_3d<realT> b = point3d_from_vector3d(tangent);

          realT tangent_deviation = (a - b).magnitude();
          if (is_good && tangent_deviation > realT(0.10)) {
            is_good = false;
          }
        }
      }

      return is_good;
    }

    template<typename realT, matrix_layout ML>
    void subdivide(
      std::vector<curve_sample_3d<realT>>& out_samples,
      const cubic_curve<realT, ML>& curve,
      const curve_sample_3d<realT> point0,
      const curve_sample_3d<realT> point1,
      realT chordalTol,
      unsigned short depth = 0)
    {
      const realT t = lerp<realT>(realT(0.5), point0._parameter,
       point1._parameter);
      const curve_sample_3d<realT> break_point = curve.evaluate(t);

      if (is_of_good_quality(curve, point0, t, point1, chordalTol, depth)) {
        return;
      } else {
        ++depth;
        subdivide(out_samples, curve, point0, break_point, chordalTol, depth);
        out_samples.push_back(break_point);
        subdivide(out_samples, curve, break_point, point1, chordalTol, depth);
        --depth;
      }
    }
  }

  template<typename realT, matrix_layout ML>
  std::vector<curve_sample_3d<realT>>
  cubic_curve<realT, ML>::compute_samples_adaptive(realT chordalTol) const
  {
    std::vector<curve_sample_3d<realT>> out_samples;

    std::vector<realT> tvals = this->compute_sample_values();
    curve_sample_3d<realT> begin = this->evaluate(tvals[0]);
    curve_sample_3d<realT> end = this->evaluate(tvals[1]);

    out_samples.push_back(begin);
    subdivide<realT, ML>(out_samples, (*this), out_samples[0], end, chordalTol);
    out_samples.push_back(end);

    return out_samples;
  }
}
