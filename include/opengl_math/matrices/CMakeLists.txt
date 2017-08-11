set(HEADERS
  type_matrix_2X2.h
  type_matrix_3X3.h
  type_matrix_4X4.h
)

set(INLINE_HEADERS
  type_matrix_2X2.inl
  type_matrix_3X3.inl
  type_matrix_4X4.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/matrices
)
