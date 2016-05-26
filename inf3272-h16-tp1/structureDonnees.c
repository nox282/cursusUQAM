#include "structureDonnees.h"

charTab_t *newCharTab(int n) {
    charTab_t *retour = malloc(sizeof(charTab_t));
    if(retour == NULL)
        return NULL;

    retour->taille = n*sizeof(char*);

    retour->tableau = malloc(retour->taille);
    if(retour->tableau == NULL) {
        free(retour);
        return NULL;
    }
    retour->nbrElem = (retour->taille/8)/17;
    return retour;
}

void destroyCharTab(charTab_t *donnees) {
    free(donnees->tableau);
    free(donnees);
}

compteTab_t *newCompteTab (int n) {
    compteTab_t *retour;
    
    retour = malloc(sizeof(compteTab_t));
    if(retour == NULL)
        return NULL;
    
    retour->taille = n*sizeof(compte_t*); 
    
    retour->comptes = malloc(retour->taille);
    if(retour->comptes == NULL) {
        free(retour);
        return NULL;
    }
    
    retour->nbrElem = n;
    return retour;
}

void destroyCompteTab(compteTab_t *donnees){
    int i = 0;
    for (i = 0; i < donnees->nbrElem; i++)
        detruireCompte(donnees->comptes[i]);
    free(donnees);
}

char *comptesToString(compteTab_t *donnees) {
    int i;
    size_t sz;
    char *buffer, *id, *nom, *solde;
    char *retour = malloc(17*donnees->nbrElem);
    retour[0] = '\0';
    if (retour == NULL)
        return NULL;
    id = malloc(5);
    if (id == NULL)
        return NULL;
    solde = malloc(5);
    if (solde == NULL)
        return NULL;
    for (i = 0; i < donnees->nbrElem; i++) {
        id = toString(id, donnees->comptes[i]->compteId);
        nom = donnees->comptes[i]->nom;
        solde = toString(solde, donnees->comptes[i]->solde);
        
        sz = snprintf(NULL, 0, "%s %s %s\n", id, nom, solde);
        buffer = malloc(sz+1);
        if(buffer == NULL)
            return NULL;
        snprintf(buffer, sz+1, "%s %s %s\n", id, nom, solde);
        strcat(retour, buffer);
        free(buffer);
    }
    free(id);
    free(solde);
    return retour;
}
