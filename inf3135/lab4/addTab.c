#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5

int main() {
   char tableau[5] = {'A','B','C','D','E'};
   
   char* parcours = tableau;
    
   while (parcours != tableau + TAILLE) {
      printf("%p: %c\n", parcours,  *parcours);
      parcours++;
   }
   return 0;
}
