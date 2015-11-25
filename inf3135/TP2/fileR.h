#ifndef FILER_H
#define FILER_H

#include "recipeQuery.h"
#include "node.h"
#include "chainedList.h"
#include "dataStructure.h"

/*
 * Opens a file and properly set up the reading to generate the data structure.
 * Parameter : file's name;
 * Returns : head of the category chained list.
 * */
category_t *readFile(char*);
/*
 * Reads a line from the file
 * Parameter : file;
 *             string in wich the line will be stored.
 * Returns : exit status.
 * */
char *readLine(FILE*);

#endif
