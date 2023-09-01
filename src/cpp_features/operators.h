#ifndef CPP_FEATURES_OPERATORS_H
#define CPP_FEATURES_OPERATORS_H

#include "../util/log.h"

namespace oper {
class A {
  int data_;

 public:
  explicit A(const int data) : data_(data){};

  A& operator++() {  // preincrement
    ++data_;
    return *this;
  }

  const A operator++(int) {  // postincrement
    auto tmp = *this;
    ++*this;
    return tmp;
  }

  A& operator+=(const A& other) {
    data_ += other.data_;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const A& a);

  static void* operator new(size_t size) {
    util::debug("allocate {} bytes\n", size);
    return malloc(size);
  }

  static void operator delete(void* ptr, std::size_t size) noexcept {
    util::debug("deallocate {} bytes\n", size);
    std::free(ptr);
  }
};

const A operator+(const A& lhs, const A& rhs) {
  auto res = lhs;
  res += rhs;
  return res;
}

std::ostream& operator<<(std::ostream& os, const A& a) {
  os << a.data_;
  return os;
}
}  // namespace oper

#endif  // CPP_FEATURES_OPERATORS_H