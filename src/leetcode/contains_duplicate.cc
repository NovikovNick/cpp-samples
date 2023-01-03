#ifndef LEETCODE_CONTAINS_DUPLICATE_H
#define LEETCODE_CONTAINS_DUPLICATE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
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
  bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> set;
    for (const auto& num : nums) if (set.insert(num).second == false) return false;
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONTAINS_DUPLICATE_H
