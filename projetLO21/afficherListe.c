#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void afficherListe(liste l)
{
    if (l == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Indiv *actuel = l;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->binaire);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
