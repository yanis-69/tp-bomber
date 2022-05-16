#ifndef H_MENU
#define H_MENU

#include "Define.h"
class Menu;



class Menu
{
	private:

		//Surfaces pour le menu
		SDL_Surface *images[3];

		//Position et taille des boutons de menu
		SDL_Rect commencer, niveau_1, niveau_2, niveau_3, niveau_4, niveau_aleatoire;

		//Fonctions privées :
		Menu(const Menu&);            //Constructeur par copie
		Menu& operator=(const Menu&); //Surcharge de l'opérateur =
	public:
		int num_page;

		//Constructeur
		Menu();
		//Destructeur
		~Menu();

		//Fonction d'initialisation
		bool init();

		//Gestion du clic
		void clic(SDL_Surface *ecran, int x, int y);

		//Fonction d'affichage
		void aff(SDL_Surface *ecran);

};

#endif
