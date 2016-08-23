#include "gumbo_dom_utils.h"

// TODO(prometheansacrifice): Bundle all routines into a class

std::map<std::string, std::string> reverseEntityTable;
std::map<std::string, std::string> entityTable;

// TODO(prometheansacrifice): Use std::map<std::string, char) instead of
// string to string
void initialize_entity_map(std::map<std::string, std::string> &entityTable) {
  entityTable["&lt;"] = "<";
  entityTable["&gt;"] = ">";
  entityTable["&amp;"] = "&";
  entityTable["&quot;"] = "\"";
  entityTable["&apos;"] = "'";
}

void initialize_reverse_entity_map(std::map<std::string,
                                   std::string> &reverseEntityTable) {
  reverseEntityTable["<"] = "&lt;";
  reverseEntityTable[">"] = "&gt;";
  reverseEntityTable["&"] = "&amp;";
  reverseEntityTable["\""] = "&quot;";
  reverseEntityTable["'"] = "&apos;";
}

std::string encode_content_replace_callback(std::string match) {
  initialize_reverse_entity_map(reverseEntityTable);
  return reverseEntityTable[match];
}

// TODO(promtheansacrifice): Enforce "runtime/references" (Is this a non-const
// reference? If so, make const or use a pointer:...)
void gumbo_dom_utils::encode_text_content_html(std::string s,
                                               std::string& encoded_string) {
  encoded_string = utils::string_replace_regex(s,
                                               "[&<>]",
                                               encode_content_replace_callback);
}

void gumbo_dom_utils::encode_html(std::string s, std::string& encoded_string) {
  encoded_string = utils::string_replace_regex(s, "[&<>\"']",
                                               encode_content_replace_callback);
}

std::string decode_content_replace_callback(std::string match) {
  initialize_entity_map(entityTable);
  return entityTable[match];
}

void gumbo_dom_utils::decode_html(std::string s, std::string& decoded_string) {
  decoded_string = utils::string_replace_regex(s, "&(quot|amp|apos|lt|gt);",
                                               decode_content_replace_callback);
}
