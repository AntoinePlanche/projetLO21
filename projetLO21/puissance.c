#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int puissance(int p,int n)
{
    if(n==0)
    {
        return(1);
    }
    return ((puissance(p,n-1))*p);

}
