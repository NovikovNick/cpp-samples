#ifndef LEETCODE_ORDERLY_QUEUE_H
#define LEETCODE_ORDERLY_QUEUE_H
#include <algorithm>
#include <format>
#include <iostream>
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
  string orderlyQueue(string s, int k) {
    if (k > 1) {
      std::sort(s.begin(), s.end());
      return s;
    }

    std::string res = s;
    for (int i = 0; i < s.size(); ++i) {
      std::rotate(s.begin(), s.begin() + 1, s.end());
      res = std::min(res, s);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ORDERLY_QUEUE_H
