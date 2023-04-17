#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/kids_with_the_greatest_number_of_candies.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;

  // act
  auto res = solution.kidsWithCandies(candies, extraCandies);

  // assert
  BOOST_CHECK(res[0]);
  BOOST_CHECK(res[1]);
  BOOST_CHECK(res[2]);
  BOOST_CHECK(!res[3]);
  BOOST_CHECK(res[4]);
}
#endif  // !CASE_1
