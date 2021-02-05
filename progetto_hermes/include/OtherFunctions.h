#ifndef OTHERFUNCTIONS_H_INCLUDED
#define OTHERFUNCTIONS_H_INCLUDED

#define GMAX 100
#define HMAX 30

void gotoxy(int x, int y); //setto il cursore nella posizione (x,y) dello schermo
void ShowConsoleCursor(bool Show);
void caricamento();         //stampa la barra di caricamento
void stampa_info();         //stampa info relative al funzionamento del gioco
void stampa_menu();         //stampa menu principale
void print_uplevel(int larghezza, int lev);     //stampa notifica di aumento livello
void print_downlevel(int larghezza, int lev);   //stampa notifica di diminuzione livello
void canc_upEdown_level(int larghezza, int altezza);    //cancella la notifica di aumento/dimuzione livello
void setColor(char color); //setta il colore del carattere da stampare

#endif // OTHERFUNCTIONS_H_INCLUDED
