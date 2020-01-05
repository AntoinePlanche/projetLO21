#include <stdio.h>
#include <stdlib.h>

#include "define.h"

int binaire_to_decimal(Individu l){
    Element* p = l;
    int result = 0, i = 0;
    while (p != NULL){
        result += p->valeur << i; // * pow(2, i);
        p = p->suivant;
        i++;
    }
    return result;
}
