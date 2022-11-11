#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/remove_duplicates_from_sorted_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 1, 2};

  auto res = solution.removeDuplicates(nums);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  auto res = solution.removeDuplicates(nums);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_2