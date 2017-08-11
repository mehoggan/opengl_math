#include "opengl_math/combinatorics/algorithms.h"

#include "suite.h"

#include <vector>

#include <check.h>

START_TEST(test_n_cr_k)
{
  std::vector<int> array = {0, 1, 2, 3, 4};
  const std::size_t k = 3;

  int x = 0;
  std::vector<std::vector<int>> choices(10);
  std::vector<std::vector<int>> expected;
  expected.push_back({0, 1, 2});
  expected.push_back({0, 1, 3});
  expected.push_back({0, 1, 4});
  expected.push_back({0, 2, 3});
  expected.push_back({0, 2, 4});
  expected.push_back({0, 3, 4});
  expected.push_back({1, 2, 3});
  expected.push_back({1, 2, 4});
  expected.push_back({1, 3, 4});
  expected.push_back({2, 3, 4});
  do {
    for (std::size_t i = 0; i < k; ++i) {
      choices[x][i] = array[i];
    }
    const auto &expect = expected[x];
    const auto &actual = choices[x];

    for (std::size_t i = 0; i < expect.size(); ++i) {
      ck_assert(expect[i] == actual[i]);
    }
    ++x;
  } while (opengl_math::combinatorics::n_cr_k<
    std::vector<int>, 5>(array, k));

  x = 0;
  std::vector<int> array_oo = {9, 8, 4, 6, 0}; // {0, 4, 6, 8, 9}
  std::sort(array_oo.begin(), array_oo.end()); // Sort required here
  std::vector<std::vector<int>> choices_oo(10);
  std::vector<std::vector<int>> expected_oo;
  expected_oo.push_back({0, 4, 6});
  expected_oo.push_back({0, 4, 8});
  expected_oo.push_back({0, 4, 9});
  expected_oo.push_back({0, 6, 8});
  expected_oo.push_back({0, 6, 9});
  expected_oo.push_back({0, 8, 9});
  expected_oo.push_back({4, 6, 8});
  expected_oo.push_back({4, 6, 9});
  expected_oo.push_back({4, 8, 9});
  expected_oo.push_back({6, 8, 9});
  do {
    for (std::size_t i = 0; i < k; ++i) {
      choices_oo[x][i] = array_oo[i];
    }
    const auto &expect = expected_oo[x];
    const auto &actual = choices_oo[x];
    for (std::size_t i = 0; i < expect.size(); ++i) {
      ck_assert(expect[i] == actual[i]);
    }
    ++x;
  } while (opengl_math::combinatorics::n_cr_k<
    std::vector<int>, 5>(array_oo, k));
}
END_TEST

int
main(int argc, char *argv[])
{
  Suite *s;
  SRunner *sr;
  TCase *tc;
  int result;

  s = suite_create("Unit Tests");
  tc = tcase_create(__FILE__);
  tcase_add_test(tc, test_n_cr_k);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
