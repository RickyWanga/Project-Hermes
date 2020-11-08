#ifndef ENTITA_H
#define ENTITA_H

#include "OtherFunctions.h"
#include <windows.h>

class Entita
{
    protected:
        COORD position;  //coordinate x y dell' angolo sinistro in alto della mia entità
        int larghezza;   //larghezza shape, la mia entità occupa l colonne
        int altezza;     //altezza shape, la mia entità occupa h righe

    public:
        Entita(int x, int y, int width, int height);    //costruttore, creo nuova istanza e gli assegn come posizione (x,y) e lunghezza ed altezza passata
        virtual ~Entita();  //distruttore

        int get_larghezza();    //ritorna larghezza entita'
        int get_altezza();      //rirorna altezza entita'
        int get_posx();         //ritorna posizione x
        int get_posy();         //ritona posizione y

        void set_coo(int x, int y);//imposta le coordinate dell'entita' a position.X=x e position.Y=y

};

#endif // ENTITA_H
