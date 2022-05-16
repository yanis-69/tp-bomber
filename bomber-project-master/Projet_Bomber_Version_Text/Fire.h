#ifndef FLAMME_H
#define FLAMME_H
#include "Define.h"
#include "Clock.h"

//
// D�finition de la classe Flamme
//

class fire
{

	public:
		SDL_Surface *maFlammeActuel, *clips[3];

		int PosCol, PosLig;

		bool display, destroy;

		Clock ecoulement;

    	//Cr�ateur/Destructeur
    	fire();
    	~fire();

		bool Init(int x, int y, int type);
		void handle_events();
};

#endif
