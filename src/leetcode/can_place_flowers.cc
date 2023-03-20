#ifndef LEETCODE_CAN_PLACE_FLOWERS_H
#define LEETCODE_CAN_PLACE_FLOWERS_H
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
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    if (n == 0) return true;
    if (size == 1) return n == 1 && flowerbed[0] == 0;

    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
      flowerbed[0] = 1;
      --n;
    }

    
    for (int i = 1; i < size - 1 && n > 0; ++i) {
      if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
        flowerbed[i] = 1;
        --n;
      }
    }

    if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) --n;

    return n <= 0;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CAN_PLACE_FLOWERS_H
