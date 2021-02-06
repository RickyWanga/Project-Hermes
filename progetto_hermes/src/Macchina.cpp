#include "Macchina.h"

#include <iostream>
using namespace std;

    Macchina::Macchina(int x, int y):Entita(x, y){}
    Macchina::~Macchina(){}

    void Macchina::inc_x(){position.X++;}
    void Macchina::dec_x(){position.X--;}

    void Macchina::stampa_car()
    {
        gotoxy(position.X, position.Y);
        cout<<"O-O";
        gotoxy(position.X, position.Y + 1);
        cout<<" H";
        gotoxy(position.X, position.Y + 2);
        cout<<"O-O";
    }

    void Macchina::canc_car()
    {
        gotoxy(position.X, position.Y);
        cout<<"   ";
        gotoxy(position.X, position.Y + 1);
        cout<<"   ";
        gotoxy(position.X, position.Y + 2);
        cout<<"   ";
    }
