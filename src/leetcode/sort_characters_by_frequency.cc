#ifndef LEETCODE_SORT_CHARACTERS_BY_FREQUENCY_H
#define LEETCODE_SORT_CHARACTERS_BY_FREQUENCY_H
#include <algorithm>
#include <format>
#include <iostream>
#include <set>
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
  string frequencySort(string s) {
    std::vector<int> freq(static_cast<int>('z') - static_cast<int>('0') + 1);
    for (const auto& ch : s) ++freq[ch - '0'];

    auto comp = [freq = freq](const char& a, const char& b) {
      if (freq[a - '0'] > freq[b - '0']) return true;
      if (freq[a - '0'] == freq[b - '0']) return a > b;
      return false;
    };
    std::set<char, decltype(comp)> set(comp);
    for (int i = 0, sz = freq.size(); i < sz; ++i) {
      if (freq[i] > 0) set.emplace(static_cast<char>(i + '0'));
    }

    std::string res;
    for (const auto& ch : set) res += std::string(freq[ch - '0'], ch);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SORT_CHARACTERS_BY_FREQUENCY_H
