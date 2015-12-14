#include "test_combinatorics.h"

void test_n_cr_k()
{
  const int N = 5;
  int array[N] = {0, 1, 2, 3, 4};
  const int k = 3;

  int x = 0;
  std::vector<int [k]> choices(10);
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
    for (int i = 0; i < k; ++i) {
      choices[x][i] = array[i];
    }
    const auto &expect = expected[x];
    const auto &actual = choices[x];
    OPENGL_MATH_ASSERT_VECTOR_EQ(expect, actual, k);
    ++x;
  } while (opengl_math::combinatorics::n_cr_k<int [N], 5>(array, k));

  x = 0;
  int array_oo[N] = {9, 8, 4, 6, 0}; // {0, 4, 6, 8, 9}
  std::sort(&array_oo[0], &array_oo[N]); // Sort required here
  std::vector<int [k]> choices_oo(10);
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
    for (int i = 0; i < k; ++i) {
      choices_oo[x][i] = array_oo[i];
    }
    const auto &expect = expected_oo[x];
    const auto &actual = choices_oo[x];
    OPENGL_MATH_ASSERT_VECTOR_EQ(expect, actual, k);
    ++x;
  } while (opengl_math::combinatorics::n_cr_k<int [N], 5>(array_oo, k));
}

bool test_combinatorics::run()
{
  test_n_cr_k();

  return true;
}