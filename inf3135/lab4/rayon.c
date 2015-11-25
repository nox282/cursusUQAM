#include <stdio.h>
#include <stdlib.h>

static float pi = 3.14159;

int main () {
    float var;
    printf("Veuillez entrer le rayon d'un cercle.\n");
    scanf("%f", &var);
    double res = var * var * pi;
    printf("L'aire du cercle = %f\n", res);
    return 0;
}
