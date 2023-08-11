#ifndef CPP_FEATURES_ATTRIBUTES_H
#define CPP_FEATURES_ATTRIBUTES_H
#include <cassert>

/// <summary>
/// https://en.cppreference.com/w/cpp/language/attributes
/// </summary>
namespace attributes {

[[deprecated("Get() is deprecated. Use get()")]] int Get() { return 42; }

[[nodiscard]] int get() {
  int res = 0;
  switch (1) {
    case 1: res += 1; [[fallthrough]];
    case 10: res += 10;
    case 100: res += 100;
  }
  return res;
}

void sample() {
  [[maybe_unused]] int x = get();
  assert(x > 100);
}

}  // namespace attributes

#endif  // CPP_FEATURES_ATTRIBUTES_H