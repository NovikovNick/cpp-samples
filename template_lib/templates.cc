#include "templates.h"
#include "templates.h"

#include <iostream>

namespace templates {

template <typename T, size_t N>
MyArray<T, N>::MyArray() : arr(N) {}

template <typename T, size_t N>
void MyArray<T, N>::Print() {
  for (const auto v : arr) {
    std::cout << v << "'";
  }
  std::cout << std::endl;
}

template <typename T, size_t N>
T& MyArray<T, N>::operator[](int i) {
  return arr[i];
}

template MyArray<double, 5>;
template MyArray<std::string, 5>;

}  // namespace templates