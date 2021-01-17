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
void agg_ost_or_tan(Campo camp, bool *ost_or_tan, int *position_x, int *length_ost);

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

    char cmd='w';//inizializzo la variabile cmd (del comando) ad un valore diverso da q (ovvero quello di uscita)

    //inizializzo variabili necessarie per la creazione di ostacoli e taniche con la funzione agg_ost_or_tan(...)
    bool type_obj;
    int x;
    int len;
    int t_uplev=0, t_downlev=0; //variabili che mi dicono l'ultimo istante in cui c'è stato un uplevel o un downlevel
    int control_value; // variabile di controllo che mi denota di quanto cambia il punteggio in base se prendo una tanica o un ostacolo, se non prendo nulla è 0


    Campo camp;  //inizializzo il mio campo quindi la mia matrice
    Macchina car=Macchina(48,26);//inizializzo la macchina
    Livello level=Livello();
    Tabellone tab=Tabellone();

    camp.stampa();  //stampo il campo
    car.stampa_car();//stampo la macchina del giocatore

    while ( cmd!='q' && cmd!='Q' ){    //se comando è diverso da q (ovvero "quit")

        stop(level.get_vel());//mano a mano che aumentano i livelli va sempre più veloce

        //dopo 10 sec dall'avanzamento o decremento del livello faccio sparire il riquadro (dove c'è scritto uplevel e downlevel)
        if(tab.get_tempo()==t_uplev+10||tab.get_tempo()==t_downlev+10)
            canc_upEdown_level(camp.get_larghezza(), camp.get_altezza());

        //ogni (level.get_intervallo)sec nuovo oggetto, che può essere un ostacolo o una tanica
        if(tab.get_tempo()%level.get_intervallo()==0)
        {   //per scegliere leggo il booleano "type_obj", se esso è 0->nuovo ostacolo di lunghezza "len"; se è 1->nuova tanica
            //in ogni caso la posizione di partenza è m[1][x]
            agg_ost_or_tan(camp, &type_obj, &x, &len);
            if (type_obj)
                camp.ins_tan(x);
            else
                camp.ins_ost(x, len);
        }

        //leggo comando
        cmd=getch();

        //in base al comando scelgo uno dei 3 casi
        if (cmd==''){//se voglio uscire
            //imposto cmd=q per uscire dal ciclo
            cmd='q';
        }
        else
        {   //cancello la macchina dallo schermo ( cancello la macchina dallo schermo per poi farla ricomparire spostata)
            car.canc_car();
            //faccio scorrere il campo da gioco
            camp.scroll();

            if (cmd=='d'||cmd=='D'){  //se è 'd' va a destra
                //sposto la macchina a dx
                car.inc_x();

                //salvo il valore di ritorno, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value=camp.move_car_dx(car,level); // ogni volta che sposto la macchina devo sempre aggiornare la control_value

                //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo annullando l'ultimo spostamento
                if (control_value==level.get_p_bar()){car.dec_x();}
            }

            if (cmd=='a'||cmd=='A'){//se è 'a' va a sinistra
                //sposto la macchina a sx
                car.dec_x();// è una matrice

                //salvo il valore di ritorno, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value=camp.move_car_sx(car,level);

                //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo annullando l'ultimo spostamento
                if (control_value==level.get_p_bar()){car.inc_x();}
            }

            if (cmd!='q')//se non devo uscire
                    car.stampa_car(); //ristampo la macchina aggiornata
            }


        //aggiorno tabellone
        if((tab.get_punt()+control_value)<0)
        {//se il punteggio aggiornato con il nuovo spostamento scende sotto 0 perdo
            camp.gameover(tab);// stampa GAMEOVER
            cmd='q'; //faccio uscire dal ciclo while
        }
        else
            tab.aggiorna(control_value);//altrimenti aggiorna tabellone(aggiorno il punteggio, aumento secondi e stampo tabellone)

        //aggiorno livelli
        if(tab.get_punt()>(level.get_level()*100)) //se punteggio attuale è maggiore di numero del livello attuale*100
        {
            level.uplevel();    //aumento di livello
            print_uplevel(camp.get_larghezza(), camp.get_altezza());
            t_uplev=tab.get_tempo();// ci salviamo l'istante in cui passiamo di livello per far sparire il riquadro uplevel
        }
        if(tab.get_punt()<(level.get_level()-1)*100)//se punteggio attuale è minore di (numero del livello attuale-1)*100
        {
            level.downlevel();  //regredisci al livello precedente
            print_downlevel(camp.get_larghezza(), camp.get_altezza());
            t_downlev=tab.get_tempo();
        }
    }

    while (cmd!=''){cmd=getch();}

}

void agg_ost_or_tan(Campo camp, bool *ost_or_tan, int *position_x, int *length_ost){

    srand(time(0));
    *position_x=3+rand()%(GMAX-2); //la posizione può andare nel range [2,99], percgè a m[:][1] e m[:][100] abbiamo i bordi del campo
    *length_ost=3+rand()%5;//calcolo una lunghezza per l'ostacolo che può andare da 3 ad 8

    //attraverso un numero random scelgo se creare una tanica o un ostacolo
    if ((rand()%100)%2)
    {
        *ost_or_tan=true;
        *position_x=*position_x-1;
    }
    else
    {
        *position_x=*position_x-*length_ost;
        *ost_or_tan=false;
    }

}
