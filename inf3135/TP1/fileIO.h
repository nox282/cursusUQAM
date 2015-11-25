#include "ceasar.h"

CEASAR_str openFile (char* path, char option);
int closeFile (CEASAR_str cstr)
bool write (char* input, FILE* file);
char* read (FILE* file);
int getFileSize(FILE* file);
