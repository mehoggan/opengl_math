#ifndef COMBINITORICS_TESTS
#define COMBINITORICS_TESTS

#include "test_base.h"

#include "combinatorics/algorithms.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class test_combinatorics : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_combinatorics"; }
};
#endif