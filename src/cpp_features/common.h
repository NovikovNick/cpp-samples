#ifndef CPP_FEATURES_COMMON_H
#define CPP_FEATURES_COMMON_H

#include <algorithm>
#include <bit>
#include <bitset>
#include <charconv>
#include <format>
#include <optional>
#include <type_traits>
#include <variant>
#include <vector>

#include "../util/log.h"

namespace common {

struct A {
  int data;

  A() : A(0){};

  A(const int num) : data(num) { util::debug("{} ctor\n", data); };

  A(const A& a) : data(a.data) { util::debug("copy ctor\n"); }

  A& operator=(const A& a) {
    util::debug("copy assignment\n");
    data = a.data;
    return *this;
  }

  A(A&& other) noexcept : data(other.data) {
    util::debug("move ctor\n");
    other.data = 0;
  }

  A& operator=(A&& a) noexcept {
    util::debug("move assignment\n");
    data = a.data;
    a.data = 0;
    return *this;
  }

  ~A() { util::debug("dtor {}\n", data); };

  static A getA() {
    A res;
    return res;  // NRVO
  }
  void foo() const;
};

struct B {
  void bar() const;
};

/// <summary>
/// std::from_chars, std::optional
/// </summary>
std::optional<int> toInt(std::string_view str);

void fromCharsSample();

/// <summary>
/// std::string_view
/// </summary>
void stringViewSample();

/// <summary>
/// std::variant
/// </summary>
void variantSample();

/// <summary>
/// bit
/// </summary>
int getCountOneBit(int num);

template <class T>
void printBits(const T& obj) {
  util::debug("{}bytes: {}\n",
              sizeof(T),
              std::bit_cast<std::bitset<sizeof(T) * 8>, T>(obj).to_string());
}
}  // namespace common

#endif  // CPP_FEATURES_COMMON_H