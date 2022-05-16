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

    int dimx;
    int dimy;
    char t [100][100];


public :


    //Le constructeur remplit dimx et dimy et les cases du tableau ter avec un terrain par défaut.

    terrain();
    terrain(const char ter[21][21]);

    bool PositionValide (const int x, const int y) const;

    char getXY (const int x, const int y) const;

    char getTerain(int x, int y) const;

    char setTerrain(int x, int y, char c);

    int getDimX () const;

    int getDimY () const;

};




#endif
