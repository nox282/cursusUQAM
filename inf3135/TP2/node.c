#include "node.h"

recipe_t *newRecipe (char *newTitle, char *newCat, recipe_t *newNext)
{
  recipe_t *ret = malloc(sizeof(recipe_t));
  
  if(ret == NULL)
    return NULL;
  
  ret->title = strdup(newTitle);
  ret->category = strdup(newCat);
  ret->next = newNext;

  return ret;
}

void destroyRecipe (recipe_t *recipe)
{
  free(recipe->title);
  free(recipe->category);
  free(recipe);
}

category_t *newCategory (char *newTitle, recipe_t *newHead, category_t *newNext)
{
  category_t *ret = malloc(sizeof(category_t));
  
  if(ret == NULL)
    return NULL;
 
  ret->title = strdup(newTitle);
  ret->head = newHead;
  ret->next = newNext;

  return ret;
  
}

void destroyCategory(category_t* category)
{
  recipe_t* current = category->head;
  recipe_t* temp;

  while(current != NULL)
  {
    temp = current->next;
    destroyRecipe(current);
    current = temp;
  }
  free(category->title);
  free(category);
}
