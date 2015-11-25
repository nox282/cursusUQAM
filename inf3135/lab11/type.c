#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void coucou(int* j) {
    printf("coucou %d\n", *j);
    (*j)++;
}

int main() {
    char** tab = NULL;
    char** tmpTab = NULL;
    char* string = NULL;
    char* tmp = NULL;
    int ch = 0;
    size_t size = 0, row = 0, column = 0;
    int i = 0;
 
    int h = 0;
    int* j = &h;
     
    do {
        tmpTab = malloc(sizeof(char)); 
        tmp = malloc(sizeof(char));
        
        column = 0;
        ch = 0;
        while(ch != -1) {
            ch = getc(stdin);
            
            if(ch == '\n')
                ch = -1;
            if(size <= column) {
            
                size = size + sizeof(char);
                tmp = realloc(string, size);
           
                if(tmp == NULL) {
                    string = NULL;
                    tmp = NULL; 
                    ch = -1;
                } else { 
                    string = tmp;
                }
            }
            string[column++] = ch;
        }
        free(tmp);
        tmpTab = realloc(tab, row*8);   
        coucou(j);

        tmp = malloc(strlen(string)*sizeof(char*));
 
        coucou(j);
        tab = tmpTab;
        printf("%d ", row);
        tab[row] = tmp;
        tab[row++] = string;
        printf("%d %d \n", sizeof(tab), sizeof(tab[row]));
        coucou(j);

        coucou(j);
        free(tmp);
        coucou(j);
    } while(strlen(string) > 1);
    for(i = 0; i < row; i++) {
        printf("%s\n", tab[i]);
        free(tab[i]);
    }
    free(tab);
    return 0;
}
