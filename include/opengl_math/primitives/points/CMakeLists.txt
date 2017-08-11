set(HEADERS
  type_point_2d.h
  type_point_3d.h
)

set(INLINE_HEADERS
  type_point_2d.inl
  type_point_3d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/primitives/points
)
