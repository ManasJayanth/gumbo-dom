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
