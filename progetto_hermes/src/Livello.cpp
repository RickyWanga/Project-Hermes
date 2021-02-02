#include "campo.h"
#include "Livello.h"
#include <time.h>
#include <iostream>
using namespace std;

    Livello::Livello()
    {
        vel= 200;
        num_livello= 1;
        p_ost= -10;
        p_tan= 10;
        p_bar= -15;
        p_car= -20;
        intervallo= 7;
    }

    Livello::~Livello(){}

    void Livello::uplevel()
    {   /*per aumentare livello e quindi incrementare la difficoltà:
            -aumento velocità
            -aumento i punti che ti vengono tolti quando urti gli ostacoli o la barriera o la macchina nemica
            -diminuisco intervallo di creazione degli ostacoli e delle taniche(le creo più spesso)*/
        if(intervallo > 2 && vel > 20)
        {
            intervallo--;
            vel-= 15;
        }

        num_livello++;
        p_ost-= 5;
        p_bar-= 5;
        p_car-= 5;
    }

    void Livello::downlevel()
    {   //per tornare al livello precedente ripristino i parametri e quindi la difficoltà del livello precedente
        intervallo ++;
        num_livello --;
        vel+= 15;
        p_ost+= 5;
        p_bar+= 5;
        p_car+= 5;
    }

    int Livello::get_intervallo(){return intervallo;}
    int Livello::get_level(){return num_livello;}
    int Livello::get_vel(){return vel;}
    int Livello::get_p_ost(){return p_ost;}
    int Livello::get_p_tan(){return p_tan;}
    int Livello::get_p_bar(){return p_bar;}
    int Livello::get_p_car(){return p_car;}
