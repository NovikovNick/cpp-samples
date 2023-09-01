#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>

#include "cpp_features/common.h"
#include "cpp_features/operators.h"
#include "util/log.h"


BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");
  auto x = std::make_unique<oper::A>(1);
  oper::A a{1};
  oper::A b{2};

  oper::A res = a + b + a;


  std::cout << res << std::endl;



  util::debug("[main]:... end\n");
}
