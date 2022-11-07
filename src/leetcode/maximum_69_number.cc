#ifndef LEETCODE_MAXIMUM_69_NUMBER_H
#define LEETCODE_MAXIMUM_69_NUMBER_H
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
  int maximum69Number(int num) {
    std::string str = std::to_string(num);
    for (auto i = 0; const auto& ch : str) {
      if (ch == '6') {
        str[i] = '9';
        return std::stoi(str);
      }
      ++i;
    }
    return num;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_69_NUMBER_H
