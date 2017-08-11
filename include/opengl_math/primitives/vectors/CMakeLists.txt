set(HEADERS
  type_vector_2d.h
  type_vector_3d.h
  type_vector_4d.h
)

set(INLINE_HEADERS
  type_vector_2d.inl
  type_vector_3d.inl
  type_vector_4d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/primitives/texcoords
)
