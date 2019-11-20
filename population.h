#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "individu.h"

Population creer_population();
int taille_population(Population P);
void selectionner_population(Population P, int nb);
void afficher_population(Population P);
void supprimer_population(Population P);

#endif // POPULATION_H_INCLUDED
