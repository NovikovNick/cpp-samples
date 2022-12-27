#ifndef LEETCODE_SUM_GAME_H
#define LEETCODE_SUM_GAME_H
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
  bool sumGame(string num) {
    int n = num.size();
    int half = n / 2;

    int lft_sum = 0, lft_mrk = 0;
    for (int i = 0; i < half; ++i) {
      if (num[i] == '?') {
        ++lft_mrk;
      } else {
        lft_sum += (num[i] - '0');
      }
    }

    int rht_sum = 0, rht_mrk = 0;
    for (int i = half; i < n; ++i) {
      if (num[i] == '?') {
        ++rht_mrk;
      } else {
        rht_sum += (num[i] - '0');
      }
    }

    return !((lft_mrk + rht_mrk) % 2 == 0 &&
             (lft_sum + odd(lft_mrk) * 9) == (rht_sum + odd(rht_mrk) * 9) &&
             (lft_sum + even(lft_mrk) * 9) == (rht_sum + even(rht_mrk) * 9));
  }

  int even(const int i) { return i / 2 + i % 2; }
  int odd(const int i) { return i / 2; }
};
}  // namespace leetcode
#endif  // LEETCODE_SUM_GAME_H
