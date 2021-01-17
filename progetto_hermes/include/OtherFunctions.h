#ifndef OTHERFUNCTIONS_H_INCLUDED
#define OTHERFUNCTIONS_H_INCLUDED

void gotoxy(int x, int y); //setto il cursore nella posizione (x,y) dello schermo
void stop(int x);          //funzione per creare un ritado
void caricamento();
void stampa_info();
void stampa_menu();
void print_uplevel(int larghezza, int altezza);
void print_downlevel(int larghezza, int altezza);
void canc_upEdown_level(int larghezza, int altezza);

#endif // OTHERFUNCTIONS_H_INCLUDED
