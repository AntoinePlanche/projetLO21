#ifndef _INDIVIDU_H_INCLUDED
#define _INDIVIDU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "define.h"

//#define INDIVIDU_RECURSIF

#ifdef INDIVIDU_RECURSIF
#define creer_individu creer_individu_recursif
#else
#define creer_individu creer_individu_iteratif
#endif

Individu creer_individu_iteratif(int longueur);
Individu creer_individu_recursif(int longueur);
Individu copier_individu(Individu base);
void supprimer_individu(Individu indiv);

void afficher_individu(Individu l);

#endif // _INDIVIDU_H_INCLUDED
