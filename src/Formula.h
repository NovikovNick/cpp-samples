#include <cstddef>
#ifndef EXAMPLEPROJECT_FORMULA_H
#define EXAMPLEPROJECT_FORMULA_H

namespace mysamples {
template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
  return N;
}
}  // namespace mysamples

#endif  // EXAMPLEPROJECT_FORMULA_H