#include "headers.h"
#include <iostream>
#include <fstream>

int main() {
  // clean_html(buf);



  char buf[PROGRAM_FILE_SIZE_LIMIT];

  read_file("input.html", buf);

  std::cout << buf;

  return 0;
}


// // writing on a text file
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main () {
  
//   return 0;
// }
