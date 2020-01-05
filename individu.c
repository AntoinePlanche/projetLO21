#include "individu.h"
#include "binaire_to_decimal.h"
#include "qualite.h"

Individu creer_individu_iteratif(int longueur){
    if (longueur == 0) return NULL;
    // Construction du premier élément
    Element* p = (Element*)malloc(sizeof(Element));
    if (p == NULL){
        printf("creer_individu_iteratif() : allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->valeur = rand() & 1; // % 2;

    Element* precedent = p;
    Element* suivant = NULL;
    for(int i = 1; i < longueur; i++){
        suivant = (Element*)malloc(sizeof(Element));
	if (suivant == NULL){
	    printf("creer_individu_iteratif() : allocation failed\n");
	    exit(EXIT_FAILURE);
	}
        suivant->valeur = rand() & 1; // % 2 : Bit aléatoire
        suivant->suivant = NULL;
        precedent->suivant = suivant;
        precedent = suivant;
    }
    return p;
}

static void _creer_recursif(int longueur, Element* p){
    if (longueur > 0){
        Element* suivant = (Element*)malloc(sizeof(Element));
        if (suivant == NULL){
            printf("_creer_recursif : allocation failed");
	    exit(EXIT_FAILURE);
        }
        suivant->valeur = rand() & 1; // % 2 : Bit aléatoire
        p->suivant = suivant;
        _creer_recursif(longueur - 1, suivant);
    } else {  // Dernier élement
        p->suivant = NULL;
    }
}

Individu creer_individu_recursif(int longueur){
    if (longueur == 0) return NULL;
    // Construction du premier élement
    Element* p = (Element*)malloc(sizeof(Element));
    if (p == NULL){
        printf("creer_individu_recursif : allocation failed\n");
    }
    p->valeur = rand() & 1; // % 2;
    p->suivant = NULL;
    _creer_recursif(longueur, p);
    return p;
}


Individu copier_individu(Individu base){
    if (base == NULL) return NULL;

    Element* courant = base;
    Element* copie = (Element*)malloc(sizeof(Element));
    if (copie == NULL){
        printf("copier_individu : allocation failed\n");
	exit(EXIT_FAILURE);
    }
    copie->valeur = courant->valeur;
    copie->suivant = NULL;
    courant = courant->suivant;
    Element* element = copie;

    while (courant != NULL){
        Element* nouveau = (Element*)malloc(sizeof(Element));
        if (nouveau == NULL){
            printf("copier_individu : allocation failed\n");
            exit(EXIT_FAILURE);
        }
        nouveau->valeur = courant->valeur;
        element->suivant = nouveau;
        element = nouveau;
        courant = courant->suivant;
    }
    element->suivant = NULL;
    return copie;
}


void afficher_individu(Individu l){
    Element* actuel = l;
    while (actuel != NULL){  // Affiche bit par bit
        printf("%d", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf(" => V = %d, Q =  %lf\n", binaire_to_decimal(l), qualite_individu(l));
}

void supprimer_individu(Individu indiv){
    Element *element = indiv, *suivant;
    while (element != NULL){  // Libère la mémoire élément par élément
        suivant = element->suivant;
        free(element);
        element = suivant;
    }
}
