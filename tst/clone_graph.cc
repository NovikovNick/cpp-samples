#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/clone_graph.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> values{{2, 4}, {1, 3}, {2, 4}, {1, 3}};
  std::vector<leetcode::Node> nodes(4);
  for (int i = 0; i < values.size(); ++i) {
    nodes[i].val = i + 1;
    for (const auto neighbor : values[i]) {
      nodes[i].neighbors.push_back(&nodes[neighbor - 1]);
    }
  }

  // act
  auto res = solution.cloneGraph(&nodes[0]);

  // assert
  debug("{}\n", res->val);
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
