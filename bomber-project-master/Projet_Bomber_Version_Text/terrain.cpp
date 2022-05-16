#include "terrain.h"
#include <iostream>
#include <cassert>

using namespace std;

const char terrain2[21][21] =
{
    "####################",
    "#...MM..M..M..MM...#",
    "#.MMMM..M..M..MMMM.#",
    "#MMMMMMMM..MMMMMMMM#",
    "#.......M..M.......#",
    "#MMMMMMMMMMMMMMMMMM#",
    "#MMMM....M.....MMMM#",
    "#MM..............MM#",
    "#.MMMMMMMMMMMMMMMM.#",
    "#..................#",
    "#.MMMMMMMMMMMMMMMM.#",
    "#MM...MM.M.MM....MM#",
    "#........M.........#",
    "#....MMMMMMMMM.....#",
    "#........M.........#",
    "#MM......M.......MM#",
    "#MMMMM...M....MMMMM#",
    "#.MMMM...M....MMMM.#",
    "#...MM...M....MM...#",
    "####################"
};

// initalise le terrain par le terrain 2
terrain::terrain()
{
    dimx=21;
    dimy=21;

    for(int x=0; x<dimx; x++)
    {
        for(int y=0; y<dimy; y++)
        {
            t[y][x] = terrain2[x][y];
            cout<<t[x][y];
        }
        cout<<endl;
    }

}
// ****************************************************************************

// prend en paramètre un tableau de char et revoie un terrain
terrain::terrain(const char ter[21][21])
{
    dimx=21;
    dimy=21;

    for(int x=0; x<dimx; x++)
    {
        for(int y=0; y<dimy; y++)
        {
            t[y][x] = ter[x][y];
            cout<<t[x][y];
        }
        cout<<endl;
    }


}
// ****************************************************************************

// récupère la valeur dans x et y
char terrain::getTerain(int x,int y) const
{

    return(t[x][y]);

}
// ****************************************************************************

// modifie la valeur du terrain en x et y
char terrain::setTerrain(int x,int y,char c)
{

    return (t[x][y]=c);

}
// ****************************************************************************

// vérifie s'il n'y a pas d'obstacle
bool terrain::PositionValide (const int x, const int y) const
{

    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (t[x][y]=='.'));
}
// ****************************************************************************

// retourne la valeur en x et y
char terrain::getXY (const int x, const int y) const
{
    assert(x>=0);
    assert(y>=0);
    assert(x<dimx);
    assert(y<dimy);
    return t[x][y];
}
// ****************************************************************************

// retourne dimx
int terrain::getDimX () const
{
    return dimx;
}
// ****************************************************************************

// retourne dimy
int terrain::getDimY () const
{
    return dimy;
}
// ****************************************************************************
