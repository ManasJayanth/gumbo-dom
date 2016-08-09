#include "test_utils.h"
#include "gumbo_dom.h"

void gumbo_dom_tests(void) {
  GumboDOM gumboDOM = GumboDOM("testing string");
  std::cout << gumboDOM.getString();
}

