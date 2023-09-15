#include "exception_safety.h"

#include <assert.h>

#include "../util/log.h"

namespace {

class A {
  int data = 0;

 public:
  A(const int i) : data(i) { log("ctor"); }
  A() : data(0) { log("ctor"); }

  A(const A& other) {
    data = other.data;
    log("copy ctor");
  }

  A& operator=(const A& other) {
    log("copy assignment operator");
    auto tmp = other;
    std::swap(*this, tmp);
    return *this;
  }

  A(A&& other) noexcept {
    data = std::exchange(other.data, 0);
    log("move ctor");
  }

  A& operator=(A&& other) noexcept {
    log("move assignment operator");
    data = std::exchange(other.data, 0);
    return *this;
  }

  ~A() { log("dtor"); }

  operator int() const { return data; }

 private:
  template <typename... Args>
  void log(std::string_view str, Args&&... args) {
    std::cout << "[" << this << "]:... ";
    util::debug(str, args...);
    std::cout << std::endl;
  }
};

template <class T>
T* newCopy(const T* src, size_t src_size, size_t dst_size) {
  assert(dst_size >= src_size);
  // new can throw
  // T::T() can throw
  T* dst = new T[dst_size];
  try {
    // T::operator=() can throw
    std::copy(src, src + src_size, dst);
  } catch (...) {
    delete[] dst;
    throw;
  }
  return dst;
}
}  // namespace

namespace exception_safety {

template <typename T>
Stack<T>::Stack() : v_(new T[3]), vsize_(3), vused_(0) {
  // new can throw bad_alloc
  // T::constructor can throw some exception
  log("ctor");
}

template <typename T>
Stack<T>::~Stack() {
  delete[] v_;
  log("dtor");
}

template <typename T>
Stack<T>::Stack(const Stack& other)
    : v_(newCopy(other.v_, other.vsize_, other.vsize_)),  //
      vsize_(vsize_),                                     //
      vused_(vused_) {
  log("copy ctor");
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
  if (this != &other) {
    auto tmp = newCopy(other.v_, other.vsize_, other.vsize_);

    log("copy assignment");

    vsize_ = other.vsize_;
    vused_ = other.vused_;
    delete[] v_;  // delete couln'd throw
    v_ = tmp;
  }

  return *this;
}

template <typename T>
size_t Stack<T>::count() const {
  return vused_;
}

template <typename T>
void Stack<T>::push(const T& val) {
  if (vused_ == vsize_) {  // increase capacity of stack if needed
    auto new_size = vsize_ * 2 + 1;
    auto tmp_ptr = newCopy(v_, vsize_, new_size);  // can throw
    tmp_ptr[vused_] = val;                         // can throw
    delete[] v_;

    vsize_ = new_size;
    v_ = tmp_ptr;
  }

  v_[vused_] = val;  // can throw
  ++vused_;
}

template <typename T>
T& Stack<T>::top() {
  if (count() == 0) throw std::runtime_error("empty stack");
  return v_[vused_ - 1];
}

template <typename T>
void Stack<T>::pop() {
  if (count() == 0) throw std::runtime_error("empty stack");
  --vused_;
}

template <typename T>
void Stack<T>::log(std::string_view arg) {
  std::cout << "[      stack     ]:... ";
  std::cout << arg;
  std::cout << std::endl;
}

void sample() {
  Stack<A> stack;

  int n = 10;
  for (int i = 1; i <= n; ++i) {
    stack.push(i);
  }
  while (stack.count() > 0) {
    int value = stack.top();
    stack.pop();
    util::debug("[exception_safety]:... {}\n", value);
  }
}

}  // namespace exception_safety