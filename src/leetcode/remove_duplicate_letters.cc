#ifndef LEETCODE_REMOVE_DUPLICATE_LETTERS_H
#define LEETCODE_REMOVE_DUPLICATE_LETTERS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <array>
#include <map>

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
 public:
  string removeDuplicateLetters(string s) {
    std::array<int, 128> indexesByChar;
    std::fill(indexesByChar.begin(), indexesByChar.end(), -1);
    for (int i = 0; i < s.size(); ++i) {
      indexesByChar[s[i]] = i;
    }

    std::map<int, char> dict;
    for (int i = 0; i < indexesByChar.size(); ++i) {
      if (indexesByChar[i] >= 0) {
        dict[indexesByChar[i]] = static_cast<char>(i);
      }
    }
    std::string res;
    for (auto [_, ch] : dict) {
      res += ch;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REMOVE_DUPLICATE_LETTERS_H
