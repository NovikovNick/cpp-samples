#ifndef LEETCODE_DETERMINE_IF_TWO_STRINGS_ARE_CLOSE_H
#define LEETCODE_DETERMINE_IF_TWO_STRINGS_ARE_CLOSE_H
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
  bool closeStrings(string word1, string word2) {
    int n = word1.size();
    if (n != word2.size()) return false;

    std::vector<int> freq1(26);
    std::vector<int> freq2(26);

    for (int i = 0; i < n; ++i) {
      ++freq1[word1[i] - 'a'];
      ++freq2[word2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
      if (static_cast<bool>(freq1[i]) != static_cast<bool>(freq2[i]))
        return false;

    std::sort(freq1.begin(), freq1.end(), std::greater<int>{});
    std::sort(freq2.begin(), freq2.end(), std::greater<int>{});

    for (int i = 0, sz = std::min(n, 26); i < sz; ++i)
      if (freq1[i] != freq2[i]) return false;

    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DETERMINE_IF_TWO_STRINGS_ARE_CLOSE_H
