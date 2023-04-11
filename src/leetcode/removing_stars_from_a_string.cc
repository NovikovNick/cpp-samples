#ifndef LEETCODE_REMOVING_STARS_FROM_A_STRING_H
#define LEETCODE_REMOVING_STARS_FROM_A_STRING_H
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
  string removeStars(string s) {
    std::string res;
    for (const auto letter : s) {
      if (letter == '*') {
        res.pop_back();
      } else {
        res.push_back(letter);
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REMOVING_STARS_FROM_A_STRING_H
