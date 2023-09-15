#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>

#include "cpp_features/exception_safety.h"
#include "util/log.h"


BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");
  
  exception_safety::sample();

  util::debug("[main]:... end\n");
}
