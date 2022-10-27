#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/stickers_to_spell_word.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> stickers = {"with", "example", "science"};
  std::string target = "thehat";

  // act
  auto res = solution.minStickers(stickers, target);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}

//BOOST_AUTO_TEST_CASE(case2) {
//  // arrange
//  leetcode::Solution solution;
//  std::vector<std::string> stickers = {"notice", "possible"};
//  std::string target = "basicbasic";
//
//  // act
//  auto res = solution.minStickers(stickers, target);
//
//  // assert
//  BOOST_CHECK_EQUAL(-1, res);
//}
//
//BOOST_AUTO_TEST_CASE(case3) {
//  // arrange
//  leetcode::Solution solution;
//  std::vector<std::string> stickers = {"these", "guess", "about", "garden",
//                                       "him"};
//  std::string target = "atomher";
//
//  // act
//  auto res = solution.minStickers(stickers, target);
//
//  // assert
//  BOOST_CHECK_EQUAL(3, res);
//}
//
//BOOST_AUTO_TEST_CASE(case4) {
//  // arrange
//  leetcode::Solution solution;
//  std::vector<std::string> stickers = {"crowd", "level", "after", "equate",
//                                       "at",    "spend", "out"};
//  std::string target = "catread";
//
//  // act
//  auto res = solution.minStickers(stickers, target);
//
//  // assert
//  BOOST_CHECK_EQUAL(3, res);
//}
//
//BOOST_AUTO_TEST_CASE(case5) {
//  // arrange
//  leetcode::Solution solution;
//  std::vector<std::string> stickers = {
//      "final",  "figure", "danger", "fish",    "some",     "product", "son",
//      "seed",   "crease", "rail",   "even",    "death",    "end",     "sit",
//      "live",   "behind", "start",  "enough",  "much",     "between", "test",
//      "is",     "happy",  "we",     "north",   "complete", "month",   "reach",
//      "excite", "stay",   "job",    "fell",    "letter",   "noun",    "seat",
//      "exact",  "than",   "ago",    "protect", "kept",     "this",    "plain",
//      "flow",   "face",   "bird",   "sand",    "rock",     "roll",    "root",
//      "fact"};
//  std::string target = "lakeblue";
//
//  // act
//  auto res = solution.minStickers(stickers, target);
//
//  // assert
//  BOOST_CHECK_EQUAL(5, res);
//}
 