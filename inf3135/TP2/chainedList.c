#include "chainedList.h"

void addRecipe(recipe_t *current, recipe_t *next)
{
  next->next = current->next;
  current->next = next;
}

void stackRecipe(recipe_t *recipe, category_t *category)
{
  recipe_t* current = category->head;
  while(current->next != NULL)
    nextRec(current);
  
  current->next = recipe;
}

recipe_t *removeRecipe(recipe_t *current, recipe_t *rm)
{
  current->next = rm->next;
  return rm;
}

void nextRec(recipe_t *recipe)
{
  recipe = recipe->next;
}

void reinitRecipe(recipe_t *current, category_t *head)
{
  while(strcmp(current->category, head->title) != 0)
  {
    nextCat(head);
  }
  current = head->head;
}

void addCategory(category_t *current, category_t *next)
{
  next->next = current->next;
  current->next = next;
}

void stackCategory(category_t *category, category_t *head)
{
  while(head->next != NULL)
    nextCat(head);
  
  head->next = category;
}

category_t *removeCategory(category_t *current, category_t *rm)
{
  current->next = rm->next;
  return rm;
}

void nextCat(category_t *category)
{
  category = category->next;
}

category_t *listContains(char* title, category_t *head)
{
  while(head != NULL)
  {
    if(strcmp(title, head->title)==0)
      return head;
    nextCat(head);
  }
  return NULL;
}
