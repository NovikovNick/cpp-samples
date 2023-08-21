#ifndef LEETCODE_REPEATED_SUBSTRING_PATTERN_H
#define LEETCODE_REPEATED_SUBSTRING_PATTERN_H
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
  bool repeatedSubstringPattern(string s) {
    int substr_begin = 0;
    int substr_end = 0;
    int base_end = 0;
    for (; substr_end < s.size(); ++substr_end) {
      debug("{}[{}, {}] ? {}[{}, {}]\n",
            s.substr(0, base_end),  //
            0,
            base_end,
            s.substr(substr_begin, substr_end),
            substr_begin,
            substr_end);
      if (s.substr(0, base_end) == s.substr(substr_begin, substr_end)) {
      } else {
        base_end = substr_end;
        substr_begin = substr_end;
      }
    }
    return s.substr(0, base_end) == s.substr(substr_begin, substr_end);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REPEATED_SUBSTRING_PATTERN_H
