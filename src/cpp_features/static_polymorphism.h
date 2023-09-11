#ifndef CPP_FEATURES_STATIC_POLYMORPHISM_H
#define CPP_FEATURES_STATIC_POLYMORPHISM_H

#include "../util/log.h"
namespace static_polymorphism {
template <typename T, typename V>
concept Processor = requires(const V& val) {
  { T::process(val) } -> std::same_as<void>;
};

template <class T>
class Log1Processor {
 public:
  using value_type = T;
  static void process(const T& val) { util::debug("[ Log1 ]:... {}\n", val); }
};

template <class T>
class Log2Processor {
 public:
  using value_type = T;
  static void process(const T& val) { util::debug("[ Log2 ]:... {}\n", val); }
};

template <typename Val, typename Proc>
  requires std::same_as<Val, typename Proc::value_type>  //
           && Processor<Proc, Val>
class Wrapper {
 public:
  using strategy = Proc;
  using value_type = Val;

  static void process(const value_type& val) {
    util::debug("[  Wrapper  ]:... start\n");
    strategy::process(val);
    util::debug("[  Wrapper  ]:... end\n");
  }
};

void sample() {
  Wrapper<int, Log1Processor<int>>::process(2);
  Wrapper<int, Log2Processor<int>>::process(3);
}
}  // namespace static_polymorphism

#endif  // CPP_FEATURES_STATIC_POLYMORPHISM_H