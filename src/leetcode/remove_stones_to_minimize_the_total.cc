#ifndef LEETCODE_REMOVE_STONES_TO_MINIMIZE_THE_TOTAL_H
#define LEETCODE_REMOVE_STONES_TO_MINIMIZE_THE_TOTAL_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <queue>
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
  int minStoneSum(vector<int>& piles, int k) {
    std::priority_queue<int> heap(piles.begin(), piles.end());
    int sum = std::accumulate(piles.begin(), piles.end(), 0);
    int half;
    while (k > 0) {
      half = heap.top() / 2;
      sum -= half;
      half = heap.top() - half;
      heap.pop();
      heap.push(half);
      --k;
    }
    return sum;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REMOVE_STONES_TO_MINIMIZE_THE_TOTAL_H
