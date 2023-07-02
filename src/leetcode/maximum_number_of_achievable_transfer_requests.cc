#ifndef LEETCODE_MAXIMUM_NUMBER_OF_ACHIEVABLE_TRANSFER_REQUESTS_H
#define LEETCODE_MAXIMUM_NUMBER_OF_ACHIEVABLE_TRANSFER_REQUESTS_H
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
  int maximumRequests(int n, vector<vector<int>>& requests) {
    debug("Check requests: \n");
    for (const auto rq : requests) debug("[{}, {}]\n", rq[0], rq[1]);    
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_NUMBER_OF_ACHIEVABLE_TRANSFER_REQUESTS_H
