#include "individu.h"
#include "binaire_to_decimal.h"
#include "qualite.h"

Individu creer_individu_iteratif(int longueur){
    Element* p = (Element*)malloc(sizeof(Element));
    if (p == NULL){
        printf("creer_individu_iteratif() : allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->valeur = rand() & 1; // % 2;
    Element* precedent = p;
    Element* suivant = NULL;
    for(int i = 1; i < longueur; i++){
        suivant = (Element*)malloc(sizeof(Element));
        suivant->valeur = rand() & 1; // % 2;
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
        suivant->valeur = rand() & 1; // % 2;
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
    p->valeur = rand() & 1; // % 2;
    p->suivant = NULL;
    _creer_recursif(longueur, p);
    return p;
}


Individu copier_individu(Individu base){
    if (base == NULL) return NULL;

    Element* courant = base;
    Element* copie = (Element*)malloc(sizeof(Element));
    copie->valeur = courant->valeur;
    copie->suivant = NULL;
    courant = courant->suivant;
    Element* element = copie;

    while (courant != NULL){
        Element* nouveau = (Element*)malloc(sizeof(Element));
        nouveau->valeur = courant->valeur;
        element->suivant = nouveau;
        element = nouveau;
        courant = courant->suivant;
    }
    element->suivant = NULL;
    return copie;
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
    printf("Valeur : %d\nQualite : %lf\n", binaire_to_decimal(l), qualite_individu(l));
}

void supprimer_individu(Individu indiv){
    Element *element = indiv, *suivant;
    while (element != NULL){
        suivant = element->suivant;
        free(element);
        element = suivant;
    }
}
