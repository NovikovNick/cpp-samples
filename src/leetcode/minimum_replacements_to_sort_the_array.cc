#ifndef LEETCODE_MINIMUM_REPLACEMENTS_TO_SORT_THE_ARRAY_H
#define LEETCODE_MINIMUM_REPLACEMENTS_TO_SORT_THE_ARRAY_H
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
  long long minimumReplacement(vector<int>& nums) {
    debug("minimumReplacement\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_REPLACEMENTS_TO_SORT_THE_ARRAY_H
