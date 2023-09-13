#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>

#include "cpp_features/cow.h"
#include "util/log.h"

BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");
  
  cow::sample();

  util::debug("[main]:... end\n");
}
