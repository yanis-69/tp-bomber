#ifndef H_terrain
#define H_terrain
struct mur
{
    int pos_x,pos_y;
    bool existe;
    bool exterieur;

};


class terrain
{
private :
     /**
      * @brief dimensions de x
      * 
      */
    int dimx;
    /**
     * @brief dimensions de y
     * 
     */
    int dimy;
    /**
     * @brief tableau de caractère définissant les murs et autres 
     * 
     */
    char t [100][100];


public :


    //Le constructeur remplit dimx et dimy et les cases du tableau ter avec un terrain par d�faut.
/**
 * @brief Construct a new terrain object
 * 
 */
    terrain();
    /**
     * @brief Construct a new terrain object
     * 
     * @param ter 
     */
    terrain(const char ter[21][21]);

/**
 * @brief vérifie si la position est valide 
 * 
 * @param x 
 * @param y 
 * @return true si on peut passer
 * @return false si il y a un obstacle
 */
    bool PositionValide (const int x, const int y) const;

/**
 * @brief récupère le carctère en x et y
 * 
 * @param x 
 * @param y 
 * @return char 
 */
    char getXY (const int x, const int y) const;

/**
 * @brief récupère la caractère en x et  y
 * 
 * @param x 
 * @param y 
 * @return char 
 */
    char getTerain(int x, int y) const;

/**
 * @brief modifie le caractère du terrain 
 * 
 * @param x 
 * @param y 
 * @param c 
 * @return char 
 */
    char setTerrain(int x, int y, char c);

/**
 * @brief récupère la dimension en x
 * 
 * @return int 
 */
    int getDimX () const;

/**
 * @brief récupère la dimension en y
 * 
 * @return int 
 */
    int getDimY () const;

};




#endif
