#ifndef LEETCODE_COUNT_ALL_POSSIBLE_ROUTES_H
#define LEETCODE_COUNT_ALL_POSSIBLE_ROUTES_H
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
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    debug("Need to count route\n");
    return 4;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_ALL_POSSIBLE_ROUTES_H
