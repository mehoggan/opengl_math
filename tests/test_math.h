#ifndef MATH_TESTS
#define MATH_TESTS

#include "test_base.h"

#include "math/matrix.h"
#include "math/numbers.h"
#include "math/trig.h"
#include "matrices/type_matrix_4X4.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include <iostream>
#include <vector>
#include <cassert>

// TODO: Note that there are no rotation tests that test negative rotations
// TODO: Note that all the matrix calculation such as ortho, pers, and lookat
// are not tested. This is because a graphical frame work with shaders would
// be needed to verify their correctness.
// TODO: Test norm
// TODO: Test angle_between
// TODO: Test operator- (point2, point2)
// TODO: Test operator- (point3, point3)

class test_math : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_math"; }
};
#endif
