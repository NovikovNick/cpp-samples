#ifndef LEETCODE_GROUP_THE_PEOPLE_GIVEN_THE_GROUP_SIZE_THEY_BELONG_TO_H
#define LEETCODE_GROUP_THE_PEOPLE_GIVEN_THE_GROUP_SIZE_THEY_BELONG_TO_H
#include <algorithm>
#include <format>
#include <iostream>
#include <map>
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
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    std::multimap<int, int> sizeToIndex;
    for (int i = 0; i < groupSizes.size(); ++i) {
      sizeToIndex.emplace(groupSizes[i], i);
    }

    std::vector<std::vector<int>> res;
    auto curr = sizeToIndex.begin();
    auto end = sizeToIndex.end();
    while (curr != end) {
      auto size = curr->first;
      res.emplace_back(size);
      while (--size >= 0) {
        res.back()[size] = curr->second;
        ++curr;
      }
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_GROUP_THE_PEOPLE_GIVEN_THE_GROUP_SIZE_THEY_BELONG_TO_H
