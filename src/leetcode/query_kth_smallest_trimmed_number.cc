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
    auto n = nums[0].size();

    std::vector<int> res(queries.size());
    for (uint8_t i = 0; i < queries.size(); ++i) {
      auto k = queries[i][0];
      auto radix = n - queries[i][1];

      std::priority_queue<std::pair<std::string, int>> max_heap;
      for (int j = 0; j < nums.size(); ++j) {
        max_heap.push({nums[j].substr(radix), j});
        if (max_heap.size() > k) max_heap.pop();
      };
      res[i] = max_heap.top().second;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
