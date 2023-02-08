#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/top_k_frequent_words.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"i", "love", "leetcode",
                                 "i", "love", "coding"};
  int k = 2;

  // act
  auto res = solution.topKFrequent(words, k);

  // assert
  std::vector<std::string> expected{"i", "love"};
  for (int i = 0; i < k; ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
    debug("{} ", res[i]);
  }
  debug("\n");
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"the", "day", "is",    "sunny", "the",
                                 "the", "the", "sunny", "is",    "is"};
  int k = 4;

  // act
  auto res = solution.topKFrequent(words, k);

  // assert
  std::vector<std::string> expected{"the", "is", "sunny", "day"};
  for (int i = 0; i < k; ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
    debug("{} ", res[i]);
  }
  debug("\n");
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"aaa", "aa", "a"};
  int k = 3;

  // act
  auto res = solution.topKFrequent(words, k);

  // assert
  std::vector<std::string> expected{"a", "aa", "aaa"};
  for (int i = 0; i < k; ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
    debug("{} ", res[i]);
  }
  debug("\n");
}
#endif  // !CASE_3