#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/frog_jump.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};

  // act
  auto res = solution.canCross(stones);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
