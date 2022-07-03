#define BOOST_TEST_MODULE SolutionTest

#include "../src/Formula.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(createMask) {
    BOOST_CHECK_EQUAL(Formula::bla(2), 4);
}
