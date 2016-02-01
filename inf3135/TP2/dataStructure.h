#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "chainedList.h"
#include "node.h"
#include "recipeQuery.h"
/*
 * Inserts the data into the data structure.
 * Parameter : category name;
 *             recipe name;
 *             head of the category list.
 * Returns : the new head of the list.
 * */
category_t *dataHandling(char*, char*, category_t*); 
/*
 * Processes a line to update the data structure.
 * Parameter : the line read;
 *             head of the category list.
 * Returns : the new head of the list.           
 * */
category_t *processLine(char*, category_t*);
/*
 * Sorts the recipes data structure alphabetically
 * Parameter : Head of the list.
 * Return : New head of the list.
 * */
category_t *sortBook(category_t*);
#endif
