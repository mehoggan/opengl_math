#ifndef MATRICES_TESTS
#define MATRICES_TESTS

#define _USE_MATH_DEFINES

#include "test_base.h"

#include "matrices/type_matrix_2X2.h"
#include "matrices/type_matrix_3X3.h"
#include "matrices/type_matrix_4X4.h"
#include "primitives/vectors/type_vector_2d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"
#include "math/numbers.h"

#include <cstdlib>
#include <ctime>

/*
 * Start of actual tests.
 */
class test_type_matrix : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_matrix"; }
};

#endif
