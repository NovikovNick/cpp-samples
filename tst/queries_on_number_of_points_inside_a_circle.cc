#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/queries_on_number_of_points_inside_a_circle.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points{
      {99, 113}, {150, 165}, {23, 65}, {175, 154}, {84, 83},
      {24, 59},  {124, 29},  {19, 97}, {117, 182}, {105, 191},
      {83, 117}, {114, 35},  {0, 111}, {22, 53}};
  std::vector<std::vector<int>> queries{{175, 154, 28}};

  // act
  auto res = solution.countPoints(points, queries);

  // assert
  for (const auto& it : res) debug("{} ", it);
  debug("\n");
}
#endif  // !CASE_1
