#ifndef LEETCODE_SMALLEST_SUFFICIENT_TEAM_H
#define LEETCODE_SMALLEST_SUFFICIENT_TEAM_H
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
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    debug("Required skills: ");
    for (const auto& skill : req_skills) debug("{}, ", skill);
    debug("\n");

    for (int i = 0; i < people.size(); ++i) {
      debug("{}: ", i);
      for (const auto& skill : people[i]) {
        debug("{} ", skill);
      }
      debug("\n");
    }
    

    return {};
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SMALLEST_SUFFICIENT_TEAM_H
