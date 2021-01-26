
#include "Macchina.h"
#include <iostream>
using namespace std;

    Macchina::Macchina(int x, int y):Entita(x,y,3,3){}
    Macchina::~Macchina(){}

    void Macchina::inc_x(){position.X++;}
    void Macchina::dec_x(){position.X--;}
    void Macchina::inc_y(){position.Y++;}
    void Macchina::dec_y(){position.Y--;}

    void Macchina::stampa_car()
    {
        gotoxy(position.X,position.Y);
        cout<<"0-0";
        gotoxy(position.X,position.Y+1);
        cout<<" H";
        gotoxy(position.X,position.Y+2);
        cout<<"0-0";
    }

    void Macchina::canc_car()
    {
        gotoxy(position.X,position.Y);
        cout<<"   ";
        gotoxy(position.X,position.Y+1);
        cout<<"   ";
        gotoxy(position.X,position.Y+2);
        cout<<"   ";
    }
