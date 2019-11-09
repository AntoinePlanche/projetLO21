#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

void initialize_iterative(Liste *liste,Indiv *individu)
{
    int i=0;
    individu->binaire=rand()%2;
    while(i<7)
    {
        individu=individu->suivant;
        individu->binaire=rand()%2;
        i++;
    }
    individu->suivant=NULL;
}
