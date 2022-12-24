#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/domino_and_tromino_tiling.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  std::vector<long long> expected{0, 1, 2, 5, 11, 24, 53, 117, 258};

  for (int i = 1; i < expected.size(); ++i) {
    // act & assert
    BOOST_CHECK_EQUAL(expected[i], solution.numTilings(i));
  }
}
#endif  // !CASE_1
