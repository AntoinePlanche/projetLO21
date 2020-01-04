#include "quicksort.h"

static PopElement* _get_element(Population p, int index){
	if (p == NULL) return NULL;
	int i = 0;
	while (p->suivant != NULL && i < index){
		p = p->suivant;
		i += 1;
	}
	return p;
}

Population quicksort_population(Population p, int taille){
	if (p == NULL || taille == 0) return NULL;
	if (p->suivant == NULL || taille == 1) return p;
	int gauche = 0, i = 0;
	PopElement* pivot = p;
    PopElement* e = p->suivant;
    PopElement* prev = p;
    PopElement* suivant = NULL;
	double pvalue = qualite_individu(pivot->valeur);
    while (i < taille - 1 && e != NULL){
        suivant = e->suivant;
        if (qualite_individu(e->valeur) < pvalue){
            prev->suivant = suivant;
            e->suivant = p;
            p = e;
            gauche += 1;
        } else {
            prev = e;
        }
        e = suivant;
        i += 1;
    }
    p = quicksort_population(p, gauche);
    if (p == NULL) {
        p = pivot;
    } else {
        _get_element(p, gauche - 1)->suivant = pivot;
    }
    pivot->suivant = quicksort_population(pivot->suivant, taille - gauche - 1);
    return p;
}
