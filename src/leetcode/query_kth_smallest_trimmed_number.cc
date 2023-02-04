#ifndef LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
#define LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
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
  struct Item {
    std::string str;
    int index;
  };

  void radixSort(std::vector<Item>& nums, const int radix_count) {
    int n = nums[0].str.size();
    for (int i = 1; i <= radix_count; ++i) {
      // todo: countingSort
      std::stable_sort(nums.begin(), nums.end(),
                       [radix = n - i](const Item& lhs, const Item& rhs) {
                         return lhs.str[radix] < rhs.str[radix];
                       });
    }
  }

 public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                     vector<vector<int>>& queries) {
    std::vector<Item> items(nums.size());
    for (int i = 0; i < nums.size(); ++i) items[i] = {nums[i], i};

    for (const auto& it : items) debug("{}({}) ", it.str, it.index);
    debug("\n");
    
    std::vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      radixSort(items, queries[i][1]);
      for (const auto& it : items) debug("{}({}) ", it.str, it.index);
      debug("\n");

      res[i] = items[queries[i][0] - 1].index;
      std::sort(items.begin(), items.end(),
                [](const Item& lhs, const Item& rhs) {
                  return lhs.index < rhs.index;
                });
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H
