#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/insert_interval.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  /*std::vector<std::vector<int>> intervals{
      {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};*/
  //std::vector<int> newInterval{4, 8};

  std::vector<std::vector<int>> intervals{
      {1, 3}, {6, 9}};
  std::vector<int> newInterval{2, 6};
  // act
  auto res = solution.insert(intervals, newInterval);

  // assert
  for (const auto& it : res) debug("[{:4d}:{:4d}],", it[0], it[1]);
  debug(" --- \n");
}
#endif  // !CASE_1
