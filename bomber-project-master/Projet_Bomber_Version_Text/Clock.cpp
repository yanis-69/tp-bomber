#include "Clock.h"

using namespace std;
extern SDL_Surface *screen;


Clock::Clock()
{
    //Initialisation des variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Clock::start()
{
    //On demarre le timer
    started = true;

    //On enlève la pause du timer
    paused = false;

    //On récupére le temps courant
    //startTicks = SDL_GetTicks();
    SDL_GetTicks();
}

void Clock::stop()
{
    //On stoppe le timer
    started = false;

    //On active la pause
    paused = false;
}

void Clock::pause()
{
    //Si le timer est en marche et pas encore en pause
    if( ( started == true ) && ( paused == false ) )
    {
        //On met en pause le timer
        paused = true;

        //On calcul le pausedTicks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Clock::unpause()
{
    //Si le timer est en pause
    if( paused == true )
    {
        //on enlève la pause du timer
        paused = false;

        //On remet à zero le startTicks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Remise à zero du pausedTicks
        pausedTicks = 0;
    }
}

int Clock::get_ticks()
{
    //Si le timer est en marche
    if( started == true )
    {
        //Si le timer est en pause
        if( paused == true )
        {
            //On retourne le nombre de ticks quand le timer a été mis en pause
            return pausedTicks;
        }
        else
        {
            //On retourne le temps courant moins le temps quand il a démarré
            return SDL_GetTicks() - startTicks;
        }
    }

    //Si le timer n'est pas en marche
    return 0;
}

bool Clock::is_started()
{
    return started;
}

bool Clock::is_paused()
{
    return paused;
}
