#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/jump_game_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{2, 1, 1, 1, 4, 0, 0, 0};
  // act
  auto res = solution.jump(nums);

  // assert

  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
