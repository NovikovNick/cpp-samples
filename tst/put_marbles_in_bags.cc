#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/put_marbles_in_bags.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> weights{1, 3, 5, 1};
  int k = 2;

  // act
  auto res = solution.putMarbles(weights, k);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
