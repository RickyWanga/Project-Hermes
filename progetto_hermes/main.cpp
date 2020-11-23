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

#include "OtherFunctions.h"
#include "Entita.h"
#include "Livello.h"
#include "Macchina.h"
#include "Ostacolo.h"
#include "Tabellone.h"
#include "Tanica.h"
#include "campo.h"



void stampa_menu();
void print_uplevel(int larghezza, int altezza);
void print_downlevel(int larghezza, int altezza);
void canc_upEdown_level(int larghezza, int altezza);

void agg_ost_or_tan(Campo camp, bool *ost_or_tan, int *position_x, int *length_ost);

int main()
{
    char cmd='0';//inizializzo la variabile cmd (del comando) ad un valore diverso da q (ovvero quello di uscita)

    //inizializzo variabili necessarie per la creazione di ostacoli e taniche con la funzione agg_ost_or_tan(...)
    bool type_obj;
    int x;
    int len;
    int t_uplev=0, t_downlev=0; //variabili che mi dicono l'ultimo istante in cui c'è stato un uplevel o un downlevel

    Campo camp;  //inizializzo il mio campo quindi la mia matrice
    Macchina car=Macchina(48,26);//inizializzo la macchina
    Livello level=Livello();
    Tabellone tab=Tabellone();

    stampa_menu();  //stampo il menu
    system("pause");

    camp.stampa();  //stampo il campo
    car.stampa_car();//stampo la macchina del giocatore

    while (cmd!='q'&&cmd!='Q' ){    //se comando è diverso da q (ovvero "quit")
        //se non premo nulla pongo il comando a w= vai avanti
        if (_kbhit()==0){cmd='w';}
        else{   //altrimenti leggo comando
                cmd=getch();}

        stop(level.get_vel());//mano a mano che aumentano i livelli va sempre più veloce

        //dopo 5 sec dall'avanzamento o decremento del livello faccio sparire il riquadro
        if(tab.get_tempo()==t_uplev+10||tab.get_tempo()==t_downlev+10)
            canc_upEdown_level(camp.get_larghezza(), camp.get_altezza());

        //ogni (level.get_intervallo)sec nuovo oggetto, che può essere un ostacolo o una tanica
        if(tab.get_tempo()%level.get_intervallo()==0)
        {
            //per scegliere leggo il booleano "type_obj", se esso è 0->nuovo ostacolo di lunghezza "len"; se è 1->nuova tanica
            //in ogni caso la posizione di partenza è m[1][x]
            agg_ost_or_tan(camp, &type_obj, &x, &len);
            if (type_obj)
                camp.ins_tan(x);
            else
                camp.ins_ost(x, len);
        }


        //in base al comando scelgo uno dei 3 casi
        if (cmd==''){//se voglio uscire
            //imposto cmd=q per uscire dal ciclo
            cmd='q';
        }
        else
        {
            int control_value=0;

            //cancello la macchina dallo schermo
            car.canc_car();

            //faccio scorrere il campo da gioco
            camp.scroll();

            if (cmd=='d'||cmd=='D'){  //se è 'd' va a destra
                //sposto la macchina a dx
                car.inc_x();

                //salvo il valore di ritorno, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                control_value=camp.move_car_dx(car,level);

                //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo annullando l'ultimo spostamento
                if (control_value==level.get_p_bar()){car.dec_x();}
            }else{
                    if (cmd=='a'||cmd=='A'){//se è 'a' va a sinistra
                    //sposto la macchina a sx
                    car.dec_x();

                    //salvo il valore di ritorno, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                    control_value=camp.move_car_sx(car,level);
                    //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo annullando l'ultimo spostamento
                    if (control_value==level.get_p_bar()){car.inc_x();}
                    }else{
                        //chiamo funzione che semplicemente scolla tutto il campo
                        control_value=camp.move_car_wx(car,level);
                    }
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
                t_uplev=tab.get_tempo();
            }
            if(tab.get_punt()<(level.get_level()-1)*100)//se punteggio attuale è minore di (numero del livello attuale-1)*100
            {
                level.downlevel();  //regredisci al livello precedente
                print_downlevel(camp.get_larghezza(), camp.get_altezza());
                t_downlev=tab.get_tempo();
            }

            if (cmd!='q')//se non devo uscire
                car.stampa_car(); //ristampo la macchina aggiornata
        }
    }

    while (cmd!=''){cmd=getch();}

    system("pause");
    return 0;
}


void stampa_menu(){
    cout<<"\n!!!!!!!!!!!!!!!!INIZIO GIOCO!!!!!!!!!!!!!!!! \nRegole: \nPremi 'a' per andare a sinistra, \nPremi 'd' per andare a destra, \nPremi 'w' per andare su, \nPremi 'ESC' per uscire dal gioco.\n\n";
    cout<<endl<<"->Questa e' la tua macchina:\n0-0\n H\n0-0\n"<<endl;
    cout<<"\n\n->Tanica di benzina:\n++\n++\n"<<endl;
    cout<<"\n\n->Esempio ostacolo:\n|***|\n"<<endl;
    cout<<endl<<"Cerca di prendere più taniche possibili e di eivtare gli ostacoli perchè se il punteggio dovesse andare sotto 0 perderai!!"<<endl<<"!Premi qualsiasi tasto per cominciare!"<<endl;
}

void print_uplevel(int larghezza, int altezza){
        gotoxy((larghezza/2)-5, (altezza/2));
        cout<<"!!!!!!!!!!!!!";
        gotoxy((larghezza/2)-5, (altezza/2)+1);
        cout<<"!!!UpLevel!!!";
        gotoxy((larghezza/2)-5, (altezza/2)+2);
        cout<<"!!!!!!!!!!!!!";
}

void print_downlevel(int larghezza, int altezza){
        gotoxy((larghezza/2)-5, (altezza/2));
        cout<<"!!!!!!!!!!!!!";
        gotoxy((larghezza/2)-5, (altezza/2)+1);
        cout<<"!!DownLevel!!";
        gotoxy((larghezza/2)-5, (altezza/2)+2);
        cout<<"!!!!!!!!!!!!!";
}

void canc_upEdown_level(int larghezza, int altezza){
        gotoxy((larghezza/2)-5, (altezza/2));
        cout<<"             ";
        gotoxy((larghezza/2)-5, (altezza/2)+1);
        cout<<"             ";
        gotoxy((larghezza/2)-5, (altezza/2)+2);
        cout<<"             ";
}
void agg_ost_or_tan(Campo camp, bool *ost_or_tan, int *position_x, int *length_ost){

    srand(time(0));
    *position_x=3+rand()%(GMAX-2); //la posizione può andare nel range [2,99], percgè a m[:][1] e m[:][100] abbiamo i bordi del campo
    *length_ost=3+rand()%5;//calcolo una lunghezza per l'ostacolo che può andare da 3 ad 8

    //attraverso un numero random scelgo se creare una tanica o un ostacolo
    if ((rand()%100)%2)
        *ost_or_tan=true;
    else
    {
        *position_x=*position_x-*length_ost;
        *ost_or_tan=false;
    }

}
