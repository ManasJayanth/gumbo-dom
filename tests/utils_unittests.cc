#include "../utils.h"
#include "gtest/gtest.h"
#include <fstream>

using namespace std;

TEST(ReadFileTest, ReadsFiles) {
  char buf[PROGRAM_FILE_SIZE_LIMIT],
    test_string[] = "Foo bar baz\n",
    test_file_name[] = "testFile.txt";

  // fstream fout;
  // fout.open(test_file_name);
  // if (fout.is_open()) {
  //   fout << test_string;
  //   fout.close();
  // } else {
  //   cout << "Unable to open file";
  // }

  read_file(test_file_name, buf);
  EXPECT_STREQ(test_string, buf);
}
