#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/parallel_courses_iii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3;
  std::vector<std::vector<int>> relations = {{1, 3}, {2, 3}};
  std::vector<int> time = {3, 2, 5};

  // act
  auto res = solution.minimumTime(n, relations, time);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
