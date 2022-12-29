#ifndef LEETCODE_SINGLE_THREADED_CPU_H
#define LEETCODE_SINGLE_THREADED_CPU_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <queue>
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
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    auto enqueue_time_comp = [tasks = tasks](const int& a, const int& b) {
      return tasks[a][0] < tasks[b][0];
    };
    auto processing_time_comp = [tasks = tasks](const int& a, const int& b) {
      if (tasks[a][1] > tasks[b][1]) return true;
      if (tasks[a][1] == tasks[b][1]) return a > b;
      return false;
    };

    std::vector<int> enqueue(n);
    std::iota(enqueue.begin(), enqueue.end(), 0);
    std::sort(enqueue.begin(), enqueue.end(), enqueue_time_comp);

    std::priority_queue<int, std::vector<int>, decltype(processing_time_comp)>
        available_tasks(processing_time_comp);

    std::vector<int> res;
    int next_task = enqueue[0];
    int time = tasks[next_task][0];
    int idle_time = time;

    available_tasks.push(next_task);

    for (int i = 1, enqueue_time; i < n; ++i) {
      next_task = enqueue[i];
      enqueue_time = tasks[next_task][0];

      while (idle_time < enqueue_time && !available_tasks.empty()) {
        auto index = available_tasks.top();
        available_tasks.pop();
        res.push_back(index);
        idle_time = idle_time + tasks[index][1];
      }

      time = enqueue_time;
      available_tasks.push(next_task);
    }

    while (!available_tasks.empty()) {
      res.push_back(available_tasks.top());
      available_tasks.pop();
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SINGLE_THREADED_CPU_H
