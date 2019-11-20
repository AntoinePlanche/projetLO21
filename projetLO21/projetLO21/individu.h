#ifndef _INDIVIDU_H_INCLUDED
#define _INDIVIDU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "define.h"

Individu creer_individu_iteratif(int longueur);
Individu creer_individu_recursif(int longueur);
void supprimer_individu(Individu indiv);

void afficher_individu(Individu l);

#endif // _INDIVIDU_H_INCLUDED
