#ifndef LEETCODE_BEST_TEAM_WITH_NO_CONFLICTS_H
#define LEETCODE_BEST_TEAM_WITH_NO_CONFLICTS_H
#include <algorithm>
#include <deque>
#include <format>
#include <iostream>
#include <list>
#include <numeric>
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
  int bestTeamScore(vector<int>& scores_arr, vector<int>& ages) {
    int n = scores_arr.size();
    std::vector<std::deque<int>> scores_by_age(1001);

    for (int i = 0; i < n; ++i) scores_by_age[ages[i]].push_back(scores_arr[i]);
    for (auto& scores : scores_by_age)
      if (!scores.empty()) std::sort(scores.begin(), scores.end());

    for (int age = 1000; age >= 0; --age) {
      auto& scores = scores_by_age[age];
      if (scores.empty()) continue;
      debug("{}", age);
      for (const auto it : scores) debug("\t{}", it);
      debug("\n");
    }


    int res = 0;
    int curr_sum = 0;
    std::list<int> curr_ages;
    for (int age = 1000; age >= 0; --age) {
      auto& scores = scores_by_age[age];
      if (scores.empty()) continue;
      
      curr_sum += std::accumulate(scores.begin(), scores.end(), 0);
      curr_ages.push_back(age);

      auto older_age = curr_ages.begin();
      while (*older_age != age) {
        auto& older_scores = scores_by_age[*older_age];
        while (!older_scores.empty() && older_scores.front() < scores.back()) {
          curr_sum -= older_scores.front();
          older_scores.pop_front();
        }

        if (older_scores.empty()) {
          curr_ages.erase(older_age++);
        } else {
          older_age = std::next(older_age);
        }
      }
      // debug("{}: {}\n", age, curr_sum);
      res = std::max(res, curr_sum);
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BEST_TEAM_WITH_NO_CONFLICTS_H
