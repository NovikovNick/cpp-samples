#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/concatenated_words.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"cat", "cats",        "catsdogcats",
                                 "dog", "dogcatsdog",  "hippopotamuses",
                                 "rat", "ratcatdogcat"};

  // act
  auto res = solution.findAllConcatenatedWordsInADict(words);

  // assert
  for (const auto& word : res) debug("{} ", word);
  debug("\n");
}
#endif  // !CASE_1
