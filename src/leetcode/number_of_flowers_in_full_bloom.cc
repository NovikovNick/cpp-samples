#ifndef LEETCODE_NUMBER_OF_FLOWERS_IN_FULL_BLOOM_H
#define LEETCODE_NUMBER_OF_FLOWERS_IN_FULL_BLOOM_H
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
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    debug("another hard problem :(...\n");
    return {};
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_FLOWERS_IN_FULL_BLOOM_H
