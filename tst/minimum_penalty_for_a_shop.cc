#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_penalty_for_a_shop.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string customers = "YYNY";

  // act
  auto res = solution.bestClosingTime(customers);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
