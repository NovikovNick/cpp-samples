#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/checking_existence_of_edge_length_limited_paths.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3;
  std::vector<std::vector<int>> edge_list{
      {0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}};
  std::vector<std::vector<int>> queries{{0, 1, 2}, {0, 2, 5}};

  // act
  auto res = solution.distanceLimitedPathsExist(n, edge_list, queries);

  // assert
  for (int i = 0; i < queries.size(); ++i)
    debug("{}. {}\n", i, res[i] ? "+" : "-");
}
#endif  // !CASE_1
