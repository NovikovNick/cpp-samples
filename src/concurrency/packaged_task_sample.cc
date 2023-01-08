#include <future>
#include <thread>
#include <vector>

#include "../util/log.h"

namespace sample_concur {

class GUI {
  using TASK = std::packaged_task<int(int)>;
  std::mutex m_;
  std::deque<TASK> tasks_;
  int frame_ = 0;

  void process_gui_message() {
    util::debug("frame = {}\n", ++frame_);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

 public:
  void run() {
    while (true) {
      process_gui_message();

      TASK task;
      {
        std::scoped_lock lock(m_);
        if (tasks_.empty()) continue;
        task = std::move(tasks_.front());
        tasks_.pop_front();
      }
      task(frame_);
    }
  }

  template <typename F>
  std::future<int> addTask(F f) {
    std::packaged_task<int(int)> task(f);
    std::future<int> res = task.get_future();
    std::scoped_lock lock(m_);
    tasks_.push_back(std::move(task));
    return res;
  }
};

void start() {
  GUI gui;

  std::thread gui_thread([&gui] { gui.run(); });
  std::thread another_thread([&gui] {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      auto task = gui.addTask([](const int frame) {
        util::debug("executed {}\n", frame);
        return frame;
      });
      util::debug("registered\n");
      int res = task.get();
      util::debug("received {}\n", res);
    }
  });

  gui_thread.join();
  another_thread.join();
}
}  // namespace sample_concur
