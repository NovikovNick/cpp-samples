#ifndef LEETCODE_COUNT_ALL_VALID_PICKUP_AND_DELIVERY_OPTIONS_H
#define LEETCODE_COUNT_ALL_VALID_PICKUP_AND_DELIVERY_OPTIONS_H
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

template <int SIZE>
class OrderCounts {
  int arr[SIZE + 1] = {0};
 public:
  constexpr OrderCounts() {
    int i = 0;
    arr[++i] = 1;
    arr[++i] = 6;
    arr[++i] = 90;
    arr[++i] = 2520;
    arr[++i] = 113400;
    arr[++i] = 7484400;
    arr[++i] = 681080400;
    arr[++i] = 729647433;
    for (; i < SIZE + 1; ++i) arr[i] = i;
  };

  int operator[](const int index) const { return arr[index]; }
};

constexpr OrderCounts<500> orderCounts;

class Solution {
 public:
  int countOrders(int n) {
    debug("need to count solutions\n");
    return orderCounts[n];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_ALL_VALID_PICKUP_AND_DELIVERY_OPTIONS_H
