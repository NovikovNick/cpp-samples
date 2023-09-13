#ifndef CPP_FEATURES_COW_H
#define CPP_FEATURES_COW_H

#include <memory>

#include "../util/log.h"

namespace cow {

template <typename T>
class cow_ptr {
  std::shared_ptr<T> ptr_;

 public:
  using ptr_type = std::shared_ptr<T>;

  cow_ptr(T* type) : ptr_(ptr_type(type)) {}

  const T* operator->() const { return ptr_.operator->(); }

  T* operator->() {
    detach();
    return ptr_.operator->();
  }

 private:
  void detach() {
    if (ptr_.use_count() != 1) {
      T* tmp = ptr_.get();
      ptr_ = ptr_type(new T(*tmp));
    }
  }
};

class A {
  int data = 0;

 public:
  A() { log("ctor"); }

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

  void func() { log("func"); };
  void funcConst() const { log("funcConst"); };

 private:
  template <typename... Args>
  void log(std::string_view str, Args&&... args) const {
    std::cout << "[" << this << "]:... ";
    util::debug(str, args...);
    std::cout << std::endl;
  }
};

template <class T, class... Args>
cow_ptr<T> make_cow(Args&&... args) {
  return cow_ptr<T>(new T(std::forward<Args>(args)...));
}

void sample() {
  auto origin = make_cow<A>();
  util::debug("[      cow       ]:... auto origin = make_cow<A>();\n");

  origin->funcConst();
  origin->funcConst();
  origin->funcConst();

  const auto readonly = origin;
  util::debug("[      cow       ]:... const auto readonly = origin;\n");

  readonly->funcConst();
  readonly->funcConst();
  readonly->funcConst();

  auto writeable = readonly;
  util::debug("[      cow       ]:... auto writeable = readonly;\n");

  const_cast<const cow_ptr<A>&>(writeable)->funcConst();
  writeable->func();
  writeable->func();
  writeable->func();
}

}  // namespace cow

#endif  // CPP_FEATURES_COW_H