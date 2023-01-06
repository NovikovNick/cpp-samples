#include <thread>

#include "../util/log.h"

namespace concurrency {
/*
concurrency::hierarchical_mutex m1000{1000};
concurrency::hierarchical_mutex m500{500};
std::scoped_lock g1(m1000);
std::scoped_lock g2(m500);
*/
class hierarchical_mutex {
  std::mutex internal_mutex;
  const uint64_t hierarchy_val;
  uint64_t prev_hierarchy_val;  
  static thread_local uint64_t this_thread_hierarchy_val;  // 1.

  void check_for_hierarchy_violation() {
    if (this_thread_hierarchy_val <= hierarchy_val)  // 2.
      throw std::logic_error("mutex hierarchy violated");
  }

  void update_hierarchy_val() {
    prev_hierarchy_val = this_thread_hierarchy_val;  // 3.
    this_thread_hierarchy_val = hierarchy_val;
  }

 public:
  explicit hierarchical_mutex(uint64_t val)
      : hierarchy_val(val), prev_hierarchy_val(0){};

  void lock() {
    check_for_hierarchy_violation();
    internal_mutex.lock();   // 4.
    update_hierarchy_val();  // 5.
  }

  void unlock() {
    if (this_thread_hierarchy_val != hierarchy_val)
      throw std::logic_error("mutex hierarchy violated");  // 9.
    this_thread_hierarchy_val = prev_hierarchy_val;        // 6.
    internal_mutex.unlock();
  }

  bool try_lock() {
    check_for_hierarchy_violation();
    if (!internal_mutex.try_lock()) return false;  // 7.
    update_hierarchy_val();
    return true;
  }
};

thread_local uint64_t hierarchical_mutex::this_thread_hierarchy_val = _UI64_MAX;  // 8.

}  // namespace concurrency
