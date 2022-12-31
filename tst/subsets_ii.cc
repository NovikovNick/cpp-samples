#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/leetcode/subsets_ii.cc"

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 10, 0};
  // act
  auto res = solution.subsetsWithDup(nums);

  // assert
  for (const auto& it : res) {
    for (const auto& node : it) {
      debug("{} ", node);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
