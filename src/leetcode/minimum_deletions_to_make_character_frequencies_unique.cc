#ifndef LEETCODE_MINIMUM_DELETIONS_TO_MAKE_CHARACTER_FREQUENCIES_UNIQUE_H
#define LEETCODE_MINIMUM_DELETIONS_TO_MAKE_CHARACTER_FREQUENCIES_UNIQUE_H
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
  int minDeletions(std::string s) {
    std::array<int, 128> counts = {0};
    for (auto ch : s) ++counts[ch];

    std::sort(counts.begin(), counts.end());

    int deletions = 0;
    for (int i = 0; i < 128; ++i) {
      if (counts[i] == 0) continue;

      for (int j = i - 1, next = counts[i]; next == counts[j] && counts[j] != 0;
           --j) {
        next = --counts[j];
        ++deletions;
      }
    }

    std::copy_if(counts.begin(),
                 counts.end(),
                 std::ostream_iterator<int>(std::cout, "\n"),
                 [](const auto& val) { return val != 0; });

    return deletions;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_DELETIONS_TO_MAKE_CHARACTER_FREQUENCIES_UNIQUE_H
