
#include "affiche.h"
#include <unistd.h>
using namespace std;

/**
 * @brief s'occupe de l'affichage SDL
 * 
 * @param jeu prend en paramète le jeu actuel
 * @param renderer prend en paramètre le renderer qui affiche
 * @param clips_actuel_j1 prend en paramètre le clip d'animation du joueur 
 */
// s'occupe de l'affichage
void Aff(const Jeu & jeu, SDL_Renderer* renderer,SDL_Surface* clips_actuel_j1)
{
    const terrain& t = jeu.GetConstTerrain(); // cr�ation du terrain
    const joueur& j1 = jeu.GetConstJoueur(); // c�ation du joueu principale
    const joueur& j4 = jeu.GetConstJoueurp();
    const joueur& j2 =jeu.GetConstJoueur2();
    const joueur& j3 =jeu.GetConstJoueur3();
    const bombe& b4=jeu.GetConstBombe();
    const bombe& b1=jeu.GetConstBombep();
    const bombe& b2=jeu.GetConstBombe2();
    const bombe& b3=jeu.GetConstBombe3();

    SDL_Surface* image_bloc_destructible = SDL_LoadBMP("data/Niveaux/1/bloc_destructible.bmp");
    SDL_Texture* bloc_destructible = SDL_CreateTextureFromSurface(renderer,image_bloc_destructible );

    SDL_Surface* image_bloc_indestructible = SDL_LoadBMP("data/Niveaux/1/bloc_indestructible.bmp");
    SDL_Texture* bloc_indestructible = SDL_CreateTextureFromSurface(renderer,image_bloc_indestructible );

    SDL_Surface* image_bloc_indestructible1 = SDL_LoadBMP("data/Niveaux/3/bloc_indestructible.bmp");
    SDL_Texture* bloc_libre= SDL_CreateTextureFromSurface(renderer,image_bloc_indestructible1 );

SDL_Surface* b_skin= SDL_LoadBMP("data/bombe_sup.bmp");
    SDL_Texture* text_b_skin= SDL_CreateTextureFromSurface(renderer,b_skin);

SDL_Surface*   clips_actuel_j3 = jeu.clipsDown_j3[0];
      SDL_Surface*   clips_actuel_j2 = jeu.clipsDown_j2[0];
      SDL_Surface*   clips_actuel_j4 = jeu.clipsDown_j4[0];


SDL_Texture* text_j1_skin= SDL_CreateTextureFromSurface(renderer,clips_actuel_j1);
SDL_Texture* text_j2_skin= SDL_CreateTextureFromSurface(renderer,clips_actuel_j2);
SDL_Texture* text_j3_skin= SDL_CreateTextureFromSurface(renderer,clips_actuel_j3);
SDL_Texture* text_j4_skin= SDL_CreateTextureFromSurface(renderer,clips_actuel_j4);


     SDL_Rect position_background;
    position_background.x = 0;
    position_background.y = 0;
    position_background.h = 471;
    position_background.w = 480;
SDL_Surface* background = SDL_LoadBMP("data/Niveaux/1/bg.bmp");
    SDL_Texture* text_background= SDL_CreateTextureFromSurface(renderer,background);
    // SDL_RenderCopy(renderer,text_background,nullptr,&position_background);

     SDL_Surface* niv = SDL_LoadBMP("data/niveau_aleatoire.bmp");
     SDL_Texture* text_niv = SDL_CreateTextureFromSurface(renderer,niv);

//cout<<"x ="<<j1.getX();
    // Affichage des murs
   
    SDL_Rect r;
    r.h = 34;
    r.w=21;
    for(int x=0; x<t.getDimX(); x++){
        for(int y=0; y<t.getDimY(); y++){

            if(t.getTerain(x,y) == '#')
            {
                r.x=0;
                r.y=0;
                r.x = x*34;
                r.y= y*21;
                SDL_RenderCopy(renderer,bloc_indestructible,nullptr,&r);
            }

            if(t.getTerain(x,y) == 'M')
            {
                r.x=0;
                r.y=0;
                r.x = x*34;
                r.y= y*21;
                SDL_RenderCopy(renderer,bloc_destructible,nullptr,&r);
            }
            
            if(t.getTerain(x,y) == '.')
            {
                r.x = x*34;
                r.y = y*21;
                r.w = 21;
                r.h = 34;
                SDL_RenderCopy(renderer,bloc_libre,nullptr,&r);
            }
        }
    }
    // Affichage du joueur
    
     SDL_Rect position_j1;
    position_j1.x = j1.getX() *34;
    position_j1.y = j1.getY()*20;
    position_j1.h = 36;
    position_j1.w = 23;

 
    SDL_Rect position_j2;
    position_j2.x = j2.getX() *34;
    position_j2.y = j2.getY()*20;
    position_j2.h = 36;
    position_j2.w = 23;
   SDL_RenderCopy(renderer,text_j1_skin,nullptr,&position_j1);

    //cout<<"x :"<<j2.getX();
SDL_RenderCopy(renderer,text_j2_skin,nullptr,&position_j2);

    SDL_Rect position_j3;
    position_j3.x = j3.getX() *34;
    position_j3.y = j3.getY() *20;
    position_j3.h = 36;
    position_j3.w = 23;
SDL_RenderCopy(renderer,text_j3_skin,nullptr,&position_j3);

    SDL_Rect position_j4;
    position_j4.x = j4.getX() *34;
    position_j4.y = j4.getY()*20;
    position_j4.h = 36;
    position_j4.w = 23;
SDL_RenderCopy(renderer,text_j4_skin,nullptr,&position_j4);
    

    // Affichage des Bombes
    if(b1.estpose==true)
    {
    SDL_Rect position_b1;
    position_b1.x = b1.getBombe_x()*34;
    position_b1.y = b1.getBombe_y()*20;
    position_b1.h = 30;
    position_b1.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b1);
       
    }
    if(b2.estpose==true)
    {
        SDL_Rect position_b2;
    position_b2.x = b2.getBombe_x()*34;
    position_b2.y = b2.getBombe_y()*20;
    position_b2.h = 30;
    position_b2.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b2);
    
    }
    if(b3.estpose==true)
    {
        SDL_Rect position_b3;
    position_b3.x = b3.getBombe_x()*34;
    position_b3.y = b3.getBombe_y()*20;
    position_b3.h = 30;
    position_b3.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b3);
    
    }
    if(b4.estpose==true)
    {
       SDL_Rect position_b4;
    position_b4.x = b4.getBombe_x()*34;
    position_b4.y = b4.getBombe_y()*20;
    position_b4.h = 30;
    position_b4.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b4);
     
    }
 
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    
   // SDL_RenderPresent(renderer);
}

/**
 * @brief s'occupe de la partie action du jeu et de appel Aff
 * 
 * @param jeu {prend en paramètre un jeu}
 * @param renderer { prend en paramètre un renderer pour l'affichage}
 */

// boucle du jeu
void boucle(Jeu & jeu,SDL_Renderer* renderer)
{
    jeu.temps.start();
    jeu.getjoueurp().Setx(18);
    jeu.getjoueurp().Sety(1);
     
     jeu.getjoueur().Setx(1);
     jeu.getjoueur().Sety(1);

    jeu.getjoueur2().Setx(1);
    jeu.getjoueur2().Sety(18);

    jeu.getjoueur3().Setx(18);
    jeu.getjoueur3().Sety(18);
SDL_Surface* b_skin= SDL_LoadBMP("data/bombe_sup.bmp");
    SDL_Texture* text_b_skin= SDL_CreateTextureFromSurface(renderer,b_skin);
    bool ok = true;
    bool pose = false;
    bool pose_j2 = false;
    bool pose_j3 = false;
    bool pose_j4 = false;
    bool j_mort=false;
    bool j_gagne=false;
    int i_j1 = 0;
   // int i_j2,i_j3,i_j4 = 0;
  
    int c;
    jeu.Init_clip();
    do
    {
        
        
        
      

// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
if(jeu.getjoueurp().getvie() != 0)
{
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

                    pose_j2 = true;
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
               pose_j2 = true;
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
        jeu.actualtime_j2 = SDL_GetTicks();
              
    if(jeu.actualtime_j2 - jeu.lasttime_j2 < 3000){

      if(pose_j2 == true){
        SDL_Rect position_b1;
    position_b1.x = jeu.getjoueurp().getX();
    position_b1.y = jeu.getjoueurp().getY();
    position_b1.h = 20;
    position_b1.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b1);
        if(jeu.getBombep().nb_bombe>0)
            {
                jeu.getBombep().estpose=true;
                jeu.getBombep().Setx(jeu.GetConstJoueurp().getX());
                jeu.getBombep().Sety(jeu.GetConstJoueurp().getY());
                jeu.getBombep().nb_bombe--;
                //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;
            }

      }
    }else{
         jeu.lasttime_j2 = jeu.actualtime_j2;
        if(jeu.getBombep().estpose==true)
        {
            jeu.explosion(jeu.getBombep(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueurp(), jeu.getjoueur2(), jeu.getjoueur3() );
            jeu.getBombep().estpose=false;
            jeu.getBombep().nb_bombe++;
            jeu.getBombep().Setx(900);
            
            pose_j2 = false;
            
    }
    }
}
//cout<<endl;
//cout<<"coordonne de x: "<<jeu.getjoueurp().getX()<<"   coordonne de y: "<<jeu.getjoueurp().getY();
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
if(jeu.GetConstJoueur2().getvie() != 0){
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

                pose_j3 = true;
                }
                else
                {
                    jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur2(),jeu.a.rand_a_b(0,3));
                }

            break;
        case 3:
            if(jeu.getBombe2().nb_bombe==1)
            {
                pose_j3 = true;
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

        jeu.actualtime_j3 = SDL_GetTicks();
              
    if(jeu.actualtime_j3 - jeu.lasttime_j3 < 3000){

      if(pose_j3 == true){
        SDL_Rect position_b1;
    position_b1.x = jeu.getjoueur2().getX();
    position_b1.y = jeu.getjoueur2().getY();
    position_b1.h = 20;
    position_b1.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b1);
        if(jeu.getBombe2().nb_bombe>0)
            {
                jeu.getBombe2().estpose=true;
                jeu.getBombe2().Setx(jeu.GetConstJoueur2().getX());
                jeu.getBombe2().Sety(jeu.GetConstJoueur2().getY());
                jeu.getBombe2().nb_bombe--;
                //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;
            }

      }
    }else{
         jeu.lasttime_j3 = jeu.actualtime_j3;
        if(jeu.getBombe2().estpose==true)
        {
                                jeu.explosion(jeu.getBombe2(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur2(), jeu.getjoueurp(), jeu.getjoueur3() );
            jeu.getBombe2().estpose=false;
            jeu.getBombe2().nb_bombe++;
            jeu.getBombe2().Setx(900);
            
            pose_j3 = false;
            
    }
    }
}
//cout<<endl;
//cout<<"coordonne de x: "<<jeu.getjoueurp().getX()<<"   coordonne de y: "<<jeu.getjoueurp().getY();
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
if(jeu.GetConstJoueur3().getvie() != 0){
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

pose_j4 = true;
                }
                else
                {
                    jeu.a.deplacer(jeu.getTerrain(),jeu.getjoueur3(),jeu.a.rand_a_b(0,3));
                }

            break;
        case 3:
            if(jeu.getBombe3().nb_bombe==1)
            {
                pose_j4 = true;
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

        jeu.actualtime_j4 = SDL_GetTicks();
              
    if(jeu.actualtime_j4 - jeu.lasttime_j4 < 3000){

      if(pose_j4 == true){
        SDL_Rect position_b1;
    position_b1.x = jeu.getjoueur3().getX();
    position_b1.y = jeu.getjoueur3().getY();
    position_b1.h = 20;
    position_b1.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b1);
        if(jeu.getBombe3().nb_bombe>0)
            {
                jeu.getBombe3().estpose=true;
                jeu.getBombe3().Setx(jeu.GetConstJoueur3().getX());
                jeu.getBombe3().Sety(jeu.GetConstJoueur3().getY());
                jeu.getBombe3().nb_bombe--;
                //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;
            }

      }
    }else{
         jeu.lasttime_j4 = jeu.actualtime_j4;
        if(jeu.getBombe3().estpose==true)
        {
                jeu.explosion(jeu.getBombe3(), jeu.getTerrain(), jeu.getjoueur(), jeu.getjoueur3(), jeu.getjoueur2(), jeu.getjoueurp() );
            jeu.getBombe3().estpose=false;
            jeu.getBombe3().nb_bombe++;
            jeu.getBombe3().Setx(900);
            
            pose_j4 = false;
            
    }
    }
}

//cout<<endl;
//cout<<"coordonne de x: "<<jeu.getjoueurp().getX()<<"   coordonne de y: "<<jeu.getjoueurp().getY();

// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************

     /// g�re les d�placements du joueur principal
     SDL_Event event;
     SDL_PollEvent(&event);
if (event.type == SDL_KEYDOWN){
        switch(event.type)
        {
            case SDL_QUIT:
                SDL_Quit();
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_UP){
                    jeu.ActionClavier('s');
                    if(i_j1 == 5)
                    {
                        i_j1 = 0;
                    }else {
                   jeu.clips_actuel_j1 = jeu.clipsUp_j1[i_j1];}
                }else if(event.key.keysym.sym == SDLK_RIGHT){
                    jeu.ActionClavier('d');
                    if(i_j1 == 5)
                    {
                        i_j1 = 0;
                    }else {
                   jeu.clips_actuel_j1 = jeu.clipsRight_j1[i_j1];
                    }
                }else if(event.key.keysym.sym == SDLK_DOWN){
                   jeu.ActionClavier('z');
                   if(i_j1 == 5)
                    {
                        i_j1 = 0;
                    }else {
                  
            jeu.clips_actuel_j1 = jeu.clipsDown_j1[i_j1];}
                }else if(event.key.keysym.sym == SDLK_LEFT){
                    jeu.ActionClavier('q');
                    if(i_j1 == 5)
                    {
                        i_j1 = 0;
                    }else {
                jeu.clips_actuel_j1 = jeu.clipsLeft_j1[i_j1];}
                }else if(event.key.keysym.sym == SDLK_SPACE){
                    pose = true;
                   
                }
                break;
     
            default:
                break;
        }
     }


   if(pose == true){
     jeu.actualtime = SDL_GetTicks();
     SDL_Rect position_b1;
    position_b1.x = jeu.getjoueur().getX();
    position_b1.y = jeu.getjoueur().getY();
    position_b1.h = 20;
    position_b1.w = 20;
    SDL_RenderCopy(renderer,text_b_skin,nullptr,&position_b1);
              
    if(jeu.actualtime - jeu.lasttime < 3000){
    
              if(jeu.getBombe().nb_bombe>0)
            {
                jeu.getBombe().estpose=true;
                jeu.getBombe().Setx(jeu.GetConstJoueur().getX());
                jeu.getBombe().Sety(jeu.GetConstJoueur().getY());
                jeu.getBombe().nb_bombe--;
                //cout<<"le x est :"<<jeu.GetConstBombe().getBombe_x()<<"   le y est: "<<jeu.GetConstBombe().getBombe_y()<<endl;
            }
              
              }else{
          jeu.lasttime = jeu.actualtime;
        if(jeu.getBombe().estpose==true)
        {
            jeu.explosion(jeu.getBombe(),jeu.getTerrain(),jeu.getjoueur(),jeu.getjoueur(), jeu.getjoueur2(), jeu.getjoueur3());
            jeu.getBombe().estpose=false;
            jeu.getBombe().nb_bombe++;
            jeu.getBombe().Setx(900);
            pose = false;
            if(jeu.getjoueur().getvie()==0)
            {
                j_mort=true;
                ok=false;
                SDL_Quit();
            }
            //cout<<jeu.getjoueur().getvie();
        }
     }
   }
     
     
     usleep(80000);
     Aff(jeu,renderer,jeu.clips_actuel_j1);
     //SDL_RenderClear(renderer);
        //cout<<" Vie de joueur 1 : "<<jeu.getjoueur().getvie();
    }
    while (ok);
    SDL_Quit();
}
// *******************************************************************************
// ******************************************************************************

