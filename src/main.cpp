#define DEBUG

#include "util/log.h"
#include "cpp_features/attributes.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  attributes::sample();
  return 0;
}
