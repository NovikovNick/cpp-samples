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