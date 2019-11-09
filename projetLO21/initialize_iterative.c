#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

liste initialize_iterative()
{
    srand(time(NULL));
    liste p=NULL;
    p = (Indiv*)malloc(sizeof(Indiv));
    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }
    p->binaire=rand()%2;
    p->suivant=NULL;
    Indiv* newel;
    Indiv* last=p;
    for(int i=1;i<longIndiv;i++)
    {
        newel=(Indiv*)malloc(sizeof(Indiv));
        newel->binaire=rand()%2;
        newel->suivant=NULL;
        last->suivant=newel;
        last=last->suivant;
    }
    return p;

}
