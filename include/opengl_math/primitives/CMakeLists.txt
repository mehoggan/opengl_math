set(HEADERS
  conversions.h
)

install(FILES
  ${HEADERS}
  DESTINATION include/opengl_math/primitives
)

add_subdirectory(colors)
add_subdirectory(points)
add_subdirectory(texcoords)
add_subdirectory(vectors)
