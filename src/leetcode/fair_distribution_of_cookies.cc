#ifndef LEETCODE_FAIR_DISTRIBUTION_OF_COOKIES_H
#define LEETCODE_FAIR_DISTRIBUTION_OF_COOKIES_H
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
  int distributeCookies(vector<int>& cookies, int k) {
    debug("Need to check all permutation of ");
    for (const auto cookie : cookies) debug("{} ", cookie);
    debug(" for {} stacks\n", k);

    std::sort(cookies.begin(), cookies.end());

    int count = 0;
    while (std::next_permutation(cookies.begin(), cookies.end())) {
     /* for (const auto cookie : cookies) debug("{} ", cookie);
      debug("\n");*/
      ++count;
    }

    return count;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FAIR_DISTRIBUTION_OF_COOKIES_H
