#ifndef LEETCODE_SORT_ITEMS_BY_GROUPS_RESPECTING_DEPENDENCIES_H
#define LEETCODE_SORT_ITEMS_BY_GROUPS_RESPECTING_DEPENDENCIES_H
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
  vector<int> sortItems(int n,
                        int m,
                        vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    debug("sort items\n");

    return {};
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SORT_ITEMS_BY_GROUPS_RESPECTING_DEPENDENCIES_H
