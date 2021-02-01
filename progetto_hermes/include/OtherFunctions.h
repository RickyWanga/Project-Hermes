#ifndef OTHERFUNCTIONS_H_INCLUDED
#define OTHERFUNCTIONS_H_INCLUDED

#define GMAX 100
#define HMAX 30

void gotoxy(int x, int y); //setto il cursore nella posizione (x,y) dello schermo
void ShowConsoleCursor(bool Show);
void caricamento();
void stampa_info();
void stampa_menu();
void print_uplevel(int larghezza, int lev);
void print_downlevel(int larghezza, int lev);
void canc_upEdown_level(int larghezza, int altezza);
void setColor( char color);
#endif // OTHERFUNCTIONS_H_INCLUDED
