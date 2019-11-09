#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

void initialize_recursive(int n,liste l)
{
    liste p=l;
    if (n!=0)
    {
        p->binaire=rand()%2;
        p=p->suivant;
        initialize_recursive(n-1,p);
    }
    else
    {
        p->suivant=NULL;
        return l;
    }
}
