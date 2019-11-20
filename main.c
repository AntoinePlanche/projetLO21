#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "croisement.h"
#include "define.h"
#include "individu.h"
#include "binaire_to_decimal.h"
#include "qualite.h"
#include "population.h"

#define PROBA_CROISEMENT 0.5
#define NB_SELECTION 4

//#define RECURSIF

int main(int argc, char ** argv){
    srand(time(NULL));

    int taille;
    printf("Taille de la population : ");
    scanf("%d", &taille);
    Population P = creer_population(taille);
    afficher_population(P);

    printf("\n\nCroisement\n");
    croiser_population(P, PROBA_CROISEMENT);
    afficher_population(P);

    printf("\n\nSelection %d\n", NB_SELECTION);
    selectionner_population(P, NB_SELECTION);
    afficher_population(P);

    supprimer_population(P);
    return 0;
}
