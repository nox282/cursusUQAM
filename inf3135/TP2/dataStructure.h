#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "chainedList.h"
#include "node.h"
#include "recipeQuery.h"
/*
 * Insert the data into the data structure.
 * Parameter : an array of data
 * */
void dataHandling(char*, char*, category_t*); 

/*
 * Processes a line to update the data structure.
 * Parameter : the line read.
 * Returns : an array that contains the data to store.           
 * */
void processLine(char*, category_t*);

#endif
