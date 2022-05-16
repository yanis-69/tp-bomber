#include "joueur.h"
#include "Jeu.h"

using namespace std;


Jeu::Jeu()
{

}

terrain& Jeu::getTerrain()
{
    return t;
}

const terrain& Jeu::GetConstTerrain() const
{
    return t;
}

bombe& Jeu::getBombe()
{
    return b;
}

bombe& Jeu::getBombep()
{
    return bp;
}

bombe& Jeu::getBombe2()
{
    return b2;
}
bombe& Jeu::getBombe3()
{
    return b3;
}


const bombe& Jeu::GetConstBombe() const
{
    return b;
}

const bombe& Jeu::GetConstBombep() const
{
    return bp;
}
const bombe& Jeu::GetConstBombe2() const
{
    return b2;
}
const bombe& Jeu::GetConstBombe3() const
{
    return b3;
}


joueur& Jeu::getjoueur()
{
    return j;
}

joueur& Jeu::getjoueurp()
{
    return jp;
}

joueur& Jeu::getjoueur2()
{
    return j2;
}

joueur& Jeu::getjoueur3()
{
    return j3;
}

const joueur& Jeu::GetConstJoueur() const
{
    return j;
}

const joueur& Jeu::GetConstJoueurp() const
{
    return jp;
}
const joueur& Jeu::GetConstJoueur2() const
{
    return j2;
}
const joueur& Jeu::GetConstJoueur3() const
{
    return j3;
}

bool Jeu::ActionClavier(const char touche)
{
    switch(touche)
    {
    case 'z':
        j.haut(t);
        break;
    case 's':
        j.bas(t);
        break;
    case 'q':
        j.gauche(t);
        break;
    case 'd':
        j.droite(t);
        break;
    }
    return false;
}

void Jeu::explosion(bombe& b,terrain& tn,joueur& j, joueur& jp, joueur& j2, joueur& j3)
{
    char c='.';

    if(b.estpose==true)
    {

        if(t.getTerain(b.getBombe_x()+1,b.getBombe_y())=='M')
        {
            t.setTerrain(b.getBombe_x()+1,b.getBombe_y(),c);
        }

        if(t.getTerain(b.getBombe_x()-1,b.getBombe_y())=='M')
        {
            t.setTerrain(b.getBombe_x()-1,b.getBombe_y(),c);
        }

        if(t.getTerain(b.getBombe_x(),b.getBombe_y()+1)=='M')
        {
            t.setTerrain(b.getBombe_x(),b.getBombe_y()+1,c);
        }

        if(t.getTerain(b.getBombe_x(),b.getBombe_y()-1)=='M')
        {
            t.setTerrain(b.getBombe_x(),b.getBombe_y()-1,c);
        }

//***************************************************************************************************
//***************************************************************************************************

        if(b.getBombe_x()-1==j.getX() && b.getBombe_y()==j.getY())
        {
            j.Setvie(j.getvie()-1);
        }

        if(b.getBombe_x()+1==j.getX() && b.getBombe_y()==j.getY())
        {
            j.Setvie(j.getvie()-1);
        }

        if(b.getBombe_x()==j.getX() && b.getBombe_y()+1==j.getY())
        {
            j.Setvie(j.getvie()-1);
        }

        if(b.getBombe_x()==j.getX() && b.getBombe_y()-1==j.getY())
        {
            j.Setvie(j.getvie()-1);
        }
//***************************************************************************************************
//***************************************************************************************************

        if(b.getBombe_x()-1==jp.getX() && b.getBombe_y()==jp.getY())
        {
            jp.Setvie(jp.getvie()-1);
        }

        if(b.getBombe_x()+1==jp.getX() && b.getBombe_y()==jp.getY())
        {
            j.Setvie(j.getvie()-1);
        }

        if(b.getBombe_x()==jp.getX() && b.getBombe_y()+1==jp.getY())
        {
            jp.Setvie(jp.getvie()-1);
        }

        if(b.getBombe_x()==jp.getX() && b.getBombe_y()-1==jp.getY())
        {
            j.Setvie(jp.getvie()-1);
        }
//***************************************************************************************************
//***************************************************************************************************
        if(active_j2)
        {
            if(b.getBombe_x()-1==j2.getX() && b.getBombe_y()==j2.getY())
            {
                j.Setvie(j2.getvie()-1);
            }

            if(b.getBombe_x()+1==j2.getX() && b.getBombe_y()==j2.getY())
            {
                j2.Setvie(j2.getvie()-1);
            }

            if(b.getBombe_x()==j2.getX() && b.getBombe_y()+1==j2.getY())
            {
                j2.Setvie(j2.getvie()-1);
            }

            if(b.getBombe_x()==j2.getX() && b.getBombe_y()-1==j2.getY())
            {
                j2.Setvie(j2.getvie()-1);
            }
        }

//***************************************************************************************************
//***************************************************************************************************

        if(active_j3)
        {
            if(b.getBombe_x()-1==j3.getX() && b.getBombe_y()==j3.getY())
            {
                j3.Setvie(j3.getvie()-1);
            }

            if(b.getBombe_x()+1==j3.getX() && b.getBombe_y()==j3.getY())
            {
                j3.Setvie(j3.getvie()-1);
            }

            if(b.getBombe_x()==j3.getX() && b.getBombe_y()+1==j3.getY())
            {
                j3.Setvie(j3.getvie()-1);
            }

            if(b.getBombe_x()==j3.getX() && b.getBombe_y()-1==j3.getY())
            {
                j3.Setvie(j3.getvie()-1);
            }
        }


    }
}


