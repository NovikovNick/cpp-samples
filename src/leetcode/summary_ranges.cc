#ifndef LEETCODE_SUMMARY_RANGES_H
#define LEETCODE_SUMMARY_RANGES_H
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
  vector<string> summaryRanges(vector<int>& nums) {
    std::vector<std::string> res;
    if (nums.empty()) return res;

    int begin = nums[0];
    int end = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (end + 1 != nums[i]) {
        if (begin == end) {
          res.push_back(std::to_string(begin));
        } else {
          res.push_back(std::to_string(begin) + "->" + std::to_string(end));
        }
        begin = nums[i];
      }
      end = nums[i];
    }

    if (begin == end) {
      res.push_back(std::to_string(begin));
    } else {
      res.push_back(std::to_string(begin) + "->" + std::to_string(end));
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUMMARY_RANGES_H
