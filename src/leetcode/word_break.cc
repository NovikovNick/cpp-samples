#ifndef LEETCODE_WORD_BREAK_H
#define LEETCODE_WORD_BREAK_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct TrieNode {
  std::vector<TrieNode*> data;
  bool is_word;
  TrieNode() : data(std::vector<TrieNode*>(0)), is_word(false) {}
};

class Trie {
  TrieNode* root;
  const std::string& str;

 public:
  Trie(const std::string& s) : root(new TrieNode()), str(s){};

  void add(const std::string& word) {
    auto curr = root;
    for (const auto letter : word) {
      curr->data[letter - 'a'] = new TrieNode();
    }
    curr->is_word = true;
  }

  bool contains(int begin, const int end) const {
    auto curr = root;
    for (; begin < end; ++begin) {
      curr = curr->data[str[begin] - 'a'];
      if (!curr) return false;
    }
    return curr->is_word;
  }
};

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return false;
  }
};

//class Solution {
//  std::unordered_set<std::string> dictionary;
//
// public:
//  bool wordBreak(string s, vector<string>& wordDict) {
//    for (const auto& word : wordDict) dictionary.insert(word);
//    return bruteforce(0, "", s);
//  }
//
//  bool bruteforce(const int i, std::string curr, const std::string& s) {
//    if (i == s.size()) {
//      return curr.empty();
//    }
//
//    curr.push_back(s[i]);
//    if (contains(curr) && bruteforce(i + 1, "", s)) {
//      return true;
//    }
//
//    return bruteforce(i + 1, curr, s);
//  }
//
//  inline bool contains(const std::string& s) {
//    return dictionary.find(s) != dictionary.end();
//  }
//};
}  // namespace leetcode
#endif  // LEETCODE_WORD_BREAK_H
