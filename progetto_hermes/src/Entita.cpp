#include "Entita.hpp"

#include <iostream>
using namespace std;

    Entita::Entita(int x, int y)
    {
        position.X = x;
        position.Y = y;
    }

    int Entita::get_posx(){return position.X;}
    int Entita::get_posy(){return position.Y;}

    void Entita::set_coo(int x, int y)
    {
         position.X = x;
         position.Y = y;
    }
