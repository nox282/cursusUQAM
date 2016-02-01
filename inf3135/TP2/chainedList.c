#include "chainedList.h"

void addRecipe(recipe_t *current, recipe_t *next)
{
  next->next = current->next;
  current->next = next;
}

void stackRecipe(recipe_t *recipe, category_t *category)
{
  recipe_t *current = category->head;
  while(current->next != NULL)
    current = current->next;
  
  current->next = recipe;
}

recipe_t *removeRecipe(category_t *category, char *rm)
{
  recipe_t *head = category->head;
  recipe_t *current = head, *previous = NULL, *ret = NULL;
  while(strcmp(current->title, rm) != 0)
  {
    previous = current;
    current = current->next;
  }
  ret = current;
  if(strcmp(ret->title, head->title) == 0)
    category->head = current->next;
  else
    previous->next = current->next; 
  return ret;
}

void addCategory(category_t *current, category_t *next)
{
  next->next = current->next;
  current->next = next;
}

void stackCategory(category_t *category, category_t *head)
{
  while(head->next != NULL)
    head = head->next;
  head->next = category;
}

category_t *removeCategory(category_t *head, char *rm)
{
  category_t *current = head, *previous = NULL, *ret = NULL;
  while(strcmp(current->title, rm) != 0)
  {
    previous = current;
    current = current->next;
  }
  ret = current;
  previous->next = current->next; 
  return ret;
}

category_t *listContains(char *title, category_t *current)
{
  if(current == NULL)
    return NULL;
  if(strcmp(title, current->title)==0)
    return current;
  else
    return listContains(title, current->next);
}
