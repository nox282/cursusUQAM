#ifndef FILEIO_H
#define FILEIO_H

#include "CEASAR_str.h"
#include "ceasar.h"
/*
 * Initializes a CEASAR_str with a file.
 * */
void initCEASAR_str(char *fileName, char *mode, CEASAR_str_t *cstr);
/*
 * Properly closes the file and the struct it is attached to.
 * */
int closeCeasar (CEASAR_str_t *cstr);
/*
 * Writes a char* into the file it is attached to.
 * */
size_t write (char* input, CEASAR_str_t *cstr);
/*
 * Writes a file's content into the char* it is attached to.
 * */
size_t read (CEASAR_str_t *cstr);
#endif
