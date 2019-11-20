#include "qualite.h"

double qualite_individu(Individu indiv){
    double valeur = (double)binaire_to_decimal(indiv);
    return F((valeur / (1 << LONGUEUR_INDIVIDU)) * (B - A) + A);
}
