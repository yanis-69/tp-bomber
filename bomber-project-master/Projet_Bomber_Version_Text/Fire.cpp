#include "Fire.h"

using namespace std;
extern SDL_Surface *screen;
extern SDL_Event event;

//Constructeur
fire::fire()
{
	maFlammeActuel = NULL;

	for (int i=0; i<3; i++)
	{
		clips[i] = NULL;
	}
}

fire::~fire()
{
	SDL_FreeSurface(maFlammeActuel) , maFlammeActuel = NULL;

	for (int i=0; i<3; i++)
	{
		SDL_FreeSurface(clips[i]) , clips[i] = NULL;
	}
}

bool fire::Init(int x, int y, int type)
{
	//On charge les images
	clips[0] = SDL_LoadBMP("IMG/Sprites/Items/FLAMME1.bmp");
	clips[1] = SDL_LoadBMP("IMG/Sprites/Items/FLAMME2.bmp");
	clips[2] = SDL_LoadBMP("IMG/Sprites/Items/FLAMME3.bmp");

	for (int i = 0 ; i < 3 ; i++)
	{
		if(clips[i]==NULL)
		{
    		cout << "Probleme de chargement des sprites FLAMMES" << endl;
    		return false;
		}
	}

	maFlammeActuel = clips[type];

	display     = true;
	destroy     = false;
	PosCol      = x;
	PosLig      = y;

	ecoulement.start();

    return true;
}

void fire::handle_events()
{
	// Boucle de rendu
	if(display)
	{
		int delay = ecoulement.get_ticks();

		if(delay >= 600)
		{
			display = false;
		}
	}
}
