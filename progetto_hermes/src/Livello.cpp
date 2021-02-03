#include "campo.h"
#include "Livello.h"

#include <time.h>
#include <iostream>

using namespace std;

    Livello::Livello()
    {
        vel = 200;
        num_livello = 1;
        p_ost = -10;
        p_tan = 20;
        p_bar = -15;
        p_car = -20;
        intervallo = 7;
        levelBlocked = -1;
    }

    Livello::~Livello(){}

    void Livello::uplevel()
    {   /*per aumentare livello e quindi incrementare la difficoltà:
            -aumento velocità
            -aumento i punti che ti vengono tolti quando urti gli ostacoli o la barriera o la macchina nemica
            -diminuisco intervallo di creazione degli ostacoli e delle taniche(le creo più spesso)*/
        if(levelBlocked == -1){
            if(intervallo > 3 && vel > 20)
            {
                intervallo--;
                vel-= 15;
            }else levelBlocked = num_livello;
        }

        num_livello++;
        p_ost-= 5;
        p_bar-= 5;
        p_car-= 5;
        p_tan+= 2;
    }

    void Livello::downlevel()
    {   //per tornare al livello precedente ripristino i parametri e quindi la difficoltà del livello precedente

        if(levelBlocked != -1){

            if(num_livello == levelBlocked)
            {
                intervallo ++;
                vel+= 15;
                levelBlocked = -1;
            }
        }else {
            intervallo ++;
            vel+= 15;
        }

        num_livello --;
        p_ost+= 5;
        p_bar+= 5;
        p_car+= 5;
        p_tan-= 2;
    }

    int Livello::get_intervallo(){return intervallo;}
    int Livello::get_level(){return num_livello;}
    int Livello::get_vel(){return vel;}
    int Livello::get_p_ost(){return p_ost;}
    int Livello::get_p_tan(){return p_tan;}
    int Livello::get_p_bar(){return p_bar;}
    int Livello::get_p_car(){return p_car;}

    void Livello::info_lev ( int x){
        gotoxy(x, 20);
        cout<< "\t   !!INFO LIVELLO!!   ";
        gotoxy(x, 21);
        cout<< "\t                      ";
        gotoxy(x, 21);
        cout<<"\tLivello: "<< num_livello;
        gotoxy(x, 22);
        cout<< "\t                      ";
        gotoxy(x, 22);
        cout <<"\tVelocita': "<< vel;
        gotoxy(x, 23);
        cout<< "\t                      ";
        gotoxy(x, 23);
        cout<<"\tIntervallo: "<<intervallo;
        gotoxy(x, 24);
        cout<< "\t                      ";
        gotoxy(x, 24);
        cout<<"\tPunti tanica: "<<p_tan;
        gotoxy(x, 25);
        cout<< "\t                      ";
        gotoxy(x, 25);
        cout<<"\tPunti ostacolo: "<<p_ost;
        gotoxy(x, 26);
        cout<< "\t                      ";
        gotoxy(x, 26);
        cout<<"\tPunti car: "<<p_car;
        gotoxy(x, 27);
        cout<< "\t                      ";
        gotoxy(x, 27);
        cout<<"\tPunti barriera: "<<p_bar;

    }
