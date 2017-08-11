set(HEADERS
  type_color_rgb.h
  type_color_rgba.h
)

set(INLINE_HEADERS
  type_color_rgb.inl
  type_color_rgba.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_math/primitives/colors
)
