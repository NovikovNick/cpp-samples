#ifndef LEETCODE_RECONSTRUCT_ITINERARY_H
#define LEETCODE_RECONSTRUCT_ITINERARY_H
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
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    debug("itinerary\n");
    return {};
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RECONSTRUCT_ITINERARY_H
