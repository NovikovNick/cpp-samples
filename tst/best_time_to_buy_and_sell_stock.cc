#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/best_time_to_buy_and_sell_stock.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> prices{7, 1, 5, 3, 6, 4};
  // act
  auto res = solution.maxProfit(prices);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
