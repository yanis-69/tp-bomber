#include "winTxt.h"
#include "text.h"


int main ( int argc, char** argv )
{
    termClear();
    Jeu jeu;
    txt_boucle(jeu);
    termClear();
    return 0;
}
