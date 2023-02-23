#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/ipo.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int k = 1e5;
  int w = 1e5;
  std::vector<int> profits(1e4, 1e4);
  std::vector<int> capital(1e4);
  std::iota(capital.begin(), capital.end(), 1);

  // act
  auto res = solution.findMaximizedCapital(k, w, profits, capital);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  int k = 2;
  int w = 0;
  std::vector<int> profits{1, 2, 3};
  std::vector<int> capital{0, 1, 1};
  
  // act
  auto res = solution.findMaximizedCapital(k, w, profits, capital);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_2
