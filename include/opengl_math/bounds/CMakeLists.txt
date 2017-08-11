set(HEADERS
  axis_aligned_2d.h
)

set(INLINE_HEADERS
  axis_aligned_2d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/bounds
)
