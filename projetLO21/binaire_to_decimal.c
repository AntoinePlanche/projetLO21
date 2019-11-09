#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "puissance.h"
#include<math.h>

int binaire_to_decimal(liste l)
{
    liste p=l;
    int result=0;
    for(int i=0;i<longIndiv;i++)
    {
        result=result+p->binaire*puissance(i,2);
        p=p->suivant;
    }
    return result;
}
