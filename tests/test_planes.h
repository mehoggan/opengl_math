#ifndef PLANES_TESTS
#define PLANES_TESTS

#include "test_base.h"

#include "planes/plane_3d.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class test_planes : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_planes"; }
};
#endif