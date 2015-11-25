#ifndef NODE_H
#define NODE_H

#include "recipeQuery.h" 
/* 
 * Recipe node for the sub chained list of recipes. 
 * */ 
typedef struct recipe recipe_t;                            

struct recipe
{ 
  char *title; 
  char *category;
  recipe_t *next;
};
/*
 * Properly creates a new recipe node.
 * Parameter : title;
 *             category;
 *             next node.
 * */
recipe_t *newRecipe (char*, char*, recipe_t*);
/*
 * Properly destroys a recipe node.
 * Parameter : node to destroy.
 * */
void destroyRecipe (recipe_t*);

/*
 * Category node for the main chained list of categories.
 * */
typedef struct category category_t;

struct category 
{ 
  char *title; 
  recipe_t *head;
  category_t *next;
}; 
/* 
 * Properly creates a new category node.
 * Parameter : title;
 *             head of the recipe list assiociated;
 *             next node.
 * */ 
category_t *newCategory (char*, recipe_t*, category_t*); 
/*
 * Properly destroys a category node and its sub chained list of recipes
 * Parameter : category
 * */
void destroyCategory(category_t*);

#endif
