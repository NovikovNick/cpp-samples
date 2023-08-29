#include <cassert>

#include "cpp_features/common.h"
#include "cpp_features/oop.h"
#include "util/log.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  util::debug("[main]:... start\n");
  oop::sample();
  util::debug("[main]:... end\n");
  return 0;
}
