#ifndef GESTDONNEE_H
#define GESTDONNEE_H

#include "menu.h"
#include "compte.h"
#include "structureDonnees.h"
#include "fichiers.h"

/*
 * Construit la strucutre de donnee a partir des donnees du fichier
 * */
compteTab_t *construireStructure(FILE*);
/*
 * Affiche les donnees d'un compte
 * */
void consulterCompte(int, FILE*);
/*
 * Effectue une transaction ente deux comptes
 * */
void transaction(int, int, int, FILE*);
/*
 * Cherche un compte
 * */
compte_t *chercherCompte(int, compteTab_t*);
/*
 * Affiche l'etat des comptes
 * */
void etatComptes(FILE*);
#endif
