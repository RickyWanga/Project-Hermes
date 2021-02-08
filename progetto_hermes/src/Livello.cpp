#include "Livello.hpp"

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
        intervallo = 10;
        levelBlocked = -1;
        velBlocked = -1;
    }

    Livello::~Livello(){}

    void Livello::uplevel()
    {   /*per aumentare livello e quindi incrementare la difficoltà:
            -aumento velocità
            -aumento i punti che ti vengono tolti quando urti gli ostacoli o la barriera o la macchina nemica
            -aumento i punti della tanica (di poco)
            -diminuisco intervallo di creazione delle entita'(le creo più spesso)*/

        if(levelBlocked == -1){ //se e' -1 posso diminuire l'intervallo senza problemi
            if(intervallo > 3)
            {
                intervallo--;
            }else levelBlocked = num_livello;
        }

        if(velBlocked == -1){//se e' -1 posso diminuire la velocita' senza problemi
            if(vel > 20)
            {
                vel-= 20;
            }else velBlocked = num_livello;
        }

        num_livello++;
        p_ost-= 5;
        p_bar-= 5;
        p_car-= 5;
        p_tan+= 2;
    }

    void Livello::downlevel()
    {   //per tornare al livello precedente ripristino i parametri e quindi la difficoltà del livello precedente

        if(levelBlocked != -1){//se e' -1 posso aumentare l'intervallo senza problemi

            if(num_livello == levelBlocked)
            {
                intervallo ++;
                levelBlocked = -1;
            }
        }else {
            intervallo ++;
        }

        if(velBlocked != -1){//se e' -1 posso aumentare la velocita' senza problemi

            if(num_livello == velBlocked)
            {
                vel+= 20;
                velBlocked = -1;
            }
        }else {
            vel+= 20;
        }

        num_livello --;
        p_ost+= 5;
        p_bar+= 5;
        p_car+= 5;
        p_tan-= 2;
    }

    //vari getter degli attributi
    int Livello::get_intervallo(){return intervallo;}
    int Livello::get_level(){return num_livello;}
    int Livello::get_vel(){return vel;}
    int Livello::get_p_ost(){return p_ost;}
    int Livello::get_p_tan(){return p_tan;}
    int Livello::get_p_bar(){return p_bar;}
    int Livello::get_p_car(){return p_car;}

    void Livello::info_lev ( int x)
    {//stampa tutte le informazioni relative al livello a video, sia il numero del livello che tutti i suoi parametri
        gotoxy(x, 20);
        cout<< "\t\t   !!INFO LIVELLO!!   ";
        gotoxy(x, 21);
        cout<< "\t\t                      ";
        gotoxy(x, 21);
        cout<<"\t\tLivello: "<< num_livello;
        gotoxy(x, 22);
        cout<< "\t\t                      ";
        gotoxy(x, 22);
        cout <<"\t\tVelocita': "<< 250 - vel;
        gotoxy(x, 23);
        cout<< "\t\t                      ";
        gotoxy(x, 23);
        cout<<"\t\tIntervallo: "<<intervallo;
        gotoxy(x, 24);
        cout<< "\t\t                      ";
        gotoxy(x, 24);
        cout<<"\t\tPunti tanica: "<<p_tan;
        gotoxy(x, 25);
        cout<< "\t\t                      ";
        gotoxy(x, 25);
        cout<<"\t\tPunti ostacolo: "<<p_ost;
        gotoxy(x, 26);
        cout<< "\t\t                      ";
        gotoxy(x, 26);
        cout<<"\t\tPunti car: "<<p_car;
        gotoxy(x, 27);
        cout<< "\t\t                      ";
        gotoxy(x, 27);
        cout<<"\t\tPunti barriera: "<<p_bar;

    }
