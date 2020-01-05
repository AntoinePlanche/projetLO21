#ifndef CROSSTWOINDIV_H_INCLUDED
#define CROSSTWOINDIV_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"
#include "individu.h"
#include "population.h"

// Croise aléatoirement deux individus selon une certaine probabilité
void croiser_individus(Individu a, Individu b, double probabilite);

// Croise aléatoirement les individus de la population deux à deux
void croiser_population(Population P, double probabilite);

#endif // CROSSTWOINDIV_H_INCLUDED
