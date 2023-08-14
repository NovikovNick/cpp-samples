#ifndef CPP_FEATURES_STRUCTURED_BINDING_H
#define CPP_FEATURES_STRUCTURED_BINDING_H
#include <cassert>

#include "../util/log.h"

/// <summary>
/// https://en.cppreference.com/w/cpp/language/structured_binding
/// </summary>
namespace struct_binding {

void sample();  // forward declaration

// 1.
class Coord {
  int row_, col_;

 public:
  Coord(int row, int col) : row_(row), col_(col){};
  int getRow() const { return row_; }
  int getCol() const { return col_; }
};

// 2.
// template <size_t N>
// decltype(auto) get(const Coord&);
//
// template <>
// decltype(auto) get<0>(const Coord& c) {
//  return c.getRow();
//};
//
// template <>
// decltype(auto) get<1>(const Coord& c) {
//  return c.getCol();
//};
template <size_t N>
decltype(auto) get(const Coord& c) {
  if constexpr (N == 0) {
    return c.getRow();
  } else if constexpr (N == 1) {
    return c.getCol();
  }
}

}  // namespace struct_binding

// 3.
namespace std {
template <>
struct tuple_size<struct_binding::Coord> : std::integral_constant<size_t, 2> {};

template <>
struct tuple_element<0, struct_binding::Coord> {
  using type = int32_t;
};

template <>
struct tuple_element<1, struct_binding::Coord> {
  using type = int32_t;
};
}  // namespace std

void struct_binding::sample() {
  Coord coord{1, 2};
  auto [row, col] = coord;
  util::debug("structual binding sample: row = {}, col = {}\n", row, col);
}

#endif  // CPP_FEATURES_STRUCTURED_BINDING_H