#ifndef STRUCTUREDONNEES_H
#define STRUCTUREDONNEES_H

#include "menu.h"
#include "compte.h"

/*
 * Tableau de char avec sa taille
 * */
typedef struct charTab charTab_t;

struct charTab {
    char **tableau;
    int taille;
    int nbrElem;
};
/*
 * Tableau de compte avec sa Taille
 * */
typedef struct compteTab compteTab_t;

struct compteTab {
    compte_t **comptes;
    int taille;
    int nbrElem;
};

charTab_t *newCharTab(int);
void destroyCharTab(charTab_t*);
compteTab_t *newCompteTab(int);
void destroyCompteTab(compteTab_t*);
char *comptesToString(compteTab_t*);
#endif
