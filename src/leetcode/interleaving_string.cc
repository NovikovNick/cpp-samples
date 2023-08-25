#ifndef LEETCODE_INTERLEAVING_STRING_H
#define LEETCODE_INTERLEAVING_STRING_H
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
  bool isInterleave(string s1, string s2, string s3) {
    debug("is {} + {} = {} ? \n", s1, s2, s3);
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INTERLEAVING_STRING_H
