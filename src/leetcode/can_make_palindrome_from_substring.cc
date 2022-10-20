#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H
#define LEETCODE_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H

namespace leetcode {

using namespace std;

template <typename T, typename U>
bool checkPairs(T start, T last, U startAlpabet, U endAlpabet, int k) {
  for (auto l = start; l != last; ++l) {
    (*(startAlpabet + (static_cast<int>(*l) - static_cast<int>('a'))))++;
  }

  k += std::distance(start, last) % 2 == 2 ? 0 : 1;

  for (auto l = startAlpabet; l != endAlpabet; ++l) {
    if (*l % 2 != 0) {
      if (--k < 0) {
        std::fill(startAlpabet, endAlpabet, 0);
        return false;
      }
    }
  }
  std::fill(startAlpabet, endAlpabet, 0);
  return true;
}

class Solution {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    std::vector<bool> res(queries.size(), true);
    std::vector<int> alphabet(26, 0);

    for (int i = 0; auto q : queries) {
      res[i++] = checkPairs(
          s.begin() + q[0], 
          s.begin() + q[1] + 1,
          alphabet.begin(), alphabet.end(), q[2] * 2);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H
