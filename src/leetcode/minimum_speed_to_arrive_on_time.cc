#ifndef LEETCODE_MINIMUM_SPEED_TO_ARRIVE_ON_TIME_H
#define LEETCODE_MINIMUM_SPEED_TO_ARRIVE_ON_TIME_H
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
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int minSpeed = -1;
    int min_velocity = 1;
    int max_velocity = 1e7;
    int mid_velocity;
    while (min_velocity <= max_velocity) {
      mid_velocity = min_velocity + (max_velocity - min_velocity) / 2;
      debug("min_velocity = {}, mid_velocity = {}, time = {}, max_velocity = {}\n",
            min_velocity,
            mid_velocity,
            getTime(dist, mid_velocity),
            max_velocity);

      if (getTime(dist, mid_velocity) <= hour) {
        max_velocity = mid_velocity - 1;
        minSpeed = mid_velocity;
      } else {
        min_velocity = mid_velocity + 1;
      }
    };
    return minSpeed;
  }

  double getTime(const vector<int>& dist, const double velocity) {
    double res = 0.0;
    for (int i = 0; i < dist.size() - 1; ++i) res += std::ceil(dist[i] / velocity);
    res += dist[dist.size() - 1] / velocity;
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_SPEED_TO_ARRIVE_ON_TIME_H
