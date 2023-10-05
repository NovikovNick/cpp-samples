#ifndef LEETCODE_MAJORITY_ELEMENT_II_H
#define LEETCODE_MAJORITY_ELEMENT_II_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <unordered_map>

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
  vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    std::unordered_map<int, int> map;
    for (auto num : nums) ++map[num];

    std::vector<int> res;
    for (auto [num, count] : map) {
      if (count > n / 3) res.push_back(num);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAJORITY_ELEMENT_II_H
