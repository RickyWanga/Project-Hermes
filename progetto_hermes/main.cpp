#include "OtherFunctions.h"
#include "Entita.h"
#include "Livello.h"
#include "Macchina.h"
#include "Ostacolo.h"
#include "Tabellone.h"
#include "Tanica.h"
#include "campo.h"


#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <windows.h>

using namespace std;

void start_game();
void agg_entita(Campo* camp, int *length_ost);

int main()
{
   /* stampo nome del gioco
    dopo tot secondi stampo il caricamento e poi il menu
    leggo la scelta
    esegui
    */

    caricamento();
    stop(7000000000000000000000000000000);
    int scelta=0;

    while(scelta!=2){
        stampa_menu();
        cin>>scelta;

        if(scelta==0)
         start_game();

        if (scelta==1)
        {
            stampa_info();
            system("pause");
        }
    }

    return 0;
}

void start_game(){

    char cmd= 'w';//inizializzo la variabile cmd (del comando) ad un valore diverso da q (ovvero quello di uscita)

    //inizializzo variabili necessarie per la creazione di ostacoli e taniche con la funzione agg_ost_or_tan(...)
    int type_obj;
    int x;
    int len;
    int t_uplev= 0, t_downlev= 0; //variabili che mi dicono l'ultimo istante in cui c'� stato un uplevel o un downlevel
    int control_value; // variabile di controllo che mi denota di quanto cambia il punteggio in base se prendo una tanica o un ostacolo, se non prendo nulla � 0


    Campo camp;  //inizializzo il mio campo quindi la mia matrice
    Macchina car= Macchina(48, 26);//inizializzo la macchina
    Livello level= Livello();
    Tabellone tab= Tabellone();

    camp.stampa();  //stampo il campo
    car.stampa_car();//stampo la macchina del giocatore

    while ( cmd != 'q' && cmd != 'Q' ){    //se comando � diverso da q (ovvero "quit")
        Sleep(level.get_vel());//mano a mano che aumentano i livelli va sempre pi� veloce

        //dopo 10 sec dall'avanzamento o decremento del livello faccio sparire il riquadro (dove c'� scritto uplevel e downlevel)
        if( tab.get_tempo() == t_uplev+ 10 || tab.get_tempo() == t_downlev+ 10 )
            canc_upEdown_level(camp.get_larghezza(), camp.get_altezza());

        /*ogni (level.get_intervallo)sec nuovo oggetto, che puo' essere
            un ostacolo, una macchina nemica o una tanica*/
        if( ( tab.get_tempo()% level.get_intervallo() ) == 0 )
        {   /*  per scegliere leggo la variabile "type_obj",
                se=0 nuova tanica,
                se essa=1 nuovo ostacolo di lunghezza "len",
                se essa=2 nuova macchina
                in ogni caso la posizione di partenza sara' m[1][x]
            */
            agg_entita(&camp, &len);
        }

        //controllo se e' stato premuto un tasto
        if(kbhit())
            cmd=getch(); //leggo comando
        else
            cmd='w';

        //in base al comando scelgo uno dei 4 casi
        if (cmd=='')//se voglio uscire
            cmd='q';  //imposto cmd=q per uscire dal ciclo
        else
        {   //cancello la macchina dallo schermo ( cancello la macchina dallo schermo per poi farla ricomparire spostata)
            car.canc_car();
            //faccio scorrere il campo da gioco
            camp.scroll();

            if (cmd== 'd' || cmd== 'D'){  //se e' 'd' va a destra
                //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value= camp.move_car_dx( &car, level );
            }

            if (cmd== 'a'|| cmd== 'A'){//se e' 'a' va a sinistra
                //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value= camp.move_car_sx( &car, level );
            }

            if (cmd== 'w' || cmd== 'W'){//se e' 'w' va avanti
                //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value= camp.move_car_wx( &car, level );
            }

            if (cmd!= 'q')//se non devo uscire
                    car.stampa_car(); //ristampo la macchina aggiornata
            }

        //aggiorno tabellone
        if( (tab.get_punt()+ control_value) < 0)
        {//se il punteggio aggiornato con il nuovo spostamento scende sotto 0 perdo
            camp.gameover(tab);// stampa GAMEOVER
            cmd= 'q'; //faccio uscire dal ciclo while
        }
        else
            tab.aggiorna(control_value);//altrimenti aggiorna tabellone(aggiorno il punteggio, aumento secondi e stampo tabellone)

        //aggiorno livelli
        if( tab.get_punt() > (level.get_level()* 100) ) //se punteggio attuale � maggiore di numero del livello attuale*100
        {
            level.uplevel();    //aumento di livello
            print_uplevel(camp.get_larghezza(), camp.get_altezza());
            t_uplev= tab.get_tempo();// ci salviamo l'istante in cui passiamo di livello per far sparire il riquadro uplevel
        }
        if(tab.get_punt() < (level.get_level()-1)* 100)//se punteggio attuale � minore di (numero del livello attuale-1)*100
        {
            level.downlevel();  //regredisci al livello precedente
            print_downlevel(camp.get_larghezza(), camp.get_altezza());
            t_downlev= tab.get_tempo();
        }
    }

    while (cmd != ''){ cmd= getch(); }

}

void agg_entita(Campo* camp, int *length_ost){

    srand(time(0));
    int x= 2+ rand()% (GMAX-3); //la posizione puo' andare nel range [2,99], perche' a m[:][1] e m[:][100] abbiamo i bordi del campo
    *length_ost= 3+ rand()% 5; //calcolo una lunghezza per l'ostacolo che pu� andare da 3 ad 8

    //attraverso un numero random scelgo se creare una tanica o un ostacolo
    int type_obj= rand()% 2;

    if(type_obj == 0){ //nuova tanica
        if ( x > GMAX- 3 ) x-= 3; //se la nuova entità andrebbe a finore sul bordo destro la sposto
        camp->ins_tan(x);
    }

   if(type_obj == 1){ //nuovo ostacolo
        if ( x > ( GMAX- *length_ost+ 1 ) ) x= x- *length_ost- 2; //se la nuova entità andrebbe a finore sul bordo destro la sposto
        camp->ins_ost(x, *length_ost);
    }

   if(type_obj == 2){ //nuova macchina nemica
        if ( x > GMAX -4 ) x-= 4; //se la nuova entità andrebbe a finore sul bordo destro la sposto
        camp->ins_car(x);
    }
}
