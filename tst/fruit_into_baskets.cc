#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/fruit_into_baskets.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> fruits{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  
  // act
  auto res = solution.totalFruit(fruits);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
