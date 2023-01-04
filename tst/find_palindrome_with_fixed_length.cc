#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/find_palindrome_with_fixed_length.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> queries{1,  2,  3,  4,  5,  10, 11, 12,
                           13, 14, 15, 80, 81, 82, 83};
  int intLength = 4;
  std::vector<int> expected{1001, 1111, 1221, 1331, 1441, 1991, 2002, 2112,
                            2222, 2332, 2442, 8998, 9009, 9119, 9229};

  // act
  auto res = solution.kthPalindrome(queries, intLength);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> queries{2, 4, 10};
  int intLength = 1;
  std::vector<int> expected{2, 4, -1};

  // act
  auto res = solution.kthPalindrome(queries, intLength);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> queries{90};
  int intLength = 15;
  std::vector<long long> expected{100000898000001};

  // act
  auto res = solution.kthPalindrome(queries, intLength);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1
