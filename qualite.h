#ifndef QUALITE_H_INCLUDED
#define QUALITE_H_INCLUDED

#include <stdlib.h>
#include <math.h>

#include "define.h"
#include "binaire_to_decimal.h"

//#define USE_F1
//#define USE_F2
#define USE_F3

#if defined(USE_F1)
 #define A -1
 #define B 1
 #define F(x) -x*x
#elif defined(USE_F2)
 #define A 0.1
 #define B 5
 #define F(x) -log(x)
#elif defined(USE_F3)
 #define A -M_PI
 #define B M_PI
 #define F(x) -cos(x)
#endif

// Donne la qualité d'un individu, avec les paramètres et fonction sélectionnés ci-dessus
double qualite_individu(Individu indiv);

#endif // QUALITE_H_INCLUDED
