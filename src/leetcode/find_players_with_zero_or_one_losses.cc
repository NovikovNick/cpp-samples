#ifndef LEETCODE_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H
#define LEETCODE_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H
#include <algorithm>
#include <format>
#include <iostream>
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
 public:
  std::vector<std::vector<int>> findWinners(vector<vector<int>>& matches) {
    std::vector<std::vector<int>> res(2);
    std::unordered_map<int, int> wins;
    std::unordered_map<int, int> loses;

    for (const auto& match : matches) {
      ++wins[match[0]];
      ++loses[match[1]];
    }
    for (const auto& [id, _] : wins) {
      if (loses.find(id) == loses.end()) {
        res[0].push_back(id);
      }
    }

    for (const auto& [id, count] : loses) {
      if (count == 1) {
        res[1].push_back(id);
      }
    }

    std::sort(res[0].begin(), res[0].end());
    std::sort(res[1].begin(), res[1].end());

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H
