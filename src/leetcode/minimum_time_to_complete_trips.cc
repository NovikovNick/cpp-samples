#ifndef LEETCODE_MINIMUM_TIME_TO_COMPLETE_TRIPS_H
#define LEETCODE_MINIMUM_TIME_TO_COMPLETE_TRIPS_H
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
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long min_trip = *std::min(time.begin(), time.end());
    long long low = 1;
    long long high = totalTrips * min_trip;
    long long mid = -1, sum;
    while (low <= high) {
      mid = low + ((high - low) >> 1);
      sum = tripsCount(mid, time);
      if (sum >= totalTrips) {
        high = mid - 1;
      } else if (sum < totalTrips) {
        low = mid + 1;
      }
    }
    return low;
  }

  long long tripsCount(const long long day, std::vector<int> time) {
    long long res = 0;
    for (const auto& t : time) res += day / t;
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_TIME_TO_COMPLETE_TRIPS_H
