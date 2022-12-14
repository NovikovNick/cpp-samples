#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/house_robber.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3, 1};

  // act
  auto res = solution.rob(nums);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
