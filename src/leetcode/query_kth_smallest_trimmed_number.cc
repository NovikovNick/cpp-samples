#ifndef LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
#define LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
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
  inline int toInt(const std::string& str, const int radix) {
    return str[str.size() - radix] - '0';
  }

 public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                     vector<vector<int>>& queries) {
    auto m = nums.size(), n = nums[0].size();
    std::vector<std::vector<int>> sorted_by_radix(n + 1,
                                                  std::vector<int>(m, 0));

    std::iota(sorted_by_radix[0].begin(), sorted_by_radix[0].end(), 0);

    // radix sort 
    std::vector<int> counts(10);
    for (int radix = 1; radix < n + 1; ++radix) {

      // counting sort for specific radix
      std::fill(counts.begin(), counts.end(), 0);
      for (int i = 0; i < m; ++i) ++counts[toInt(nums[i], radix)];

      int index = 0;
      for (auto& count : counts) {
        std::swap(count, index);
        index += count;
      }

      for (int i = 0; i < m; ++i) {
        auto prev_index = sorted_by_radix[radix - 1][i];
        auto num = toInt(nums[prev_index], radix);
        sorted_by_radix[radix][counts[num]] = prev_index;
        ++counts[num];
      }
    }

    std::vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      auto k = queries[i][0];
      auto radix = queries[i][1];
      res[i] = sorted_by_radix[radix][k - 1];
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
