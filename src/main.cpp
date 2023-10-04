#define BOOST_TEST_MODULE MainSampleCppTest

#include <array>
#include <boost/test/included/unit_test.hpp>
#include <cassert>
#include <memory>
#include <queue>
#include <unordered_set>

#include "cpp_features/raii.h"
#include "util/log.h"


BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");

  /*int x = 27;

  auto a1 = x;
  const auto &a2 = x;
  auto &&a3 = a2;
  auto &&a4 = x;
  auto &&a5 = 27;
  auto a6 = {27};
  auto a7{27};

  const char *const str = "";
  auto a8 = str;

  decltype(a1) d1;
  decltype(a4) d2 = d1;
  decltype((a1)) d3 = d2;

  decltype(auto) d4 = a2;
  auto f = f1();*/

  util::debug("[main]:... end\n");
}
