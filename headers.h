#ifndef HEADERS_H
#define HEADERS_H
#define PROGRAM_FILE_SIZE_LIMIT 1024 * 1024

#include <stdio.h>

const char* read_file(const char* filename, const char* buffer);
const char* clean_html(const char* html);

#endif
