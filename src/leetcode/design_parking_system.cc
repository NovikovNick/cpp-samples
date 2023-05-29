#ifndef LEETCODE_DESIGN_PARKING_SYSTEM_H
#define LEETCODE_DESIGN_PARKING_SYSTEM_H
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

class ParkingSystem {
  std::vector<int> counts;

 public:
  ParkingSystem(int big, int medium, int small) : counts({0, big, medium, small}) {}

  bool addCar(int carType) {
	  return --counts[carType] >= 0;
  }
};

}  // namespace leetcode
#endif  // LEETCODE_DESIGN_PARKING_SYSTEM_H
