#include <stdio.h>
#include <stdlib.h>
#include "individu.h"

Population creer_population()
{
    int n;
    printf("Combien y a t'il d'individu dans la population P1 ?\n");
    scanf("%i",&n);
    Population P = (Population)malloc(sizeof(Population));
    if (P == NULL)
    {
        printf("creer_population() : allocation failed\n");
        exit(EXIT_FAILURE);
    }
    P->valeur = creer_individu_iteratif(LONGUEUR_INDIVIDU);
    Population precedent = P;
    Population suivant = NULL;
    for(int i = 1; i < n; i++)
    {
        suivant = (Population)malloc(sizeof(Population));
        suivant->valeur = creer_individu_iteratif(LONGUEUR_INDIVIDU);
        suivant->suivant = NULL;
        precedent->suivant = suivant;
        precedent = suivant;
    }
    return P;
}


void afficher_population(Population P)
{
    Population actuelle = P;
    while(actuelle != NULL)
    {
        afficher_individu(actuelle->valeur);
        actuelle=actuelle->suivant;
    }
}
