#ifndef DECODE_H
#define DECODE_H

#include "ceasar.h"
/*
 * Returns the character that has the most instances in a given char*.
 * */
char heaviestCharacter (const char *string);
/*
 * Returns the ceasar number from given char*.
 * */
int ceasarNumber (char character);
/*
 * Decodes the encrypted string and returns the decrypted one.
 **/
char* decode (char *input);
#endif
