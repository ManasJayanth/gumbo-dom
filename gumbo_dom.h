#ifndef GUMBO_DOM_H_
#define GUMBO_DOM_H_

#include <string>
#include "gumbo.h"

class GumboDOM {
 public:
  GumboDOM();
  explicit GumboDOM(const char* html_string);
  const char* getString(void);
  void initialize_gumbo_dom(void);

 private:
  std::string html;
};

#endif  // GUMBO_DOM_H_
