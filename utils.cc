#include "utils.h"

#include <iostream>

const char* utils::read_file(const char* filename, const char* buffer) {
  std::fstream fin;
  fin.open(filename);
  fin.read((char*)buffer, PROGRAM_FILE_SIZE_LIMIT);
  return buffer;
}

void utils::string_replace_regex(std::string buffer,
                           std::string pattern,
                           std::string replacing_substring,
                           std::string& result_string) {

  regex_t re;
  regmatch_t pm;

  char *pattern_cstr = new char [pattern.length() + 1];
  std::strcpy (pattern_cstr, pattern.c_str());

  char *buffer_cstr = new char[buffer.length() + 1];
  std::strcpy (buffer_cstr, buffer.c_str());

  result_string = buffer;
  (void) regcomp (&re, pattern_cstr, REG_EXTENDED);
  int error = regexec (&re, &buffer_cstr[0], 1, &pm, 0);
  while (error == 0) {
    result_string.replace(pm.rm_so, pm.rm_eo - pm.rm_so, replacing_substring);
    error = regexec (&re, buffer_cstr + pm.rm_eo, 1, &pm, REG_NOTBOL);
  }

  // Clean up
  delete[] pattern_cstr;
  delete[] buffer_cstr;
}


void utils::string_replace_regex(std::string buffer,
                                 std::string pattern,
                                 void (*replacement_callback)(std::string, std::string&),
                                 std::string& result_string) {

  char *buffer_cstr = new char[buffer.length() + 1];
  std::strcpy(buffer_cstr, buffer.c_str());
  int buffer_cstr_len = buffer.length();

  char *pattern_cstr = new char[pattern.length() + 1];
  std::strcpy (pattern_cstr, pattern.c_str());

  regex_t re;
  regmatch_t pm[1];

  regcomp(&re, pattern_cstr, REG_EXTENDED);
  int search_start = 0;
  int regexec_status = regexec(&re, &buffer_cstr[0] + search_start, 1, pm, 0);

  while(regexec_status == 0) {
    int match_len = pm[0].rm_eo - pm[0].rm_so;

    char *matched_string = new char[match_len];
    memcpy(matched_string, &buffer_cstr[pm[0].rm_so + search_start], match_len);
    matched_string[match_len] = '\0';

    std::string replacing_substring;
    replacement_callback(std::string(matched_string), replacing_substring);
    delete[] matched_string;

    buffer_cstr_len += replacing_substring.length();
    char *new_buffer = new char[buffer_cstr_len + 1];

    memcpy(new_buffer, buffer_cstr, pm[0].rm_so + search_start + 1);
    memcpy(new_buffer + pm[0].rm_so + search_start, replacing_substring.c_str(), replacing_substring.length());
    memcpy(new_buffer + pm[0].rm_so + search_start + replacing_substring.length(), buffer_cstr + pm[0].rm_eo + search_start, buffer_cstr_len - (pm[0].rm_eo + search_start));
    new_buffer[buffer_cstr_len + 1] = '\0';

    delete[] buffer_cstr;
    buffer_cstr = new_buffer;

    search_start = search_start + pm[0].rm_eo;
    regexec_status = regexec(&re, &buffer_cstr[search_start], 1, pm, 0);
  }
  

  result_string = std::string(buffer_cstr);
  delete[] buffer_cstr;
  delete[] pattern_cstr;
}
