#ifndef LEETCODE_DESIGN_UNDERGROUND_SYSTEM_H
#define LEETCODE_DESIGN_UNDERGROUND_SYSTEM_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct PassengerStart {
  std::string startStation;
  int startedAt;
};

struct TotalTime {
  uint64_t totalTime = 0;
  double count = 0.0;

  double getAverageTime() { return count > 0 ? totalTime / count : 0.0; }

  void addTime(const int time) {
    totalTime += time;
    ++count;
  }
};
class UndergroundSystem {
  std::unordered_map<int, PassengerStart> passengers;
  std::unordered_map<std::string, TotalTime> statistic;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    passengers[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const auto& start = passengers[id];
    statistic[start.startStation + "-" + stationName].addTime(t - start.startedAt);
  }

  double getAverageTime(string startStation, string endStation) {
    return statistic[startStation + "-" + endStation].getAverageTime();
  }
};

}  // namespace leetcode
#endif  // LEETCODE_DESIGN_UNDERGROUND_SYSTEM_H
