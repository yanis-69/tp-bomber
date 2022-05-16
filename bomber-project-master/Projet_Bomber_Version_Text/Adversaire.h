#ifndef ADVERSAIRE_H_INCLUDED
#define ADVERSAIRE_H_INCLUDED
#include "Define.h"
#include "joueur.h"
#include "terrain.h"
#include "bombe.h"


class Adversaire
{

public:
    int x,y,rand_dir;
    joueur ordi;
    int priorite_actuelle=0;
    int priorite_actuelle2=0;
    int priorite_actuelle3=0;

    Adversaire();
    void deplacer(terrain& t, joueur& j,  int direction);
    int action(joueur jp, joueur j,bombe bp,bombe b, terrain& t);
    int rand_a_b(int a, int b);

};

#endif // ADVERSAIRE_H_INCLUDED
