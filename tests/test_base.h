#ifndef TEST_TEST_BASE_H_INCLUDED
#define TEST_TEST_BASE_H_INCLUDED

#include "core/platform.h"

#include <stdio.h>

#include <cassert>
#include <iostream>

#if __OPENGL_MATH_WINDOWS__
#define OPENGL_MATH_ASSERT_EQ(lhs, rhs) \
  if (!((lhs) == (rhs))) { \
    char buff[1024]; \
    sprintf_s(buff, 1024, "Failed on %d in %s in %s\n", \
      __LINE__, __FILE__, __FUNCTION__); \
    OutputDebugStringA("***********************************************\n"); \
    OutputDebugStringA(buff); \
    OutputDebugStringA("***********************************************\n"); \
      } \
  assert(((lhs) == (rhs)));

#define OPENGL_MATH_ASSERT_NE(lhs, rhs) \
  if (((lhs) == (rhs))) { \
    char buff[1024]; \
    sprintf_s(buff, 1024, "Failed on %d in %s in %s\n", \
      __LINE__, __FILE__, __FUNCTION__); \
    OutputDebugStringA("***********************************************\n"); \
    OutputDebugStringA(buff); \
    OutputDebugStringA("***********************************************\n"); \
          } \
  assert(((lhs) != (rhs)));

#define OPENGL_MATH_ASSERT(expression) \
  if (!expression) { \
    char buff[1024]; \
    sprintf_s(buff, 1024, "Failed on %d in %s in %s\n", \
      __LINE__, __FILE__, __FUNCTION__); \
    OutputDebugStringA("***********************************************\n"); \
    OutputDebugStringA(buff); \
    OutputDebugStringA("***********************************************\n"); \
      } \
  assert(expression);
#else
#define OPENGL_MATH_ASSERT_EQ(lhs, rhs) \
  if (!((lhs) == (rhs))) { \
    std::cout << "Failure on " << __LINE__ << " in " << __FILE__ << " in " \
      << __FUNCTION__ << std::endl; \
  assert(((lhs) == (rhs)));

#define OPENGL_MATH_ASSERT_EQ(lhs, rhs) \
  if (((lhs) == (rhs))) { \
    std::cout << "Failure on " << __LINE__ << " in " << __FILE__ << " in " \
      << __FUNCTION__ << std::endl; \
  assert(((lhs) != (rhs)));

#define OPENGL_MATH_ASSERT(expression) \
  if (!expression) { \
    std::cout << "Failure on " << __LINE__ << " in " << __FILE__ << " in " \
      << __FUNCTION__ << std::endl; \
      } \
  assert(expression);
#endif

class test_base
{
public:
  ~test_base()
  {}

  virtual bool run() = 0;
  virtual const char *name() = 0;
};

#endif
