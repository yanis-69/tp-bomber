#ifndef FLAMME_H
#define FLAMME_H
#include "Define.h"
#include "Clock.h"

//
// Définition de la classe Flamme
//

class fire
{

	public:
		SDL_Surface *maFlammeActuel, *clips[3];

		int PosCol, PosLig;

		bool display, destroy;

		Clock ecoulement;

    	//Créateur/Destructeur
    	fire();
    	~fire();

		bool Init(int x, int y, int type);
		void handle_events();
};

#endif
