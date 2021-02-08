#ifndef OTHERFUNCTIONS_HPP_INCLUDED
#define OTHERFUNCTIONS_HPP_INCLUDED

void gotoxy(int x, int y); //setto il cursore nella posizione (x,y) dello schermo
void ShowConsoleCursor(bool Show);  //funzone per nascondere il cursore
void print_uplevel(int larghezza, int lev); //stampa notifica di aumento livello
void print_downlevel(int larghezza, int lev); //stampa notifica di diminuzione livello
void canc_upEdown_level(int larghezza, int altezza); //cancella la notifica di aumento/dimuzione livello
void setColor(char color); //setta il colore del carattere da stampare

#endif // OTHERFUNCTIONS_HPP_INCLUDED
