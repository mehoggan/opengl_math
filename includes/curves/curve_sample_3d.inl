namespace opengl_math
{
  template<typename realT>
  curve_sample_3d<realT>::curve_sample_3d() :
    _position(),
    _tangent(),
    _parameter(realT(0))
  {}

  template<typename realT>
  curve_sample_3d<realT>::curve_sample_3d(const point_3d<realT> &position,
    const vector_3d<realT>& tangent, realT parameter) :
    _position(position),
    _tangent(tangent),
    _parameter(parameter)
  {}

  template<typename realT>
  void curve_sample_3d<realT>::normalize_tangent()
  {
    if (!float_equals(_tangent.magnitude(), realT(0),
      std::numeric_limits<float>::epsilon())) {
      _tangent.normalize();
    }
  }
}
