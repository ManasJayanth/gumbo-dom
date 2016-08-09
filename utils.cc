#include "utils.h"
#include  <fstream>

const char* read_file(const char* filename, const char* buffer) {
  // FILE *fptr = fopen(filename, "r");
  // fread((void *)buffer, sizeof(char), PROGRAM_FILE_SIZE_LIMIT, fptr);
  // fclose(fptr);
  std::fstream fin;
  fin.open(filename);
  fin.read((char*)buffer, PROGRAM_FILE_SIZE_LIMIT);
  return buffer;
}
