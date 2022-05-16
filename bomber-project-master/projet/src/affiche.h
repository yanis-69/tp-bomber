#ifndef AFFICH_H_INCLUDED
#define AFFICH_H_INCLUDED
#include <iostream>
#include "jeu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_timer.h"


     /**
      * @brief boucle de jeu 
      * 
      * @param jeu prend en paramètre un jeu
      * @param renderer prend en paramètre un renderer pour l'affichage
      */
     void boucle(Jeu & jeu, SDL_Renderer* renderer);
#endif // AFFICH_H_INCLUDED
