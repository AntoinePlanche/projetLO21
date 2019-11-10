#include "individu.h"

Individu creer_individu_iteratif(int longueur){
    Element* p = (Element*)malloc(sizeof(Element));
    if (p == NULL){
        printf("creer_individu_iteratif() : allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->valeur = rand() % 2;
    Element* precedent = p;
    Element* suivant = NULL;
    for(int i = 1; i < longueur; i++){
        suivant = (Element*)malloc(sizeof(Element));
        suivant->valeur = rand() % 2;
        suivant->suivant = NULL;
        precedent->suivant = suivant;
        precedent = suivant;
    }
    return p;
}

static void _creer_recursif(int longueur, Element* p){
    if (longueur > 0){
        Element* suivant = (Element*)malloc(sizeof(Element));
        if (suivant == NULL){
            printf("_creer_recursif : allocation failed");
        }
        suivant->valeur = rand() % 2;
        p->suivant = suivant;
        _creer_recursif(longueur - 1, suivant);
    } else {
        p->suivant = NULL;
    }
}

Individu creer_individu_recursif(int longueur){
    Element* p = (Element*)malloc(sizeof(Element));
    if (p == NULL){
        printf("creer_individu_recursif : allocation failed\n");
    }
    p->valeur = rand() % 2;
    p->suivant = NULL;
    _creer_recursif(longueur, p);
    return p;
}


void afficher_individu(Individu l){
    /*if (l == NULL){
        exit(EXIT_FAILURE);
    }*/

    Element* actuel = l;

    while (actuel != NULL){
        printf("%d -> ", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
