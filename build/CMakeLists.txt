cmake_minimum_required(VERSION 3.0.2)

project(opengl_math CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/../tests/build ${CMAKE_CURRENT_BINARY_DIR}/tests)

include_directories(${CMAKE_SOURCE_DIR}/../includes)
include_directories(${CMAKE_SOURCE_DIR}/../)

set(src ${CMAKE_SOURCE_DIR}/../src/dummy.cpp
  ${CMAKE_SOURCE_DIR}/../declspec.h
  ${CMAKE_SOURCE_DIR}/../includes/bounds/axis_aligned_2d.inl
  ${CMAKE_SOURCE_DIR}/../includes/bounds/axis_aligned_2d.h
  ${CMAKE_SOURCE_DIR}/../includes/combinatorics/algorithms.h
  ${CMAKE_SOURCE_DIR}/../includes/core/enumerations.h
  ${CMAKE_SOURCE_DIR}/../includes/core/memory_leaks.h
  ${CMAKE_SOURCE_DIR}/../includes/core/platform.h
  ${CMAKE_SOURCE_DIR}/../includes/curves/cubic_curve.inl
  ${CMAKE_SOURCE_DIR}/../includes/curves/cubic_curve.h
  ${CMAKE_SOURCE_DIR}/../includes/curves/curve_sample_3d.inl
  ${CMAKE_SOURCE_DIR}/../includes/curves/curve_sample_3d.h
  ${CMAKE_SOURCE_DIR}/../includes/planes/plane_3d.inl
  ${CMAKE_SOURCE_DIR}/../includes/planes/plane_3d.h
  ${CMAKE_SOURCE_DIR}/../includes/math/algebra.h
  ${CMAKE_SOURCE_DIR}/../includes/math/clamp.h
  ${CMAKE_SOURCE_DIR}/../includes/math/matrix.h
  ${CMAKE_SOURCE_DIR}/../includes/math/numbers.h
  ${CMAKE_SOURCE_DIR}/../includes/math/sqrt.h
  ${CMAKE_SOURCE_DIR}/../includes/math/trig.h
  ${CMAKE_SOURCE_DIR}/../includes/math/vector.h
  ${CMAKE_SOURCE_DIR}/../includes/matrices/type_matrix_2X2.h
  ${CMAKE_SOURCE_DIR}/../includes/matrices/type_matrix_2X2.inl
  ${CMAKE_SOURCE_DIR}/../includes/matrices/type_matrix_3X3.h
  ${CMAKE_SOURCE_DIR}/../includes/matrices/type_matrix_3X3.inl
  ${CMAKE_SOURCE_DIR}/../includes/matrices/type_matrix_4X4.h
  ${CMAKE_SOURCE_DIR}/../includes/matrices/type_matrix_4X4.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/colors/type_color_rgb.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/colors/type_color_rgb.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/colors/type_color_rgba.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/colors/type_color_rgba.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/conversions.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/points/type_point_2d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/points/type_point_2d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/points/type_point_3d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/points/type_point_3d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/texcoords/type_texcoord_2d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/texcoords/type_texcoord_2d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/texcoords/type_texcoord_3d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/texcoords/type_texcoord_3d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/texcoords/type_texcoord_4d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/texcoords/type_texcoord_4d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/vectors/type_vector_2d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/vectors/type_vector_2d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/vectors/type_vector_3d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/vectors/type_vector_3d.inl
  ${CMAKE_SOURCE_DIR}/../includes/primitives/vectors/type_vector_4d.h
  ${CMAKE_SOURCE_DIR}/../includes/primitives/vectors/type_vector_4d.inl)

include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_library(opengl_math_static STATIC ${src})
add_library(opengl_math_shared SHARED ${src})

add_definitions(-DUNICODE -D_UNICODE)

enable_testing()
add_test(NAME tests COMMAND math_tests)
