#include "test_utils.h"

void TestUtils::assert_test(bool actual, bool expected, const char* message) {
  std::cout << message;
  assert(actual == expected);
}

void TestUtils::add_test(void (*test)(void)) {
  this->tests.push_back(test);
}

void TestUtils::run(void) {
  for (std::list<fp>::iterator it=this->tests.begin(); it != this->tests.end(); ++it)
    (*it)();
}
