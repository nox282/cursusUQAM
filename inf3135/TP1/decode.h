#include "ceasar.h"
#include "fileIO.h"
/*
 * Takes a string as argument
 * Returns the character that has the most instances in a given string.
 **/
char heaviestCharacter (const char *string);
/*
 * Takes a character as argument
 * Returns the ceasar number
 **/
int ceasarNumber (char character);
/*
 * Takes two CEASAR_str and a ceasar Number 
 * Decodes the encrypted string and stoes the result
 **/
void decode (CEASAR_str *input, CEASAR_str *output);
