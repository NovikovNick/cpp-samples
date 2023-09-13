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
    int n = ratings.size();
    int total_candy = n;
    std::vector<int> candies(n, 1);
    total_candy += traverse(ratings.begin(), candies.begin(), ratings.end());
    total_candy += traverse(ratings.rbegin(), candies.rbegin(), ratings.rend());
    return total_candy;
  }

  // solution without heap allocation
  /*int candy(vector<int>& ratings) {
    int n = ratings.size();
    int total_candy = n;
    if (n == 1) return total_candy;

    std::array<int, 20000> candies;
    std::fill(candies.begin(), candies.begin() + n, 1);

    total_candy += traverse(ratings.begin(), candies.begin(), ratings.end());
    total_candy += traverse(ratings.rbegin(),
                            std::reverse_iterator(candies.begin() + n),
                            ratings.rend());
    return total_candy;
  }*/
  
  // brutforce solution
  // int candy(vector<int>& ratings) {
  //   int n = ratings.size();
  //   if (n == 1) return 1;
  //   std::array<int, 20001> candies{1};
  //   int total_candies = n;
  //   for (int i = 1; i < n; ++i) {
  //     candies[i] = 1;
  //     auto lhs = i - 1;
  //     auto rhs = i;
  //     if (ratings[lhs] == ratings[rhs]) continue;
  //     if (ratings[lhs] < ratings[rhs]) {
  //       total_candies += candies[lhs];
  //       candies[rhs] += candies[lhs];
  //     } else {
  //       for (; rhs > 0; --lhs, --rhs) {
  //         if (ratings[lhs] <= ratings[rhs]) break;
  //         if ((ratings[lhs] > ratings[rhs]) && (candies[lhs] <= candies[rhs])) {
  //           total_candies += candies[rhs] - candies[lhs] + 1;
  //           candies[lhs] += candies[rhs] - candies[lhs] + 1;
  //         };
  //       }
  //     }
  //   }
  //   return total_candies;
  // }

 private:
  int traverse(auto rating_begin, auto candies_begin, auto sentinel) {
    auto rating_lhs = rating_begin;
    auto rating_rhs = std::next(rating_begin);

    auto candy_lhs = candies_begin;
    auto candy_rhs = std::next(candies_begin);
    int total = 0;
    while (rating_rhs != sentinel) {
      if (*rating_lhs < *rating_rhs && *candy_lhs >= *candy_rhs) {
        total += *candy_lhs - *candy_rhs + 1;
        *candy_rhs = *candy_lhs + 1;
      }

      ++rating_lhs;
      ++rating_rhs;
      ++candy_lhs;
      ++candy_rhs;
    }
    return total;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CANDY_H
