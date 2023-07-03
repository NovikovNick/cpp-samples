#ifndef LEETCODE_BUDDY_STRINGS_H
#define LEETCODE_BUDDY_STRINGS_H
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
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;
    int n = s.size();
    std::vector<int> counts(128);
    std::vector<std::pair<char, char>> diff;
    for (int i = 0; i < n; ++i) {
      if (s[i] != goal[i]) diff.push_back({s[i], goal[i]});
      ++counts[static_cast<int>(s[i])];
    }

    if (diff.size() == 2) {
      const auto [a1, a2] = diff[0];
      const auto [b1, b2] = diff[1];
      return a1 == b2 && a2 == b1;
    } else if (diff.empty()) {
      for (const auto count : counts) {
        if (count > 1) return true;
      }
    }
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BUDDY_STRINGS_H
