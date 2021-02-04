#ifndef CAMPO_H
#define CAMPO_H

#include "Livello.h"
#include "Macchina.h"
#include "Tabellone.h"

class Campo
{
    protected:
        int larghezza;
        int altezza;
        char m[HMAX][GMAX]; //matrice su cui mettero' taniche di benzina ed ostacoli
        char bordo;     //carattere che definisce il bordo del mio campo

    public:
        Campo(int h, int l);//costruttore che setta il campo da gioco vuoto con larghezza "GMAX" e altezza "HMAX"
        virtual ~Campo();   //distruttore

        void stampa();      //stampa il campo da gioco da capo
        void scroll();      //sposta tutti gli elementi della matrice di uno in basso
        void gameover(Tabellone tab);    //stampa "game over" al centro

        int get_larghezza();//ritorna la larghezza del campo
        int get_altezza();  //ritorna l'altezza del campo

        void del_tan (int x, int y);   //cancella la tanica di benzina che inizia dall'angolo in alto a sinistra in posizione (x,y)
        void del_ost(int x, int y);    //cancella l ostacolo con estremo sinistro in alto (x,y)
        void del_car(int x, int y ); //cancello la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
        void ins_tan(int x);            //inserisco una tanica nel campo con (x,y) come coordinate dell' angolo sinisro in alto
        void ins_ost(int x, int len);   //inserisco un ostacolo di lunghezza "len" nel campo con (x,y) come coordinate dell' angolo sinisro in alto
        void ins_car(int x);    //inserisco la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
        void ins_enemy_car(int x);//inserisco la macchina nemica nel campo con (x,y) come coordinate dell' angolo sinisro in alto

        int control_collision(Livello level, int x, int y); /*funzione che data la posizione (x,y) della macchina ti restituisce:
                -0 non ho sbattuto da nessuna parte
                -ritorna il valore di cosa ho beccato */

        int control_collision_car( Livello level, int x, int y);

        int move_car_dx(Macchina* car, Livello level); /*controllo cosa � successo con la macchina spostata di una posizione a dx:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

        int move_car_sx(Macchina* car, Livello level); /*controllo cosa � successo con la macchina spostata di una posizione a sx:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

        int move_car_wx(Macchina* car, Livello level);/*controllo cosa � successo con la macchina che va solo avanti:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

        void agg_entita();/*  in base ad un numero randomico che pu� essere 0, 1 , 2 scelgo che entit� aggiungere",
                                se=0 nuova tanica,
                                se essa=1 nuovo ostacolo di lunghezza "len",
                                se essa=2 nuova macchina nemica
                                in ogni caso la posizione di partenza sara' m[1][x]
                            */
};

#endif // CAMPO_H
