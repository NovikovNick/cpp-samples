#ifndef LEETCODE_PARALLEL_COURSES_III_H
#define LEETCODE_PARALLEL_COURSES_III_H
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
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    debug("another hard problem\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PARALLEL_COURSES_III_H
