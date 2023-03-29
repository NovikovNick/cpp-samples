#ifndef LEETCODE_REDUCING_DISHES_H
#define LEETCODE_REDUCING_DISHES_H
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
  int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    std::sort(satisfaction.begin(), satisfaction.end());

    for (const auto it : satisfaction) debug("{} ", it);
    debug("\n");

    if (satisfaction[n - 1] < 0) return 0;

    int negative = 0;
    while (satisfaction[negative] < 0) ++negative;


    int res = calculateTime(1, 0, negative, satisfaction) +
              calculateTime(negative + 1, negative, n, satisfaction);

    for (int i = 1; i < negative; ++i) {
      int time = negative - i + 1;
      int unlike_time = calculateTime(1, i, negative, satisfaction);
      int like_time = calculateTime(time, negative, n, satisfaction);
      debug("{}. [{}] = {} + {} = {}\n", i, time, unlike_time, like_time,
            unlike_time + like_time);
      if (res > unlike_time + like_time) return res;
      res = unlike_time + like_time;
    }

    return res;
  }

  int calculateTime(int begin_time, int begin, const int end,
                    const std::vector<int>& satisfaction) {
    int res = 0;
    for (; begin < end; ++begin, ++begin_time) {
      res += satisfaction[begin] * begin_time;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REDUCING_DISHES_H
