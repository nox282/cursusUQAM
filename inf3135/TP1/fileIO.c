#include "fileIO.h"

CEASAR_str* openFile (char* path, char option)
{
	CEASAR_str *ret;
	int fileSize;

	*ret.file = fopen(path, option+'b');
	
	if (*ret.file = NULL)
		*ret = NULL;
	else
	{
		*ret.fileSize = getFileSize(*ret.file);
		*ret.string = (char*) malloc(*ret.filesize * sizeof(char));
	}
	return ret;
}

int closeFile (CEASAR_str *cstr)
{
	free(*cstr.string);
	return fclose (*cstr.file);
}

int write (char* input, CEASAR_str *cstr)
{
	*cstr.string = input;
	return fprintf(*cstr.file, *cstr.string);
}

char* read (CEASAR_str *cstr) {
	char string[*cstr.filesize];
	while (fgets(string, *cstr.filesize, *cstr.file) != EOF)
	{
		*cstr.string += string;
	}
	return *cstr.string;
}


int getFileSize(FILE* file)
{
	int ret;
	fseek(file, 0L, SEEK_END);
	ret = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return ret;
}
