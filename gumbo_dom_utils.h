#ifndef GUMBO_DOM_UTILS_H_
#define GUMBO_DOM_UTILS_H_

#include <string>
#include <map>
#include <regex>

#include "utils.h"

namespace gumbo_dom_utils {

  void encode_text_content_html(std::string s, std::string& encoded_string);
  void encode_html(std::string s, std::string& encoded_string);

}

#endif  // GUMBO_DOM_UTILS_H_
