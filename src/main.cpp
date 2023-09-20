#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>
#include <memory>

#include "cpp_features/lock_free.h"
#include "util/log.h"
#include <queue>


BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");

  lock_free::sample();
  /*
  std::queue<int> queue;
  auto t = queue.front();
  */
  util::debug("[main]:... end\n");
}
