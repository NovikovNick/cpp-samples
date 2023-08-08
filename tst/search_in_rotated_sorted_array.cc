#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/search_in_rotated_sorted_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  // act
  auto res = solution.search(nums, target);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
