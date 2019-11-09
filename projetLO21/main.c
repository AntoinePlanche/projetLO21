#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "define.h"
#include "initialize_recursive.h"
#include "initialize_iterative.h"
#include "afficherListe.h"
#include "binaire_to_decimal.h"
#include "puissance.h"

int main(int argc, char ** argv)
{
    printf("%i ",puissance(2,5));
    srand(time(NULL));
    Liste *liste=malloc(sizeof(*liste));
    Indiv *individu=malloc(sizeof(*individu));
    liste->premier=individu;
    if (liste == NULL || individu==NULL)
    {
        exit(EXIT_FAILURE);
    }

    if(0)
    {
        initialize_recursive(longIndiv,liste,individu);
        afficherListe(liste,individu);
        printf("%d",binaire_to_decimal(liste,individu));
    }
    else
    {
        initialize_iterative(liste,individu);
        afficherListe(liste,individu);
    }
    return 0;
}
