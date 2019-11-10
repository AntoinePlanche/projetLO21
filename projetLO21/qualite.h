#ifndef QUALITE_H_INCLUDED
#define QUALITE_H_INCLUDED

#include <stdlib.h>

#include "define.h"
#include "binaire_to_decimal.h"

#define USE_F1

#ifdef USE_F1
 #define A -1
 #define B 1
 #define F(x) -x*x
#endif

double qualite_individu(Individu indiv);

#endif // QUALITE_H_INCLUDED
