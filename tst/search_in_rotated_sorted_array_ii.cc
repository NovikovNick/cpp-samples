#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/search_in_rotated_sorted_array_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{2, 2, 2, 3, 2, 2, 2};
  int target = 3;

  // act
  auto res = solution.search(nums, target);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
