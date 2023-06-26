#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/total_cost_to_hire_k_workers.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> costs{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int k = 9;
  int candidates = 1;

  // act
  auto res = solution.totalCost(costs, k, candidates);

  // assert
  BOOST_CHECK_EQUAL(45, res);
}
#endif  // !CASE_1
