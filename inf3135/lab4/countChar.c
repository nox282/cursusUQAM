#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

int main () {
    char string[MAX_STRING_LENGTH];
    fgets (string, MAX_STRING_LENGTH, stdin);
    
    int sizeStr = strlen(string);
    sizeStr--;
    
    int i = 0;
    int count = 0;
    
    for(i = 0; i < sizeStr; i++) {
        if((string[i]>='a' && string[i]<='z') ||
             (string[i]>='A' && string[i] <='Z'))
        count++;
    }
    
    printf("%d, %d\n", sizeStr, count);
    
    return 0; 
}
