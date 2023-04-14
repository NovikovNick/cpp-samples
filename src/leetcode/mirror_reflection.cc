#ifndef LEETCODE_MIRROR_REFLECTION_H
#define LEETCODE_MIRROR_REFLECTION_H
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
  int mirrorReflection(int p, int q) {
    if (q == p) return 1;
    if (p % q == 0) return p & 1 ? 1 : 2;
    return p & 1 ? q & 1 : 2;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MIRROR_REFLECTION_H
