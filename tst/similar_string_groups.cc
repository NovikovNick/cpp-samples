#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/similar_string_groups.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> str{"tars", "rats", "arts", "star"};

  // act
  auto res = solution.numSimilarGroups(str);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1

