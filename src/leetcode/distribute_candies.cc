#ifndef LEETCODE_DISTRIBUTE_CANDIES_H
#define LEETCODE_DISTRIBUTE_CANDIES_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int distributeCandies(vector<int>& candyType) {
    std::sort(candyType.begin(), candyType.end());
    auto it = std::unique(candyType.begin(), candyType.end());
    return std::min<int>(candyType.size() / 2,
                         std::distance(candyType.begin(), it));
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DISTRIBUTE_CANDIES_H
