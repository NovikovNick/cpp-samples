#ifndef LEETCODE_IS_SUBSEQUENCE_H
#define LEETCODE_IS_SUBSEQUENCE_H
#include <algorithm>
#include <format>
#include <iostream>
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
  bool isSubsequence(string s, string t) {
    if (s.empty()) return true;
    if (t.empty()) return false;

    int s_index = 0;
    for (auto ch : t) {
      if (ch == s[s_index]) ++s_index;
      if (s_index == s.size()) return true;
    }

    return s_index == s.size();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_IS_SUBSEQUENCE_H
