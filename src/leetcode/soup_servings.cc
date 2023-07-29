#ifndef LEETCODE_SOUP_SERVINGS_H
#define LEETCODE_SOUP_SERVINGS_H
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
  double soupServings(int n) {
    debug("soup serving\n");
    return 0.0;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SOUP_SERVINGS_H
