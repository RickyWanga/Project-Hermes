
#include "Entita.h"
#include <iostream>
using namespace std;

    Entita::Entita(int x, int y, int width, int height)
    {
        position.X=x;
        position.Y=y;
        larghezza=width;
        altezza=height;
    }

    Entita::~Entita(){}

    int Entita::get_larghezza(){return larghezza;}
    int Entita::get_altezza(){return altezza;}

    int Entita::get_posx(){return position.X;}
    int Entita::get_posy(){return position.Y;}

    void Entita::set_coo(int x, int y)
     {
         position.X=x;
         position.Y=y;
     }
