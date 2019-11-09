#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#define longIndiv 8

typedef unsigned char Bit;

typedef struct Indiv Indiv;
struct Indiv
{
    Bit binaire;
    Indiv *suivant;

};

typedef Indiv *liste;


#endif // DEFINE_H_INCLUDED
