#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define LONGUEUR_INDIVIDU 16
#define PROBA_CROISEMENT 0.5
#define NB_SELECTION 4

typedef unsigned char Bit;

// Element d'individu
typedef struct _indiv_element_s {
    Bit valeur;
    struct _indiv_element_s* suivant;
} Element;

typedef Element* Individu;

// Element de population
typedef struct _pop_element_s {
    Individu valeur;
    struct _pop_element_s* suivant;
} PopElement;

typedef PopElement* Population;


#endif // DEFINE_H_INCLUDED
