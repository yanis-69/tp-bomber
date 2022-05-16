#include "affiche.h"
#include <iostream>
#include "SDL2/SDL.h"


int main ( int argc, char** argv )
{
    Jeu jeu;
SDL_Window* pWindow = NULL;
pWindow = SDL_CreateWindow("Ma premi�re application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  700,
                                                                 600,
                                                                  SDL_WINDOW_SHOWN);
    //SDL_Renderer* renderer =SDL_CreateRenderer(pWindow, -1 , SDL_RENDERER_SOFTWARE);
    SDL_Renderer* renderer_s =SDL_CreateRenderer(pWindow, -1 , SDL_RENDERER_SOFTWARE);     
    
   
    while(pWindow){
    
    SDL_RenderClear(renderer_s);
    boucle(jeu,renderer_s);                                                
    
}   

}