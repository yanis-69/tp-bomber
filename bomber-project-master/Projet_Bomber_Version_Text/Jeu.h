#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "joueur.h"
#include "bombe.h"
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
    Adversaire a;
    Jeu();
    terrain& getTerrain();

    joueur& getjoueurp();
    bombe& getBombep();

    joueur& getjoueur();
    bombe& getBombe();

    joueur& getjoueur2();
    bombe& getBombe2();

    joueur& getjoueur3();
    bombe& getBombe3();

    const terrain& GetConstTerrain()const ;

    const joueur& GetConstJoueur() const ;
    const bombe& GetConstBombe() const;

    const joueur& GetConstJoueurp() const ;
    const bombe& GetConstBombep() const;

    const joueur& GetConstJoueur2() const ;
    const bombe& GetConstBombe2() const;

    const joueur& GetConstJoueur3() const ;
    const bombe& GetConstBombe3() const;

    bool active_j1,active_j2,active_j3=true;
    bool ActionClavier(const char touche);
    void explosion( bombe& b, terrain& t, joueur& j, joueur& jp,joueur& jp2,joueur& jp3 );

};

#endif // JEU_H_INCLUDED
