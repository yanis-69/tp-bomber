#include "terrain.h"
#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief création du terrain
 * 
 */
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

/**
 * @brief Construct a new terrain::terrain object
 * 
 */
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

/**
 * @brief Construct a new terrain::terrain object
 * 
 * @param ter 
 */
// prend en param�tre un tableau de char et revoie un terrain
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

/**
 * @brief récupère la valeur du terrain en x et y donné
 * 
 * @param x 
 * @param y 
 * @return char la valeur du terrain
 */
// r�cup�re la valeur dans x et y
char terrain::getTerain(int x,int y) const
{

    return(t[x][y]);

}
// ****************************************************************************

/**
 * @brief Modifie la valeur du terrain
 * 
 * @param x 
 * @param y 
 * @param c
 * @return char la valeur en x y
 */
// modifie la valeur du terrain en x et y
char terrain::setTerrain(int x,int y,char c)
{

    return (t[x][y]=c);

}
// ****************************************************************************

/**
 * @brief vérifie si il n'y a pas d'obstacle
 * 
 * @param x 
 * @param y 
 * @return true si on peux bouger
 * @return false il y a un obstacle devant
 */
// v�rifie s'il n'y a pas d'obstacle
bool terrain::PositionValide (const int x, const int y) const
{

    return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (t[x][y]=='.'));
}
// ****************************************************************************

// retourne la valeur en x et y
/**
 * @brief récupère la valeur en x et y du terrain
 * 
 * @param x 
 * @param y 
 * @return char 
 */
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
/**
 * @brief récupère les dimensions du terrain horizontale
 * 
 * @return int les dimensions en x
 */
int terrain::getDimX () const
{
    return dimx;
}
// ****************************************************************************

// retourne dimy
/**
 * @brief récupère les dimensions du terrain verticale
 * 
 * @return int les dimensions en y
 */
int terrain::getDimY () const
{
    return dimy;
}
// ****************************************************************************
