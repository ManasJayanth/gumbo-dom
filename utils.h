#ifndef UTILS_H
#define UTILS_H
#define PROGRAM_FILE_SIZE_LIMIT 1024 * 1024

#include <fstream>
#include <string>
#include <regex>

namespace utils {

  const char* read_file(const char* filename, const char* buffer);

  std::string string_replace_regex(std::string buffer,
                                   std::string pattern,
                                   std::string (*callback)(std::string));
}

#endif
