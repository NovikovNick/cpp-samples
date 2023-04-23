#ifndef LEETCODE_RESTORE_THE_ARRAY_H
#define LEETCODE_RESTORE_THE_ARRAY_H
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
  int numberOfArrays(string s, int k) {
    debug("what is the number of numbers can be in the string {}\n", s);
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RESTORE_THE_ARRAY_H
