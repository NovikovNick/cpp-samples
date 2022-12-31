#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/distribute_candies.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> candyType{100000, 0, 100000, 0, 100000, 0,
                             100000, 0, 100000, 0, 100000, 0};
  // act
  auto res = solution.distributeCandies(candyType);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
