#include "bombe.h"
/**
 * @brief Construct a new bombe::bombe object
 * 
 */
bombe::bombe()
{
    nb_bombe=1;
    estpose=false;
    x=1;
    y=1;

}

/**
 * @brief actualise la position en x
 * 
 * @param xe nouveau x
 * @return int la nouvelle position de x
 */
int bombe::Setx(int xe)
{
    x=0;
    return x=xe;
}

/**
 * @brief acutalise la position de la bombe en y
 * 
 * @param ye nouveau y
 * @return int la nouvelle position de la bombe en y
 */
int bombe::Sety(int ye)
{
    y=0;
    return y=ye;
}

/**
 * @brief récupère la position de la bombe en x
 * 
 * @return int la position de la bombe en x
 */
int bombe::getBombe_x() const
{
    return x;
}

/**
 * @brief récupère la position de la bombe en y
 * 
 * @return int la position de la bombe en y
 */
int bombe::getBombe_y() const
{
    return y;
}

/**
 * @brief réduit le nombre de bombe lorqu'on pose 
 * 
 */
void bombe::pose()
{
    nb_bombe--;
}
