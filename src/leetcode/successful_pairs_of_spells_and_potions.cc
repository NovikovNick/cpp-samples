#ifndef LEETCODE_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_H
#define LEETCODE_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_H
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
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    std::sort(potions.begin(), potions.end());

    double min_potion;
    for (int i = 0; i < spells.size(); ++i) {
      min_potion = success / static_cast<double>(spells[i]);
      auto lower = std::lower_bound(potions.begin(), potions.end(), min_potion);
      spells[i] = std::distance(lower, potions.end());
    }

    return spells;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_H
