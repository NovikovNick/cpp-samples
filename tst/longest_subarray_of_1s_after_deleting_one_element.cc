#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/longest_subarray_of_1s_after_deleting_one_element.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};

  // act
  auto res = solution.longestSubarray(nums);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
