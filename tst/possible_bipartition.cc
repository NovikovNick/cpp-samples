#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/possible_bipartition.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> dislikes{{1, 2}, {1, 3}, {2, 4}};

  // act
  auto res = solution.possibleBipartition(4, dislikes);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
