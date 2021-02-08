#ifndef MACCHINA_HPP
#define MACCHINA_HPP

#include "Entita.hpp"

class Macchina : public Entita{
    public:
        Macchina(int x, int y); //costruttore che setta la macchina nella posizione (x,y)

        void inc_x();   //incremento di uno la position.X
        void dec_x();   //decremento di uno la position.X
        void stampa_car();  //stampo la macchina sullo schermo con angolo sinistro in alto in posizione "position"
        void canc_car();    //cancello la macchina dallo schermo con angolo sinistro in alto in posizione "position"
};

#endif // MACCHINA_HPP
