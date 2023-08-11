#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/coin_change_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int amount = 500;
  std::vector<int> coins{3, 5, 7, 8, 9, 10, 11};

  // act
  auto res = solution.change(amount, coins);

  // assert
  BOOST_CHECK_EQUAL(35502874, res);
}
#endif  // !CASE_1
