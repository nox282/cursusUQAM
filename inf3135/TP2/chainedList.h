#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H

#include "recipeQuery.h"
#include "node.h"
/*
 * Adds a recipe node to the chained list at a specified place.
 * Parameter : current node;
 *             node to be added.
 * */
void addRecipe(recipe_t*, recipe_t*);
/*
 * Adds a recipe node at the end of the chained list.
 * Parameter : node to be added;
 *             the category it belongs.
 * */
void stackRecipe(recipe_t*, category_t*);
/*
 * Removes a recipe node from the chained list.
 * Parameter : head of the list;
 *             node to be removed.
 * Returns : The removed recipe.
 * */
recipe_t *removeRecipe(category_t*, char*);

/*
 * Adds a category node to the chained list.
 * Parameter : current node;
 *             node to be added.
 * */
void addCategory(category_t*, category_t*);
/*
 * Adds a category node at the end of the chained list.
 * Parameter : node to be added;
 *             head category list.
 * */
void stackCategory(category_t*, category_t*);
/*
 * Removes a category node from the chained list.
 * Parameter : Head of the list; 
 *             node to be removed.
 * Return : node removed.
 * */
category_t *removeCategory(category_t*, char*);
/*
 * Returns wether or not a category exists
 * Parameter : category name.
 * Returns : the category, NULL if not found.
 * */
category_t *listContains(char*, category_t*);

#endif
