#ifndef LIVELLO_H
#define LIVELLO_H

#include "OtherFunctions.h"

class Livello
{
    protected:
        int vel;//velocità
        int num_livello;
        int intervallo;//contiene il valore durante ogni quale deve essere creato un nuovo ostacolo o tanica

        int p_ost;  //quanti punti vale prendere l'ostacolo (valore in negativo)
        int p_tan;  //quanti punti vale prendere la tanica (valore in positivo)
        int p_bar;  //quanti punti vale prendere la barriera (valore in negativo)
        int p_car;  //quanti punti vale prendere un'altrea car (valore in negativo)
        int levelBlocked;  //indica il numero del livello dal quale la velocita' e' bloccata, ovvero non aumentera' piu'

    public:
        Livello();          //inizializza un'istanza della classe livello con num_livello=1
        virtual ~Livello(); //distruttore

        void uplevel();     //aumenta di un livello quindi aumenta la difficolta'
        void downlevel();   //diminuisce di un livello quindi diminuisce la difficolta'

        int get_intervallo();//ritorna il valore di "intervallo"
        int get_level();    //ritorna il numero del livello attuale
        int get_vel();      //ritorna la velocita' attuale
        int get_p_ost();    //ritorna valore ostacolo
        int get_p_tan();    //...tanica
        int get_p_bar();    //...barriera
        int get_p_car();    //...car

         void info_lev ( int x);
};

#endif // LIVELLO_H
