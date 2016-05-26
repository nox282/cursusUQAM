#include "fichiers.h"

charTab_t *extraireDuFichier(FILE* fichierP){
    
    int tailleFichier;
    char *ligneDupliquee;
    char *ligne = malloc(sizeof(char)*18);    

    fseek(fichierP, 0, SEEK_END);
    tailleFichier = ftell(fichierP);
    fseek(fichierP, 0, SEEK_SET);
        
    charTab_t *donnees = newCharTab(tailleFichier);

    int i = 0;

    while(fgets(ligne, 18, fichierP)){ 
        nettoyerChaine(ligne);
        ligneDupliquee = strdup(ligne);

        donnees->tableau[i] = ligneDupliquee;
        i++;
    }
    return donnees;
}

void ecrireDansFichier(FILE *fichier, char *chaine){
    int tailleChaine = strlen(chaine);
    int fd;
    pid_t wait(int *status), pid;
    fd = fileno(fichier);
    pid = fork(); 
    if(pid != 0){
        wait(NULL);
    }else{
        verrouillerFichier(fichier);
        write(fd, chaine, tailleChaine);
        deverrouillerFichier(fichier);
    }
}

void nettoyerChaine(char* chaine){
    size_t tailleChaine = strlen(chaine);
    int i;

    for(i=tailleChaine; i<0; i--){
        if(chaine[i] == '\n')
            chaine[i] = '\0';
    }
}

void verrouillerFichier(FILE* fichierP){
    int fd = fileno(fichierP);
    lseek(fd,0,0);
    if(lockf(fd,F_LOCK,1)<0){
        printf("Le fichier n'a pas pu etre verrouille\n");
    }
}

void deverrouillerFichier(FILE* fichierP){
    int fd = fileno(fichierP);
    lseek(fd,0,0);
    if(lockf(fd,F_ULOCK,0<0)){
        printf("Le fichier n'a pas pu etre deverrouille\n");
    }
}
