#include "a.h"

namespace foo {

using namespace std::chrono;

template <int x>
A<x>::A(std::function<void()> on_tick)
    : on_tick_(on_tick), tick_time_(duration_cast<microseconds>(frame{1}).count()) {}

template <int x>
int A<x>::getX() {
  return x;
}
template <int x>
void A<x>::operator()() {
  std::cout << std::format("operator(): 1/{} = {}micro\n", x, getCount());
  on_tick_();
}

template class A<60>;
}  // namespace foo

