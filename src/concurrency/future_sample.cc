#include <future>
#include <thread>
#include <vector>

#include "../util/log.h"

namespace sample_concur {

// todo: try to parallel some leetcode problem
void start() {
  int thread_count = std::max<int>(4, std::thread::hardware_concurrency());
  std::vector<std::future<int>> res;
  for (int i = 0; i < thread_count; ++i)
    res.push_back(std::async(std::launch::async, [num = i] {
      int res = 0;
      for (int i = 0; i < INT_MAX; ++i) ++res;
      util::debug("Task {} completed\n", num);
      return res;
    }));

  util::debug("after future\n");
  for (auto& it : res) util::debug("result = {}\n", it.get());
}
}  // namespace sample_concur
