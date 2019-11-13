#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"
#include "CrossTwoIndiv.h"

void crossTwoIndiv(Individu* a,Individu* b)
{
    srand(time(NULL));
    Element* x=*a;
    Element* y=*b;
    double p;
    double c;
    Individu d=malloc(sizeof(Individu));
    for (int i=0;i<LONGUEUR_INDIVIDU;i++)
    {
        printf("Quelle est la probabilite d'intervetir le bit %i ? (compris entre 0 et 100)\n",i+1);
        scanf("%lf",&p);
        while (p>100 || p<0)
        {
            printf("la probabilite doit etre comprise entre 0 et 100, réessayer \n");
            printf("Quelle est la probabilite d'intervetir le bit %i ? (compris entre 0 et 100)\n",i+1);
            scanf("%lf",&p);
        }
        c=rand()%100;
        printf("c = %lf\n",c);
        if(c<p)
        {
            d->valeur=x->valeur;
            x->valeur=y->valeur;
            y->valeur=d->valeur;
            x=x->suivant;
            y=y->suivant;
        }
    }
}
