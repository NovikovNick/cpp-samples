#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_ways_of_cutting_a_pizza.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> pizza{"A..", "AAA", "..."};
  int k = 3;

  // act
  auto res = solution.ways(pizza, k);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
