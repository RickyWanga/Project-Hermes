#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "OtherFunctions.h"
#include "Entita.h"
#include "Livello.h"
#include "Macchina.h"
#include "Tabellone.h"
#include "campo.h"

using namespace std;

void caricamento();         //stampa la barra di caricamento
void stampa_menu();         //stampa menu principale
void stampa_info();         //stampa info relative al funzionamento del gioco
void start_game();          //fa partire il gioco

int main()
{
    ShowConsoleCursor(false); //faccio sparire il cursore

    srand(time(0));//per creare le entità randomicamente

    //facciamo stampare il caricamento del gioco
    caricamento();

    //attendiamo un secondo per non far scomparire subito il caricamento
    Sleep(250);

    int choose; //inizializzo la variabile che userò per leggere i comandi
    int y = 2; //variabili che uso per muovere la freccia su e giu', la imposto sulla prima opzione

    //entro nel loop per stampare il menù
    while(y != 4) // se y = 4 significa che ho scelto l'opzione "Esci"
    {
        //imposto la variabile per spostare la freccia a qualcosa che non fa nulla, ovvero che non mi fa uscire dal gioco e che non mi fa muovere la freccia da sola
        choose='m';

        stampa_menu(); //stampo menu'
        y = 2; //imposto la variabile che indica dove stampare la freccia alla prima opzione

        while(choose != 13) //quando cmd = 13 significa che ho premuto invio
        {
            //stampo la freccia di blu
            gotoxy(21, y);
            setColor('b');
            cout<<"<---";

            choose = getche(); //leggo il comando

            //cancello la freccia
            gotoxy(21, y);
            cout<<"        ";

            if(choose == 's' || choose == 'S') //se la freccia deve andare giù
                if(y == 4) {y = 2;} //se sono gia' all'ultima opzione torno alla prima
                else {y++;} //altrimenti stampo la freccia all' opzione successiva

            if(choose == 'w' || choose == 'W') //se la freccia deve andare su
                if(y == 2) {y=4;} //se sono gia' alla prima opzione torno all' ultima
                else {y--;} //altrimeni stampo la freccia all' opzione precedente
        }

        //in base alla posizione della freccia quando ho premuto invio faccio il comando correlato
        if(y == 2) {start_game();}
        if(y == 3) {stampa_info();}
    }
    return 0;
}

void caricamento(){
    setColor('g');
    srand(time(0));
    int x = 0;
    for(int i = 0; i < 100; i++){

        int r = rand()%1000;
        x++;
        cout<< "\r" << x << "%" << '|' <<flush;
        cout<<string(x, '°')<<flush;
        if(i<43){
            Sleep(r/6);
        }
        else if(i > 43 && i < 74){
            Sleep(r/7);
        }
        else if(i < 98){
            Sleep(r/5);
        }
        else if(i > 97 && i != 99){
            Sleep(2000);
        }
    }
    cout<<endl<<endl<<"caricamento completato";
}

void stampa_menu(){
    system("CLS");
    setColor('p');
    cout<<"\n!!HERMES GAME!!";
    setColor('g');
    cout<<"\n -->INIZIA IL GIOCO";
    setColor('y');
    cout<<"\n -->INFORMAZIONI";
    setColor('r');
    cout<<"\n -->ESCI ";
}

void stampa_info(){
    setColor('y');
    system("CLS");
    cout<<" \n\tRegole: \n\tPremi 'a' per andare a sinistra, \n\tPremi 'd' per andare a destra, \n\tSe nessun tasto viene premuto la macchinina andra' avanti da sola. \n\tPremi 'ESC' in qualsiasi momento per uscire dal gioco.\n";
    cout<<endl<<"\t-> Questa e' la tua macchina:";
    setColor('p');
    cout<<"\n\t   O-O\n\t    H\n\t   O-O"<<endl;
    setColor('y');
    cout<<"\n\t-> Macchina nemica:";
    setColor('r');
    cout<<"\n\t   0-0\n\t    @\n\t   0-0"<<endl;
    setColor('y');
    cout<<"\n\t-> Tanica di benzina:";
    setColor('g');
    cout<<"\n\t   ++\n\t   ++"<<endl;
    setColor('y');
    cout<<"\n\t-> Esempio ostacolo:";
    setColor('b');
    cout<<"\n\t   |***|"<<endl;
    setColor('y');
    cout<<"\n\tPer aumentare lo SCORE prendi piu' taniche possibili ed evita gli ostacoli (che ti toglieranno punti!!).\n\tRicorda che se il punteggio dovesse scendere sotto 0 perderai!!\n\tBUONA FORTUNA!"<<endl;
    cout<<"\n\t\t\t\t\tCreated by: Alice Altena, Alice Guidi, Letizia Gorini, Ricky Wanga.\n\n\t";

    system("pause");
}

void start_game(){

    char cmd = 0;//inizializzo la variabile cmd (del comando) ad un valore diverso da ESC (ovvero quello di uscita)
    int t_uplev = 0, t_downlev = 0; //variabili che mi dicono l'ultimo istante in cui c'e' stato un uplevel o un downlevel
    int control_value; // variabile di controllo che mi denota di quanto cambia il punteggio in base a cosa urto
    bool gameOver = false; //la inizializziamo a false = non e' stato chiamato camp.gameOver();

    Campo camp = Campo(30, 70);  //inizializzo il mio campo quindi la mia matrice  di larghezza 70 e altezza 30
    Macchina car = Macchina(camp.get_larghezza()/2, camp.get_altezza()-4);//inizializzo la macchina al centro del campo giu' in basso
    Livello level = Livello();
    Tabellone tab = Tabellone();

    setColor('w');
    camp.stampa();  //stampo il campo
    setColor('p');
    car.stampa_car();//stampo la macchina del giocatore

    while ( cmd != ''){    //se il comando e' diverso da ESC continuo
        Sleep(level.get_vel());//mano a mano che aumentano i livelli va sempre piu' veloce

        //dopo 10 sec dall'avanzamento o decremento del livello faccio sparire il riquadro (dove c'� scritto uplevel e downlevel)
        if( tab.get_tempo() == t_uplev + 10 || tab.get_tempo() == t_downlev + 10 )
            canc_upEdown_level(camp.get_larghezza(), camp.get_altezza());


        if( ( tab.get_tempo()% level.get_intervallo() ) == 0 )
        {
            /*ogni (level.get_intervallo)sec nuovo oggetto, che puo' essere
            un ostacolo, una macchina nemica o una tanica in modop randomico*/
            camp.agg_entita();
        }

        //controllo se e' stato premuto un tasto
        if(kbhit()) cmd = getch(); //leggo comando
        else cmd = 0; //imposto che vada avanti

        //in base al comando scelgo uno dei casi
        if (cmd == 'd' || cmd == 'D'){  //se e' 'd' va a destra
            //faccio scorrere il campo da gioco
            camp.scroll();

            //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
            control_value = camp.move_car_dx( &car, level );

        }else if (cmd == 'a'|| cmd == 'A'){//se e' 'a' va a sinistra
                    //faccio scorrere il campo da gioco
                    camp.scroll();

                    //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                    control_value = camp.move_car_sx( &car, level );

                }else {//se non premo nulla va avanti da solo
                            //faccio scorrere il campo da gioco
                            camp.scroll();

                            //salvo il valore di ritorno in control_value, in base ad esso capisco se e cosa ha urtato, visionare la funzione per info
                            control_value = camp.move_car_wx( &car, level );
                        }


        //aggiorno tabellone
        if( (tab.get_punt() + control_value) < 0) //se il punteggio aggiornato con il nuovo spostamento scende sotto 0 perdo
        {
            camp.gameover(tab);// stampa GAMEOVER
            gameOver = false;
            cmd = ''; //faccio uscire dal ciclo while
        }
        else {
            tab.aggiorna(control_value, camp.get_larghezza());//altrimenti aggiorna tabellone(aggiorno il punteggio, aumento secondi e stampo tabellone)
            level.info_lev(camp.get_larghezza());
        }

        //aggiorno livelli
        if( tab.get_punt() > (level.get_level()* 100) )
        {   //se punteggio attuale e' maggiore del numero del livello attuale * 100, quindi ogni 100 punti
            level.uplevel();    //aumento di livello
            print_uplevel(camp.get_larghezza(), level.get_level());
            t_uplev = tab.get_tempo();// ci salviamo l'istante in cui passiamo di livello per far sparire il riquadro uplevel
            tab.t_insert(t_uplev,level.get_level());
        }
        if(tab.get_punt() < (level.get_level()-1)* 100)
        {   //se punteggio attuale e' minore del numero del livello attuale * 100, quindi ogni 100 punti
            level.downlevel();  //regredisci al livello precedente
            print_downlevel(camp.get_larghezza(), level.get_level());
            t_downlev = tab.get_tempo();
            tab.t_insert(t_downlev,level.get_level());
        }
    }

    if( !gameOver ){ camp.gameover(tab);  }
    cmd = 0;

    while (cmd != ''){ cmd = getch(); } //quando premo esc esco dal gioco e torno al menù
}
