#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "define.h"
#include "individu.h"
#include "binaire_to_decimal.h"

#define LONGUEUR_INDIVIDU 8

//#define RECURSIF

int main(int argc, char ** argv){
    srand(time(NULL));
#ifdef RECURSIF
    creer_individu_recursif(LONGUEUR_INDIVIDU);
    afficherListe(l);
    printf("%d",binaire_to_decimal(l));
#else
    Individu l = creer_individu_iteratif(LONGUEUR_INDIVIDU);
    afficher_individu(l);
    printf("%d\n", binaire_to_decimal(l));
#endif
    return 0;
}
