#ifndef _INDIVIDU_H_INCLUDED
#define _INDIVIDU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "define.h"

//#define INDIVIDU_RECURSIF

#ifdef INDIVIDU_RECURSIF  // Appel de creer_individu(longueur) depuis l'extérieur
#define creer_individu creer_individu_recursif
#else
#define creer_individu creer_individu_iteratif
#endif

// Crée un individu de la longueur donnée par un algorithme itératif
Individu creer_individu_iteratif(int longueur);

// Crée un individu de la longueur donnée par un algorithme récursif
Individu creer_individu_recursif(int longueur);

// Copie un individu
Individu copier_individu(Individu base);

// Libère la mémoire occupée par l'individu
void supprimer_individu(Individu indiv);

// Affiche les caractéristiques de l'individu
void afficher_individu(Individu l);

#endif // _INDIVIDU_H_INCLUDED
