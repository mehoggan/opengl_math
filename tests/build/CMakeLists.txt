cmake_minimum_required(VERSION 3.0.2)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/../includes)
include_directories(${CMAKE_SOURCE_DIR}/../)

set(src ${CMAKE_SOURCE_DIR}/../tests/main.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_base.h
  ${CMAKE_SOURCE_DIR}/../tests/test_curves.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_curves.h
  ${CMAKE_SOURCE_DIR}/../tests/test_math.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_math.h
  ${CMAKE_SOURCE_DIR}/../tests/test_numbers.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_numbers.h
  ${CMAKE_SOURCE_DIR}/../tests/test_operations.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_operations.h
  ${CMAKE_SOURCE_DIR}/../tests/test_type_color.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_type_color.h
  ${CMAKE_SOURCE_DIR}/../tests/test_type_matrix.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_type_matrix.h
  ${CMAKE_SOURCE_DIR}/../tests/test_type_point.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_type_point.h
  ${CMAKE_SOURCE_DIR}/../tests/test_type_texcoord.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_type_texcoord.h
  ${CMAKE_SOURCE_DIR}/../tests/test_type_vector.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_type_vector.h)
                       

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

add_executable(opengl_math_tests ${src})

add_definitions(-DUNICODE -D_UNICODE)
  
target_link_libraries(opengl_math_tests opengl_math_static)

install(TARGETS opengl_math_tests DESTINATION bin)
