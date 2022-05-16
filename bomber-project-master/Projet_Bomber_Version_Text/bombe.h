#ifndef BOMBE_H_INCLUDED
#define BOMBE_H_INCLUDED
#include "joueur.h"

class bombe
{
private:
    const int nb_bombe_max=3;
    int x,y;
    joueur j;

public:
    int Setx(int xe);
    int Sety(int ye);
    int getBombe_x() const;
    int getBombe_y() const;
    int nb_bombe;
    bombe();
    const joueur& GetConstJoueur() const ;
    void pose();
    bool estpose;

};

#endif // BOMBE_H_INCLUDED
