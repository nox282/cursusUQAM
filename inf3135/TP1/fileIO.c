#include "fileIO.h"

void initCEASAR_str(char *fileName, char *mode, CEASAR_str_t *cstr)
{
  int ret;
  FILE *file = fopen (fileName, mode);
  cstr->file = file;
  read(cstr);
}

int closeCeasar (CEASAR_str_t *cstr)
{
  int ret = fclose(cstr->file);
  destCEASAR_str(cstr);
  return ret;
}

size_t write (char *input, CEASAR_str_t *cstr)
{
  size_t ret = fwrite(input, sizeof(char), cstr->fileSize, cstr->file);
  read(cstr);
  return ret;
}

size_t read (CEASAR_str_t *cstr)
{
  return fread(cstr->string, cstr->fileSize, 1, cstr->file);
}
