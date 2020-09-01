#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

class MyClass {
 public:
  bool jau() { return true; }
};

BOOST_AUTO_TEST_CASE(my_test) {
  MyClass mc;

  BOOST_CHECK(mc.jau());
}