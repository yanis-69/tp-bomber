#ifndef ADVERSAIRE_H_INCLUDED
#define ADVERSAIRE_H_INCLUDED
#include "joueur.h"
#include "terrain.h"
#include "bombe.h"


class Adversaire
{

public:
    
    
    /**
     * @brief prioité pour les bots 
     * 
     */
    int x,y,rand_dir;
    joueur ordi;
    int priorite_actuelle=0;
    int priorite_actuelle2=0;
    int priorite_actuelle3=0;

    
    Adversaire();
    /**
     * @brief deplace le joueur j dans une direction donné
     * 
     * @param t 
     * @param j 
     * @param direction 
     */
    void deplacer(terrain& t, joueur& j,  int direction);
    
    /**
     * @brief récupère la priorité actuel en fonction des évenements
     * 
     * @param jp 
     * @param j 
     * @param bp 
     * @param b 
     * @param t 
     * @return int 
     */
    int action(joueur jp, joueur j,bombe bp,bombe b, terrain& t);

    /**
     * @brief génère un random
     * 
     * @param a 
     * @param b 
     * @return int 
     */
    int rand_a_b(int a, int b);

};

#endif // ADVERSAIRE_H_INCLUDED
