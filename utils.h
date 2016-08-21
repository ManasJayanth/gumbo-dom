#ifndef UTILS_H_
#define UTILS_H_
#define PROGRAM_FILE_SIZE_LIMIT 1024 * 1024

#include <fstream>
#include <string>
#include <regex>

namespace utils {

  const char* read_file(const char* filename, char* buffer);

  std::string string_replace_regex(std::string buffer,
                                   std::string pattern,
                                   std::string (*callback)(std::string));
}

#endif  // UTILS_H_
