#include "Timer.h"

using namespace std;
extern SDL_Surface *screen;

/**
 * @brief Construct a new Timer:: Timer object
 * 
 */
Timer::Timer()
{
    //Initialisation des variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

/**
 * @brief initialise le temps
 * 
 */
void Timer::start()
{
    //On demarre le timer
    started = true;

    //On enl�ve la pause du timer
    paused = false;

    //On r�cup�re le temps courant
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    //On stoppe le timer
    started = false;

    //On enl�ve la pause
    paused = false;
}

void Timer::pause()
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

void Timer::unpause()
{
    //Si le timer est en pause
    if( paused == true )
    {
        //on enl�ve la pause du timer
        paused = false;

        //On remet � zero le startTicks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Remise � zero du pausedTicks
        pausedTicks = 0;
    }
}

int Timer::get_ticks()
{
    //Si le timer est en marche
    if( started == true )
    {
        //Si le timer est en pause
        if( paused == true )
        {
            //On retourne le nombre de ticks quand le timer a �t� mis en pause
            return pausedTicks;
        }
        else
        {
            //On retourne le temps courant moins le temps quand il a d�marr�
            return SDL_GetTicks() - startTicks;
        }
    }

    //Si le timer n'est pas en marche
    return 0;
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}
