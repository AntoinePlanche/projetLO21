#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CrossTwoIndiv.h"
#include "define.h"
#include "individu.h"
#include "binaire_to_decimal.h"
#include "qualite.h"
#include "Population.h"

//#define RECURSIF

int main(int argc, char ** argv){
    srand(time(NULL));
#ifdef RECURSIF
    creer_individu_recursif(LONGUEUR_INDIVIDU);
    afficherListe(l);
    printf("%d",binaire_to_decimal(l));
#else
    Individu l = creer_individu_iteratif(LONGUEUR_INDIVIDU);
    Individu m = creer_individu_iteratif(LONGUEUR_INDIVIDU);
    Population P =creer_population();
    afficher_population(P);
    printf("Valeur : %d\nQualite : %lf\n", binaire_to_decimal(l), qualite_individu(l));
    crossTwoIndiv(&l,&m);
    afficher_individu(l);
    afficher_individu(m);
#endif
    return 0;
}
