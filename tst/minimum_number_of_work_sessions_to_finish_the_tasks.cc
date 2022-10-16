#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/minimum_number_of_work_sessions_to_finish_the_tasks.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {1, 2, 3};
  int target = 3;

  // act
  auto res = solution.minSessions(nums, target);

  // assert
  std::cout << res << std::endl;
  BOOST_CHECK_EQUAL(2, res);
}
