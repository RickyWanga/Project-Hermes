
#include "Campo.h"
#include <iostream>
using namespace std;

        Campo::Campo()//costruttore che setta il campo da gioco vuoto con larghezza "GMAX" e altezza "HMAX"
        {
            larghezza=GMAX;
            altezza=HMAX;
            bordo=':';

            //creo il campo
            for (int j=0;j<altezza;j++)
            {
                for (int i=1;i<larghezza-1;i++)
                    m[j][i]=' ';

                m[j][0]=bordo;
                m[j][larghezza-1]=bordo;
            }
        }

        Campo::~Campo(){}

        void Campo::stampa(){  //stampa il campo da gioco da capo
            system("CLS");//pulisco tutto lo schermo

            //stampo matrice
            for (int j=0;j<altezza;j++)
            {
                for(int i=0;i<larghezza;i++) {cout<<m[j][i];}
                cout<<endl;

            }
        }

        void Campo::scroll(){   //sposta tutti gli elementi della matrice di uno in basso

            for (int k=1;k<larghezza;k++){m[0][k]=' ';}//prima nuova riga tutta vuota

            for (int i=altezza;i>0;i--)
                for (int j=larghezza-2;j>0;j--)
                {
                    m[i][j]=m[i-1][j];
                    if (m[i][j]!=' ')
                    {
                        gotoxy(j, i-1);
                        cout<<" ";
                        gotoxy(j, i);
                        cout<<m[i][j];
                    }
                }

            gotoxy(30, 0);
            cout<<"                                        ";
        }

        void Campo::gameover(Tabellone tab){//stampa "game over" al centro
            system("CLS");//pulisco tutto lo schermo
            gotoxy((larghezza/2)-5, (altezza/2));
            cout<<"!GAME OVER!";
            gotoxy((larghezza/2)-5, (altezza/2)+3);
            cout<<"Your time:"<<tab.get_tempo();
            gotoxy((larghezza/2)-10, (altezza/2)+4);
            cout<<"Premi 'ESC' per uscire";
            gotoxy(0, 30);
        }

        int Campo::get_larghezza(){return larghezza;}//ritorna la larghezza del campo
        int Campo::get_altezza(){return altezza;}//ritorna l'altezza del campo

         void Campo::del_tan (int x, int y){ //cancella la tanica di benziona con estremo sinistro in alto (x,y)
            m[y][x]=' ';
            m[y][x+1]=' ';
            m[y+1][x]=' ';
            m[y+1][x+1]=' ';
        }

        void Campo::del_ost(int x, int y){//cancella l ostacolo con estremo sinistro in alto (x,y)
            int i=1;
            m[y][x]=' ';
            while (m[y][x+i]!='|')
            {
                m[y][x+i]=' ';
                i++;
            }
            m[y][x+i]=' ';
        }

        void Campo::ins_tan(int x){//inserisco una tanica nel campo con (x,1) come coordinate dell' angolo sinisro in alto
           m[1][x]='+';
           m[1][x+1]='+';
           m[2][x]='+';
           m[2][x+1]='+';
        }

        void Campo::ins_ost(int x, int len){//inserisco un ostacolo di lunghezza l nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[1][x]='|';
            m[1][x+len-1]='|';

            for (int i=1;i<len-1;i++)
                m[1][x+i]='*';
        }

        void Campo::ins_car(int x, int y ){//inserisco la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[y][x]='0';
            m[y+2][x]='0';
            m[y+2][x+2]='0';
            m[y][x+2]='0';
            m[y+1][x+1]='H';
            m[y][x+1]='-';
            m[y+2][x+1]='-';
        }

        void Campo::del_car(int x, int y ){//rimuovo la macchina dal campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[y][x]=' ';
            m[y+2][x]=' ';
            m[y+2][x+2]=' ';
            m[y][x+2]=' ';
            m[y+1][x+1]=' ';
            m[y][x+1]=' ';
            m[y+2][x+1]=' ';
        }

         int Campo::control_collision(int x, int y){/*funzione che data la posizione (x,y) della macchina ti restituisce:
                -0 non ho sbattuto da nessuna parte
                -ritorna il valore di cosa ho beccato */
                return 0;

         }

        int Campo::move_car_dx(Macchina car, Livello level){
         /*controllo cosa è successo con la macchina spostata di una posizione a dx:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

            int temp_return_value=0; //variabile temporanea impostata a 0, se non urterò nulla ritornando questa variabile la funzione tornerà 0, altrimenti ritornerà il valore dell'oggetto urtato
            int x_temp_car=car.get_posx(), y_temp_car=car.get_posy();   //creo variabili temporanee con il valore rispettivamente di car.position.X e car.position.Y per non dover chiamare sempre la car.get_pos_...

            //controllo "urti" con barriera
            if (m[y_temp_car][x_temp_car+2]==':')
                temp_return_value=temp_return_value+level.get_p_bar();//modifico la variabile temporanea perchè ho urtato la barriera

            //controllo "urti" con ostacoli o taniche
            for (int i=0; i<3 ;i++)
            {
                if(m[y_temp_car+i][x_temp_car+2]=='|' || m[y_temp_car][x_temp_car+i]=='|' || m[y_temp_car][x_temp_car+i]=='*')
                    temp_return_value=temp_return_value+level.get_p_ost();  //modifico la variabile temporanea perchè ho urtato un ostacolo
                if(m[y_temp_car+i][x_temp_car+2]=='+' ||  m[y_temp_car][x_temp_car+i]=='+')
                    temp_return_value=temp_return_value+level.get_p_tan();  //modifico la variabile temporanea perchè ho urtato una tanica
            }

            return temp_return_value;
        }

        int Campo::move_car_sx(Macchina car, Livello level){
            /*controllo cosa è successo con la macchina spostata di una posizione a sx:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

            int temp_return_value=0; //variabile temporanea impostata a 0, se non urterò nulla ritornando questa variabile la funzione tornerà 0, altrimenti ritornerà il valore dell'oggetto urtato
            int x_temp_car=car.get_posx(), y_temp_car=car.get_posy();   //creo variabili temporanee con il valore rispettivamente di car.position.X e car.position.Y per non dover chiamare sempre la car.get_pos_...

            //controllo "urti" con barriera
            if (m[y_temp_car][x_temp_car]==':')
                temp_return_value=temp_return_value+level.get_p_bar();//modifico la variabile temporanea perchè ho urtato la barriera

            //controllo "urti" con ostacoli o taniche
            for (int i=0; i<3 ;i++)
            {
                if(m[y_temp_car+i][x_temp_car]=='|' || m[y_temp_car][x_temp_car+i]=='|' || m[y_temp_car][x_temp_car+i]=='*')
                    temp_return_value=temp_return_value+level.get_p_ost();  //modifico la variabile temporanea perchè ho urtato un ostacolo
                if(m[y_temp_car+i][x_temp_car]=='+' ||  m[y_temp_car][x_temp_car+i]=='+')
                    temp_return_value=temp_return_value+level.get_p_tan();  //modifico la variabile temporanea perchè ho urtato una tanica
            }

            return temp_return_value;
        }


        int Campo::move_car_wx(Macchina car, Livello level){
            return 0;
        }


