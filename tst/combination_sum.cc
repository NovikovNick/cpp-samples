#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/combination_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> candidates{2, 3, 5};
  int target = 8;

  // act
  auto res = solution.combinationSum(candidates, target);

  // assert
  for (int i = 0; i < res.size(); ++i) {
    debug("{}. ", i);
    for (int j = 0; j < res[i].size(); ++j) {
      debug("{} ", res[i][j]);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
