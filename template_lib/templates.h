#ifndef CPP_FEATURES_TEMPLATES_H
#define CPP_FEATURES_TEMPLATES_H

#include <vector>

namespace templates {

template <auto Val>
struct intergral_constant {
  using value_type = decltype(Val);
  static constexpr value_type value = Val;
};

using six_type = intergral_constant<6>;
using one_type = intergral_constant<1>;

template <typename T, size_t N>
class MyArray {
  std::vector<T> arr;

 public:
  MyArray();
  void Print();
  T& operator[](int i);
};

}  // namespace templates

#endif  // CPP_FEATURES_TEMPLATES_H