#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/leetcode/maximum_running_time_of_n_computers.cc"

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 2;
  std::vector<int> batteries{1, 1, 1, 1};

  // act
  auto res = solution.maxRunTime(n, batteries);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
