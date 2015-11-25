#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256
#define ALPHABET 26
#define MAX_BUFFER 50

char heaviestCharacter (const char *string);
int ceasarNumber (char character);
void decode (const char *string);

int main (int argc, char **argv)
{
    FILE *fpi
    FILE *fpo
    char bufferi[MAX_BUFFER + 1];

    fpi = fopen(argv[1], "r");
    
    if (fpi == NULL)
    {
        printf("error");
        return 1;
    }
    
    while (fgets(buffer, MAX_BUFFER, fp) != NULL)
    {
         fprintf
    }
    return 0;
}

//return the character that has the most instances in a given string.
char heaviestCharacter (const char *string)
{
    char characterCount[ALPHABET];
    int i = 0;
    int maximum = 0;
    char temp;
    //count every character in the string
    for (i = 0; i < strlen(string); i++)
    {
	temp = string[i];
        if ((temp >= 'A' && temp <= 'Z') ||
  			(temp >= 'a' && temp <= 'z'))
        {
            if (temp >= 'A' && temp <= 'Z')
                temp += 32;
            characterCount[(int)string[i] - 97]++;
        }
    }
    //find the most representated character
    for (i = 0; i < ALPHABET; i++)
    {
        if (characterCount[i] > characterCount[maximum])
            maximum = i;       
    }
    return (characterCount[maximum] + 97);
}

//return the ceasar number
int ceasarNumber (char character)
{
    int ret = 0;
    if (character > 'e')
        ret = 'e' - character;
    else
        ret = character - 'e';
    return ret;
}

//Decode an encrypted string
void decode (const char *string)
{
    int i = 0;
    char heaviestChar = heaviestCharacter(string);
    char temp;
    int ceasar = ceasarNumber(heaviestChar);
    
    for (i = 0; i < strlen(string); i++) 
    {
        temp = string[i];
        temp += ceasar;
        fprintf("%c", temp, sortie.txt
    }
}
