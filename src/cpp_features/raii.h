#ifndef CPP_FEATURES_RAII_H
#define CPP_FEATURES_RAII_H

#include <memory>
#include <vector>

#include "../util/log.h"

namespace raii {

class A {
 public:
  int data;
  A(const int data) : data(data){};
  A(const A& other) : data(other.data) {
    // throw std::exception();
  }

  A& operator=(const A& other) {
    data = other.data;
    throw std::exception();
  }
};

template <class T>
class MyRAII {
 public:
  std::string s_;
  T* p_;
  MyRAII(T* p, const std::string& s) : p_(p), s_(s){};

  MyRAII(const MyRAII<T>& other) : p_(new T(*other.p_)) {
    try {
      s_ = other.s_;
    } catch (...) {
      delete p_;
      throw;
    }
  }

  MyRAII<T>& operator=(const MyRAII<T>& other) {
    if (this == &other) return *this;

    MyRAII<T> copy = other;
    swap(copy);
    return *this;
  }

  MyRAII(MyRAII<T>&& other) noexcept : p_(nullptr) { *this = std::move(other); };

  MyRAII& operator=(MyRAII<T>&& other) noexcept {
    if (this == &other) return *this;
    delete p_;
    p_ = std::exchange(other.p_, nullptr);
    s_ = std::move(other.s_);
  }

  ~MyRAII() { delete p_; }

 private:
  void swap(MyRAII<T>& other) { std::swap(p_, other.p_); }
};

void sample() {
  try {
    using T = A;
    std::vector<MyRAII<T>> arr;
    for (int i = 0; i < 100; ++i) {
      arr.push_back(MyRAII(new T{i}, "asdf"));
      util::debug("[raii]:... new {}\n", i);
    }

    for (auto raii : arr) {
      util::debug("[raii]:... log {}\n", raii.p_->data);
    }

    MyRAII<int> x(new int{22}, "123");
    MyRAII<int> tmp(new int{42}, "3123");
    x = std::move(tmp);
  } catch (...) {
  }
}

}  // namespace raii

#endif  // CPP_FEATURES_RAII_H