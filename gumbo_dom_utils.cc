#include "gumbo_dom_utils.h"
#include <iostream>


// TODO: Bundle all routines into a class


std::map<char, std::string> reverseEntityTable;

void initialize_entity_map() {
  std::map<std::string, char> entityTable;
  entityTable["lt"] = '<';
  entityTable["gt"] = '>';
  entityTable["amp"] = '&';
  entityTable["quot"] = '"';
  entityTable["apos"] = '\'';
}

void initialize_reverse_entity_map(std::map<char, std::string> &reverseEntityTable) {
  reverseEntityTable['<'] = "&lt;";
  reverseEntityTable['>'] = "&gt;";
  reverseEntityTable['&'] = "&amp;";
  reverseEntityTable['"'] = "&quot;";
  reverseEntityTable['\''] = "&apos;";
}

void encode_content_replace_callback(std::string match, std::string& replacement) {
  initialize_reverse_entity_map(reverseEntityTable);
  replacement = reverseEntityTable[match[0]];  
}

void gumbo_dom_utils::encode_text_content_html(std::string s, std::string& encoded_string) {
  utils::string_replace_regex(s, "[&<>]", encode_content_replace_callback, encoded_string);
}

void gumbo_dom_utils::encode_html(std::string s, std::string& encoded_string) {
  utils::string_replace_regex(s, "[&<>\"']", encode_content_replace_callback, encoded_string);
}
