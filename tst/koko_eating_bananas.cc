#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/koko_eating_bananas.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> piles{1000000000};
  int h = 2;

  // act
  auto res = solution.minEatingSpeed(piles, h);

  // assert
  BOOST_CHECK_EQUAL(500000000, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> piles{805306368, 805306368, 805306368};
  int h = 1000000000;

  // act
  auto res = solution.minEatingSpeed(piles, h);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1