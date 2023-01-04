#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_rounds_to_complete_all_tasks.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> tasks{2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
  // act
  auto res = solution.minimumRounds(tasks);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
