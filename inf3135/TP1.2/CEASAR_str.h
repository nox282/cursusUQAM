#ifndef CEASAR_STR_H
#define CEASAR_STR_H

#include "ceasar.h"
/*
 * CEASAR_str links a file to a string.
 * */
struct CEASAR_str
{
  char *string;
  FILE *file;
  long fileSize;
};

typedef struct CEASAR_str CEASAR_str_t;

/*
 * Properly creates a new CEASAR_str by allocating memory.
 * */
CEASAR_str_t *newCEASAR_str(long size);
/*
 * Properly destroys a CEASAR_str by freeing all allocated
 * memory.
 * */
void destCEASAR_str(CEASAR_str_t *cstr);
#endif
