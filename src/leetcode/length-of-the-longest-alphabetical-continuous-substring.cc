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
Iter is_valid_until(Iter start, Iter end, BinaryPredicate predicate) {
  auto fst = start;
  auto snd = std::next(start);
  while (snd != end) {
    if (!predicate(*fst, *snd)) {
      return snd;
    }
    ++fst;
    ++snd;
  }
  return end;
};

struct Comparator {
 private:
  std::string alfabet_ = "abcdefghijklmnopqrstuvwxyz";

 public:
  bool operator()(const char& a, const char& b) const {
    int nextElemIndex = static_cast<int>(a) - 96;
    return nextElemIndex < 26 && alfabet_[nextElemIndex] == b;
  }
};

class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int res = 1;
    auto prev = s.begin();
    auto cur = s.begin();
    Comparator comparator;
    while (cur != s.end()) {
      cur = is_valid_until(cur, s.end(), comparator);
      res = std::max(res, static_cast<int>(std::distance(prev, cur)));
      prev = cur;
      if (res == 26) {
        return res;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LENGTH_OF_THE_LONGEST_ALPHABETICAL_CONTINUOUS_SUBSTRING_H
