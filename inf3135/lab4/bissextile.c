#include <stdio.h>
#include <stdlib.h>

int main() {
   int var;
   scanf("%d", &var);
   if (var % 400 != 0)
      printf("bissextile");
   else
      printf("nonbissextile");
   return 0;
}
