#ifndef UTILS_H
#define UTILS_H
#define PROGRAM_FILE_SIZE_LIMIT 1024 * 1024

#include <fstream>
#include <cstring>

// Unix headers. See supported platforms in the ReadMe
#include <sys/types.h>
#include <regex.h>

namespace utils {

  const char* read_file(const char* filename, const char* buffer);
  void string_replace_regex(std::string input_string,
                            std::string pattern,
                            std::string replacing_substring,
                            std::string& result_string);

  void string_replace_regex(std::string buffer,
                            std::string pattern,
                            void (*replacement_callback)(std::string, std::string&),
                            std::string& result_string);
}

#endif
