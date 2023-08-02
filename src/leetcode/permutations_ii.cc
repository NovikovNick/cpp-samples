#ifndef LEETCODE_PERMUTATIONS_II_H
#define LEETCODE_PERMUTATIONS_II_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <set>

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
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::vector<std::vector<int>> res;

    std::sort(nums.begin(), nums.end());
    do {
      res.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    return res;
  }


  /*
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::set<std::vector<int>> set;
    backtracking(0, nums, set);
    return std::vector<std::vector<int>>(set.begin(), set.end());
  }

  void backtracking(const int begin,
                    std::vector<int>& nums,
                    std::set<std::vector<int>>& set) {
    if (begin == nums.size()) {
      set.insert(nums);
      return;
    }
    for (int i = begin; i < nums.size(); ++i) {
      std::swap(nums[begin], nums[i]);
      backtracking(begin + 1, nums, set);
      std::swap(nums[begin], nums[i]);
    }
  }
  */
};
}  // namespace leetcode
#endif  // LEETCODE_PERMUTATIONS_II_H
