#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/longest_string_chain.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{
      "wnyxmflkf", "xefx",     "usqhb",      "ttmdvv",     "hagmmn",  "tmvv",
      "pttmdvv",   "nmzlhlpr", "ymfk",       "uhpaglmmnn", "zckgh",   "hgmmn",
      "isqxrk",    "isqrk",    "nmzlhpr",    "uysyqhxb",   "haglmmn", "xfx",
      "mm",        "wymfkf",   "tmdvv",      "uhaglmmn",   "mf",      "uhaglmmnn",
      "mfk",       "wnymfkf",  "powttkmdvv", "kwnyxmflkf", "xx",      "rnqbhxsj",
      "uysqhb",    "pttkmdvv", "hmmn",       "iq",         "m",       "ymfkf",
      "zckgdh",    "zckh",     "hmm",        "xuefx",      "mv",      "iqrk",
      "tmv",       "iqk",      "wnyxmfkf",   "uysyqhb",    "v",       "m",
      "pwttkmdvv", "rnqbhsj"};

  // act
  auto res = solution.longestStrChain(words);

  // assert
  BOOST_CHECK_EQUAL(10, res);
}
#endif  // !CASE_1
