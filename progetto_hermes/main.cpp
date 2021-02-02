#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <windows.h>

#include "OtherFunctions.h"
#include "Entita.h"
#include "Livello.h"
#include "Macchina.h"
#include "Ostacolo.h"
#include "Tabellone.h"
#include "Tanica.h"
#include "campo.h"

using namespace std;

void start_game();
void agg_entita(Campo* camp);

int main()
{
    ShowConsoleCursor(false);

    //facciamo stampare il caricamento del gioco
    caricamento();

    //attendiamo un secondo per non far scomparire subito il caricamento
    Sleep(250);

    //inizializzo la variabile che userò per leggere i comandi
    int x;
    COORD co;
    co.Y=0;

    //entro nel loop per far stampare il menù
    while(co.Y!=4){ // se co.Y==4 significa che ho scelto l'opzione "Esci"
        //reimposto la variabile per leggere il comando a qualcosa che non fa nulla, ovvero che non mi fa uscire dal gioco e che non mi fa camminare le frecce
        x='m';
        //setto le coordinate dalle quali stampare il menù e lo stampo
        /*co.X=20;
        co.Y=7;*/
        stampa_menu();
        co.X=21;
        co.Y=2;

        while(x!= 13) //quando x==13 significa che ho premuto invio
        {
            gotoxy(co.X,co.Y);
            setColor('b');
            cout<<"<---";
            x=getch();
            gotoxy(co.X,co.Y);
            cout<<"                        ";

            if(x=='s'||x=='S') //se la freccia deve andare giù
            {
                if(co.Y==4) {co.Y=2;}
                else {co.Y++;}
            }

            if(x=='w'||x=='W') //se la freccia deve andare su
            {
                if(co.Y==2) {co.Y=4;}
                else {co.Y--;}
            }
        }
        //in base a dove ho premuto invio faccio il comando correlato
        if(co.Y==2) {start_game();}
        if(co.Y==3) {stampa_info();}
    }
    return 0;
}

void start_game(){

    char cmd= 'w';//inizializzo la variabile cmd (del comando) ad un valore diverso da q (ovvero quello di uscita)
    int t_uplev= 0, t_downlev= 0; //variabili che mi dicono l'ultimo istante in cui c'� stato un uplevel o un downlevel
    int control_value; // variabile di controllo che mi denota di quanto cambia il punteggio in base se prendo una tanica o un ostacolo, se non prendo nulla � 0

    Campo camp= Campo(30, 70);  //inizializzo il mio campo quindi la mia matrice  di larghezza 70 e altezza 30
    Macchina car= Macchina(camp.get_larghezza()/2, camp.get_altezza()-4);//inizializzo la macchina al centro del campo giu' in basso
    Livello level= Livello();
    Tabellone tab= Tabellone();

    setColor('w');
    camp.stampa();  //stampo il campo
    setColor('p');
    car.stampa_car();//stampo la macchina del giocatore

    while ( cmd != 'q' && cmd != 'Q' ){    //se comando � diverso da q (ovvero "quit")
        Sleep(level.get_vel());//mano a mano che aumentano i livelli va sempre pi� veloce

        //dopo 10 sec dall'avanzamento o decremento del livello faccio sparire il riquadro (dove c'� scritto uplevel e downlevel)
        if( tab.get_tempo() == t_uplev + 10 || tab.get_tempo() == t_downlev + 10 )
            canc_upEdown_level(camp.get_larghezza(), camp.get_altezza());

        /*ogni (level.get_intervallo)sec nuovo oggetto, che puo' essere
            un ostacolo, una macchina nemica o una tanica*/
        if( ( tab.get_tempo()% level.get_intervallo() ) == 0 )
        {
            /*funzione che mi aggiunge un entità random nella matrice*/
            camp.agg_entita();
        }

        //controllo se e' stato premuto un tasto
        if(kbhit()) cmd=getch(); //leggo comando
        else cmd='w'; //imposto che vada avanti

        //in base al comando scelgo uno dei 4 casi
        if (cmd=='') cmd='q';  //se voglio uscire imposto cmd=q per uscire dal ciclo
        else
        {   /*//cancello la macchina dallo schermo ( cancello la macchina dallo schermo per poi farla ricomparire spostata)
            car.canc_car();*/

            //faccio scorrere il campo da gioco
            camp.scroll();

            if (cmd== 'd' || cmd== 'D'){  //se e' 'd' va a destra
                //cancello la macchina dallo schermo ( cancello la macchina dallo schermo per poi farla ricomparire spostata)
                car.canc_car();
                //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value= camp.move_car_dx( &car, level );
                setColor('p');
                car.stampa_car(); //se non devo uscire ristampo la macchina aggiornata

            }else if (cmd== 'a'|| cmd== 'A'){//se e' 'a' va a sinistra
                        //cancello la macchina dallo schermo ( cancello la macchina dallo schermo per poi farla ricomparire spostata)
                        car.canc_car();
                        //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                        control_value= camp.move_car_sx( &car, level );
                        setColor('p');
                        car.stampa_car(); //se non devo uscire ristampo la macchina aggiornata
                    }else {//se e' 'w' va avanti
                            //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                            control_value= camp.move_car_wx( &car, level );
                            setColor('p');
                            car.stampa_car(); //se non devo uscire ristampo la macchina aggiornata
                        }

            if(cmd == 'q')
            {
                //cancello la macchina dallo schermo ( cancello la macchina dallo schermo per poi farla ricomparire spostata)
                car.canc_car();
            }
        }

        //aggiorno tabellone
        if( (tab.get_punt() + control_value) < 0) //se il punteggio aggiornato con il nuovo spostamento scende sotto 0 perdo
        {
            camp.gameover(tab);// stampa GAMEOVER
            cmd= 'q'; //faccio uscire dal ciclo while
        }
        else {
            tab.aggiorna(control_value, camp.get_larghezza());//altrimenti aggiorna tabellone(aggiorno il punteggio, aumento secondi e stampo tabellone)
            level.info_lev(camp.get_larghezza()+5);
        }
        //aggiorno livelli
        if( tab.get_punt() > (level.get_level()* 100) ) //se punteggio attuale � maggiore di numero del livello attuale*100
        {
            level.uplevel();    //aumento di livello
            print_uplevel(camp.get_larghezza(), level.get_level());
            t_uplev= tab.get_tempo();// ci salviamo l'istante in cui passiamo di livello per far sparire il riquadro uplevel
            tab.t_insert(t_uplev,level.get_level());
        }
        if(tab.get_punt() < (level.get_level()-1)* 100)//se punteggio attuale � minore di (numero del livello attuale-1)*100
        {
            level.downlevel();  //regredisci al livello precedente
            print_downlevel(camp.get_larghezza(), level.get_level());
            t_downlev= tab.get_tempo();
            tab.t_insert(t_downlev,level.get_level());
        }
    }

    while (cmd != ''){ cmd= getch(); } //quando premo esc esco dal gioco e torno al menù
}
