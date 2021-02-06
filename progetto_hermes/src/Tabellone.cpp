#include "Tabellone.h"

#include <iostream>
using namespace std;

    Tabellone::Tabellone()
    {
        tempo = 0;
        punteggio = 0;
        head = NULL;
    }

    Tabellone::~Tabellone(){}

    int Tabellone::get_tempo(){return tempo;}
    int Tabellone::get_punt(){return punteggio;}
    ptr_list Tabellone::get_list(){return head;}

    void Tabellone::stampa_tab(int x)//stampa tabellone
    {
        gotoxy(x, 3);
        cout<<"\t\t                 ";
        gotoxy(x, 4);
        cout<<"\t\t                 ";


        setColor('y');
        gotoxy(x, 2);
        cout<<"\t\t!!INFO GIOCO!!";
        gotoxy(x, 3);
        cout<<"\t\t  TIME:  "<< tempo;
        gotoxy(x, 4);
        cout<<"\t\t  SCORE:  "<< punteggio;
    }

    void Tabellone::aggiorna(int score, int x)//incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone
    {
        punteggio = punteggio + score;
        tempo++;
        Tabellone::stampa_tab(x);
    }

    void Tabellone::t_insert(int value,int livello)// t_insert inserisce in codo un nuovo nodo alla lista "head"
    {
        ptr_list tmp = head ;

        //creo nuovo elemento
        ptr_list tail = new nodo;
        tail->value = value;
        tail->livello = livello;
        tail->next = NULL;

        if(tmp == NULL){head = tail;}
        else {
            while(tmp->next != NULL) { tmp = tmp->next; } //scorriamo la lista finche' non arriviamo all' ultimo elemento
            //inseriamo il nuovo elemento in coda
            tmp->next = tail;
        }
    }


    int Tabellone::stampa_lista(int x,int y)
    {
        ptr_list tmp = head;
        int oldlev = 0;

        while(tmp != NULL){
            gotoxy(x, y);
            if( oldlev < tmp->livello ){
                setColor('w');
                cout<<"Sei salito al livello "<<tmp->livello<< " dopo "<<tmp->value<<" secondi";
            }else{
                setColor('r');
                cout<<"Sei sceso al livello "<<tmp->livello<< " dopo "<<tmp->value<<" secondi";

            }
            oldlev = tmp->livello;
            tmp = tmp->next;
            y++;
        }
        return y; // ritorna la prima riga libera dopo la stampa della lista
    }
