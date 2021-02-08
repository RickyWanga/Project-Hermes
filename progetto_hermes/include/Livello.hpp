#ifndef LIVELLO_HPP
#define LIVELLO_HPP

#include "OtherFunctions.hpp"

class Livello
{
    protected:
        int vel;    //velocità livello corrente
        int num_livello;    //contiene il valore del livello corrente
        int intervallo;     //intervallo ogni quale deve essere creato un nuovo ostacolo o tanica

        int p_ost;  //quanti punti vale prendere l'ostacolo (valore in negativo)
        int p_tan;  //quanti punti vale prendere la tanica (valore in positivo)
        int p_bar;  //quanti punti vale prendere la barriera (valore in negativo)
        int p_car;  //quanti punti vale prendere un'altra macchina (valore in negativo)
        int levelBlocked;  //indica il numero del livello dal quale l'intervallo e' bloccato, ovvero non aumentera' piu'
        int velBlocked;   //indica il numero del livello dal quale la velocita' e' bloccata, ovvero non aumentera' piu'

    public:
        Livello();          //costruttore che inizializza la classe livello con tutti i sparametri del livello 1

        void uplevel();     //aumenta il livello e tutti i relativi parametri
        void downlevel();   //diminuisce il livello e tutti i relativi parametri

        int get_intervallo();   //ritorna il valore di "intervallo"
        int get_level();        //ritorna il numero del livello attuale
        int get_vel();          //ritorna la velocita' attuale
        int get_p_ost();        //ritorna valore ostacolo
        int get_p_tan();        //...tanica
        int get_p_bar();        //...barriera
        int get_p_car();        //...car

        void info_lev(int x);   //stampa tutte le informazioni relative al livello a video, sia il numero del livello che tutti i suoi parametri
};

#endif // LIVELLO_HPP
