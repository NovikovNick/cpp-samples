#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/remove_stones_to_minimize_the_total.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> piles{5, 4, 9};
  // act
  auto res = solution.minStoneSum(piles, 2);

  // assert
  BOOST_CHECK_EQUAL(12, res);
}
#endif  // !CASE_1
