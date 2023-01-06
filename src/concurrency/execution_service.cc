#include <condition_variable>
#include <queue>
#include <thread>

#include "../util/log.h"

namespace concurrency {

/*
  concurrency::ExecutionService execution_service(10);
  std::vector<std::thread> threads;
  for (int i = 1; i < 100000; i *= 10)
    threads.emplace_back([&execution_service, i]() {
      for (int j = 1; j < 10; ++j) execution_service.registerTask(j * i);
    });
  for (auto& t : threads) t.join();
  std::this_thread::sleep_for(std::chrono::seconds(2));
*/
class ExecutionService {
  using TASK = int;
  std::vector<std::thread> threads_;
  std::condition_variable condition_;
  std::queue<TASK> queue_;
  std::mutex mut_;

 public:
  ExecutionService(const int thread_count)
      : threads_(std::vector<std::thread>()) {
    for (int i = 0; i < thread_count; ++i)
      threads_.emplace_back(&ExecutionService::process, this);
    for (auto& t : threads_) t.detach();
  }

  void registerTask(const TASK& task) {
    {
      std::scoped_lock lock(mut_);
      queue_.push(task);
    }
    util::debug("registered -> {}\n", task);
    condition_.notify_one();
  }

 private:
  void process() {
    while (true) {
      std::unique_lock lock(mut_);
      condition_.wait(lock, [&queue_ = queue_] { return !queue_.empty(); });
      const auto task = queue_.front();
      queue_.pop();
      lock.unlock();

      // process
      util::debug("process -> {}\n", task);
    }
  }
};
}  // namespace concurrency
