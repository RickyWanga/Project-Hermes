
#include "Tabellone.h"
#include <iostream>
using namespace std;

    Tabellone::Tabellone()
    {
        tempo=0;
        punteggio=0;
    }

    Tabellone::~Tabellone(){}

    void Tabellone::set_tempo(int time){tempo=time;}

    void Tabellone::inc_punt(int score){punteggio=punteggio+score;}
    void Tabellone::inc_tempo(){tempo++;}

    int Tabellone::get_tempo(){return tempo;}
    int Tabellone::get_punt(){return punteggio;}

    void Tabellone::stampa_tab()//stampa tabellone
    {
        gotoxy(0,1);
        cout<<"\t                 \t                   ";
        gotoxy(0,1);
        cout<<"\tTIME:\t"<<tempo<<"\tSCORE:\t"<<punteggio;
    }

    void Tabellone::aggiorna(int score)//incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone
    {
        punteggio=punteggio+score;
        tempo++;
        Tabellone::stampa_tab();
    }
