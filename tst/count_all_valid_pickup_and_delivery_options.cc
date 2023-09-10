#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/count_all_valid_pickup_and_delivery_options.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.countOrders(2);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_1
