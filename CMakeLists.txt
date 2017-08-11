cmake_minimum_required(VERSION 3.0.2)
project(opengl_math)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

option(
  BUILD_SHARED_LIBS
  "Build shared libraries over static library."
  OFF
)
option(
  OPENGL_MATH_TESTS
  "Build unit tests."
  ON
)

add_subdirectory(include)
add_subdirectory(lib)

if(OPENGL_MATH_TESTS)
  add_subdirectory(tests)
endif()
