#ifndef LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
#define LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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
  vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                     vector<vector<int>>& queries) {
    int n = nums[0].size();
    std::vector<uint64_t> input(nums.size());
    for (int i = 0; i < nums.size(); ++i) input[i] = std::stoi(nums[i]);

    std::vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int radix = std::pow(10, queries[i][1]);
      auto cmp = [&nums = input, radix = radix](const int& lhs,
                                                const int& rhs) {
        int lhs_trimmed = nums[lhs] - (nums[lhs] / radix) * radix;
        int rhs_trimmed = nums[rhs] - (nums[rhs] / radix) * radix;
        if (lhs_trimmed < rhs_trimmed) return true;
        if (lhs_trimmed == rhs_trimmed) return lhs < rhs;
        return false;
      };
      std::priority_queue<int, std::vector<int>, decltype(cmp)> max_heap(cmp);

      for (int j = 0; j < nums.size(); ++j) {
        max_heap.push(j);
        if (max_heap.size() > queries[i][0]) max_heap.pop();
      };

      res[i] = max_heap.top();
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
