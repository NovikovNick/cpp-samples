#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>

#include "cpp_features/common.h"
#include "cpp_features/separate_duplicate_methods.h"
#include "util/log.h"

BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");

  separate_duplicate_methods::sample();

  util::debug("[main]:... end\n");
}
