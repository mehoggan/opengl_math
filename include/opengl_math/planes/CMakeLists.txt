set(HEADERS
  plane_3d.h
)

set(INLINE_HEADERS
  plane_3d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/planes
)
