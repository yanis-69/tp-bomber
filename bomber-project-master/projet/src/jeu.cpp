#include "joueur.h"
#include "jeu.h"

using namespace std;

/**
 * @brief Construct a new Jeu:: Jeu object
 * 
 */
Jeu::Jeu()
{

}

/**
 * @brief récupère un terrain
 * 
 * @return terrain& un terrain 
 */
terrain& Jeu::getTerrain()
{
    return t;
}

/**
 * @brief récupère un terrain
 * 
 * @return const terrain& return un terrain
 */
const terrain& Jeu::GetConstTerrain() const
{
    return t;
}

/**
 * @brief récupère la bombe du joueur
 * 
 * @return bombe& la bombe du joueur
 */
bombe& Jeu::getBombe()
{
    return b;
}

/**
 * @brief récupère la bombe de l'ordi
 * 
 * @return bombe& la bombe de l'ordi
 */
bombe& Jeu::getBombep()
{
    return bp;
}

/**
 * @brief récupère la bombe de l'ordi 2
 * 
 * @return bombe& la bombe de l'ordi 2
 */
bombe& Jeu::getBombe2()
{
    return b2;
}
/**
 * @brief récupère la bombe de l'ordi 3
 * 
 * @return bombe& la bombe de l'ordi 3
 */
bombe& Jeu::getBombe3()
{
    return b3;
}

/**
 * @brief récupère la bombe du joueur
 * 
 * @return const bombe& bombe& la bombe du joueur 
 */
const bombe& Jeu::GetConstBombe() const
{
    return b;
}

/**
 * @brief récupère la bombe de l'ordi
 * 
 * @return const bombe& bombe& la bombe de l'ordi
 */
const bombe& Jeu::GetConstBombep() const
{
    return bp;
}

/**
 * @brief récupère la bombe de l'ordi 2
 * 
 * @return const bombe& bombe& la bombe de l'ordi 2
 */
const bombe& Jeu::GetConstBombe2() const
{
    return b2;
}
/**
 * @brief récupère la bombe de l'ordi 3
 * 
 * @return const bombe& bombe& la bombe de l'ordi 3
 */
const bombe& Jeu::GetConstBombe3() const
{
    return b3;
}

/**
 * @brief récupère le joueur 
 * 
 * @return joueur& return le joueur
 */
joueur& Jeu::getjoueur()
{
    return j;
}

/**
 * @brief récupère l'ordi
 * 
 * @return joueur& return l'ordi
 */
joueur& Jeu::getjoueurp()
{
    return jp;
}

/**
 * @brief récupère l'ordi
 * 
 * @return joueur& return l'ordi
 */
joueur& Jeu::getjoueur2()
{
    return j2;
}

/**
 * @brief récupère l'ordi
 * 
 * @return joueur& return l'ordi
 */
joueur& Jeu::getjoueur3()
{
    return j3;
}

/**
 * @brief récupère un joueur
 * 
 * @return const joueur& return un joueur
 */
const joueur& Jeu::GetConstJoueur() const
{
    return j;
}

/**
 * @brief récupère un ordi 
 * 
 * @return const joueur& return un ordi
 */
const joueur& Jeu::GetConstJoueurp() const
{
    return jp;
}

/**
 * @brief récupère un ordi 
 * 
 * @return const joueur& return un ordi
 */
const joueur& Jeu::GetConstJoueur2() const
{
    return j2;
}

/**
 * @brief récupère un ordi 
 * 
 * @return const joueur& return un ordi
 */
const joueur& Jeu::GetConstJoueur3() const
{
    return j3;
}

/**
 * @brief bouge le joueur selon la touche appuyé
 * 
 * @param touche prend en paramètre la touche appuyé
 * @return true 
 * @return false return toujours false
 */
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

/**
 * @brief gère l'explosion de la bombe
 * 
 * @param b pend en paarmètre le bombe à exploser
 * @param tn prend en paramètre le terrain 
 * @param j   prend en paramètre le joeuur
 * @param jp  prend en paramètre l'ordi
 * @param j2 prend en paramètre l'ordi 2
 * @param j3 prend en paramètre l'ordi 3
 */
void Jeu::explosion(bombe& b,terrain& tn,joueur& j, joueur& jp, joueur& j2, joueur& j3)
{
    char c='.';

    actualtime = SDL_GetTicks();

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


/**
 * @brief Initialise les clips d'animation pour les quatres entités
 * 
 */
void Jeu::Init_clip(){
// j1
// ********************************************************************************
    clipsUp_j1[0] = SDL_LoadBMP("data/Sprites/Bomberman/UP1.bmp");
	clipsUp_j1[1] = SDL_LoadBMP("data/Sprites/Bomberman/UP2.bmp");
	clipsUp_j1[2] = SDL_LoadBMP("data/Sprites/Bomberman/UP3.bmp");
	clipsUp_j1[3] = SDL_LoadBMP("data/Sprites/Bomberman/UP4.bmp");
	clipsUp_j1[4] = SDL_LoadBMP("data/Sprites/Bomberman/UP5.bmp");
	clipsUp_j1[5] = SDL_LoadBMP("data/Sprites/Bomberman/UP6.bmp");

	clipsDown_j1[0] = SDL_LoadBMP("data/Sprites/Bomberman/DOWN1.bmp");
	clipsDown_j1[1] = SDL_LoadBMP("data/Sprites/Bomberman/DOWN2.bmp");
	clipsDown_j1[2] = SDL_LoadBMP("data/Sprites/Bomberman/DOWN3.bmp");
	clipsDown_j1[3] = SDL_LoadBMP("data/Sprites/Bomberman/DOWN4.bmp");
	clipsDown_j1[4] = SDL_LoadBMP("data/Sprites/Bomberman/DOWN5.bmp");
	clipsDown_j1[5] = SDL_LoadBMP("data/Sprites/Bomberman/DOWN6.bmp");

	clipsLeft_j1[0] = SDL_LoadBMP("data/Sprites/Bomberman/LEFT1.bmp");
	clipsLeft_j1[1] = SDL_LoadBMP("data/Sprites/Bomberman/LEFT2.bmp");
	clipsLeft_j1[2] = SDL_LoadBMP("data/Sprites/Bomberman/LEFT3.bmp");
	clipsLeft_j1[3] = SDL_LoadBMP("data/Sprites/Bomberman/LEFT4.bmp");
	clipsLeft_j1[4] = SDL_LoadBMP("data/Sprites/Bomberman/LEFT5.bmp");
	clipsLeft_j1[5] = SDL_LoadBMP("data/Sprites/Bomberman/LEFT6.bmp");

	clipsRight_j1[0] = SDL_LoadBMP("data/Sprites/Bomberman/RIGHT1.bmp");
	clipsRight_j1[1] = SDL_LoadBMP("data/Sprites/Bomberman/RIGHT2.bmp");
	clipsRight_j1[2] = SDL_LoadBMP("data/Sprites/Bomberman/RIGHT3.bmp");
	clipsRight_j1[3] = SDL_LoadBMP("data/Sprites/Bomberman/RIGHT4.bmp");
	clipsRight_j1[4] = SDL_LoadBMP("data/Sprites/Bomberman/RIGHT5.bmp");
	clipsRight_j1[5] = SDL_LoadBMP("data/Sprites/Bomberman/RIGHT6.bmp");


// ********************************************************************************
// j2
// ********************************************************************************
    clipsUp_j2[0] = SDL_LoadBMP("data/Sprites/Ordi1/UP1.bmp");
			clipsUp_j2[1] = SDL_LoadBMP("data/Sprites/Ordi1/UP2.bmp");
			clipsUp_j2[2] = SDL_LoadBMP("data/Sprites/Ordi1/UP3.bmp");
			clipsUp_j2[3] = SDL_LoadBMP("data/Sprites/Ordi1/UP4.bmp");
			clipsUp_j2[4] = SDL_LoadBMP("data/Sprites/Ordi1/UP5.bmp");
			clipsUp_j2[5] = SDL_LoadBMP("data/Sprites/Ordi1/UP6.bmp");

			clipsDown_j2[0] = SDL_LoadBMP("data/Sprites/Ordi1/DOWN1.bmp");
			clipsDown_j2[1] = SDL_LoadBMP("data/Sprites/Ordi1/DOWN2.bmp");
			clipsDown_j2[2] = SDL_LoadBMP("data/Sprites/Ordi1/DOWN3.bmp");
			clipsDown_j2[3] = SDL_LoadBMP("data/Sprites/Ordi1/DOWN4.bmp");
			clipsDown_j2[4] = SDL_LoadBMP("data/Sprites/Ordi1/DOWN5.bmp");
			clipsDown_j2[5] = SDL_LoadBMP("data/Sprites/Ordi1/DOWN6.bmp");

			clipsLeft_j2[0] = SDL_LoadBMP("data/Sprites/Ordi1/LEFT1.bmp");
			clipsLeft_j2[1] = SDL_LoadBMP("data/Sprites/Ordi1/LEFT2.bmp");
			clipsLeft_j2[2] = SDL_LoadBMP("data/Sprites/Ordi1/LEFT3.bmp");
			clipsLeft_j2[3] = SDL_LoadBMP("data/Sprites/Ordi1/LEFT4.bmp");
			clipsLeft_j2[4] = SDL_LoadBMP("data/Sprites/Ordi1/LEFT5.bmp");
			clipsLeft_j2[5] = SDL_LoadBMP("data/Sprites/Ordi1/LEFT6.bmp");

			clipsRight_j2[0] = SDL_LoadBMP("data/Sprites/Ordi1/RIGHT1.bmp");
			clipsRight_j2[1] = SDL_LoadBMP("data/Sprites/Ordi1/RIGHT2.bmp");
			clipsRight_j2[2] = SDL_LoadBMP("data/Sprites/Ordi1/RIGHT3.bmp");
			clipsRight_j2[3] = SDL_LoadBMP("data/Sprites/Ordi1/RIGHT4.bmp");
			clipsRight_j2[4] = SDL_LoadBMP("data/Sprites/Ordi1/RIGHT5.bmp");
			clipsRight_j2[5] = SDL_LoadBMP("data/Sprites/Ordi1/RIGHT6.bmp");
// ********************************************************************************
// j3 ********************************************************************************
            clipsUp_j3[0] = SDL_LoadBMP("data/Sprites/Ordi2/UP1.bmp");
			clipsUp_j3[1] = SDL_LoadBMP("data/Sprites/Ordi2/UP2.bmp");
			clipsUp_j3[2] = SDL_LoadBMP("data/Sprites/Ordi2/UP3.bmp");
			clipsUp_j3[3] = SDL_LoadBMP("data/Sprites/Ordi2/UP4.bmp");
			clipsUp_j3[4] = SDL_LoadBMP("data/Sprites/Ordi2/UP5.bmp");
			clipsUp_j3[5] = SDL_LoadBMP("data/Sprites/Ordi2/UP6.bmp");

			clipsDown_j3[0] = SDL_LoadBMP("data/Sprites/Ordi2/DOWN1.bmp");
			clipsDown_j3[1] = SDL_LoadBMP("data/Sprites/Ordi2/DOWN2.bmp");
			clipsDown_j3[2] = SDL_LoadBMP("data/Sprites/Ordi2/DOWN3.bmp");
			clipsDown_j3[3] = SDL_LoadBMP("data/Sprites/Ordi2/DOWN4.bmp");
			clipsDown_j3[4] = SDL_LoadBMP("data/Sprites/Ordi2/DOWN5.bmp");
			clipsDown_j3[5] = SDL_LoadBMP("data/Sprites/Ordi2/DOWN6.bmp");

			clipsLeft_j3[0] = SDL_LoadBMP("data/Sprites/Ordi2/LEFT1.bmp");
			clipsLeft_j3[1] = SDL_LoadBMP("data/Sprites/Ordi2/LEFT2.bmp");
			clipsLeft_j3[2] = SDL_LoadBMP("data/Sprites/Ordi2/LEFT3.bmp");
			clipsLeft_j3[3] = SDL_LoadBMP("data/Sprites/Ordi2/LEFT4.bmp");
			clipsLeft_j3[4] = SDL_LoadBMP("data/Sprites/Ordi2/LEFT5.bmp");
			clipsLeft_j3[5] = SDL_LoadBMP("data/Sprites/Ordi2/LEFT6.bmp");

			clipsRight_j3[0] = SDL_LoadBMP("data/Sprites/Ordi2/RIGHT1.bmp");
			clipsRight_j3[1] = SDL_LoadBMP("data/Sprites/Ordi2/RIGHT2.bmp");
			clipsRight_j3[2] = SDL_LoadBMP("data/Sprites/Ordi2/RIGHT3.bmp");
			clipsRight_j3[3] = SDL_LoadBMP("data/Sprites/Ordi2/RIGHT4.bmp");
			clipsRight_j3[4] = SDL_LoadBMP("data/Sprites/Ordi2/RIGHT5.bmp");
			clipsRight_j3[5] = SDL_LoadBMP("data/Sprites/Ordi2/RIGHT6.bmp");


// ********************************************************************************
//j4
// ********************************************************************************
clipsUp_j4[0] = SDL_LoadBMP("data/Sprites/Ordi3/UP1.bmp");
			clipsUp_j4[1] = SDL_LoadBMP("data/Sprites/Ordi3/UP2.bmp");
			clipsUp_j4[2] = SDL_LoadBMP("data/Sprites/Ordi3/UP3.bmp");
			clipsUp_j4[3] = SDL_LoadBMP("data/Sprites/Ordi3/UP4.bmp");
			clipsUp_j4[4] = SDL_LoadBMP("data/Sprites/Ordi3/UP5.bmp");
			clipsUp_j4[5] = SDL_LoadBMP("data/Sprites/Ordi3/UP6.bmp");

			clipsDown_j4[0] = SDL_LoadBMP("data/Sprites/Ordi3/DOWN1.bmp");
			clipsDown_j4[1] = SDL_LoadBMP("data/Sprites/Ordi3/DOWN2.bmp");
			clipsDown_j4[2] = SDL_LoadBMP("data/Sprites/Ordi3/DOWN3.bmp");
			clipsDown_j4[3] = SDL_LoadBMP("data/Sprites/Ordi3/DOWN4.bmp");
			clipsDown_j4[4] = SDL_LoadBMP("data/Sprites/Ordi3/DOWN5.bmp");
			clipsDown_j4[5] = SDL_LoadBMP("data/Sprites/Ordi3/DOWN6.bmp");

			clipsLeft_j4[0] = SDL_LoadBMP("data/Sprites/Ordi3/LEFT1.bmp");
			clipsLeft_j4[1] = SDL_LoadBMP("data/Sprites/Ordi3/LEFT2.bmp");
			clipsLeft_j4[2] = SDL_LoadBMP("data/Sprites/Ordi3/LEFT3.bmp");
			clipsLeft_j4[3] = SDL_LoadBMP("data/Sprites/Ordi3/LEFT4.bmp");
			clipsLeft_j4[4] = SDL_LoadBMP("data/Sprites/Ordi3/LEFT5.bmp");
			clipsLeft_j4[5] = SDL_LoadBMP("data/Sprites/Ordi3/LEFT6.bmp");

			clipsRight_j4[0] = SDL_LoadBMP("data/Sprites/Ordi3/RIGHT1.bmp");
			clipsRight_j4[1] = SDL_LoadBMP("data/Sprites/Ordi3/RIGHT2.bmp");
			clipsRight_j4[2] = SDL_LoadBMP("data/Sprites/Ordi3/RIGHT3.bmp");
			clipsRight_j4[3] = SDL_LoadBMP("data/Sprites/Ordi3/RIGHT4.bmp");
			clipsRight_j4[4] = SDL_LoadBMP("data/Sprites/Ordi3/RIGHT5.bmp");
			clipsRight_j4[5] = SDL_LoadBMP("data/Sprites/Ordi3/RIGHT6.bmp");

// ********************************************************************************
// ******************************************************************************** 
}