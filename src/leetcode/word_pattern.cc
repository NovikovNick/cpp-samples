#ifndef LEETCODE_WORD_PATTERN_H
#define LEETCODE_WORD_PATTERN_H
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

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    std::vector<std::string> hash(26, "");

    // 1. 
    int n = s.size(), m = pattern.size();
    int i = 0, j = 0;
    std::string word;
    for (int key; i < n && j < m;) {
      while (s[i] != ' ' && i < n) word += s[i++];

      key = pattern[j] - 'a';
      if (hash[key] == "") {
        hash[key] = word;
      } else if (hash[key] != word) {
        return false;
      }

      word = "";
      ++i;
      ++j;
    }
    if (i < n || j < m) return false;

    // 2.
    std::unordered_set<char> uniquePatters(pattern.begin(), pattern.end());
    std::unordered_set<std::string> uniqueWords(hash.begin(), hash.end());
    uniqueWords.insert("");

    return (uniqueWords.size() - 1) == uniquePatters.size();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_WORD_PATTERN_H
