#ifndef COMPTE_H
#define COMPTE_H

#include "menu.h"

typedef struct compte compte_t;

/*
 * Structure compte contient tous les elements du compte.
 * */
struct compte {
    short compteId;
    char *nom;
    int solde;
};

/*
 * Creer une nouvelle instance de la structure compte a partir d'une ligne du fichier.
 * */
compte_t *newCompte(char*);

/*
 * Free la memoire occupe par l'instance donnee.
 * */
void detruireCompte(compte_t*);

/*
 * Convert a value to a string
 * */
char *toString(char*,int);

#endif
