#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/jump_game.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{3, 2, 1, 0, 4};
  // act
  auto res = solution.canJump(nums);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1
