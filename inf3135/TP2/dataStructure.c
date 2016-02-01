#include "dataStructure.h"

/*
 * Sorts the category list alphabetically
 * Parameter : Head of the list to be sorted;
 *             Size of the list.
 * Return : the head of the sorted list
 * */
category_t* sortCategory(category_t*, int);
/*
 * Sorts the recipes of a specific category alphabetically
 * Parameter : Category it belongs;
 *             Size of the list.
 * Returns : the category with the sublist sorted.
 * */
category_t *sortRecipe(category_t*, int);

category_t *dataHandling(char *recipe, char *category, category_t *head)
{
  category_t *current = head;
  recipe_t* recipeNode = newRecipe(recipe, category, NULL);

  if(head == NULL)
  {
    head = newCategory(category, recipeNode, NULL); 
  } 
  else if(listContains(category, head) != NULL)
  {
    current = listContains(category, head);
    stackRecipe(recipeNode, current);
  }
  else
  {
    stackCategory(newCategory(category, recipeNode, NULL), head);
  }
  return head;
}


category_t *processLine(char *line, category_t *head)
{ 
  char *recipe = NULL, *token = NULL, s[2] = "[";
  if(strcmp(line, "") == 0)
    return head;
  
  token = strtok(line, s);
  cleanString(token);
  recipe = strdup(token);
  token = strtok(NULL, s);
  while(token != NULL)
  {
    cleanString(token);
    head = dataHandling(recipe, token, head);
    token = strtok(NULL, s);
  }
  free(recipe);
  return head;
}

category_t *sortBook(category_t *head)
{
  category_t *current = head;
  recipe_t *currentRec = NULL;
  int count = 0;
  while (current != NULL)
  {
    current = current->next;
    count++;
  }
  head = sortCategory(head, count); 
  current = head;
  while (current != NULL)
  {
    count = 0;
    currentRec = current->head;
    while (currentRec != NULL)
    {
      currentRec = currentRec->next;
      count++;
    }
    current = sortRecipe(current, count);
    current = current->next;
  }
  return head;
}
category_t *sortCategory(category_t *head, int size)
{
  if(size < 1)
    return head;
  int i;
  category_t *current = head, *temp = current;
  for(i = 0; i < size; i++)
  {
    if(strcmp(current->title, temp->title) > 0)
      temp = current;
    if(current->next != NULL)
      current = current->next;
  }
  if(strcmp(current->title, temp->title) > 0)
    temp = current;
  if(strcmp(temp->title, current->title) != 0)
  {
    if(strcmp(temp->title, head->title) == 0)
      head = temp->next;
    else 
      temp = removeCategory(head, temp->title); 
    addCategory(current, temp);
  }
  return sortCategory(head, size-1);
}

category_t *sortRecipe(category_t *category, int size)
{
  int i;
  recipe_t *current = category->head, *temp = current;
  if(size < 1)
    return category;
  for(i = 0; i < size; i++)
  {
    if(strcmp(current->title, temp->title) > 0)
      temp = current;
    if(current->next != NULL)
      current = current->next;
  }
  if(strcmp(current->title, temp->title) > 0)
    temp = current;
  if(strcmp(temp->title, current->title) != 0)
  {
    temp = removeRecipe(category, temp->title); 
    addRecipe(current, temp);
  }
  return sortRecipe(category, size-1);
}
