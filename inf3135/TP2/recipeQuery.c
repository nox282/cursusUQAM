#include "recipeQuery.h"
#include "node.h"
#include "chainedList.h"
#include "fileR.h"

void displayCategory(category_t*);

int main (int argc, char **argv)
{
  category_t *head = readFile(argv[1]);
  category_t *current = head;
  while(current != NULL)
  {
    displayCategory(current);
    nextCat(current);
  }
  return 0;
}


void displayCategory(category_t *category)
{
  recipe_t *current = NULL;
  reinitRecipe(current, category);
  printf("%s : ", category->title);
  while (current->next != NULL)
  {
    printf("%s, ", current->title);
    nextRec(current);
  }
  printf("%s.\n", current->title);
}
