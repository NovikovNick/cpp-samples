#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/all_paths_from_source_to_target.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  // std::vector<std::vector<int>> graph{{1, 2}, {3}, {3}, {}};
  std::vector<std::vector<int>> graph{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

  // act
  auto res = solution.allPathsSourceTarget(graph);

  // assert
  for (const auto& it : res) {
    for (const auto& node : it) {
      debug("{} ", node);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
