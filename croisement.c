#include "croisement.h"

void croiser_individus(Individu a, Individu b, double probabilite){
    Element* element_a = a;  // Elements courants, restent synchronisés
    Element* element_b = b;
    double tirage;  // Conteneur pour la valeur aléatoire
    Bit temp;
    int norm_proba = (int)(probabilite * RAND_MAX);  // On normalise une fois la probabilité pour les entiers aléatoires plutôt que chaque tirage entre 0 et 1
    for (int i = 0; i < LONGUEUR_INDIVIDU; i++){
        tirage = rand();
        if(tirage < norm_proba){  // Échange des valeurs
            temp = element_a->valeur;
            element_a->valeur = element_b->valeur;
            element_b->valeur = temp;
	}
        element_a = element_a->suivant;
        element_b = element_b->suivant;
    }
}

void croiser_population(Population P, double probabilite){
    int i, taille = taille_population(P);
    PopElement* element = P;
    // On crée un table d'attribution des croisements, qu'on remplit aléatoirement avec les individus
    Individu* attribution = (Individu*)calloc(sizeof(Individu), taille);
    if (attribution == NULL){
	    printf("croiser_population : allocation failed\n");
	    exit(EXIT_FAILURE);
    }
    while (element != NULL){
        int index = rand() % taille;  // Index aléatoire attribué à l'individu
        while (attribution[index] != NULL) index = (index + 1) % taille;  // On sélectionne ensuite la prochaine case libre à partir de cet index (si la case est déjà prise)
        attribution[index] = element->valeur;
        element = element->suivant;
    }

    for (i = 0; i < taille / 2; i++){  // Puis on croise les individus deux à deux
        croiser_individus(attribution[i * 2], attribution[i * 2 + 1], probabilite);
    }
    free(attribution);
}
