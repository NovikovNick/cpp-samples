#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/unique_number_of_occurrences.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr{1, 2, 2, 1, 1, 3};

  // act
  auto res = solution.uniqueOccurrences(arr);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
