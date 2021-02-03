#include "OtherFunctions.h"

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

void ShowConsoleCursor(bool Show)
{
    int Size=25;
    //The Size = the cursor height, by default 25. Size range: 1 - 100
    _CONSOLE_CURSOR_INFO CurInfo; //Define the cursor size

    if (Size<=0)
    Size = 1;
    if (Size>100)
    Size = 100;

    CurInfo.dwSize = Size; //Define the visibility of the cursor
    CurInfo.bVisible = Show;

    //Set parameters
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
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

void stampa_info(){
    setColor('y');
    system("CLS");
    cout<<" \n\tRegole: \n\tPremi 'a' per andare a sinistra, \n\tPremi 'd' per andare a destra, \n\tSe nessun tasto viene premuto la macchinina andra' avanti da sola. \n\tPremi 'ESC' in qualsiasi momento per uscire dal gioco.\n";
    cout<<endl<<"\t-> Questa e' la tua macchina:";
    setColor('p');
    cout<<"\n\t   0-0\n\t    H\n\t   0-0"<<endl;
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

void stampa_menu(){
    system("CLS");
    setColor('p');
    cout<<"\n!!HERMES GAME!!";
    setColor('g');
    cout<<"\n -->INIZIA IL GIOCO";
    setColor('y');
    cout<<"\n -->STAMPA INFO";
    setColor('r');
    cout<<"\n -->ESCI ";
}


void print_uplevel(int larghezza, int lev){
    setColor('G');
    gotoxy(larghezza, 7 );
    cout<<"\t\t---------------";
    gotoxy(larghezza, 8 );
    cout<<"\t\t  ! UPLEVEL !  ";
    gotoxy(larghezza, 9 );
    cout<<"\t\t               ";
    gotoxy(larghezza, 9 );
    cout<<"\t\t   Level "<<lev;
    gotoxy(larghezza, 10 );
    cout<<"\t\t---------------";
    setColor('w');
}

void print_downlevel(int larghezza, int lev){
    setColor('R');
    gotoxy(larghezza, 7 );
    cout<<"\t\t---------------";
    gotoxy(larghezza, 8 );
    cout<<"\t\t ! DOWNLEVEL ! ";
    gotoxy(larghezza, 9 );
    cout<<"\t\t               ";
    gotoxy(larghezza, 9 );
    cout<<"\t\t   Level "<<lev;
    gotoxy(larghezza, 10 );
    cout<<"\t\t---------------";
    setColor('w');
}

void canc_upEdown_level(int larghezza, int altezza){
    setColor('w');
    gotoxy(larghezza, 7 );
    cout<<"\t\t                    ";
    gotoxy(larghezza, 8 );
    cout<<"\t\t                    ";
    gotoxy(larghezza, 9 );
    cout<<"\t\t                    ";
    gotoxy(larghezza, 10 );
    cout<<"\t\t                    ";
}

void setColor( char color){
    if (color == 'r') //red
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    if (color == 'b') //blue
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    if (color == 'g') //green
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (color == 'y') //yellow
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    if (color == 'p') //pink
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    if (color == 'w') //white
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if (color == 'G') //nero su verde
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
    if (color == 'R') //bianco su rosso
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
    if (color == 'Y') //black on white
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);

}

