#include <OtherFunctions.h>
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

void gotoxy(int x, int y)
{
    COORD co;
    co.X=x;
    co.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}
void stop(int t)
{
    int x=(100/t)*1000000;
    while(x!=0){x--;}
}


void caricamento(){
    srand(time(0));
    int x=0;
    for(int i=0; i<100; i++){

        int r= rand()%1000;
        x++;
        cout<<"\r"<<x<<"%"<< '|'<<flush;
        cout<<string(x,'�')<<flush;
        if(i<43){
            Sleep(r/6);
        }
        else if(i>43 && i<74){
            Sleep(r/7);
        }
        else if(i<98){
            Sleep(r/5);
        }
        else if(i>97&& i!= 99){
            Sleep(2000);
        }


    }
    cout<<endl<<endl<<"caricamento completato";

    }


void stampa_info(){
    cout<<" \nRegole: \nPremi 'a' per andare a sinistra, \nPremi 'd' per andare a destra, \nPremi 'w' per andare su, \nPremi 'ESC' per uscire dal gioco.\n\n";
    cout<<endl<<"->Questa e' la tua macchina:\n0-0\n H\n0-0\n"<<endl;
    cout<<"\n\n->Tanica di benzina:\n++\n++\n"<<endl;
    cout<<"\n\n->Esempio ostacolo:\n|***|\n"<<endl;
    cout<<endl<<"Cerca di prendere pi� taniche possibili e di eivtare gli ostacoli perch� se il punteggio dovesse andare sotto 0 perderai!!\n!Premi qualsiasi tasto per cominciare!"<<endl;
}

void stampa_menu(){
    system("CLS");
    cout<<"\n!!HERMES GAME!! \n 0)INIZIA IL GIOCO\n 1) STAMPA INFO\n 2) ESCI ";

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
