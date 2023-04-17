#ifndef LEETCODE_KIDS_WITH_THE_GREATEST_NUMBER_OF_CANDIES_H
#define LEETCODE_KIDS_WITH_THE_GREATEST_NUMBER_OF_CANDIES_H
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
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n = candies.size();
    int max = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> res(n);
    for (int i = 0; i < n; ++i) res[i] = candies[i] + extraCandies >= max;
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_KIDS_WITH_THE_GREATEST_NUMBER_OF_CANDIES_H
