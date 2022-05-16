#ifndef H_joueur
#define H_joueur

#include "terrain.h"

class joueur
{
private:
    int x,y;
    int vie;
    int nb_joueur_tue=0;

public:
    joueur();

    void gauche (const terrain & t);
    void droite (const terrain & t);
    void haut (const terrain & t);
    void bas (const terrain & t);

    int get_jtue() const;
    int Set_jtue(int j);
    int getX () const;
    int getY () const;

    void Setx(int y);
    void Sety(int x);
    int getvie() const ;
    int Setvie(int v);



};

#endif
