#include "bombe.h"

bombe::bombe()
{
    nb_bombe=1;
    estpose=false;
    x=1;
    y=1;

}

int bombe::Setx(int xe)
{
    x=0;
    return x=xe;
}

int bombe::Sety(int ye)
{
    y=0;
    return y=ye;
}

int bombe::getBombe_x() const
{
    return x;
}

int bombe::getBombe_y() const
{
    return y;
}
void bombe::pose()
{
    nb_bombe--;
}
