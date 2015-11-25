#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H

#include "recipeQuery.h"
#include "node.h"
/*
 * Adds a recipe node to the chained list at specified place.
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
 * Parameter : current node;
 *             node to be removed.
 * Returns : The removed recipe.
 * */
recipe_t *removeRecipe(recipe_t*, recipe_t*);
/*
 * Returns the next node from the recipe chained list.
 * Parameter : current node.
 * */
void nextRec(recipe_t*);
/*
 * Returns the head of the recipe chained list.
 * Parameter : current node from the recipes;
 *             head of the category chained list.
 * */
void reinitRecipe(recipe_t*, category_t*);

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
 * Parameter : current node;
 *             node to be removed.
 * */
category_t *removeCategory(category_t*, category_t*);
/*
 * Returns the next node from the category chained list.
 * Parameter : current node.
 * */
void nextCat(category_t*);
/*
 * Returns wether or not a category exists
 * Parameter : category name.
 * Returns : the category, NULL if not found.
 * */
category_t *listContains(char*, category_t*);

#endif
