#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "puissance.h"
#include<math.h>

int binaire_to_decimal(Liste *liste,Indiv *individu)
{
    int result=0;
    individu=liste->premier;
    for(int i=0;i<longIndiv;i++)
    {
        result=result+puissance(i,individu->binaire);
        individu=individu->suivant;
    }
    return result;
}
