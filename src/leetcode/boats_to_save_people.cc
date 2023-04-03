#ifndef LEETCODE_BOATS_TO_SAVE_PEOPLE_H
#define LEETCODE_BOATS_TO_SAVE_PEOPLE_H
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
  int numRescueBoats(vector<int>& people, int limit) {
    std::sort(people.begin(), people.end());
    int res = 0, fst = 0, snd = people.size() - 1;
    while (fst <= snd) {
      if (people[fst] + people[snd] <= limit) ++fst;
      --snd;
      ++res;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BOATS_TO_SAVE_PEOPLE_H
