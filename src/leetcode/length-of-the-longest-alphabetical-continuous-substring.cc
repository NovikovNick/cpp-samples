#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H
#define LEETCODE_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H

namespace leetcode {

using namespace std;

template <typename Iter, typename BinaryPredicate>
std::pair<Iter, int> is_valid_until(Iter start, Iter end,
                                    BinaryPredicate predicate) {
  auto fst = start;
  auto snd = std::next(start);
  int distance = 1;
  while (snd != end) {
    if (!predicate(*fst, *snd)) {
      return std::make_pair(snd, distance);
    }
    ++fst;
    ++snd;
    ++distance;
  }
  return std::make_pair(end, distance);
};

class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int res = 1;
    auto cur = s.begin();
    auto end = s.end();
    auto continuousAlphabetOrder = [](const char& a, const char& b) -> bool {
      return (static_cast<int>(b) - static_cast<int>(a)) == 1;
    };
    while (cur != end) {
      auto [it, distance] = is_valid_until(cur, end, continuousAlphabetOrder);
      res = std::max(res, distance);
      if (res == 26) {
        return res;
      }
      cur = it;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H
