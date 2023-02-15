#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/add_to_array_form_of_integer.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> num{1, 2, 3, 4};
  // act
  auto res = solution.addToArrayForm(num, 23);

  // assert
  std::vector<int> expected{1, 2, 5, 7};
  for (int i = 0; i < expected.size(); ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }
}
#endif  // !CASE_1
