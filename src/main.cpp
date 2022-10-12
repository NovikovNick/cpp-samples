#include <string>

#include "algorithm.cc"
#include "binary_literal.cc"

template <typename T>
requires(sizeof(T) > 4) void foo(T arg) {
  std::cout << "large arg " << std::endl;
}
template <typename T>
requires(sizeof(T) <= 4) void foo(T arg) {
  std::cout << "small arg " << std::endl;
}

int main() {
  int literal = 00101_binary;
  std::cout << "it works... " + std::to_string(literal) << std::endl;
  foo('a');
  foo(1LL);
  return 0;
}
