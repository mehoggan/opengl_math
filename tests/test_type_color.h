#ifndef COLOR_TESTS
#define COLOR_TESTS

#include "test_base.h"

#include "primitives/colors/type_color_rgb.h"
#include "primitives/colors/type_color_rgba.h"

#include <iostream>
#include <vector>
#include <cassert>

class test_type_color : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_colors"; }
};

#endif
