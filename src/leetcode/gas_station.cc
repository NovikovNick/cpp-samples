#ifndef LEETCODE_GAS_STATION_H
#define LEETCODE_GAS_STATION_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    if (n == 1) return gas[0] >= cost[0] ? 0 : -1;

    int gas_sum = gas[n - 1], cost_sum = cost[n - 1];
    gas[n - 1] = gas[n - 1] - cost[n - 1];
    int max_index = n - 1, max_diff = gas[n - 1];
    for (int i = (n - 2); i >= 0; --i) {
      gas_sum += gas[i];
      cost_sum += cost[i];
      gas[i] = gas[i] - cost[i] + gas[i + 1];
      if (max_diff < gas[i]) {
        max_diff = gas[i];
        max_index = i;
      }
    }

    return gas_sum < cost_sum ? -1 : max_index;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_GAS_STATION_H
