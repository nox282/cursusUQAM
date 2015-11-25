#include "fileR.h"

char addMoreSpace(char*, size_t, char);//adds a chunk of memory.

category_t *readFile(char *fileName)
{
  char *line;
  category_t* head = NULL;
  FILE *file = fopen(fileName, "r"); 
  if(file == NULL)
    return NULL;
  int j = 0; 
  //while (feof(file) == 0)
  while(j<10)
  {
    line = readLine(file);
    processLine(line, head);
    free(line);
    printf("read %d\n", j++);
  }
  fclose(file);
  return head;
}

char *readLine(FILE *file)
{
  char* line;
  int ch = 0, index = 0;
  size_t size = 0;
 
  line = malloc(sizeof(char));
  if (line == NULL)
    ch = -1; 
  
  while(ch != -1)
  {
    ch = fgetc(file);
    if(ch == '\n' || feof(file) != 0)
      ch = -1;
    else
    { 
      if(size <= index)
        ch = addMoreSpace(line, size+=10, ch);
      line[index++] = ch;
    }
  }
  return line;
}


char addMoreSpace(char *string, size_t size, char ch)
{
  char *tmp;
  tmp = realloc(string, size);
  if(tmp == NULL)
  {
    free(string);
    ch = -1;
  }
  else
    string = tmp;  
  return ch;
}

