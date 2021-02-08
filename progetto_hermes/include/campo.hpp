#ifndef CAMPO_HPP
#define CAMPO_HPP

#include "Livello.hpp"
#include "Macchina.hpp"
#include "Tabellone.hpp"

class Campo
{
    protected:
        int larghezza;      //numero di colonne della matrice del campo da gioco
        int altezza;        //numero di righe della matrice del campo da gioco
        char** m;           //matrice sulla quale salveremo le entità
        char bordo;         //carattere che definisce il bordo del mio campo

    public:
        Campo(int h, int l);//costruttore che setta il campo da gioco vuoto con larghezza "l" e altezza "h"
        virtual ~Campo();   //distruttore classe che mi libera lo spazio dedicato alla matrice

        void stampa();      //stampa il campo da gioco da capo
        void scroll();      //sposta tutti gli elementi della matrice di una riga in basso
        void gameover(Tabellone tab);    //stampa "game over" e le statistiche

        int get_larghezza();//ritorna la larghezza del campo
        int get_altezza();  //ritorna l'altezza del campo

        void del_tan (int x, int y);    //cancella la tanica di benzina che ha l' angolo in alto a sinistra in posizione (x,y)
        void del_ost(int x, int y);     //cancella l ostacolo che ha l' angolo in alto a sinistra in posizione (x,y)
        void del_car(int x, int y );    //cancello la macchina che ha l' angolo in alto a sinistra in posizione (x,y)
        void ins_tan(int x);            //inserisco una tanica avente come coordinate dell' angolo sinistro in alto (x,1) nella matrice
        void ins_ost(int x, int len);   //inserisco un ostacolo di lunghezza "len" avente come coordinate dell' angolo sinistro in alto (x,1) nella matrice
        void ins_enemy_car(int x);      //inserisco una macchina nemica avente come coordinate dell' angolo sinistro in alto (x,1) nella matrice

        int control_collision(Livello level, int x, int y); /*metodo che data una posizione (x,y) restituisce:
                -0 se quella posizione nella matrice non corrisponde a nulla, quindi se in (x,y) ho il campo vuoto
                - ritorna il valore dell'entità a cui appartiene il carattere nella posizione (x,y) e la elimina sia dalla matrice che dallo schermo */

        int control_collision_car( Livello level, int x, int y);//metodo che richiama il precedente, ovvero control_collision(..), su tutto il contorno della macchinina del giocatore, ne controlla quindi le collisioni nel campo da gioco

        int move_car_dx(Macchina* car, Livello level); /*controllo cosa è successo dopo aver spostato la macchina di una posizione a dx e la ristampo nella nuova posizione. Inoltre:\
                -se non urto niente, ne' i lati del campo da gioco, ne' diverse entità-> ritorna 0
                -se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

        int move_car_sx(Macchina* car, Livello level); /*controllo cosa è successo dopo aver spostato la macchina di una posizione a sx e la ristampo nella nuova posizione. Inoltre:
                -se non urto niente, ne' i lati del campo da gioco, ne' diverse entità-> ritorna 0
                -se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

        int move_car_wx(Macchina* car, Livello level);/*controllo cosa succede non muovendo la macchina (andando solo avanti):
                -se non urto niente, ne' i lati del campo da gioco, ne' diverse entità-> ritorna 0
                -se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

        void agg_entita();/*  in base ad un numero randomico che può essere 0, 1 , 2 scelgo che entità aggiungere",
                                se=0 nuova tanica,
                                se essa=1 nuovo ostacolo di lunghezza "len",
                                se essa=2 nuova macchina nemica
                                in ogni caso la posizione di partenza sara' m[1][x], ovvero inizio campo
                            */
};

#endif // CAMPO_HPP
