#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

typedef unsigned char Bit;

typedef struct _element_s Element;
struct _element_s{
    Bit valeur;
    struct _element_s* suivant;

};

typedef Element* Individu;


#endif // DEFINE_H_INCLUDED
