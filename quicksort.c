#include "quicksort.h"

static PopElement* _element(Population p, int index){
	if (p == NULL) return NULL;
	int i = 0;
	while (p->suivant != NULL && i < index){
		p = p->suivant;
		i += 1;
	}
	return p;
}

Population quicksort_population(Population p, int taille){
    // Rien à trier
    if (p == NULL || taille == 0) return NULL;
    if (p->suivant == NULL || taille == 1) return p;

    int gauche = 0, i = 0;  // taille de la gauche du pivot, compteur
    PopElement* pivot = p;  // On prend le premier element comme pivot pour ne pas avoir à se soucier de ce qu'il y a déjà à sa gauche avant de commencer
    PopElement* e = p->suivant;  // element courant
    PopElement* prev = p;  // trace de la liste
    PopElement* suivant = NULL;
    double pvalue = qualite_individu(pivot->valeur); // valeur du pivot
    
    while (i < taille - 1 && e != NULL){
        suivant = e->suivant;
        if (qualite_individu(e->valeur) > pvalue){  // Décalage à gauche du pivot
            prev->suivant = suivant;
            e->suivant = p;  // On place simplement l'élément au début de la liste
            p = e;
            gauche += 1;
        } else {
            prev = e;  // Rien à faire
        }
        e = suivant;
        i += 1;
    }
    p = quicksort_population(p, gauche);  // Tri de la partie gauche
    if (p == NULL){  // Pas de partie gauche : le pivot est le premier élément
        p = pivot;
    } else {  // on recompose la liste : le pivot devient le suivant du dernier élement de la partie gauche triée
        _element(p, gauche - 1)->suivant = pivot;
    }
    pivot->suivant = quicksort_population(pivot->suivant, taille - gauche - 1);  // Tri de la partie droite, qui revient juste après le pivot
    return p;  // Important, le premier élément change en cours de traitement
}
