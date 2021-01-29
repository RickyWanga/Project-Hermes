
#include "Tabellone.h"
#include <iostream>
using namespace std;

    Tabellone::Tabellone()
    {
        tempo=0;
        punteggio=0;
        head=NULL;
    }

    Tabellone::~Tabellone(){}

    void Tabellone::set_tempo(int time){tempo=time;}

    void Tabellone::inc_punt(int score){punteggio=punteggio+score;}
    void Tabellone::inc_tempo(){tempo++;}

    int Tabellone::get_tempo(){return tempo;}
    int Tabellone::get_punt(){return punteggio;}
    ptr_list Tabellone::get_list(){return head;}

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

     void Tabellone::t_insert(int value,int livello){   // t_insert fa parte di tabellone e la lista � l'attributo di tabellone
     ptr_list tmp=new nodo;
     tmp->value=value;
     tmp->livello=livello;
     tmp->next=head;
     head=tmp;
     }


    int Tabellone::stampa_lista(int x,int y){
    ptr_list tmp=head;
    while(tmp!=NULL){
    gotoxy(x,y);
    cout<<"sei salito al livello "<<tmp->livello<< " dopo "<<tmp->value<<" secondi";
    tmp=tmp->next;
    y--;
    }
    return y; // ritorna la prima riga libera dopo la stampa della lista
    }
