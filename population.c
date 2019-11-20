#include "population.h"

Population creer_population(int taille){
    PopElement* P = (PopElement*)malloc(sizeof(PopElement));
    if (P == NULL){
        printf("creer_population() : allocation failed\n");
        exit(EXIT_FAILURE);
    }
    P->valeur = creer_individu(LONGUEUR_INDIVIDU);
    PopElement* precedent = P;
    PopElement* suivant = NULL;
    for (int i = 1; i < taille; i++){
        suivant = (PopElement*)malloc(sizeof(PopElement));
        suivant->valeur = creer_individu(LONGUEUR_INDIVIDU);
        suivant->suivant = NULL;
        precedent->suivant = suivant;
        precedent = suivant;
    }
    return P;
}

int taille_population(Population P){
    int taille = 0;
    PopElement* element = P;
    while (element != NULL){
        taille += 1;
        element = element->suivant;
    }
    return taille;
}

void selectionner_population(Population P, int nb){
    int i;
    PopElement* courant = P;
    PopElement* base = P;
    for (int i = 0; i < nb && courant->suivant != NULL; i++){
        courant = courant->suivant;
    }
    i = 1;
    while (courant != NULL){
        courant->valeur = copier_individu(base->valeur);
        i += 1;
        if (i > nb){
            i = 1;
            base = P;
        } else {
            base = base->suivant;
        }
        courant = courant->suivant;
    }
}

void afficher_population(Population P){
    PopElement* courant = P;
    while (courant != NULL){
        afficher_individu(courant->valeur);
        courant = courant->suivant;
    }
}

void supprimer_population(Population P){
    PopElement *element = P, *suivant;
    while (element != NULL){
        suivant = element->suivant;
        supprimer_individu(element->valeur);
        free(element);
        element = suivant;
    }
}
