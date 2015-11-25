#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* readKeyboardInput()
{
  char* userInput;
  char* temp;
  char inputChar = 0;
  int size = sizeof(char);
  int index = 0;
  int memBlock = 10;
  userInput = malloc(sizeof(char));
  if(userInput == NULL)
    return NULL;
  while(inputChar!='\n' && inputChar != EOF)
  {
    inputChar = fgetc(stdin);
    if(index > size)
    {
      size+= memBlock;
      temp = realloc(userInput,size);
      if(temp == NULL)
      {
        free(userInput);
        return NULL;
      }
      userInput = temp;
    }
    userInput[index++] = inputChar;
  }
  return userInput;
}
int main()
{
  char* userInput;
  char* endValue = "QUITTER\n";
  do
  {
    printf("Entrez votre critËre de recherche : ");
    userInput = readKeyboardInput();
    printf("Input : %s\n",userInput);
  }while(strcmp(userInput,endValue)!=0);
  free(userInput);
  return 0;
}

