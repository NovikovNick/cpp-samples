#ifndef LEETCODE_FIND_THE_TOWN_JUDGE_H
#define LEETCODE_FIND_THE_TOWN_JUDGE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
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
  int findJudge(int n, vector<vector<int>>& trust) {
    std::vector<std::unordered_set<int>> trusted(n + 1);
    for (const auto& it : trust) trusted[it[0]].insert(it[1]);

    int judge = -1;

    // The town judge trusts nobody.
    for (int i = 1; i < n + 1; ++i) {
      if (trusted[i].empty()) {
        if (judge == -1) {
          judge = i;
        } else {
          return -1;
        }
      }
    }
    if (judge == -1) return -1;

    // Everybody (except for the town judge) trusts the town judge.
    for (int i = 1; i < n + 1; ++i) {
      if (judge == i) continue;
      if (!trusted[i].contains(judge)) return -1;
    }
    return judge;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_TOWN_JUDGE_H
