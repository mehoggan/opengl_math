set(HEADERS
  tessellated_triangle_data.h
  tessellation_ops.h
)

set(INLINE_HEADERS
  tessellated_triangle_data.inl
  tessellation_ops.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/primitives/points
)
