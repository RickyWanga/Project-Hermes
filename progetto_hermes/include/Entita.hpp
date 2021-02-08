#ifndef ENTITA_HPP
#define ENTITA_HPP

#include "OtherFunctions.hpp"

#include <windows.h>

class Entita
{
    protected:
        COORD position;  //coordinate dell' angolo sinistro in alto della mia entità

    public:
        Entita(int x, int y);    //costruttore, gli assegno come posizione (x,y)
        virtual ~Entita();  //distruttore

        int get_posx(); //ritorna posizione x
        int get_posy(); //ritona posizione y

        void set_coo(int x, int y);//imposta le coordinate dell'entita' a position.X=x e position.Y=y

};

#endif // ENTITA_HPP
