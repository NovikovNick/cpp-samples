#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_ice_cream_bars.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> costs{1, 3, 2, 4, 1};
  int coins = 7;

  // act
  auto res = solution.maxIceCream(costs, coins);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
