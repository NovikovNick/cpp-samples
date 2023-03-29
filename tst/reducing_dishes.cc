#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reducing_dishes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> satisfaction{-1, -8, 0, 1, 1, 1, 1, 1, 1, 1, 1, 5, -7};

  // act
  auto res = solution.maxSatisfaction(satisfaction);

  // assert
  BOOST_CHECK_EQUAL(14, res);
}
#endif  // !CASE_1
