#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "individu.h"
#include "qualite.h"

// Crée une population d'un certain nombre d'individus
Population creer_population(int taille);

// Donne la taille de la population
int taille_population(Population P);

// Remplace tous les individus après les *nb* premiers individus de la population par ces *nb* premiers
void selectionner_population(Population P, int nb);

// Affiche les individus de la population
void afficher_population(Population P);

// Renvoie l'individue à la qualité la plus élevée de la population
Individu meilleur_individu(Population P);

// Libère la mémoir occupée par la population et tous les individus qui la composent
void supprimer_population(Population P);

#endif // POPULATION_H_INCLUDED
