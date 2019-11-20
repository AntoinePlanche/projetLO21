#include <stdio.h>
#include <stdlib.h>
#include "individu.h"

    /* partitionner(tableau T, entier premier, entier dernier, entier pivot)
    échanger T[pivot] et T[dernier]  // échange le pivot avec le dernier du tableau , le pivot devient le dernier du tableau
    j := premier
    pour i de premier à dernier - 1 // la boucle se termine quand i = (dernier-1).
        si T[i] <= T[dernier] alors
            échanger T[i] et T[j]
            j := j + 1
    échanger T[dernier] et T[j]
    renvoyer j

int partitionner(Population P, int premier, int dernier, int pivot)
{
    Population un = Population P;
    Population deux = Population P;
    Individu temp;
    for(int i = 0; i<pivot; i++)
    {
        un=un->suivant;
        deux=deux->suivant;
    }
    for (int i = pivot; i<dernier; i++)
    {
        deux=deux->suivant;
    }
    temp=un->valeur;
    un->valeur=deux->valeur;
    deux->valeur=temp;

    int j=premier;

    for(i=premier;i<dernier;i++)
    {
        if()
        {

        }
    }

}

    */



