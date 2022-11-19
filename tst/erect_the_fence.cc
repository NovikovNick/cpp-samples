#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 0
#define DEBUG 1

#include "../src/leetcode/erect_the_fence.cc"

#include <algorithm>
#include <boost/test/included/unit_test.hpp>
#include <iostream>

void AssertCoord(const int x, const int y,
                 std::vector<std::vector<int>>& trees) {
  std::vector<int> coord{x, y};
  BOOST_CHECK(std::find(trees.cbegin(), trees.cend(), coord) != trees.cend());
}

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> trees{{2, 2}, {1, 1}, {2, 0},
                                      {2, 4}, {3, 3}, {4, 2}};
  // act
  auto res = solution.outerTrees(trees);

  // assert
  std::vector<std::vector<int>> expected{
      {1, 1}, {3, 3}, {2, 0}, {4, 2}, {2, 4}};
  // for (const auto& it : res) debug("[{},{}],", it[0], it[1]);

  BOOST_CHECK(expected.size() == res.size());
  for (const auto& it : expected) {
    AssertCoord(it[0], it[1], res);
  }
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> trees{
      {3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5},
      {4, 5}, {3, 5}, {2, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 1}, {4, 2}, {0, 3}};
  // act
  auto res = solution.outerTrees(trees);

  // assert
  std::vector<std::vector<int>> expected{
      {0, 3}, {7, 4}, {3, 0}, {4, 0}, {1, 4}, {6, 5}, {5, 5}, {4, 5},
      {7, 3}, {7, 2}, {2, 1}, {6, 1}, {3, 5}, {5, 0}, {2, 5}, {1, 2}};

  // for (const auto& it : res) debug("[{},{}],", it[0], it[1]);

  BOOST_CHECK(expected.size() == res.size());
  for (const auto& it : expected) {
    AssertCoord(it[0], it[1], res);
  }
}
#endif  // !CASE_2