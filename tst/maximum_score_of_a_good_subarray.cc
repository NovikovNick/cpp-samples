#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_score_of_a_good_subarray.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {1, 4, 3, 7, 4, 5};
  int k = 3;

  // act
  auto res = solution.maximumScore(nums, k);

  // assert
  BOOST_CHECK_EQUAL(15, res);
}
#endif  // !CASE_1
