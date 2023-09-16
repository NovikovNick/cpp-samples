#include "exception_safety.h"

#include <assert.h>

#include <memory>

#include "../util/log.h"
#include <stack>

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

  ~A() noexcept { log("dtor"); }

  operator int() const { return data; }

 private:
  template <typename... Args>
  void log(std::string_view str, Args&&... args) {
    std::cout << "[" << this << "]:... ";
    util::debug(str, args...);
    std::cout << std::endl;
  }
};

// unused in current implementation
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

template <class T>
inline StackImpl<T>::StackImpl(size_t size)                 //
    : v_(static_cast<T*>(operator new(sizeof(T) * size))),  // can throw
      vsize_(size),                                         //
      vused_(0) {}

template <class T>
StackImpl<T>::~StackImpl() {
  std::destroy(v_, v_ + vused_);  // call destuctors, couln'd throw
  operator delete(v_);
}

template <class T>
void StackImpl<T>::Swap(StackImpl& other) noexcept {
  std::swap(v_, other.v_);
  std::swap(vsize_, other.vsize_);
  std::swap(vused_, other.vused_);
}

template <typename T>
Stack<T>::Stack(size_t size) : StackImpl<T>(size) {
  log("ctor");
}

template <typename T>
Stack<T>::~Stack() {
  log("dtor");
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) : StackImpl<T>(other.vsize_) {
  while (this->vused_ < other.vused_) {
    std::construct_at(            // if some of T::T() throw exception
        this->v_ + this->vused_,  // then StackImpl correctly call destructors for
        other.v_[this->vused_]);  // all objects created up to this point
    this->vused_ += 1;
  }
  log("copy ctor");
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
  Stack copy(other);                            // can throw
  log("copy assignment: copy-and-swap idiom");  //
  Swap(copy);                                   // noexcept
  return *this;
}

template <typename T>
size_t Stack<T>::size() const {
  return this->vused_;
}

template <typename T>
void Stack<T>::push(const T& val) {
  if (this->vused_ == this->vsize_) {     // increase capacity of stack if needed
    Stack<T> tmp(this->vsize_ * 2 + 1);   // can throw
    while (tmp.size() < this->vused_) {   //
      tmp.push(this->v_[tmp.size()]);     // can throw
    }                                     //
    tmp.push(val);                        // can throw
    this->Swap(tmp);                      // noexcept
  } else {                                //
    T* ptr = this->v_ + this->vused_;     //
    std::construct_at(ptr, val);          // can throw
    this->vused_ += 1;
  }
}

template <typename T>
T& Stack<T>::top() {
  if (size() == 0) throw std::runtime_error("empty stack");
  return this->v_[this->vused_ - 1];
}

template <typename T>
void Stack<T>::pop() {
  if (size() == 0) throw std::runtime_error("empty stack");
  this->vused_ -= 1;
  T* ptr = this->v_ + this->vused_;
  std::destroy(ptr, ptr + 1);
}

template <typename T>
void Stack<T>::log(std::string_view arg) {
  std::cout << "[      stack     ]:... ";
  std::cout << arg;
  std::cout << std::endl;
}

void sample() {
  Stack<A> origin(10);
  // std::stack<A> origin;
  auto stack = origin;

  int n = 10;
  for (int i = 1; i <= n; ++i) {
    stack.push(i);
  }
  while (stack.size() > 0) {
    int value = stack.top();
    stack.pop();
    util::debug("[exception_safety]:... {}\n", value);
  }
}

}  // namespace exception_safety