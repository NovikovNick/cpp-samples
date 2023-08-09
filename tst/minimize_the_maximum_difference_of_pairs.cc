#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimize_the_maximum_difference_of_pairs.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{3, 4, 2, 3, 2, 1, 2};
  int p = 3;

  // act
  auto res = solution.minimizeMax(nums, p);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
