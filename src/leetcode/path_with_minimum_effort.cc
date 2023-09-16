#ifndef LEETCODE_PATH_WITH_MINIMUM_EFFORT_H
#define LEETCODE_PATH_WITH_MINIMUM_EFFORT_H
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
  int minimumEffortPath(vector<vector<int>>& heights) {
    debug("minimumEffortPath\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PATH_WITH_MINIMUM_EFFORT_H
