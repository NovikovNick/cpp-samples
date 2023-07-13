#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/course_schedule.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int numCourses = 5;
  std::vector<std::vector<int>> prerequisites{{1, 4}, {2, 4}, {3, 1}, {3, 2}};

  // act
  auto res = solution.canFinish(numCourses, prerequisites);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
