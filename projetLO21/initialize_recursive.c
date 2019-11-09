#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

void initialize_recursive(int n,Liste *liste,Indiv *individu)
{
    if (n!=0)
    {
        individu->binaire=rand()%2;
        individu=individu->suivant;
        initialize_recursive(n-1,liste,individu);
    }
    else
    {
        individu->suivant=NULL;
    }
}
