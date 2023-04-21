#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/profitable_schemes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 10;
  int minProfit = 5;
  std::vector<int> group{2, 3, 5, 1};
  std::vector<int> profit{6, 7, 8, 5};

  // act
  auto res = solution.profitableSchemes(n, minProfit, group, profit);

  // assert
  BOOST_CHECK_EQUAL(14, res);
}
#endif  // !CASE_1
