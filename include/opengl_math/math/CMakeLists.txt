set(HEADERS
  algebra.h
  clamp.h
  CMakeLists.txt
  matrix.h
  numbers.h
  sqrt.h
  trig.h
  vector.h
)

install(FILES
  ${HEADERS}
  DESTINATION include/opengl_math/math
)
