#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/permutations_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 1, 2};

  // act
  auto res = solution.permuteUnique(nums);

  // assert
  for (int row = 0; row < res.size(); ++row) {
    for (int col = 0; col < res[row].size(); ++col) {
      debug("{} ", res[row][col]);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
