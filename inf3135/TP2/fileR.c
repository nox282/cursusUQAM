#include "fileR.h"

category_t *readFile(char *fileName)
{
  char *line;
  category_t* head = NULL;
  FILE *file = fopen(fileName, "r"); 
  if(file == NULL)
    return NULL;
  
  while (feof(file) == 0)
  {
    line = readLine(file);
    if (line != NULL)
      head = processLine(line, head);
    else
      printf("Unable to read line from file.\n");
    free(line);
  }
  fclose(file);
  return head;
}

char *readLine(FILE *file)
{
  char *line, *tmp = NULL;
  int ch = 0;
  size_t index = 0, size = 1;
  line = malloc(sizeof(char));
  if(line == NULL) return NULL;
  while(ch != -1)
  {
    ch = fgetc(file);
    if(ch == '\n' || feof(file) != 0) ch = -1;
    else
    {
      if(size-1 <= index)
      {
        size += 10;
        tmp = realloc(line, size);
        if(tmp == NULL) ch = -1;
        else line = tmp;
      } 
      if(ch != -1)
      {
        line[index++] = ch;
        line[index] = '\0';
      }
    }
  }
  return line;
}
