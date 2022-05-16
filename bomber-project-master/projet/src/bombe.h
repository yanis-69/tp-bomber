#ifndef BOMBE_H_INCLUDED
#define BOMBE_H_INCLUDED
#include "joueur.h"

class bombe
{
private:
/**
 * @brief initialise le nombre de bombe max et la position d'un joueur
 * 
 */
    const int nb_bombe_max=3;
    int x,y;
    joueur j;

public:
/**
 * @brief modifie la position de x
 * 
 * @param xe 
 * @return int 
 */
    int Setx(int xe);
    /**
     * @brief modifie la position de y
     * 
     * @param ye 
     * @return int 
     */
    int Sety(int ye);

    /**
     * @brief récupère la position de la bombe en x
     * 
     * @return int 
     */
    int getBombe_x() const;
    /**
     * @brief récupère la position de la bombe en y
     * 
     * @return int 
     */
    int getBombe_y() const;
    /**
     * @brief initialise le nombre de bombe disponible
     * 
     */
    int nb_bombe;
    bombe();
    const joueur& GetConstJoueur() const ;
    /**
     * @brief réduit le nombre de bombe disponible
     * 
     */
    void pose();
    /**
     * @brief si la bombe est posé passe a true
     * 
     */
    bool estpose; 

};

#endif // BOMBE_H_INCLUDED
