#ifndef LEETCODE_FIND_THE_DIFFERENCE_H
#define LEETCODE_FIND_THE_DIFFERENCE_H
#include <algorithm>
#include <array>
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
  char findTheDifference(string s, string t) {
    std::array<int, 128> counts;
    std::fill(counts.begin(), counts.end(), 0);
    for (const auto ch : t) ++counts[ch];

    for (const auto ch : s) --counts[ch];

    for (int i = 0; i < 128; ++i) {
      if (counts[i]) return static_cast<char>(i);
    }
    return '0';
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_DIFFERENCE_H
