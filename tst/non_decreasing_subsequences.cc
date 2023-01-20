#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/non_decreasing_subsequences.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  //std::vector<int> nums{4, 6, 7, 7};
  //std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  std::vector<int> nums{1,2,3,3,5};
  
  // act
  auto res = solution.findSubsequences(nums);
  solution.nqueens(4);

  // assert
  for (const auto& row : res) {
    for (const auto& it : row) {
      debug("{:4d}", it);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
