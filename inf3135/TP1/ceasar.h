#ifndef CEASAR_H
#define CEASAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256
#define ALPHABET 26
#define MAX_BUFFER 50

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct
{
	char* string,
	FILE* file,
	int fileSize
} CEASAR_str;

#endif
