#include "compte.h"

bool verifierInfos(char*);
compte_t *construireCompteStruct(char*);

compte_t *newCompte(char *infos) {
    compte_t *ret = NULL;
    if(verifierInfos(infos)) {
        ret = construireCompteStruct(infos);
        if(ret == NULL)
            printf("La construction du compte a echoue\n");
    } else {
        printf("Informations du compte incorrectes\n");
        return ret; 
    }
    return ret;
}

compte_t *construireCompteStruct(char *infos) {
    char *token = NULL, s[2] = " ";
    compte_t *ret = malloc(sizeof(compte_t));
    if(ret == NULL)
        return NULL;
    token = strtok(infos, s);
    ret->compteId = strtoumax(token, NULL, 10);
    token = strtok(NULL, s);
    ret->nom = strdup(token);
    token = strtok(NULL, s);
    ret->solde = strtoumax(token, NULL, 10);
    return ret;
}

bool verifierInfos(char *infos) {
    regex_t regex;
    bool ret = false;

    if (regcomp(&regex, "[0-9]{4} [A-Za-z]{6} [0-9]{4}", REG_EXTENDED|REG_NOSUB)){
        printf("L'initialisation de la regex a echoue\n");
        return false;
    }
    if(strlen(infos) != 17)
        ret = false;
    else {
        if(regexec(&regex, infos, (size_t) 0, NULL, 0) != 0)
            ret = false;
        else
            ret = true;
    }
    regfree(&regex);
    return ret;
}

void detruireCompte(compte_t *compte) {
    free(compte->nom);
    free(compte);
}

char *toString(char *chaine, int value) {
    chaine[0] = '\0';
    int i;
    for (i = 3; i >= 0; i--) {
        chaine[i] = (value%10)+48;
        value = value/10;
    }
    chaine[4] = '\0';
    return chaine;
}
