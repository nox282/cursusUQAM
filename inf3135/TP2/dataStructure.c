#include "dataStructure.h"

void cleanString(char*);//removes all non-alpha character from the end of a string (lower case).

void dataHandling(char *recipe, char *category, category_t *head)
{
  printf("coucou\n");
  printf("%s %s \n", category, recipe);
  category_t *current = head;
  recipe_t* recipeNode = newRecipe(recipe, category, NULL);

  if(head == NULL)
  {
    head = newCategory(category, recipeNode, NULL); 
  printf("head == null\n");
  }
  else if((current = listContains(category, head)) != NULL)
  {
    stackRecipe(recipeNode, current);
  printf("list exists\n");
  }
  else
  {
    stackCategory(newCategory(category, recipeNode, NULL), head);
  printf("new cat\n");
  }
}


void processLine(char *line, category_t *head)
{ 
  char *recipe, *category, *token, s[2] = "[";
  if(strcmp(line, "") == 0)
    return;    
  
  token = strtok(line, s);
  recipe = strdup(token);
  token = strtok(NULL, s);
  while(token != NULL)
  {
    cleanString(token);
    category = strdup(token);
    dataHandling(recipe, category, head);
    if(head == NULL)
      printf("ok.\n");
    token = strtok(NULL, s);
  }
  free(category);
  free(recipe);
}

void cleanString(char *string)
{
  int i = (int)strlen(string)-1;
  while (string[i] < 'a' || string[i] > 'z')
    i--;
  string[(i+1)] = '\0';
}
