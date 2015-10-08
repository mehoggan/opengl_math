#ifndef POINT_TESTS
#define POINT_TESTS

#include "test_base.h"

#include "primitives/points/type_point_2d.h"
#include "primitives/points/type_point_3d.h"

#include <iostream>
#include <vector>
#include <cassert>

class test_type_point : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_point"; }
};

#endif
