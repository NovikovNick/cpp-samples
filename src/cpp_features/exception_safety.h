#ifndef CPP_FEATURES_EXCEPTION_SAFETY_H
#define CPP_FEATURES_EXCEPTION_SAFETY_H

#include <string>

namespace exception_safety {
template <typename T>
class Stack {
 public:
  Stack();
  ~Stack();

  Stack(const Stack<T>&);
  Stack<T>& operator=(const Stack<T>&);

  size_t count() const;
  void push(const T&);
  T& top();
  void pop();

 private:
  size_t vsize_;
  size_t vused_;
  T* v_;

  void log(std::string_view arg);
};

void sample();

}  // namespace exception_safety

#endif  // CPP_FEATURES_EXCEPTION_SAFETY_H