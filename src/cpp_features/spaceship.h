#ifndef CPP_FEATURES_SPACESHIP_H
#define CPP_FEATURES_SPACESHIP_H

#include "../util/log.h"

/// <summary>
/// https://en.cppreference.com/w/cpp/language/operator_comparison#Three-way_comparison
/// </summary>
namespace spaceship {

struct Point2d {
  int x, y;
  constexpr auto operator<=>(const Point2d&) const noexcept = default;
};
void sample() {
  /*Point2d p1{1, 2};
  Point2d p2{2, 3};
  auto r1 = p1 < p2;
  auto r2 = p1 == p2;
  auto r3 = p1 <=> p2;*/
}

}  // namespace spaceship

#endif  // CPP_FEATURES_SPACESHIP_H