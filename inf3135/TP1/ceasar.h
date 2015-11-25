#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
/*
 * Returns a file's size.
 * If it doesn't exists, creates it.
 * */
int getFileSize (char *fileName);
