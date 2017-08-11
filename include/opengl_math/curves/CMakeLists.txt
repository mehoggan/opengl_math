set(HEADERS
  cubic_curve.h
  curve_sample_3d.h
)

set(INLINE_HEADERS
  cubic_curve.inl
  curve_sample_3d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/curves
)
