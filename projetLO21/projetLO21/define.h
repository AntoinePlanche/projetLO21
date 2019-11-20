#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define LONGUEUR_INDIVIDU 8

typedef unsigned char Bit;

typedef struct _element_s Element;
struct _element_s{
    Bit valeur;
    struct _element_s* suivant;

};

typedef Element* Individu;

typedef struct p_element{
Individu valeur;
struct p_element* suivant;
}e_population;

typedef e_population* Population;


#endif // DEFINE_H_INCLUDED
