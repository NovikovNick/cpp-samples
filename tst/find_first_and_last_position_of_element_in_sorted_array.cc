#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_first_and_last_position_of_element_in_sorted_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = { 5, 7, 7, 8, 8, 10};
  int target = 8;

  // act
  auto res = solution.searchRange(nums, target);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
