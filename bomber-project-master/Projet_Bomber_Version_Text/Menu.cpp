#include "Menu.h"

using namespace std;

//Nombre d'images a charger dans le menu
const int NBIMAGE=3;

//Constructeur
Menu::Menu()
{
	for(int i=0;i<NBIMAGE;i++)
		images[i] = NULL;
}

Menu::~Menu()
{
	for(int i=0;i<NBIMAGE;i++)
	{
		SDL_FreeSurface(images[i]) , images[i] = NULL;
	}
}
/*
//Fonction d'initialisation
bool Menu::init()
{
	//On charge l'image de fond
	images[0] = SDL_LoadBMP("IMG/menu.bmp");

	//Initialisation de la position du bouton Commencer
	images[1] = SDL_LoadBMP("IMG/commencer.bmp");
	commencer.x = (WIDTH-images[1]->w)/2;
	commencer.y = HEIGHT-images[1]->h-50;
	commencer.w = images[1]->w;
	commencer.h = images[1]->h;

	//Initialisation de la position du niveau 1
	niveau_1.x = 30;
	niveau_1.y = 138;
	niveau_1.w = 134; // images[2]->w;
	niveau_1.h = 103; // images[2]->h;

	//Initialisation de la position du niveau 2
	niveau_2.x = 178;
	niveau_2.y = 74;
	niveau_2.w = 134; // images[3]->w;
	niveau_2.h = 103; // images[3]->h;

	//Initialisation de la position du niveau 3
	niveau_3.x = 326;
	niveau_3.y = 138;
	niveau_3.w = 134; // images[4]->w;
	niveau_3.h = 103; // images[4]->h;

	//Initialisation de la position du niveau aleatoire
	niveau_aleatoire.x = 178;
	niveau_aleatoire.y = 231;
	niveau_aleatoire.w = 134; // images[6]->w;
	niveau_aleatoire.h = 103; // images[6]->h;

	images[2] = SDL_LoadBMP("IMG/bg.bmp");

	//On teste le retour du chargement
	for(int i=0;i<NBIMAGE;i++)
	{
		if(images[i]==NULL)
		{
			cout << "Probleme de chargement d'une des images du menu" << endl;
			return false;
		}
	}

	//Mise en place de la transparence
	for(int i=1;i<NBIMAGE;i++)
	{
		if(i != 2)
			SDL_SetColorKey(images[i],SDL_SRCCOLORKEY,0);
	}

	num_page = 1;

	return true;
}
*/
//Gestion du clic
void Menu::clic(SDL_Surface *screen, int x, int y)
{
	if(num_page == 1)
	{
		/* Page principale */

		if((commencer.x<x)&&(commencer.x+commencer.w>x)&&(commencer.y<y)&&(commencer.y+commencer.h>y))
		{
			//Menu Commencer
			cout << "------------------" << endl;
			cout << "Choix du niveau:  " << endl;
			cout << "------------------" << endl;

			num_page = 2;
		}
	}
	else if(num_page == 2)
	{
		/* Choix du niveau */

		if((niveau_1.x<x)&&(niveau_1.x+niveau_1.w>x)&&(niveau_1.y<y)&&(niveau_1.y+niveau_1.h>y))
		{
			//Menu choix du niveau 1
			cout << "------------------" << endl;
			cout << "Bomberman:        " << endl;
			cout << "--> niveau 1      " << endl;
			cout << "------------------" << endl;


		}
		else if((niveau_2.x<x)&&(niveau_2.x+niveau_2.w>x)&&(niveau_2.y<y)&&(niveau_2.y+niveau_2.h>y))
		{
			//Menu choix du niveau 2
			cout << "------------------" << endl;
			cout << "Bomberman:        " << endl;
			cout << "--> niveau 2      " << endl;
			cout << "------------------" << endl;


		}
		else if((niveau_3.x<x)&&(niveau_3.x+niveau_3.w>x)&&(niveau_3.y<y)&&(niveau_3.y+niveau_3.h>y))
		{
			//Menu choix du niveau 3
			cout << "------------------" << endl;
			cout << "Bomberman:        " << endl;
			cout << "--> niveau 3      " << endl;
			cout << "------------------" << endl;


		}
		else if((niveau_aleatoire.x<x)&&(niveau_aleatoire.x+niveau_aleatoire.w>x)&&(niveau_aleatoire.y<y)&&(niveau_aleatoire.y+niveau_aleatoire.h>y))
		{
			//Menu choix du niveau Aléatoire
			cout << "------------------" << endl;
			cout << "Bomberman:        " << endl;
			cout << "--> niveau aleatoire " << endl;
			cout << "------------------" << endl;


		}

	}
}

//Fonction d'affichage
void Menu::aff(SDL_Surface *screen)
{
	if(num_page == 1)
	{
		if(images[0] && images[1])
		{
			SDL_BlitSurface(images[0],NULL,screen,NULL);
			SDL_BlitSurface(images[1],NULL,screen,&commencer);
		}
	}
	else if(num_page == 2)
	{
		if(images[2])
		{
			SDL_BlitSurface(images[2],NULL,screen,NULL);
		}

	}
}
