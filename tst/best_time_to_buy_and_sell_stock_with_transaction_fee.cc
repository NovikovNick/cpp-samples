#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/best_time_to_buy_and_sell_stock_with_transaction_fee.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> prices{1, 3, 2, 8, 4, 9};
  int fee = 2;

  // act
  auto res = solution.maxProfit(prices, fee);

  // assert
  BOOST_CHECK_EQUAL(8, res);
}
#endif  // !CASE_1
