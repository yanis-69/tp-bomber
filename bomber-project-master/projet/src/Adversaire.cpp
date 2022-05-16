#include "Adversaire.h"
#include <time.h>
#include <stdlib.h>

Adversaire::Adversaire()
{

}

/**
 * @brief déplace le joueur selon une direction donné
 * 
 * @param t prend en paramètre un terrain
 * @param j prend en paramètre un ordinateur
 * @param direction prend en paramète une direction entre 0 et 3
 */
// gere les deplacements d'un joueur en fonction de la direction
void Adversaire::deplacer(terrain& t,joueur& j, int direction)
{
    //cout<<direction;
    switch(direction)
    {
    case 0:
        if (t.PositionValide(j.getX(),j.getY()+1))
        {
            j.Sety(j.getY()+1);

        }
        break;
    case 1:
        if (t.PositionValide(j.getX(),j.getY()-1))
        {
            j.Sety(j.getY()-1);
        }
        break;
    case 2:
        if (t.PositionValide(j.getX()+1,j.getY()))
        {
            j.Setx(j.getX()+1);
        }
        break;
    case 3:
        if (t.PositionValide(j.getX()-1,j.getY()))
        {
            j.Setx(j.getX()-1);
        }
        break;
    default:
        break;
    }
}
//***************************************************************************************************
//***************************************************************************************************


/**
 * @brief Défini la priorité du bot selon les actions autour de lui
 * 
 * @param jp {prend en paramèter un joueur (l'ordi)}
 * @param j {prend un paramètre le player }
 * @param bp {bombe ordi}
 * @param b {bombe joueur}
 * @param t { terrain sur leqeul on joue }
 * @return int {retourne la priorité }
 */
int Adversaire::action(joueur jp, joueur j,bombe bp,bombe b,terrain& t)
{
    if(t.getTerain(j.getX()+1,j.getY()=='.')
            || t.getTerain(j.getX()-1,j.getY()=='.')
            || t.getTerain(j.getX(),j.getY()+1=='.')
            || t.getTerain(j.getX(),j.getY()-1=='.') )
    {
        priorite_actuelle=1;
    }

    if(t.getTerain(j.getX()+1,j.getY()=='M')
            || t.getTerain(j.getX()-1,j.getY()=='M')
            || t.getTerain(j.getX(),j.getY()+1=='M')
            || t.getTerain(j.getX(),j.getY()-1=='M') )
    {
        priorite_actuelle=2;
    }

    // si on rencontre un joueur on passe en priorit� 3
    if(jp.getX()==j.getX()+1 || jp.getX()==j.getX()-1 || jp.getY()==j.getY()-1 ||jp.getY()==j.getY()+1 )
    {
        priorite_actuelle=3;
    }
    //***************************************************************************************************
    //***************************************************************************************************

    // si on rencontre une bombe priorit� 4
    if(  (j.getX()==bp.getBombe_x() && j.getY()==bp.getBombe_y())  // j meme pose que bombe
            || (j.getX()+1 ==bp.getBombe_x() && j.getY()==bp.getBombe_y()) // j a gauche de la bombe
            || (j.getX()-1==bp.getBombe_x()&& j.getY()==bp.getBombe_y())  // j a droite
            || (j.getX()==bp.getBombe_x() && j.getY()-1==b.getBombe_y())  // bombe en dessous
            || (j.getX()==bp.getBombe_x() && j.getY()+1==bp.getBombe_y()) ) // bombe au dessus
    {
        priorite_actuelle=4;
    }
    //***************************************************************************************************
    //***************************************************************************************************

    return priorite_actuelle;
}

/**
 * @brief fonction rand
 * 
 * @param a {minimum}
 * @param b {maximum}
 * @return int {return un nombre aléatoire}
 */
// fonction rand
int Adversaire::rand_a_b(int a, int b)
{
    return rand() % (b - a+1) + a;
}
//***************************************************************************************************
