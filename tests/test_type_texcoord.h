#ifndef TEX_COORD_TESTS
#define TEX_COORD_TESTS

#include "test_base.h"

#include "primitives/texcoords/type_texcoord_2d.h"
#include "primitives/texcoords/type_texcoord_3d.h"
#include "primitives/texcoords/type_texcoord_4d.h"

#include <iostream>
#include <vector>
#include <cassert>

class test_type_texcoord : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_texcoord"; }
};

#endif//
