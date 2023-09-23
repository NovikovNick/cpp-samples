#ifndef LEETCODE_LONGEST_STRING_CHAIN_H
#define LEETCODE_LONGEST_STRING_CHAIN_H
#include <algorithm>
#include <array>
#include <format>
#include <iostream>
#include <list>
#include <unordered_map>
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
  std::array<std::list<std::string_view>, 18> groupedBySize;
  std::unordered_map<std::string_view, int> dp;

 public:
  int longestStrChain(vector<string>& words) {
    int n = words.size();

    auto eq = equal(words[0], words[1]);

    for (auto& word : words) {
      groupedBySize[word.size()].emplace_back(word);
      dp[word] = 0;
    }

    for (int size = 0; size < 18; ++size) {
      for (auto word : groupedBySize[size]) {
        dp[word] = dp[word] == 0      //
                       ? count(word)  //
                       : 0;
      }
    }

    int res = 0;
    for (auto [_, count] : dp) {
        res = std::max(res, count);
    }
    return res;
  }

  int count(std::string_view str) {
    int res = 0;
    for (auto word : groupedBySize[str.size() + 1]) {
      if (equal(str, word)) {
        dp[word] = dp[word] == 0      //
                       ? count(word)  //
                       : 0;
        res = std::max(res, dp[word]);
      }
    }
    return res + 1;
  }

  bool equal(std::string_view search, std::string_view target) {
    int j = 0;
    for (int i = 0; i < search.size(); ++i, ++j) {
      if (search[i] != target[j]) {
        --i;
        if (j == (i + 2)) return false;
      }
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_STRING_CHAIN_H
