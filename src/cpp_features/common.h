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

/* START FORWARD DECLARATION */

struct ForwardDeclaraged;  // incomplete type

struct ForwardDeclaragedConsumer {
  // ForwardDeclaraged state; incomplete type is not allowed
  ForwardDeclaraged* state_ref;
  ForwardDeclaraged& state_ptr;

  ForwardDeclaraged get(const ForwardDeclaraged& arg);
};

/* END FORWARD DECLARATION */

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

inline void reverseString(std::string& str) {
  auto n = str.size();
  for (size_t i = 0; i < n / 2; ++i) {
    std::swap(str[i], str[n - 1 - i]);
  }
}

template <typename FwdIt, typename Val>
  requires std::forward_iterator<FwdIt> &&
           std::same_as<Val, typename FwdIt::value_type>
auto remove_n_elements(FwdIt begin,
                        FwdIt end,
                        const Val remove_value,
                        int remove_count) {
  return std::remove_if(begin, end, [&remove_count, remove_value](auto& val) {
    if (val == remove_value && remove_count > 0) {
      --remove_count;
      return true;
    }
    return false;
  });
}

}  // namespace common

#endif  // CPP_FEATURES_COMMON_H