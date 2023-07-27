#ifndef LEETCODE_MAXIMUM_RUNNING_TIME_OF_N_COMPUTERS_H
#define LEETCODE_MAXIMUM_RUNNING_TIME_OF_N_COMPUTERS_H
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
  long long maxRunTime(int n, vector<int>& batteries) {
    debug("maxRunTime\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_RUNNING_TIME_OF_N_COMPUTERS_H
