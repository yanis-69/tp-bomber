#ifndef H_joueur
#define H_joueur

#include "terrain.h"

class joueur
{
private:
/**
 * @brief initialise tous les paramètres de base
 * 
 */
    int x,y;
    /**
 * @brief initialise tous les paramètres de base
 * 
 */
    int vie;
    /**
 * @brief initialise tous les paramètres de base
 * 
 */
    int nb_joueur_tue=0;

public:
/**
 * @brief Construct a new joueur object
 * 
 */
    joueur();
 
    /**
     * @brief demande un mouvements a gauche
     * 
     * @param t le terrain de jeu
     */
    void gauche (const terrain & t);
    /**
     * @brief demande un mouvements a droite
     * 
     * @param t le terrain de jeu
     */
    void droite (const terrain & t);
    /**
     * @brief demande un mouvements en haut
     * 
     * @param t le terrain de jeu
     */
    void haut (const terrain & t);
    /**
     * @brief demande un mouvements en bas
     * 
     * @param t le terrain de jeu
     */
    void bas (const terrain & t);

 /**
  * @brief recupère le nombre de tué
  * 
  * @return int 
  */
    int get_jtue() const;
    /**
     * @brief tue un ordi
     * 
     * @param j 
     * @return int 
     */
    int Set_jtue(int j);
    /**
     * @brief réupère x
     * 
     * @return int 
     */
    int getX () const;
    /**
     * @brief récupère y
     * 
     * @return int 
     */
    int getY () const;

    /**
     * @brief défini x
     * 
     * @param y 
     */
    void Setx(int y);
    /**
     * @brief défini y
     * 
     * @param x 
     */
    void Sety(int x);
    /**
     * @brief récupère la vie
     * 
     * @return int 
     */
    int getvie() const ;
    /**
     * @brief modifie la vie acutelle
     * 
     * @param v 
     * @return int 
     */
    int Setvie(int v);



};

#endif
