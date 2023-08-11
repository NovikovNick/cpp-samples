#define DEBUG

#include "util/log.h"
#include "cpp_features/structured_binding.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  struct_binding::sample();
  return 0;
}
