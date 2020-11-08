#include <OtherFunctions.h>
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
void stop(int t)
{
    int x=(100/t)*1000000;
    while(x!=0){x--;}
}
