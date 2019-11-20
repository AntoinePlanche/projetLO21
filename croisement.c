#include "croisement.h"

void croiser_individus(Individu a, Individu b, double probabilite){
    Element* element_a = a;
    Element* element_b = b;
    double tirage;
    Bit temp;
    int norm_proba = (int)(probabilite * RAND_MAX);
    for (int i = 0; i < LONGUEUR_INDIVIDU; i++){
        tirage = rand();
        if(tirage < norm_proba){
            temp = element_a->valeur;
            element_a->valeur = element_b->valeur;
            element_b->valeur = temp;

            element_a = element_a->suivant;
            element_b = element_b->suivant;
        }
    }
}

void croiser_population(Population P, double probabilite){
    int i, taille = taille_population(P);
    PopElement* element = P;
    Individu* attribution = (Individu*)calloc(sizeof(Individu), taille);
    while (element != NULL){
        int index = rand() % taille;
        while (attribution[index] != NULL) index = (index + 1) % taille;
        attribution[index] = element->valeur;
        printf("%d, ", index);
        element = element->suivant;
    }

    for (i = 0; i < taille / 2; i++){
        croiser_individus(attribution[i * 2], attribution[i * 2 + 1], probabilite);
    }
    free(attribution);
}
