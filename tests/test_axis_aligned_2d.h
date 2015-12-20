#ifndef AXIS_ALIGNED_2D_TESTS
#define AXIS_ALIGNED_2D_TESTS

#include "test_base.h"

#include "bounds/axis_aligned_2d.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class test_axis_aligned_2d : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_axis_aligned_2d"; }
};
#endif
