#ifndef CPP_FEATURES_LOCK_FREE_H
#define CPP_FEATURES_LOCK_FREE_H

#include <algorithm>
#include <array>
#include <cassert>
#include <memory>
#include <thread>

namespace lock_free {

template <typename T, size_t CAPACITY>
class LockFreeCircularQueue final {
  std::array<T, CAPACITY> buffer_;
  T default_value_if_empty_;
  std::atomic<size_t> write_index_;
  std::atomic<size_t> read_index_;

 public:
  explicit LockFreeCircularQueue(const T& default_value_if_empty)
      : default_value_if_empty_(default_value_if_empty),
        write_index_(0),
        read_index_(0) {}

  bool push(T value) {
    auto old_write_index = write_index_.load();
    auto new_write_index = (old_write_index + 1) % CAPACITY;
    if (new_write_index == read_index_.load()) {
      return false;
    }
    std::swap(buffer_[old_write_index], value);
    write_index_.store(new_write_index);
    return true;
  }

  const T& top() const {
    auto read_index = read_index_.load();
    const T& res = buffer_[read_index];
    return read_index == write_index_.load()  //
               ? default_value_if_empty_      //
               : res;
  }

  bool pop() {
    auto old_read_index = read_index_.load();
    auto new_read_index = (old_read_index + 1) % CAPACITY;
    if (old_read_index == write_index_.load()) {
      return false;
    } else {
      read_index_.store(new_read_index);
      return true;
    }
  }

  LockFreeCircularQueue(const LockFreeCircularQueue& other)
      : default_value_if_empty_(other.default_value_if_empty_),
        write_index_(other.write_index_.load()),
        read_index_(other.read_index_.load()) {
    std::copy(other.buffer_.begin(), other.buffer_.end(), buffer_.begin());
  };

  LockFreeCircularQueue& operator=(const LockFreeCircularQueue& other) {
    LockFreeCircularQueue copy(other);
    swap(copy);
    return *this;
  };

  LockFreeCircularQueue(LockFreeCircularQueue&& other) noexcept = delete;
  LockFreeCircularQueue& operator=(LockFreeCircularQueue&& other) noexcept = delete;
  ~LockFreeCircularQueue() = default;

 private:
  void swap(LockFreeCircularQueue<T, CAPACITY>& other) noexcept {
    std::swap(buffer_, other.buffer_);
    std::swap(default_value_if_empty_, other.default_value_if_empty_);
    write_index_.store(other.write_index_.exchange(write_index_.load()));
    read_index_.store(other.read_index_.exchange(read_index_.load()));
  }
};

void copyConsturtorTest() {
  // arrange
  int default_value_if_queue_is_empty = -1;
  LockFreeCircularQueue<int, 10> origin(default_value_if_queue_is_empty);
  origin.push(1);
  origin.push(2);
  origin.push(3);

  // act
  auto copy = origin;

  // assert
  auto val = copy.top();
  assert(val == 1);
  copy.pop();

  val = copy.top();
  assert(val == 2);
  copy.pop();

  val = copy.top();
  assert(val == 3);
  copy.pop();

  val = copy.top();
  assert(val == default_value_if_queue_is_empty);
}

void copyAssignmentTest() {
  // arrange
  int default_value_if_queue_is_empty = -1;
  LockFreeCircularQueue<int, 10> origin(default_value_if_queue_is_empty);
  origin.push(1);
  auto copy = origin;
  copy.push(2);
  copy.push(3);

  // act
  origin = copy;

  // assert
  auto val = origin.top();
  assert(val == 1);
  origin.pop();

  val = origin.top();
  assert(val == 2);
  origin.pop();

  val = origin.top();
  assert(val == 3);
  origin.pop();

  val = origin.top();
  assert(val == default_value_if_queue_is_empty);
}

void concurrencyTest() {
  LockFreeCircularQueue<int, 10> queue(-1);
  int n = 1e7;
  auto producer = [&queue, n]() {
    for (int i = 0; i <= n;) {
      while (queue.push(i)) ++i;
    }
  };
  auto consumer = [&queue, n]() {
    while (queue.top() == -1)
      ;

    int prev = -1;
    while (prev != n) {
      do {
        while (queue.top() == -1)
          ;
        auto curr = queue.top();

        assert(prev + 1 == curr);  // !

        prev = curr;

      } while (queue.pop() && prev != n);
    }
  };

  auto t1 = std::thread(producer);
  auto t2 = std::thread(consumer);
  t1.join();
  t2.join();
}

void sample() {
  copyConsturtorTest();
  copyAssignmentTest();
  concurrencyTest();
}
}  // namespace lock_free

#endif  // CPP_FEATURES_LOCK_FREE_H