#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/leetcode/fair_distribution_of_cookies.cc"

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> cookies{6, 1, 3, 2, 2, 4, 1, 2};
  int k = 3;

  // act
  auto res = solution.distributeCookies(cookies, k);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
#endif  // !CASE_1
