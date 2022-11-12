#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/implement_trie_prefix_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Trie trie;
  std::vector<int> res(4);
  // act

  trie.insert("apple");
  res[0] = trie.search("apple");    // return True
  res[1] = trie.search("app");      // return False
  res[2] = trie.startsWith("app");  // return True
  trie.insert("app");
  res[3] = trie.search("app");  // return True

  // assert
  BOOST_CHECK_EQUAL(true, res[0]);
  BOOST_CHECK_EQUAL(false, res[1]);
  BOOST_CHECK_EQUAL(true, res[2]);
  BOOST_CHECK_EQUAL(true, res[3]);
}
#endif  // !CASE_1
