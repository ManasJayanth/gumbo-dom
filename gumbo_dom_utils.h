#ifndef GUMBO_DOM_UTILS_H
#define GUMBO_DOM_UTILS_H

#include <string>
#include <map>
#include "utils.h"

namespace gumbo_dom_utils {

  void encode_text_content_html(std::string s, std::string& encoded_string);
  void encode_html(std::string s, std::string& encoded_string);
}

#endif