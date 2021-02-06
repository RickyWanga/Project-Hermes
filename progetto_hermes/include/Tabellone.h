#ifndef TABELLONE_H
#define TABELLONE_H

#include "OtherFunctions.h"


   struct nodo{
       int value;
       int livello;
       nodo* next;
   };
   typedef nodo*ptr_list;

class Tabellone
{

    protected:
        int tempo;      //contatore secondi di gioco
        int punteggio;  //contatore punteggio
        ptr_list head;  //puntatore alla testa della lista dei punteggi

    public:
        Tabellone();            //costruttore
        virtual ~Tabellone();   //distruttore

        void set_tempo(int time);   //modifico la variabile tempo sostituendola con temp

        void inc_punt(int score);   //aumento il punteggio del valore "score" che puo' essere anche negativo
        void inc_tempo();           //aumento di uno il contatore dei secondi

        int get_tempo();            //ritorna il secondo di gioco al quale sono arrivato fino ad ora
        int get_punt();             //ritorna il punteggio al quale sono arrivato fino ad ora
        ptr_list get_list();

        void stampa_tab(int x);          //stampa tabellone
        void aggiorna(int score, int x);   //incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone
        void t_insert(int value,int livello);
        int stampa_lista(int x,int y);


};

#endif // TABELLONE_H
