#ifndef LEETCODE_FIND_IN_MOUNTAIN_ARRAY_H
#define LEETCODE_FIND_IN_MOUNTAIN_ARRAY_H
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

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
 public:
  int get(int index) { return 0; };
  int length() { return 0; };
};

class Solution {
 public:
  int findInMountainArray(int target, MountainArray& mountainArr) {
    debug("and another hard problem!\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_IN_MOUNTAIN_ARRAY_H
