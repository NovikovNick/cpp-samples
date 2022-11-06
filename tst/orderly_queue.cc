#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/orderly_queue.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "cba";
  int k = 1;
  // act
  auto res = solution.orderlyQueue(s, k);

  // assert
  BOOST_CHECK_EQUAL("acb", res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::string s = "baaca";
  int k = 3;
  // act
  auto res = solution.orderlyQueue(s, k);

  // assert
  BOOST_CHECK_EQUAL("aaabc", res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::string s = "kuh";
  int k = 1;
  // act
  auto res = solution.orderlyQueue(s, k);

  // assert
  BOOST_CHECK_EQUAL("hku", res);
}
#endif  // !CASE_3