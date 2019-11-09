#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void afficherListe(Liste *liste,Indiv *individu)
{
    individu=liste->premier;
    while (individu != NULL)
    {
        printf("%d ", individu->binaire);
        individu = individu->suivant;
    }
    printf("NULL\n");
}
