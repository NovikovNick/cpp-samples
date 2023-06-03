#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/time_needed_to_inform_all_employees.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 6;
  int headID = 2;
  std::vector<int> manager{2, 2, -1, 2, 2, 2};
  std::vector<int> informTime{0, 0, 1, 0, 0, 0};

  // act
  auto res = solution.numOfMinutes(n, headID, manager, informTime);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
