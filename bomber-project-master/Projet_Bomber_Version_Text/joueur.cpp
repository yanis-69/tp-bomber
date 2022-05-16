#include "joueur.h"

joueur::joueur ()
{
    x =1;
    y=1;
    vie=2;
}

void joueur::Setx(int y)
{
    x=y;
}

void joueur::Sety(int x)
{
    y=x;
}

void joueur::gauche (const terrain & t)
{
    if (t.PositionValide(x-1,y)) x--;
}

void joueur::droite (const terrain & t)
{
    if (t.PositionValide(x+1,y)) x++;
}

void joueur::haut (const terrain & t)
{
    if (t.PositionValide(x,y+1)) y++;
}

void joueur::bas(const terrain & t)
{
    if (t.PositionValide(x,y-1)) y--;
}

int joueur::Setvie(int v)
{
    return vie=v;
}

int joueur::Set_jtue(int j)
{
    return nb_joueur_tue=nb_joueur_tue+1;
}

int joueur::getX () const
{
    return x;
}

int joueur::getY () const
{
    return y;
}

int joueur::get_jtue() const
{
    return nb_joueur_tue;
}

int joueur::getvie() const
{
    return vie;
}
