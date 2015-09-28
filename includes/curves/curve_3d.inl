namespace opengl_math
{
  template<typename realT>
  curve_3d<realT>::curve_3d()
  {}

  template<typename realT>
  curve_3d<realT>::~curve_3d()
  {}

  template<typename realT>
  vector_3d<realT> curve_3d<realT>::evaluate_tangent(realT t) const
  {
    const realT delta = 0.001f;

    realT backward_t = max<realT>(t - delta, 0.0f);
    realT forward_t = min<realT>(t + delta, 1.0f);

    point_3d<realT> p0 = this->evaluate_position(backward_t);
    point_3d<realT> p1 = this->evaluatePosition(forward_t);

    vector_3d<realT> tangent = p1 - p0;
    tangent *= (realT(1.0) / (forward_t - backward_t));

    return tan;
  }

  template<typename realT>
  curve_sample_3d<realT> curve_3d<realT>::evaluate(realT t) const
  {
    curve_sample_3d<realT> sample;

    sample._position = this->evaluate_position(t);
    sample._tangent = this->evaluate_tangent(t);

    sample._parameter = t;

    return sample;
  }

  template<typename realT>
  std::vector<realT> curve_3d<realT>::compute_sample_values(
    std::size_t sample_count) const
  {
    sample_count = max(sample_count, static_cast<size_t>(2));

    std::vector<realT> out_samples;
    out_samples.reserve(sample_count);
    out_samples.push_back(realT(0.0f));
    for (size_t i = 1; i < sample_count - 1; ++i) {
      out_samples.push_back(static_cast<realT>(i) / (sample_count - realT(1)));
    }
    out_samples.push_back(realT(1.0));

    return out_samples;
  }

  template<typename realT>
  std::vector<curve_sample_3d<realT>> curve_3d<realT>::compute_samples_uniform(
    std::size_t sample_count) const
  {
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
    template<typename realT>
    realT chordal_distance_squared_from_secant(
      const curve_3d<realT> &curve,
      const curve_sample_3d<realT> &point0,
      const curve_sample_3d<realT> &point1,
      realT percent)
    {
      point_3d<realT> sec_pos = lerp(realT(percent), point0._position,
        point1._position);

      curve_sample_3d<realT> pos = curve.evaluate(point0._parameter +
        (percent * (point1._parameter - point0._parameter)));

      return ERROR;//pos.m_position.DistanceSquared(sec_pos);
    }

    const unsigned short max_depth = 10;

    template<typename realT>
    bool is_of_good_quality(
      const curve_3d<realT> &curve,
      const curve_sample_3d<realT> &point0,
      const realT mid_t,
      const curve_sample_3d<realT> &point1,
      const tessellation_quality<realT> &quality,
      const unsigned short depth)
    {
      realT curr_chordal_tol = chordal_distance_squared_from_secant(curve,
        point0, point1, mid_t);
      realT chordal_tol_sq = squared(quality._chordal_tol);
      bool chordal_tol_good = (curr_chordal_tol <= chordal_tol_sq);
      bool is_good = chordal_tol_good;

      if (depth > max_depth) {
        is_good = true;
      } else if (is_good) {
        vector_3d<realT> secant = point1.m_position - point0.m_position;
        ERROR // Next line
        if (secant.is_near_zero() || point0.m_tangent.is_near_zero()) {
          is_good = true;
        } else {
          vector_3d<realT> tangent = point0.m_tangent;
          secant.normalize();
          tangent.normalize();

          ERROR //realT tangent_deviation = secant.distance(tangent);
          if (is_good && tangent_deviation > realT(0.10)) {
            is_good = false;
          }
        }
      }

      return is_good;
    }

    template<typename realT>
    void subdivide(
      std::vector<curve_sample_3d<realT>>& out_samples,
      const curve_3d<realT>& curve,
      const curve_sample_3d<realT> point0,
      const curve_sample_3d<realT> point1,
      const tessellation_quality<realT>& quality,
      unsigned short depth = 0)
    {
      ERROR //const realT t = lerp(realT(0.5), point0.m_parameter, point1.m_parameter);
      const curve_sample_3d<realT> break_point = curve.evaluate(t);

      if (is_of_good_quality(curve, point0, t, point1, quality, depth)) {
        return;
      } else {
        ++depth;
        subdivide(out_samples, curve, point0, break_point, quality, depth);
        out_samples.push_back(break_point);
        subdivide(out_samples, curve, break_point, point1, quality, depth);
        --depth;
      }
    }
  }

  template<typename realT>
  std::vector<curve_sample_3d<realT>> curve_3d<realT>::compute_samples_adaptive(
    const tessellation_quality<realT> &quality) const
  {
    std::vector<curve_sample_3d<realT>> out_samples;

    std::vector<realT> tvals = this->compute_sample_values();
    curve_sample_3d<realT> begin = this->evaluate(tvals[0]);
    curve_sample_3d<realT> end = this->evaluate(tvals[1]);

    out_samples.push_back(begin);
    subdivide(out_samples, curve, out_samples[0], end, quality);
    out_samples.push_back(end);

    return out_samples;
  }
}
