#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "puissance.h"
#include <math.h>

int binaire_to_decimal(Individu l){
    Element* p = l;
    int result = 0, i = 0;
    while (p != NULL){
        result += p->valeur * (1 << i); //puissance(2, i);
        p = p->suivant;
        i++;
    }
    return result;
}
