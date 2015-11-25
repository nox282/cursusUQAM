#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 256

size_t longueurChaine(const char *chaine);

int main () {
    char chaineUs[MAX_STRING];
    fgets (chaineUs, MAX_STRING, stdin);
    int strlen = longueurChaine (chaineUs);
    printf("%d\n", strlen);
    return 0;
}

size_t longueurChaine (const char *chaine) {
    size_t ret;
    if (chaine[0] == 
    return ret;
}
