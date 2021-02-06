#include "OtherFunctions.h"

#include <iostream>
#include <windows.h>
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
    int Size=25;//Size corrisponde all'altezza del cursore

    _CONSOLE_CURSOR_INFO CurInfo;//creiamo una nuova variabile (del tipo adatto) per identificare il cursore

    CurInfo.dwSize = Size; //Definiamone la grandezza
    CurInfo.bVisible = Show;//Rendiamolo true(=visibile) o false(=nascosto) in base al bool in input

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), & CurInfo);
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
    if (color == 'r') //rosso su nero
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    if (color == 'b') //blu su nero
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    if (color == 'g') //verde su nero
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (color == 'y') //gialo su nero
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    if (color == 'p') //rosa su nero
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    if (color == 'w') //bianco su nero
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if (color == 'G') //nero su verde
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
    if (color == 'R') //bianco su rosso
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
    if (color == 'Y') //nero su giallo
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);

}

