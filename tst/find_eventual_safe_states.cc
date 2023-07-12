#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_eventual_safe_states.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> graph{{}, {0, 2, 3, 4}, {3}, {4}, {}};
  std::vector<int> expected{0, 1, 2, 3, 4};

  // act
  auto res = solution.eventualSafeNodes(graph);

  // assert
  if (expected.size() == res.size()) {
    for (int i = 0; i < expected.size(); ++i) {
      BOOST_CHECK_EQUAL(expected[i], res[i]);
    }
  } else {
    BOOST_CHECK(false);
  }  
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  std::vector<int> expected{2, 4, 5, 6};

  // act
  auto res = solution.eventualSafeNodes(graph);

  // assert
  if (expected.size() == res.size()) {
    for (int i = 0; i < expected.size(); ++i) {
      BOOST_CHECK_EQUAL(expected[i], res[i]);
    }
  } else {
    BOOST_CHECK(false);
  }
}
#endif  // !CASE_2
