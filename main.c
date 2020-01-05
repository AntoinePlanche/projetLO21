#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "define.h"
#include "croisement.h"
#include "individu.h"
#include "population.h"
#include "quicksort.h"


//#define RECURSIF

int main(int argc, char ** argv){
    srand(time(NULL));

    int taille = -1;
    while (taille < 20 || taille > 200){
        printf("Taille de la population (20 - 200) : ");
        scanf("%d", &taille);
    }
    float proba_croisement = -1;
    while (proba_croisement < 0.1 || proba_croisement > 0.9){
        printf("Probabilité de croisement (0.1 - 0.9) : ");
        scanf("%f", &proba_croisement);
    }
    int nb_generations = -1;
    while (nb_generations < 20 || nb_generations > 200){
        printf("Nombre de générations (20 - 200) : ");
        scanf("%d", &nb_generations);
    }

    Population P = creer_population(taille);

    int i;
    for (i = 0; i < nb_generations; i++){
        croiser_population(P, proba_croisement);
        P = quicksort_population(P, taille);
        selectionner_population(P, NB_SELECTION);
    }
    afficher_individu(meilleur_individu(P));
    supprimer_population(P);
    return 0;
}
