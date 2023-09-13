#ifndef LEETCODE_CANDY_H
#define LEETCODE_CANDY_H
#include <algorithm>
#include <array>
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
  int candy(vector<int>& ratings) {
    std::copy(ratings.begin(),  //
              ratings.end(),    //
              std::ostream_iterator<int>(std::cout, "\n"));

    int n = ratings.size();
    if (n == 1) return 1;

    std::array<int, 20001> candies{1};
    int total_candies = n;
    for (int i = 1; i < n; ++i) {
      candies[i] = 1;
      auto lhs = i - 1;
      auto rhs = i;

      if (ratings[lhs] == ratings[rhs]) continue;
      if (ratings[lhs] < ratings[rhs]) {
        total_candies += candies[lhs];
        candies[rhs] += candies[lhs];
      } else {
        for (; rhs > 0; --lhs, --rhs) {
          if (ratings[lhs] <= ratings[rhs]) break;
          if ((ratings[lhs] > ratings[rhs]) && (candies[lhs] <= candies[rhs])) {
            total_candies += candies[rhs] - candies[lhs] + 1;
            candies[lhs] += candies[rhs] - candies[lhs] + 1;
          };
        }
      }
    }
    return total_candies;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CANDY_H
