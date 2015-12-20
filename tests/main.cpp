#include "test_base.h"
#include "test_math.h"
#include "test_numbers.h"
#include "test_operations.h"
#include "test_type_color.h"
#include "test_type_matrix.h"
#include "test_type_point.h"
#include "test_type_texcoord.h"
#include "test_type_vector.h"
#include "test_curves.h"
#include "test_combinatorics.h"
#include "test_planes.h"
#include "test_axis_aligned_2d.h"

#define _CRTDBG_MAP_ALLOC
#include "core/memory_leaks.h"

#include <array>
#include <cstdint>
#include <memory>

int main(int argc, char *argv[])
{
  MEMORY_LEAK_DETECTION_START();
  std::array<std::shared_ptr<test_base>, 12> tests = {
    std::shared_ptr<test_base>(new test_math()),
    std::shared_ptr<test_base>(new test_numbers()),
    std::shared_ptr<test_base>(new test_operations()),
    std::shared_ptr<test_base>(new test_type_color()),
    std::shared_ptr<test_base>(new test_type_matrix()),
    std::shared_ptr<test_base>(new test_type_point()),
    std::shared_ptr<test_base>(new test_type_texcoord()),
    std::shared_ptr<test_base>(new test_type_vector()),
    std::shared_ptr<test_base>(new test_curves()),
    std::shared_ptr<test_base>(new test_combinatorics()),
    std::shared_ptr<test_base>(new test_planes()),
    std::shared_ptr<test_base>(new test_axis_aligned_2d())
  };

  std::cout << "Going to run " << tests.size() << " tests." << std::endl;
  for(auto test_ptr : tests) {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "Running " << test_ptr->name() << std::endl;
    std::cout << "==============================================" << std::endl;
    test_ptr->run();
  }

  for (auto test_ptr : tests) {
    test_ptr.reset();
  }

  return 0;
}
