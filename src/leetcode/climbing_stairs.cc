#ifndef LEETCODE_CLIMBING_STAIRS_H
#define LEETCODE_CLIMBING_STAIRS_H
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

  int climbStairs(int n) { 
    return fib(n);
  }

  int fib(const int n) {
    if (n <= 3) return n;

    int fst = 3, snd = 5;

    for (int i = 4; i < n; ++i) {
      std::swap(fst, snd);
      snd += fst;
    }
    return snd;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CLIMBING_STAIRS_H
