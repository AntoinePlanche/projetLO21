#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define LONGUEUR_INDIVIDU 8

typedef unsigned char Bit;

typedef struct _indiv_element_s {
    Bit valeur;
    struct _indiv_element_s* suivant;
} Element;

typedef Element* Individu;


typedef struct _pop_element_s {
    Individu valeur;
    struct _pop_element_s* suivant;
} PopElement;

typedef PopElement* Population;


#endif // DEFINE_H_INCLUDED
