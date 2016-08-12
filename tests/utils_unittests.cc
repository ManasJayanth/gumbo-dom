#include "../utils.h"
#include "gtest/gtest.h"
#include <fstream>

using namespace std;

TEST(ReadFileTest, ReadsFiles) {
  char buf[PROGRAM_FILE_SIZE_LIMIT],
    test_string[] = "Foo bar baz\n",
    test_file_name[] = "testFile.txt";

  utils::read_file(test_file_name, buf);
  ASSERT_STREQ(test_string, buf);
}

TEST(StringReplace, RegexReplacesString) {
  std::string test_string = "Alice is going to the market";
  std::string pattern = "Alice";
  std::string replacement_substring = "Bob";
  std::string result_string = "";
  utils::string_replace_regex(test_string, pattern,
                        replacement_substring, result_string);
  std::string expected_string = "Bob is going to the market";
  ASSERT_STREQ(result_string.c_str(), expected_string.c_str());
}


void replacement_callback(std::string match, std::string& replacement) {
  replacement = match + " Marley";
}

TEST(StringReplace, RegexReplacesStringViaCallback) {  
  std::string test_string = "Bob is going to the market";
  std::string pattern = "Bob";
  std::string replacement_substring;
  std::string result_string = "";
  utils::string_replace_regex(test_string, pattern,
                        replacement_callback, result_string);
  std::string expected_string = "Bob Marley is going to the market";
  ASSERT_STREQ(result_string.c_str(), expected_string.c_str());
}
