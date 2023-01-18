#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/squares_of_a_sorted_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{-4, -1, 0, 3, 10};

  // act
  auto res = solution.sortedSquares(nums);

  // assert
  for (int i = 0; i < res.size(); ++i) debug("{} ", res[i]);
}
#endif  // !CASE_1
