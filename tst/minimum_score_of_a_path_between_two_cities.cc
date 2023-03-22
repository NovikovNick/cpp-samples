#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_score_of_a_path_between_two_cities.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> roads{
      {1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
  int n = 4;

  // act
  auto res = solution.minScore(n, roads);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> roads{
      {4, 5, 7468}, {6, 2, 7173}, {6, 3, 8365}, {2, 3, 7674}, {5, 6, 7852},
      {1, 2, 8547}, {2, 4, 1885}, {2, 5, 5192}, {1, 3, 4065}, {1, 4, 7357}};
  int n = 6;

  // act
  auto res = solution.minScore(n, roads);

  // assert
  BOOST_CHECK_EQUAL(1885, res);
}
#endif  // !CASE_2