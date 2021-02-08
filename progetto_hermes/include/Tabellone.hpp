#ifndef TABELLONE_HPP
#define TABELLONE_HPP

#include "OtherFunctions.hpp"

//struttura che useremo per implementare la lista
struct nodo{
       int value;
       int livello;
       nodo* next;
   };
typedef nodo* ptr_list;

class Tabellone
{

    protected:
        int tempo;      //contatore secondi di gioco
        int punteggio;  //contatore punteggio
        ptr_list head;  //puntatore alla testa della lista dei UPLEVEL & DOWNLEVEL

    public:
        Tabellone();            //costruttore che setta tutti gli attributi della classe al valore iniziale
        virtual ~Tabellone();   //distruttore della classe

        int get_tempo();    //ritorna i secondi giocati fino ad ora
        int get_punt();     //ritorna il punteggio al quale sono arrivato fino ad ora
        ptr_list get_list();//ritorna la lista dei UPLEVEL & DOWNLEVEL

        void stampa_tab(int x);              //stampa tabellone dalla colonna x in poi
        void aggiorna(int score, int x);     //incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone dalla colonna x in poi
        void t_insert(int value,int livello);//inserisce un nuovo nodo nella lista con valori "value" e "livello"
        int stampa_lista(int x,int y);       //stampa la lista dei UPLEVEL & DOWNLEVEL, ovvero le statistiche di gioco


};

#endif // TABELLONE_HPP
