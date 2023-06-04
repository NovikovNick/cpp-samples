#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/leetcode/number_of_provinces.cc"

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> isConnected{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  // act
  auto res = solution.findCircleNum(isConnected);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
