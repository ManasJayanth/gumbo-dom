#include "gtest/gtest.h"
#include "test_utils.h"


int main() {
  TestUtils testUtils = TestUtils();
  testUtils.add_test(gumbo_dom_tests);
  testUtils.run();
}
