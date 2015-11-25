#include "decode.h"

char heaviestCharacter (const char *string)
{	
  int characterCount[ALPHABET];
  int i = 0;
  int maximum = 0;
  char temp;
  
  for (i = 0; i < ALPHABET; i++)
    characterCount[i] = 0;
  //count every character in the string
  for (i = 0; i < strlen(string); i++)
  {
    temp = string[i];
    if ((temp >= 'A' && temp <= 'Z') ||
      (temp >= 'a' && temp <= 'z'))
    {
      if (temp >= 'A' && temp <= 'Z')
        temp = temp + 32;
      characterCount[temp - 97]++;
    } 
  }
  //find the most recurent character
  for (i = 0; i < ALPHABET; i++)
  {
    if (characterCount[i] > characterCount[maximum])
      maximum = i;       
  }
  return (maximum + 97);
}

int ceasarNumber (char character)
{
  int ret = 0;
  if (character > 'e')
    ret = -(character - 'e');
  else
    ret = 'e' - character;
  return ret;
}

char* decode (char *input)
{
  int i = 0;
  char heaviestChar = heaviestCharacter(input);
  int ceasar = ceasarNumber(heaviestChar);

  for (i = 0; i < strlen(input); i++)            
  {
    if(input[i] >= 'A' && input[i] <= 'Z') 
    {
      if ((input[i] + ceasar) > 'Z')
        input[i] = input[i] + ceasar - ALPHABET;
      else if ((input[i] + ceasar) < 'A')
        input[i] = input[i] + ceasar + ALPHABET;
      else    
        input[i] = input[i] + ceasar; 
    }
    else if(input[i] >= 'a' && input[i] <= 'z')
    {    
      if ((input[i] + ceasar) > 'z')
        input[i] = input[i] + ceasar - ALPHABET;
      else if ((input[i] + ceasar) < 'a')
        input[i] = input[i] + ceasar + ALPHABET;
      else    
        input[i] = input[i] + ceasar; 
    }
  }
  return input;
}
