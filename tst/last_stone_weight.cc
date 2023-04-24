#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/last_stone_weight.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> stones{2, 7, 4, 1, 8, 1};

  // act
  auto res = solution.lastStoneWeight(stones);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
