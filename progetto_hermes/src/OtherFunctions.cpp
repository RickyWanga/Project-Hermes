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

void caricamento(){
    srand(time(0));
    int x=0;
    for(int i=0; i<100; i++){

        int r= rand()%1000;
        x++;
        cout<<"\r"<<x<<"%"<< '|'<<flush;
        cout<<string(x,'°')<<flush;
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
    system("CLS");
    cout<<" \nRegole: \nPremi 'a' per andare a sinistra, \nPremi 'd' per andare a destra, \nPremi 'w' per andare su, \nPremi 'ESC' per uscire dal gioco.\n\n";
    cout<<endl<<"->Questa e' la tua macchina:\n0-0\n H\n0-0"<<endl;
    cout<<"\n->Macchina nemica:\n0-0\n @\n0-0"<<endl;
    cout<<"\n->Tanica di benzina:\n++\n++"<<endl;
    cout<<"\n->Esempio ostacolo:\n|***|"<<endl;
    cout<<"\nCerca di prendere piu' taniche possibili e di eivtare gli ostacoli\nRicorda che se il punteggio dovesse scendere sotto 0 perderai!!"<<endl;
    system("pause");
}

void stampa_menu(){
    system("CLS");
    cout<<"\n!!HERMES GAME!! \n -->INIZIA IL GIOCO\n -->STAMPA INFO\n -->ESCI ";
}

void print_uplevel(int larghezza, int altezza, int lev){
        gotoxy((larghezza/2)-5, (altezza/2));
        cout<<"-------------";
        gotoxy((larghezza/2)-5, (altezza/2)+1);
        cout<<"|  Level "<<lev<<"  |";
        gotoxy((larghezza/2)-5, (altezza/2)+2);
        cout<<"-------------";
}

void print_downlevel(int larghezza, int altezza, int lev){
        gotoxy((larghezza/2)-5, (altezza/2));
        cout<<"-------------";
        gotoxy((larghezza/2)-5, (altezza/2)+1);
        cout<<"|  Level "<<lev<<"  |";
        gotoxy((larghezza/2)-5, (altezza/2)+2);
        cout<<"-------------";
}

void canc_upEdown_level(int larghezza, int altezza){
        gotoxy((larghezza/2)-5, (altezza/2));
        cout<<"             ";
        gotoxy((larghezza/2)-5, (altezza/2)+1);
        cout<<"             ";
        gotoxy((larghezza/2)-5, (altezza/2)+2);
        cout<<"             ";
}
