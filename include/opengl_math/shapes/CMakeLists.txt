set(HEADERS
  enumerations.h
  line.h
  sphere.h
  triangle.h
)

set(INLINE_HEADERS
  line.inl
  sphere.inl
  triangle.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/primitives/points
)
