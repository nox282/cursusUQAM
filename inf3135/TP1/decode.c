#include "decode.h"
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
	//find the most recurent character
	for (i = 0; i < ALPHABET; i++)
	{
	if (characterCount[i] > characterCount[maximum])
		maximum = i;       
	}
	return (characterCount[maximum] + 97);
}

int ceasarNumber (char character);
{
	int ret = 0;
	if (character > 'e')
		ret = 'e' - character;
	else
		ret = character - 'e';
	return ret;
}

void decode (CEASAR_str *input, CEASAR_str *output)
{
	int i = 0;
	char heaviestChar = heaviestCharacter(*input.string);
	int ceasar = ceasarNumber(heaviestChar);
	
	for (i = 0; i < strlen(*input.string); i++)
	{
		
	}
}
