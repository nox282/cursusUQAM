#ifndef FICHIERS_H
#define FICHIERS_H

#include "menu.h"
#include "structureDonnees.h"

/*
 * Extrait les donnees du fichier dans un tableau de char*
 * */
charTab_t *extraireDuFichier(FILE* fichierP);
/*
 * Ecrit dans le fichier le nouveau solde d'un compte
 * */
void ecrireDansFichier(FILE*, char*);
/*
 * Nettoie une chaine, notamment le caractère '\n'
 * */
void nettoyerChaine(char* chaine);
/*
 * Verrouille une partie du fichier
 * */
void verrouillerFichier(FILE* fichierP);
/*
 * Deverrouille une partie du fichie:
 * */
void deverrouillerFichier(FILE* fichierP);


#endif
