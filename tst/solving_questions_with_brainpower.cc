#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/solving_questions_with_brainpower.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 1e5;
  std::vector<std::vector<int>> questions(n, std::vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    questions[i][0] = rand() % 100;
    questions[i][1] = rand() % 10;
  }

  /*std::vector<std::vector<int>> questions {
    {21, 5}, {92, 3}, {74, 2}, {39, 4}, {58, 2}, {5, 5}, {49, 4}, { 65, 3 }
  };*/


  // act
  auto res = solution.mostPoints(questions);

  // assert
  BOOST_CHECK_EQUAL(157, res);
}
#endif  // !CASE_1
