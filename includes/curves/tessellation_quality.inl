namespace opengl_math
{
  namespace
  {
    template<typename realT>
    static tessellation_quality<realT> create_precise()
    {
      tessellation_quality<realT> precise_quality;
      precise_quality._chordal_tol = 0.0005f;
      return precise_quality;
    }
  }

  template<typename realT>
  const tessellation_quality<realT>
  tessellation_quality<realT>::default_quality;

  template<typename realT>
  const tessellation_quality<realT>
  tessellation_quality<realT>::precise_quality = create_precise<realT>();

  template<typename realT>
  tessellation_quality<realT>::tessellation_quality() :
    _chordal_tol(0.01f)
  {}
}
