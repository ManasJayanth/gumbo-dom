#include "utils.h"

const char* utils::read_file(const char* filename, char* buffer) {
  std::fstream fin;
  fin.open(filename);
  fin.read(reinterpret_cast<char*>(buffer), PROGRAM_FILE_SIZE_LIMIT);
  return buffer;
}

std::string utils::string_replace_regex(std::string buffer,
                                        std::string pattern,
                                        std::string (*callback)(std::string)) {
  std::regex e(pattern);

  std::string result;


  const std::sregex_token_iterator end;

  int pos;
  std::string search = buffer;
  for (std::sregex_token_iterator i(buffer.cbegin(), buffer.cend(), e);
        i != end;
       ++i) {
     std::string matchStr = *i;
     std::string replacingSubstring = callback(matchStr);

     pos = search.find(matchStr);
     result += search.substr(0, pos);

     result += replacingSubstring;
     search.erase(0, pos + 1);
  }

  result += search;

  return result;
}
