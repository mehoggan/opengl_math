set(HEADERS
  type_texcoord_2d.h
  type_texcoord_3d.h
  type_texcoord_4d.h
)

set(INLINE_HEADERS
  type_texcoord_2d.inl
  type_texcoord_3d.inl
  type_texcoord_4d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/primitives/texcoords
)
