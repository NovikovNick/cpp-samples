#ifndef LEETCODE_FIND_THE_DUPLICATE_NUMBER_H
#define LEETCODE_FIND_THE_DUPLICATE_NUMBER_H
#include <algorithm>
#include <format>
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

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
  int findDuplicate(vector<int>& nums) {
    std::unordered_set<int> set;
    for (auto num : nums) {
      if (!set.insert(num).second) {
        return num;
      }
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_DUPLICATE_NUMBER_H
