#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "Wintxt.h"
#include "text.h"
#include "jeu.h"
#include "bombe.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_timer.h"
#include "Adversaire.h"
using namespace std;

/// menu d'affichage du d�but
const char menu[9][57]=
{
    "                                                   ",
    "     *****************************************     ",
    "     *                                       *     ",
    "     *  Bienvenue dans Le Jeu Bomberman      *     ",
    "     *                                       *     ",
    "     *  Appuyer sur Y pour commencer le jeu  *     ",
    "     *                                       *     ",
    "     *****************************************     ",
    "                                                   "
};

/// menu de mort du joueur principale
const char fin_J1_mort[9][57]=
{
    "                                                   ",
    "     *****************************************     ",
    "     *                                       *     ",
    "     *              Game Over                *     ",
    "     *                                       *     ",
    "     *  Vous avez epuisez toutes vos vies    *     ",
    "     *                                       *     ",
    "     *****************************************     ",
    "                                                   "
};

/// menu de victoire du joueuer principale
const char fin_J1_gagne[9][57]=
{
    "                                                   ",
    "     *****************************************     ",
    "     *                                       *     ",
    "     *              Felicitation             *     ",
    "     *                                       *     ",
    "     *  Vous avez epuisez toutes les vies    *     ",
    "     *       de vos adversaires              *     ",
    "     *****************************************     ",
    "                                                   "
};

// s'occupe de l'affichage
void txtAff(WinTXT & win, const Jeu & jeu)
{
    const terrain& t = jeu.GetConstTerrain(); // cr�ation du terrain
    const joueur& j = jeu.GetConstJoueur(); // c�ation du joueu principale
    const joueur& jp= jeu.GetConstJoueurp();
    const joueur& j2=jeu.GetConstJoueur2();
    const joueur& j3=jeu.GetConstJoueur3();
    const bombe& b=jeu.GetConstBombe();
    const bombe& bp=jeu.GetConstBombep();
    const bombe& b2=jeu.GetConstBombe2();
    const bombe& b3=jeu.GetConstBombe3();
    // const Fantome& fan = jeu.getConstFantome();
    win.clear();
    // Affichage des murs
    for(int x=0; x<t.getDimX(); ++x)
        for(int y=0; y<t.getDimY(); ++y)
            win.print(x,y,t.getXY(x,y));

    // Affichage du joueur
    win.print(j.getX(),j.getY(),'P');
    win.print(jp.getX(),jp.getY(),'I');
    win.print(j2.getX(),j2.getY(),'J');
    win.print(j3.getX(),j3.getY(),'K');
    // Affichage des Bombes
    if(b.estpose==true)
    {
        win.print(b.getBombe_x(),b.getBombe_y(),'B');
        //cout<<b.getBombe_x()<<b.getBombe_y();
    }
    

    win.draw();
}

// ****************************************************************************
// ****************************************************************************
// permet d'afficher le menu
void menuaff(WinTXT &win, const char t[9][57])
{
    win.clear();
    for(int i=0; i<9; i++)
    {
        for(int y=0; y<57; y++)
        {
            cout<<t[i][y];
        }
        cout<<endl;
    }

    win.draw();
}
// ****************************************************************************
// ****************************************************************************

// boucle du jeu
void txt_boucle (Jeu & jeu)
{
    // Creation d'une nouvelle fenetre en mode texte
    // => fenetre de dimension (WIDTH,HEIGHT)
    WinTXT win (jeu.GetConstTerrain().getDimX(),jeu.GetConstTerrain().getDimY());
    WinTXT winmenu(0,0);
    WinTXT win_jmort(0,0);
    WinTXT win_jgagne(0,0);
    jeu.getjoueurp().Setx(18);
    jeu.getjoueurp().Sety(1);

    jeu.getjoueur2().Setx(1);
    jeu.getjoueur2().Sety(18);

    jeu.getjoueur3().Setx(18);
    jeu.getjoueur3().Sety(18);

    bool ok = true;
    bool j_mort=false;
    bool j_gagne=false;
    int c;

    termClear();
// ****************************************************************************
// ****************************************************************************

// affiche le menu de d�part ************************
    do
    {
        menuaff(winmenu,menu);
#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32

        c = win.getCh();
        if(c=='y')
        {
            ok=false;
        }

    }
    while (ok);
// ****************************************************************************
// ****************************************************************************
    termClear();
    ok=true;
// ****************************************************************************
// ****************************************************************************

    do
    {

        txtAff(win,jeu);

#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32

// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************

    /// g�re l'ordi plac� cot� haut droit
        // jeu.actionsAutomatiques();
        jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueurp(),jeu.a.rand_a_b(0,3));
        // cout<<"le rand est : "<<jeu.a.rand_a_b(0,3)<<"            ";
        //cout<<jeu.a.rand_a_b(0,3);
        int b=jeu.a.action(jeu.getjoueur(),jeu.getjoueurp(),jeu.getBombe(),jeu.getBombep(),jeu.getTerrain());
//cout<<b;

        switch(b)
        {
        case 1:
            jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueurp(),jeu.a.rand_a_b(0,3));
            break;
        case 2:
            if(jeu.a.priorite_actuelle==2)
            {
                if(jeu.getBombep().nb_bombe>0)
                {


                    jeu.getBombep().estpose=true;
                    jeu.getBombep().Setx(jeu.GetConstJoueurp().getX());
                    jeu.getBombep().Sety(jeu.GetConstJoueurp().getY());
                    jeu.getBombep().nb_bombe--;
                    //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;

                    jeu.explosion(jeu.getBombep(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueurp(), jeu.getjoueur2(), jeu.getjoueur3() );

                }
                else
                {
                    jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueurp(),jeu.a.rand_a_b(0,3));
                }
            }
            break;
        case 3:
            if(jeu.getBombep().nb_bombe==1)
            {
                jeu.explosion(jeu.getBombep(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueurp(), jeu.getjoueur2(), jeu.getjoueur3() );
            }
            else
            {
                jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueurp(),jeu.a.rand_a_b(0,3));
            }
            break;
        case 4:
            jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueurp(),jeu.a.rand_a_b(0,3));
            break;
        default:
            break;
        }

        if(jeu.getBombep().estpose==true)
        {
            jeu.explosion(jeu.getBombep(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueurp(), jeu.getjoueur2(), jeu.getjoueur3() );
            jeu.getBombep().estpose=false;
            jeu.getBombep().nb_bombe++;
            jeu.getBombep().Setx(0);
        }

//cout<<endl;
//cout<<"coordonne de x: "<<jeu.getjoueurp().getX()<<"   coordonne de y: "<<jeu.getjoueurp().getY();
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
    /// g�re l'ordi plac� cot� Bas Gauche
        // jeu.actionsAutomatiques();
        jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur2(),jeu.a.rand_a_b(0,3));
        // cout<<"le rand est : "<<jeu.a.rand_a_b(0,3)<<"            ";
        //cout<<jeu.a.rand_a_b(0,3);
        int d=jeu.a.action(jeu.getjoueur(),jeu.getjoueur2(),jeu.getBombe(),jeu.getBombe2(),jeu.getTerrain());
//cout<<b;

        switch(d)
        {
        case 1:
            jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur2(),jeu.a.rand_a_b(0,3));
            break;
        case 2:
                if(jeu.getBombe2().nb_bombe>0)
                {


                    jeu.getBombe2().estpose=true;
                    jeu.getBombe2().Setx(jeu.GetConstJoueur2().getX());
                    jeu.getBombe2().Sety(jeu.GetConstJoueur2().getY());
                    jeu.getBombe2().nb_bombe--;
                    //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;

                    jeu.explosion(jeu.getBombe2(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur2(), jeu.getjoueurp(), jeu.getjoueur3() );

                }
                else
                {
                    jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur2(),jeu.a.rand_a_b(0,3));
                }

            break;
        case 3:
            if(jeu.getBombe2().nb_bombe==1)
            {
                jeu.explosion(jeu.getBombe2(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur2(), jeu.getjoueurp(), jeu.getjoueur3() );
            }
            else
            {
                jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur2(),jeu.a.rand_a_b(0,3));
            }
            break;
        case 4:
            jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur2(),jeu.a.rand_a_b(0,3));
            break;
        default:
            break;
        }

        if(jeu.getBombe2().estpose==true)
        {
            jeu.explosion(jeu.getBombe2(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur2(), jeu.getjoueurp(), jeu.getjoueur3() );
            jeu.getBombe2().estpose=false;
            jeu.getBombe2().nb_bombe++;
            jeu.getBombe2().Setx(0);
        }

//cout<<endl;
//cout<<"coordonne de x: "<<jeu.getjoueurp().getX()<<"   coordonne de y: "<<jeu.getjoueurp().getY();
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************

    /// g�re l'ordi plac� cot� Bas Droit
        // jeu.actionsAutomatiques();
        jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur3(),jeu.a.rand_a_b(0,3));
        // cout<<"le rand est : "<<jeu.a.rand_a_b(0,3)<<"            ";
        //cout<<jeu.a.rand_a_b(0,3);
        int e=jeu.a.action(jeu.getjoueur(),jeu.getjoueur3(),jeu.getBombe(),jeu.getBombe3(),jeu.getTerrain());
//cout<<b;

        switch(e)
        {
        case 1:
            jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur3(),jeu.a.rand_a_b(0,3));
            break;
        case 2:

                if(jeu.getBombe3().nb_bombe>0)
                {
                    jeu.getBombe3().estpose=true;
                    jeu.getBombe3().Setx(jeu.GetConstJoueur3().getX());
                    jeu.getBombe3().Sety(jeu.GetConstJoueur3().getY());
                    jeu.getBombe3().nb_bombe--;
                    //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;

                    jeu.explosion(jeu.getBombe3(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur3(), jeu.getjoueur2(), jeu.getjoueurp() );

                }
                else
                {
                    jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur3(),jeu.a.rand_a_b(0,3));
                }

            break;
        case 3:
            if(jeu.getBombe3().nb_bombe==1)
            {
                jeu.explosion(jeu.getBombe3(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur3(), jeu.getjoueur2(), jeu.getjoueurp() );
            }
            else
            {
                jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur3(),jeu.a.rand_a_b(0,3));
            }
            break;
        case 4:
            jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur3(),jeu.a.rand_a_b(0,3));
            break;
        default:
            break;
        }

        if(jeu.getBombe3().estpose==true)
        {
            jeu.explosion(jeu.getBombe3(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur3(), jeu.getjoueur2(), jeu.getjoueurp() );
            jeu.getBombe3().estpose=false;
            jeu.getBombe3().nb_bombe++;
            jeu.getBombe3().Setx(0);
        }


//cout<<endl;
//cout<<"coordonne de x: "<<jeu.getjoueurp().getX()<<"   coordonne de y: "<<jeu.getjoueurp().getY();

// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************

     /// g�re les d�placements du joueur principale
        c = win.getCh();

        switch (c)
        {
        case 'q':
            jeu.ActionClavier('q');
            break;
        case 'd':
            jeu.ActionClavier('d');

            break;
        case 's':
            jeu.ActionClavier('z');
            break;
        case 'z':
            jeu.ActionClavier('s');
            break;

        case 'b':
            if(jeu.getBombe().nb_bombe>0)
            {
                jeu.getBombe().estpose=true;
                jeu.getBombe().Setx(jeu.GetConstJoueur().getX());
                jeu.getBombe().Sety(jeu.GetConstJoueur().getY());
                jeu.getBombe().nb_bombe--;
                //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;


            }
            break;

        }

        if(jeu.getBombe().estpose==true)
        {
            jeu.explosion(jeu.getBombe(),jeu.getTerrain(),jeu.getjoueur(),jeu.getjoueur(), jeu.getjoueur2(), jeu.getjoueur3());
            jeu.getBombe().estpose=false;
            jeu.getBombe().nb_bombe++;
            jeu.getBombe().Setx(0);

            if(jeu.getjoueur().getvie()==0)
            {
                j_mort=true;
                ok=false;
            }
            //cout<<jeu.getjoueur().getvie();

        }
        cout<<" Vie de joueur 1 : "<<jeu.getjoueur().getvie();


    }
    while (ok);
// *******************************************************************************
// *******************************************************************************

    ok=true;
    termClear();

// *******************************************************************************
// *******************************************************************************
/// affiche l'�cran de victoire *****************************
    while(ok==true && j_gagne==true)
    {
        menuaff(win_jgagne,fin_J1_gagne);
#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32


        c = win.getCh();
        switch(c)
        {
        case 'q':
            ok=false;
            break;
        }

    }


// **************************************************************************************
// **************************************************************************************

    termClear();

// *******************************************************************************
// *******************************************************************************
/// affiche game over quand le joueur *****************
    while(ok==true || j_mort==true)
    {
        menuaff(win_jmort,fin_J1_mort);
#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32

        // jeu.actionsAutomatiques();

        c = win.getCh();
        switch(c)
        {
        case 'q':
            ok=false;
            break;
        }
        cout<<c;

    }
// ****************************************************************************
// ****************************************************************************
    termClear();


}

// ****************************************************************************
// ****************************************************************************
