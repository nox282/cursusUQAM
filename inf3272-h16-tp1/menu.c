#include "menu.h"
#include "compte.h"
#include "fichiers.h"
#include "gestDonnee.h"
#define BUFFER 250 

void afficherMenu();
int lireUtilisateur();
int controllerEntree(char*);
/*
 * Execution principale
 * */
void executerMenu(FILE*);
void consulter(FILE*);
void transferer(FILE*);
int main (int argc, char **argv) {
    FILE *fichier = NULL;
    if (argc != 2) {
        printf("Executez le programme avec le fichier des comptes.\n");
        return EXIT_FAILURE;
    } else {
        fichier = fopen(argv[1], "r+");
        if (fichier != NULL) {
            executerMenu(fichier);
            fclose(fichier);
        } else {
            printf("Fichier non existant\n");
            return EXIT_FAILURE;
        }
    }
    return 0;
}

void afficherMenu() {
    printf("Que vouslez-vous faire ?\n\t1 - Consulter un compte;\n\t2 - Effectuer un transfert;\n\t3 - Afficher l'etat des comptes;\n\t4 - Quitter.\nVeuillez entrer le chiffre correspondant a votre choix.\n");
}

int lireUtilisateur() {
    char entree[BUFFER];
    fgets(entree, BUFFER, stdin);
    return controllerEntree(entree);
}

int controllerEntree(char *entree) {
    int i;
    int tailleEntree = (int)strlen(entree);
    if (tailleEntree > 5)
    {
        printf("Vous devez entrer 4 chiffre au maximum\n");
        return -1;
    }
    else {
        for(i = 0; i < tailleEntree; i++) {
            if (entree[i] < '0' && entree[i] > '9') {
                printf("Vous ne devez entrer que des chiffres\n");
                return -1;
            }
        }
        return strtoumax(entree, NULL, 10);
    }
}

void executerMenu(FILE* fichier) {
    int entree;
    do {
        afficherMenu();
        entree = lireUtilisateur();
        if(entree != 1 && entree != 2 && entree != 3 && entree != 4)
            printf("Entree invalide\n");
        else {
            switch(entree) {
                case 1:
                    consulter(fichier);
                    break;
                case 2:
                    transferer(fichier);
                    break;
                case 3:
                    etatComptes(fichier);
                    break;
                case 4:
                    return;
                    break;
            }
        }
    }while(entree != 4);
}

void consulter(FILE *fichier) {
    int id;
    printf("Entrez votre Identifiant : \n");
    id = lireUtilisateur();
    consulterCompte(id, fichier);
}

void transferer(FILE *fichier) {
    int idSource, idDest, choix, somme;
    
    printf("Entrez votre Identifiant : \n");
    idSource = lireUtilisateur();
    printf("Entrez l'identifiant du compte que vous voulez crediter/debiter :\n");
    idDest = lireUtilisateur();
    do {
        printf("Voulez-vous :\n\t1 - Debiter\n\t2 - Crediter\nle destinataire ? Entrez le choix correspondant.\n");
        choix = lireUtilisateur();
        if (choix != 1 && choix != 2)
            printf("Entree invalide.\n");
    } while(choix != 1 && choix != 2);
    printf("Entrez la somme de votre transaction :\n");
    somme = lireUtilisateur();
    switch(choix) {
        case 1:
            transaction(idDest, idSource, somme, fichier);
            break;
        case 2:
            transaction(idSource, idDest, somme, fichier);
            break;
    }
}
