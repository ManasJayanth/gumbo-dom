#ifndef GUMBO_DOM_H
#define GUMBO_DOM_H

#include <string>
#include "gumbo.h"

class GumboDOM {
 public:
  GumboDOM();
  GumboDOM(const char* html_string);
  const char* getString(void);
  void initialize_gumbo_dom(void);

 private:
  std::string html;
};

#endif

