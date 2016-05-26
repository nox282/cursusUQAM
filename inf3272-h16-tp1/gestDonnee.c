#include "gestDonnee.h"

compteTab_t *construireStructure(FILE *fichier) {
    int i = 0;
    charTab_t *brute = extraireDuFichier(fichier);
    compteTab_t *donnees = newCompteTab(brute->nbrElem);
    for (i = 0; i < brute->nbrElem; i++) {
        donnees->comptes[i] = newCompte(brute->tableau[i]);
        if (donnees->comptes[i] == NULL)
            return NULL;
    }
    destroyCharTab(brute);
    return donnees;
}

void consulterCompte(int id, FILE *fichier) {
    compteTab_t *comptes = construireStructure(fichier);
    compte_t *compte = chercherCompte(id, comptes);
    if(compte == NULL){
        printf("Ce compte n'existe pas.\n");
        return;
    }
    printf("#####################\n");
    printf("Identifiant du compte : %d\nNom : %s\nSolde : %d\n",
        compte->compteId, compte->nom, compte->solde);
    printf("#####################\n");
    destroyCompteTab(comptes);
}

void transaction(int idDebit, int idCredit, int somme, FILE *fichier ) {
    compteTab_t *comptes = construireStructure(fichier);
    compte_t* debit = chercherCompte(idDebit, comptes);
    compte_t* credit = chercherCompte(idCredit, comptes);
    
    if(debit == NULL || credit == NULL){
        printf("Ce compte n'existe pas.\n");
        return;
    }
    if(somme > debit->solde)
        printf("Pas assez d'argent sur le compte pour debiter.\n");
    else if((credit->solde + somme) > 9999)
        printf("Le solde du crediteur ne peut pas depasser 9999.\n");
    else {
        debit->solde -= somme;
        credit->solde += somme;
        ecrireDansFichier(fichier, comptesToString(comptes));
    }
    destroyCompteTab(comptes);
}

compte_t *chercherCompte(int id, compteTab_t *donnees) {
    int i;
    for(i = 0; i < donnees->nbrElem; i++) {
        if(donnees->comptes[i]->compteId == id){
            return donnees->comptes[i];
        }
    }
    return NULL;
}

void etatComptes(FILE *fichier) {
    int i;
    compteTab_t *comptes = construireStructure(fichier);
    printf("#####################\n");
    printf("id-- Nom--- Solde\n");
    for(i = 0; i < comptes->nbrElem; i++)
        printf("%d %s %d\n", comptes->comptes[i]->compteId, comptes->comptes[i]->nom, comptes->comptes[i]->solde);
    printf("#####################\n");
    destroyCompteTab(comptes);
}
