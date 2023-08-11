#ifndef FOO_TEMPLATE_H
#define FOO_TEMPLATE_H
#include <chrono>
#include <format>
#include <functional>
#include <iostream>

namespace foo {

	/*
	
	namespace {
	auto on_tick = []() { util::debug("called on tick\n"); };
	  foo::A<60> a(on_tick);
	}  // namespace

	int main(int argc, char argv[]) {
	  util::debug("x = {}\n", a.getX());
	  util::debug("count = {}\n", a.getCount());
	  a();
	  return 0;
	}

	
	*/

template <int x>
class A {
  using frame = std::chrono::duration<uint64_t, std::ratio<1, x>>;
  long long tick_time_;
  std::function<void()> on_tick_;

 public:
  A(std::function<void()> on_tick);
  int getX();
  int getCount() { return static_cast<int>(tick_time_);
  };
  void operator()();
};
}  // namespace foo

#endif  // FOO_TEMPLATE_H