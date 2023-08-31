#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>

#include "cpp_features/common.h"
#include "cpp_features/string.h"
#include "util/log.h"

BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");

  std::string str = "12345";
  util::debug("[main]:... str = {}\n", str);
  common::reverseString(str);
  util::debug("[main]:... str = {}\n", str);
  util::debug("[main]:... end\n");
}
