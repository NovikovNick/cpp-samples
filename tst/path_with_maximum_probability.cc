#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/path_with_maximum_probability.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3;
  std::vector<std::vector<int>> edges{{0, 1}};
  std::vector<double> succProb{0.5};
  int start = 0;
  int end = 2;

  // act
  auto res = solution.maxProbability(n, edges, succProb, start, end);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  int n = 3;
  std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
  std::vector<double> succProb{0.5, 0.5, 0.2};
  int start = 0;
  int end = 2;

  // act
  auto res = solution.maxProbability(n, edges, succProb, start, end);

  // assert
  BOOST_CHECK_EQUAL(0.25, res);
}
#endif  // !CASE_2
