#ifndef TESSELLATION_QUALITY_H_INCLUDED
#define TESSELLATION_QUALITY_H_INCLUDED

namespace opengl_math
{
  template<typename realT>
  struct tessellation_quality
  {
  public:
    tessellation_quality();

    realT _chordal_tol;

    static const tessellation_quality default_quality;
    static const tessellation_quality precise_quality;
  };
}
#include "tessellation_quality.inl"
#endif
