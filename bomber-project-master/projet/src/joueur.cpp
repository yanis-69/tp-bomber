#include "joueur.h"

/**
 * @brief Construct a new joueur::joueur object
 * 
 */
joueur::joueur ()
{
    x =1;
    y=1;
    vie=2;
    
}

/**
 * @brief acutalise la position en x
 * 
 * @param y return la nouvelle position en x
 */
void joueur::Setx(int y)
{
    x=y;
}

/**
 * @brief acutalise la position en y
 * 
 * @param x return la nouvelle position en y
 */
void joueur::Sety(int x)
{
    y=x;
}

/**
 * @brief bouge si possible le joeuur à gauche
 * 
 * @param t prend paramètre le terrain
 */
void joueur::gauche (const terrain & t)
{
    if (t.PositionValide(x-1,y)) x--;
}

/**
 * @brief bouge si possible le joeuur à droite
 * 
 * @param t prend paramètre le terrain
 */
void joueur::droite (const terrain & t)
{
    if (t.PositionValide(x+1,y)) x++;
}

/**
 * @brief bouge si possible le joeuur en haut
 * 
 * @param t prend paramètre le terrain
 */
void joueur::haut (const terrain & t)
{
    if (t.PositionValide(x,y+1)) y++;
}

/**
 * @brief bouge si possible le joeuur en bas
 * 
 * @param t prend paramètre le terrain
 */
void joueur::bas(const terrain & t)
{
    if (t.PositionValide(x,y-1)) y--;
}

/**
 * @brief acutalise la vie du joueur
 * 
 * @param v prend en paramètre le nouvelle vie
 * @return int return le nombre de vie actuelle
 */
int joueur::Setvie(int v)
{
    return vie=v;
}

/**
 * @brief actualise le nombre de joeur tué
 * 
 * @param j prend en paramètre un int
 * @return int 
 */
int joueur::Set_jtue(int j)
{
    return nb_joueur_tue=nb_joueur_tue+1;
}

/**
 * @brief obtient la position en x
 * 
 * @return int 
 */
int joueur::getX () const
{
    return x;
}

/**
 * @brief obtient la postiion en y
 * 
 * @return int 
 */
int joueur::getY () const
{
    return y;
}

/**
 * @brief obtient le nombre de tué
 * 
 * @return int 
 */
int joueur::get_jtue() const
{
    return nb_joueur_tue;
}

/**
 * @brief récupère la vie
 * 
 * @return int 
 */
int joueur::getvie() const
{
    return vie;
}
