#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/design_add_and_search_words_data_structure.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::WordDictionary dictionary;

  // act
  dictionary.addWord("asdf");
  dictionary.addWord("dfg");

  // assert
  BOOST_CHECK(dictionary.search("a.df"));
  BOOST_CHECK(dictionary.search("asdf"));
  BOOST_CHECK(dictionary.search("a.d."));
  BOOST_CHECK(dictionary.search("..."));
  BOOST_CHECK(!dictionary.search("as..."));
  BOOST_CHECK(!dictionary.search("agdg"));
  BOOST_CHECK(!dictionary.search("as"));
}
#endif  // !CASE_1
