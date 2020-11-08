#ifndef TABELLONE_H
#define TABELLONE_H

#include "OtherFunctions.h"

class Tabellone
{

    protected:
        int tempo;      //contatore secondi di gioco
        int punteggio;  //contatore punteggio

    public:
        Tabellone();            //costruttore
        virtual ~Tabellone();   //distruttore

        void set_tempo(int time);   //modifico la variabile tempo sostituendola con temp

        void inc_punt(int score);   //aumento il punteggio del valore "score" che puo' essere anche negativo
        void inc_tempo();           //aumento di uno il contatore dei secondi

        int get_tempo();            //ritorna il secondo di giioco al quale sono arrivato fino ad ora
        int get_punt();             //ritorna il punteggio al quale sono arrivato fino ad ora


        void stampa_tab();          //stampa tabellone
        void aggiorna(int score);   //incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone
};

#endif // TABELLONE_H