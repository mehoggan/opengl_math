#ifndef VECTOR_TESTS
#define VECTOR_TESTS

#include "test_base.h"

#include "math/numbers.h"
#include "primitives/vectors/type_vector_2d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include <iostream>
#include <vector>
#include <cassert>

class test_type_vector : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_vector"; }
};

#endif
