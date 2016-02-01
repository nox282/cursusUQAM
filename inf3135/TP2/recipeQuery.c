#include "recipeQuery.h"
#include "node.h"
#include "chainedList.h"
#include "fileR.h"

/*
 * Asks for user search query
 * Return : user input.
 * */
char *userInput();
/*
 * Processes user search Query
 * Parameter : user input;
 *             Categoryies list.
 * Returns : -1 if the input query is invalid
 * */
int processQuery(char*, category_t*);
/*
 * Search through the list and display the result
 * Parameter : category to be found;
 *             keyword to be found;
 *             Categories list.
 * */
void find(char*, char*, category_t*);
/*
 * Search through a recipe sub list and display the result
 * Parameter : keyword to be found;
 *             recipes list.
 * Return : -1 if allocation fails.
 * */
int findRecipe(char*, recipe_t*);
void displayCategory(category_t*);//Displays a entire Category.
void displayResult(recipe_t**, size_t);//Displays a successful recipe query;
char *toLowerCase(char*);//returns a lower case copy of a string.

int main (int argc, char **argv)
{
  if(argv[1] == NULL)
  {  
    printf("You need to specify a file path.\n");
    return EXIT_FAILURE; 
  }
  else
  {
    category_t *head = readFile(argv[1]);
    if(head == NULL)
    {
      printf("No such file.\n");
      return EXIT_FAILURE;
    }
    head = sortBook(head);
    category_t *current = head;
    char *input = NULL;
    while (strcmp(input = userInput(),"\n") != 0)
    {
      if(processQuery(input, head) == -1)
        printf("Invalid query.\n");
    }
    free(input);
    while(current != NULL)
    {
      destroyCategory(current);
      current = current->next;
    }
    printf("Goodbye.\n");
  }
  return EXIT_SUCCESS;
}


char *userInput()
{
  char *input = NULL, *tmp = NULL, ch = 0;
  size_t size = 1, index =  0;
  input = malloc(sizeof(char));
  if(input == NULL)
    return NULL;
  printf("Please enter your query : \n");
  while(ch != '\n')
  {
    ch = fgetc(stdin);
    if(size-1 <= index)
    {
      size += 10;
      tmp = realloc(input, size);
      if(tmp == NULL)
      {
        free(input);
        return NULL;  
      }
      else input = tmp;
    }
    input[index++] = ch;
    input[index] = '\0';
  }
  return input;
}

int processQuery(char *input, category_t *head)
{
  char *category = NULL, *keyword = NULL, *token, s[2] = " ";
  if(strcmp(input, "") == 0) return -1;

  token = strtok(input, s);
  cleanString(token);
  category = strdup(token);
  token = strtok(NULL, s);
  while (token != NULL)
  {
    cleanString(token);
    if(strcmp(token, "") != 0)
    {
      if(keyword == NULL)
        keyword = strdup(token);
      else
      {
        free(category);
        free(keyword);
        return -1;
      }
    }
    token = strtok(NULL, s);
  }
  if(strcmp(category, "") != 0) find(category, keyword, head);
  if(keyword != NULL) free(keyword);
  free(category);
  return 0;
}

void find(char *category, char *keyword, category_t *head)
{
  category_t *current = head;
  char *tmp = toLowerCase(category);
  current = listContains(tmp, head);
  if(current != NULL)
  {
    if(keyword == NULL)
      displayCategory(current);
    else
      if(findRecipe(keyword, current->head) == -1) printf("Unexpected Error\n");
  }
  else
    printf("Sorry, This category does not exists.\n");
}

int findRecipe(char *keyword, recipe_t *head)
{
  recipe_t *currentRec = NULL;
  recipe_t **result = NULL, **tmpResult = NULL;
  size_t size = 1, index = 0;
  char *tmpKey, *tmpRec;
  result = malloc(size*sizeof(void*));
  if(result == NULL) return -1;
  result[0] = NULL;
  tmpKey = toLowerCase(keyword);
  currentRec = head;
  while(currentRec != NULL)
  {
    tmpRec = toLowerCase(currentRec->title);
    if(strstr(tmpRec, tmpKey) != NULL)
    {
      if(size <= index)
      {
        size++;
        tmpResult = realloc(result, size*sizeof(void*));
        if(tmpResult == NULL)
        {
          free(tmpRec);
          free(tmpKey);
          return -1;
        }
        else result = tmpResult;
      }
      result[index++] = currentRec;
    }
    currentRec = currentRec->next;
    free(tmpRec);
  }
  displayResult(result, size);
  free(tmpKey);
  return 0;
}



void displayCategory(category_t *category)
{
  recipe_t *current = category->head;
  while (current->next != NULL)
  {
    printf("\t%s,\n ", current->title);
    current = current->next;
  }
  printf("\t%s.\n", current->title);
}

void displayResult(recipe_t **result, size_t size)
{
  if(result[0] == NULL)
    printf("No results for this query.\n");
  else
  {
    int i = 0;
    for(i = 0; i < size; i++)
      printf("\t%s\n", result[i]->title);
  }
  free(result);
}

void cleanString(char *string)
{
  int i = (int)strlen(string)-1;
  while ((string[i] < 'a' || string[i] > 'z') &&
          (string[i] < 'A' || string[i] > 'Z') && i>= 0)
    i--;
  string[(i+1)] = '\0';
}

char *toLowerCase(char *string)
{
  int i = 0;
  char *ret = malloc(strlen(string)*sizeof(char));
  if(ret == NULL)
    return NULL;
  for(i = 0; i < strlen(string); i++)
  {
    if(string[i] > 'A' && string[i] < 'Z')
      ret[i] = string[i]+32;
    else ret[i] = string[i];
  }
  ret[i] = '\0';
  return ret;
}
