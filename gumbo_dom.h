#ifndef HEADERS_H
#define HEADERS_H

#include <string>
#include "gumbo.h"

class GumboDOM {
 private:
  std::string html;

 public:
  GumboDOM();
  GumboDOM(const char* html_string);
  const char* getString(void);
};

#endif

