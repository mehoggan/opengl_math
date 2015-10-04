namespace opengl_math
{
  template<typename realT>
  curve_3d<realT>::curve_3d()
  {}

  template<typename realT>
  curve_3d<realT>::~curve_3d()
  {}

  template<typename realT>
  curve_sample_3d<realT> curve_3d<realT>::evaluate(realT t) const
  {
    curve_sample_3d<realT> out_sample;
    out_sample._position = evaluate_position(t);
    out_sample._tangent = evaluate_tangent(t);
    out_sample._parameter = t;

    return out_sample;
  }

  template<typename realT>
  std::vector<realT>
  curve_3d<realT>::compute_sample_values(std::size_t sample_count) const
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
  std::vector<curve_sample_3d<realT>>
  curve_3d<realT>::compute_samples_uniform(std::size_t sample_count) const
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
    template<typename realT>
    realT chordal_distance_squared_from_secant(
      const curve_3d<realT> &curve,
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

    template<typename realT>
    bool is_of_good_quality(
      const curve_3d<realT> &curve,
      const curve_sample_3d<realT> &p0,
      const realT mid_t,
      const curve_sample_3d<realT> &p1,
      const tessellation_quality<realT> &quality,
      const unsigned short depth)
    {
      realT curr_chordal_tol = chordal_distance_squared_from_secant(curve,
        p0, p1, mid_t);
      realT chordal_tol_sq = squared(quality._chordal_tol);
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

    template<typename realT>
    void subdivide(
      std::vector<curve_sample_3d<realT>>& out_samples,
      const curve_3d<realT>& curve,
      const curve_sample_3d<realT> point0,
      const curve_sample_3d<realT> point1,
      const tessellation_quality<realT>& quality,
      unsigned short depth = 0)
    {
      const realT t = lerp<realT>(realT(0.5), point0._parameter,
       point1._parameter);
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
  std::vector<curve_sample_3d<realT>>
  curve_3d<realT>::compute_samples_adaptive(
    const tessellation_quality<realT> &quality) const
  {
    std::vector<curve_sample_3d<realT>> out_samples;

    std::vector<realT> tvals = this->compute_sample_values();
    curve_sample_3d<realT> begin = this->evaluate(tvals[0]);
    curve_sample_3d<realT> end = this->evaluate(tvals[1]);

    out_samples.push_back(begin);
    subdivide(out_samples, (*this), out_samples[0], end, quality);
    out_samples.push_back(end);

    return out_samples;
  }
}
