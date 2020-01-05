#include "population.h"

Population creer_population(int taille){
    if (taille == 0) return NULL;
    PopElement* P = (PopElement*)malloc(sizeof(PopElement));
    if (P == NULL){
        printf("creer_population() : allocation failed\n");
        exit(EXIT_FAILURE);
    }
    P->valeur = creer_individu(LONGUEUR_INDIVIDU);
    PopElement* precedent = P;
    PopElement* suivant = NULL;
    for (int i = 1; i < taille; i++){
        suivant = (PopElement*)malloc(sizeof(PopElement));
        if (suivant == NULL){
            printf("creer_population() : allocation failed\n");
            exit(EXIT_FAILURE);
        }
        suivant->valeur = creer_individu(LONGUEUR_INDIVIDU);
        suivant->suivant = NULL;
        precedent->suivant = suivant;
        precedent = suivant;
    }
    return P;
}

int taille_population(Population P){
    int taille = 0;
    PopElement* element = P;
    while (element != NULL){
        taille += 1;
        element = element->suivant;
    }
    return taille;
}

void selectionner_population(Population P, int nb){
    int i;
    PopElement* courant = P;  // Element courant de la liste
    PopElement* base = P;  // Element du début de la liste
    for (int i = 0; i < nb && courant->suivant != NULL; i++){  // Passe les *nb* premiers élements
        courant = courant->suivant;
    }
    i = 1;  // Compteur de l'élément de remplacement
    while (courant != NULL){
        supprimer_individu(courant->valeur);  // Remplace la valeur par celle du début de la liste : supprime l'original puis copie celui du début
        courant->valeur = copier_individu(base->valeur);
        i += 1;
        if (i > nb){  // Arrivé à *nb* : retour au début de la liste pour les éléments de la liste
            i = 1;
            base = P;
        } else {  // Sinon passe à l'élément de remplacement suivant
            base = base->suivant;
        }
        courant = courant->suivant;
    }
}

void afficher_population(Population P){
    PopElement* courant = P;
    while (courant != NULL){
        afficher_individu(courant->valeur);
        courant = courant->suivant;
    }
}

Individu meilleur_individu(Population P){
    Individu meilleur = P->valeur;  // Meilleur élement trouvé jusque là
    int qualite, maxqualite = qualite_individu(meilleur);  // tampon de la qualité de l'élement courant, qualité de *meilleur*
    while (P->suivant != NULL){
        P = P->suivant;
        qualite = qualite_individu(P->valeur);
        if (qualite > maxqualite){  // P est meilleur que *meilleur*, on remplace
            meilleur = P->valeur;
            maxqualite = qualite;
        }
    }
    return meilleur;
}

void supprimer_population(Population P){
    PopElement *element = P, *suivant;
    while (element != NULL){
        suivant = element->suivant;
        supprimer_individu(element->valeur);
        free(element);
        element = suivant;
    }
}
