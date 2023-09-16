#ifndef CPP_FEATURES_EXCEPTION_SAFETY_H
#define CPP_FEATURES_EXCEPTION_SAFETY_H

#include <string>

namespace exception_safety {

template <class T>
class StackImpl {
 protected:
  StackImpl(size_t size = 0);
  ~StackImpl();
  void Swap(StackImpl& other) noexcept;

  T* v_;
  size_t vsize_;
  size_t vused_;

 private:
  StackImpl(const StackImpl&) = delete;
  StackImpl& operator=(const StackImpl&) = delete;
};

template <typename T>
class Stack : private StackImpl<T> {
 public:
  explicit Stack(size_t size = 0);
  ~Stack();

  Stack(const Stack<T>&);
  Stack<T>& operator=(const Stack<T>&);

  size_t size() const;
  void push(const T&);
  T& top();
  void pop();

 private:
  void log(std::string_view arg);
};

void sample();

}  // namespace exception_safety

#endif  // CPP_FEATURES_EXCEPTION_SAFETY_H