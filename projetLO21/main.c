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
    liste l=(Indiv*)malloc(sizeof(Indiv));
    if(l == NULL)
    {
        EXIT_FAILURE;
    }
    if(0)
    {
        initialize_recursive(longIndiv,l);
        afficherListe(l);
        printf("%d",binaire_to_decimal(l));
    }
    else
    {
        l=initialize_iterative();
        afficherListe(l);
        printf("%d",binaire_to_decimal(l));
    }
    return 0;
}
