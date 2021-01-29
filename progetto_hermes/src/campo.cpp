
#include "Campo.h"
#include <iostream>
using namespace std;

        Campo::Campo()//costruttore che setta il campo da gioco vuoto con larghezza "GMAX" e altezza "HMAX"
        {
            larghezza= GMAX;
            altezza= HMAX;
            bordo= ':';

            //creo il campo
            for (int j=0; j<altezza; j++)
            {
                for (int i=1; i<larghezza-1; i++)
                    m[j][i]= ' ';

                m[j][0]= bordo;
                m[j][larghezza -1]= bordo;
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

            for (int k=1; k<larghezza; k++ ){m[0][k]= ' ';}//prima nuova riga tutta vuota

            for (int i=altezza; i>0; i--)
                for (int j=larghezza-2; j>0; j--)
                {
                    m[i][j]= m[i-1][j];
                    if (m[i][j] != ' ')
                    {
                        gotoxy(j, i-1);
                        cout<<" ";
                        gotoxy(j, i);
                        cout<<m[i][j];
                    }
                }

            gotoxy(0, 29);
            cout<<"                                                                                                                        ";
            gotoxy(0,30);
            cout<<"                                                                                                                        ";
        }

        void Campo::gameover(Tabellone tab){//stampa "game over" al centro
            system("CLS");//pulisco tutto lo schermo
            gotoxy( (larghezza/ 2) -5, (altezza/ 2) );
            cout<<"!GAME OVER!";
            gotoxy( (larghezza/ 2) -10, (altezza/ 2) +3 );
            cout<<"You survived for:";
            gotoxy( (larghezza/ 2) -10, (altezza/ 2) +4 );
            cout<<tab.get_tempo()<<"sec";
            int tmp=tab.stampa_lista((larghezza/ 2) -10, (altezza/ 2) +5);
            gotoxy( (larghezza/ 2) -10, tmp-- );
            cout<<"Premi 'ESC' per uscire";
            gotoxy(0, 30);
        }

        int Campo::get_larghezza(){return larghezza;}//ritorna la larghezza del campo
        int Campo::get_altezza(){return altezza;}//ritorna l'altezza del campo

         void Campo::del_tan (int x, int y){ //cancella la tanica di benziona con estremo sinistro in alto (x,y)
            m[y][x]=' ';
            m[y][x+1]=' ';
            gotoxy(x,y);
            cout << "  ";
            m[y+1][x]=' ';
            m[y+1][x+1]=' ';
            gotoxy(x,y+1);
            cout << "  ";
        }

        void Campo::del_ost(int x, int y){//cancella l ostacolo con estremo sinistro in alto (x,y)
            int i=1;
            m[y][x]=' ';
            gotoxy(x,y);
            cout << "  ";
            while (m[y][x+i]!='|')
            {
                m[y][x+i]=' ';
                gotoxy(x+i,y);
                cout << " ";
                i++;
            }
            m[y][x+i]=' ';
            gotoxy(x+i,y);
            cout << " ";
        }

        void Campo::ins_tan(int x){//inserisco una tanica nel campo con (x,1) come coordinate dell' angolo sinisro in alto
           m[1][x]= '+';
           m[1][x+1]= '+';
           m[2][x]= '+';
           m[2][x+1]= '+';
        }

        void Campo::del_car(int x, int y ){//rimuovo la macchina dal campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[y][x]=' ';
            m[y+2][x]=' ';
            m[y+2][x+2]=' ';
            m[y][x+2]=' ';
            m[y+1][x+1]=' ';
            m[y][x+1]=' ';
            m[y+2][x+1]=' ';
            gotoxy(x,y);
            cout << "   ";
            gotoxy(x,y+1);
            cout << "   ";
            gotoxy(x,y+2);
            cout << "   ";
        }

        void Campo::ins_ost(int x, int len){//inserisco un ostacolo di lunghezza l nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[1][x]= '|';
            m[1][x+ len-1]= '|';

            for (int i=1; i<len-1; i++)
                m[1][x+ i]= '*';
        }

        void Campo::ins_car(int x){//inserisco la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[1][x]= '0';
            m[1][x+1]='-';
            m[1][x+2]='0';
            m[2][x+1]='H';
            m[3][x]= '0';
            m[3][x+1]='-';
            m[3][x+2]= '0';
        }

        int Campo::control_collision( Livello level, int x, int y){
            int tmp= 0;
            if ( m[y][x] == ':' )
                    tmp= level.get_p_ost();
            else if ( m[y][x] == '|' ){ //abbiamo 2 casi |*|
                    if( m[y][x+1] == '*' ){ //caso 1 m[y][x] � l'angolo sx dell'ostacolo
                        del_ost(x,y);
                        tmp= level.get_p_ost();
                    }else{                //caso 2 m[y][x] � l'angolo dx dell'ostacolo
                        while( m[y][x] != '|' ){x--;}
                        del_ost(x,y);
                        tmp= level.get_p_ost();
                    }
                }else if( m[y][x] == '*' ){ //un altro caso se xy � *
                    while( m[y][x] != '|' ){x--;} //decremento x fino a quando non mi ritrovo nell'angolo sx dell'entit�
                    del_ost(x,y);
                    tmp= level.get_p_ost();
                }
                else if ( m[y][x] == '+' ){ //4 casi dato che le taniche sono 2x2 di +
                    if( m[y][x+1] == '+' ){    //caso 1 e 2 a dx di xy c'� un +
                        if( m[y-1][x+1] == '+' ){ //caso 1 xy � l'angolo basso sx
                            del_tan(x,y-1);
                            tmp= level.get_p_tan();
                        }
                        if( m[y+1][x+1] == '+' ){ //caso 2 xy � l'angolo alto sx
                            del_tan(x,y);
                            tmp= level.get_p_tan();
                        }
                    }
                    else if( m[y][x-1] == '+' ){ //caso 3 e 4 a sx di xy c'� un +
                            if( m[y-1][x-1] == '+' ){ //caso 3 xy � l'angolo in basso a dx
                                del_tan(x-1,y-1);
                                tmp= level.get_p_tan();
                            }
                            if( m[y+1][x-1] == '+' ){  //caso 4 xy � l'angolo alto a dx
                                del_tan(x-1,y);
                                tmp= level.get_p_tan();
                            }
                        }
                }
                else if ( m[y][x] == '0' ){
                    if( m[y][x-1] == '-' ){         //xy � una ruota a dx
                        if( m[y+2][x] == '0' ){      //xy � in alto a dx
                            del_car(x-2,y);
                            tmp= level.get_p_car();
                        }
                        else{                    //xy � in basso a dx
                            del_car(x-2,y-2);
                            tmp= level.get_p_car();
                        }
                    }
                    else{                       //xy � una ruota a sx
                        if( m[y+2][x] == '0' ){      //xy � in alto a sx
                            del_car(x,y);
                            tmp= level.get_p_car();
                        }
                        else{                    //xy � in basso a sx
                            del_car(x,y-2);
                            tmp= level.get_p_car();
                        }
                    }
                }

            return tmp;
        }

        int Campo::control_collision_car( Livello level, int x, int y){
            int tmp= 0;
            tmp+= control_collision(level, x, y);
            tmp+= control_collision(level, x+1, y);
            tmp+= control_collision(level, x+2, y);
            tmp+= control_collision(level, x+1, y+1);
            tmp+= control_collision(level, x, y+2);
            tmp+= control_collision(level, x+1, y+2);
            tmp+= control_collision(level, x+2, y+2);
            return tmp;
        }

        int Campo::move_car_dx(Macchina* car, Livello level){
         /*controllo cosa � successo con la macchina spostata di una posizione a dx con il metodo control_collision_cas che :
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

                //sposto la macchina a dx
                car->inc_x();
                int tmp= control_collision_car(level, car->get_posx(), car->get_posy());

                //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo
                if ( larghezza-3 == car->get_posx() )
                    car->set_coo(larghezza-5, car->get_posy());

            return tmp;
        }

        int Campo::move_car_sx(Macchina* car, Livello level){
            /*controllo cosa � successo con la macchina spostata di una posizione a sx:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

              //sposto la macchina a dx
                car->dec_x();
                int tmp= control_collision_car(level, car->get_posx(), car->get_posy());

                //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo
                if ( 0 == car->get_posx() )
                    car->set_coo(2, car->get_posy());

            return tmp;
        }


        int Campo::move_car_wx(Macchina* car, Livello level){
            /*controllo cosa � successo con la macchina ferma:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

            return  control_collision_car(level, car->get_posx(), car->get_posy());
        }


