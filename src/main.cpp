#define BOOST_TEST_MODULE MainSampleCppTest

#include <facade.h>

#include <boost/test/included/unit_test.hpp>
#include <cassert>

#include "cpp_features/crtp.h"
#include "util/log.h"


BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");
  
  crtp::sample();

  util::debug("[main]:... end\n");
}
