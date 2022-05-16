#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "joueur.h"
#include "bombe.h"
#include "SDL2/SDL.h"
#include "Timer.h"
#include "Adversaire.h"

class Jeu
{
private:
    terrain t;
    joueur j;
    joueur jp;
    joueur j2;
    joueur j3;
    bombe b;
    bombe bp;
    bombe b2;
    bombe b3;

public:
/**
 * @brief initialise les clips d'animation pou SDL j1
 * 
 */
    SDL_Surface  *clipsLeft_j1[6], *clipsRight_j1[6], *clipsUp_j1[6], *clipsDown_j1[6];
    /**
 * @brief initialise les clips d'animation pou SDL orid 1
 * 
 */
    SDL_Surface  *clipsLeft_j2[6], *clipsRight_j2[6], *clipsUp_j2[6], *clipsDown_j2[6];
    /**
 * @brief initialise les clips d'animation pou SDL ordi 2
 * 
 */
    SDL_Surface  *clipsLeft_j3[6], *clipsRight_j3[6], *clipsUp_j3[6], *clipsDown_j3[6];
    /**
 * @brief initialise les clips d'animation pou SDL ordi3
 * 
 */
    SDL_Surface  *clipsLeft_j4[6], *clipsRight_j4[6], *clipsUp_j4[6], *clipsDown_j4[6];
    /**
     * @brief image actuel stocker qui est égale a un *Clips pour j1
     * 
     */
    SDL_Surface *clips_actuel_j1 = clipsDown_j1[0];
    /**
     * @brief image actuel stocker qui est égale a un *Clips pour ordi1
     * 
     */
    SDL_Surface* clips_actuel_j2;
    /**
     * @brief image actuel stocker qui est égale a un *Clips pour ordi2
     * 
     */
    SDL_Surface* clips_actuel_j3;
    /**
     * @brief image actuel stocker qui est égale a un *Clips pour ordi3
     * 
     */
    SDL_Surface* clips_actuel_j4;
    /**
 * @brief gère le temps
 * 
 */
    Timer temps;
    /**
 * @brief gère le temps
 * 
 */
    float actualtime,lasttime;
    /**
 * @brief gère le temps
 * 
 */
    float actualtime_j2= 0;
    /**
 * @brief gère le temps
 * 
 */
    float lasttime_j2 = 0;
    /**
 * @brief gère le temps
 * 
 */
    float actualtime_j3= 0;
    /**
 * @brief gère le temps
 * 
 */
    float lasttime_j3 = 0;
    /**
 * @brief gère le temps
 * 
 */
    float actualtime_j4= 0;
    /**
 * @brief gère le temps
 * 
 */
    float lasttime_j4 = 0;
    
    /**
     * @brief initialise tous les clips
     * 
     */
    void Init_clip();
    Adversaire a;
    Jeu();
    terrain& getTerrain();

/**
 * @brief récupère l'ordi 1
 * 
 * @return joueur& 
 */
    joueur& getjoueurp();
    /**
     * @brief récupère la bombe de l'ordi1
     * 
     * @return bombe& 
     */
    bombe& getBombep();

/**
 * @brief récupère le joueur
 * 
 * @return joueur& 
 */
    joueur& getjoueur();
    /**
     * @brief récupère la bombe du joueur 
     * 
     * @return bombe& 
     */
    bombe& getBombe();

/**
 * @brief récupère l'ordi 2
 * 
 * @return joueur& 
 */
    joueur& getjoueur2();
    /**
     * @brief récupère la bombe de l'ordi 2
     * 
     * @return bombe& 
     */
    bombe& getBombe2();

/**
 * @brief récupère l'ordi 3
 * 
 * @return joueur& 
 */
    joueur& getjoueur3();
    /**
     * @brief récupère la bombe de l'ordi 3
     * 
     * @return bombe& 
     */
    bombe& getBombe3();

    const terrain& GetConstTerrain()const ;
/**
 * @brief récupère le joueur
 * 
 * @return joueur& 
 */
    const joueur& GetConstJoueur() const ;
    /**
     * @brief récupère la bombe du joueur 
     * 
     * @return bombe& 
     */
    const bombe& GetConstBombe() const;
/**
 * @brief récupère l'ordi 1
 * 
 * @return joueur& 
 */
    const joueur& GetConstJoueurp() const ;
    /**
     * @brief récupère la bombe de l'ordi 1
     * 
     * @return bombe& 
     */
    const bombe& GetConstBombep() const;
/**
 * @brief récupère l'ordi 2
 * 
 * @return joueur& 
 */
    const joueur& GetConstJoueur2() const ;
    /**
     * @brief récupère la bombe de l'ordi 2
     * 
     * @return bombe& 
     */
    const bombe& GetConstBombe2() const;
    /**
 * @brief récupère l'ordi 3
 * 
 * @return joueur& 
 */

    const joueur& GetConstJoueur3() const ;
    /**
     * @brief récupère la bombe de l'ordi 3
     * 
     * @return bombe& 
     */
    const bombe& GetConstBombe3() const;

    bool active_j1,active_j2,active_j3=true;
    bool ActionClavier(const char touche);
    void explosion( bombe& b, terrain& t, joueur& j, joueur& jp,joueur& jp2,joueur& jp3 );

};

#endif // JEU_H_INCLUDED
