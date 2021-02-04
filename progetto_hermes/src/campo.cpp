
#include "Campo.h"
#include <iostream>
#include <ctime>

using namespace std;

        Campo::Campo(int h, int l)//costruttore che setta il campo da gioco vuoto con larghezza "l" e altezza "h"
        {
            larghezza = l;
            altezza = h;
            bordo = ':';

            //creo il campo
            for (int j = 0; j < altezza; j++)
            {
                for (int i = 1; i < larghezza - 1; i++)
                    m[j][i] = ' ';

                m[j][0] = bordo;
                m[j][larghezza - 1] = bordo;
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

            for (int k = 1; k < larghezza; k++ ){m[0][k]= ' ';}//prima nuova riga tutta vuota

            for (int i = altezza; i > 0; i--)
            {
                for (int j = larghezza - 2; j > 0; j--)
                {
                    m[i][j] = m[i-1][j];
                    if (m[i][j] != ' ')
                    {
                        gotoxy(j, i-1);
                        cout<<" ";
                        if (m[i][j] == '|' || m[i][j] == '*') setColor('b');
                        if (m[i][j] == '+') setColor('g');
                        if (m[i][j] == '0' || m[i][j] == '@' || m[i][j] == '-') setColor('r');
                        gotoxy(j, i);
                        cout<<m[i][j];
                    }
                }
            }

            gotoxy(0, altezza - 1);
            cout<<"                                                                                                                        ";
            gotoxy(0, altezza);
            cout<<"                                                                                                                        ";
        }

        void Campo::gameover(Tabellone tab){//stampa "game over" al centro
            system("CLS");//pulisco tutto lo schermo
            gotoxy( (larghezza/ 2) -5, (altezza/ 2) );
            setColor('r');
            cout<<"!GAME OVER!";
            gotoxy( (larghezza/ 2) -10, (altezza/ 2) +3 );
            setColor('w');
            cout<<"You survived for: "<<tab.get_tempo()<<" sec";

            int tmp=tab.stampa_lista((larghezza/ 2) -10, (altezza/ 2) +5);

            gotoxy( (larghezza/ 2) -10, tmp++ );
            setColor('w');
            cout<<"Premi 'ESC' per tornare al menu'.";
            gotoxy(0, altezza);
        }

        int Campo::get_larghezza(){return larghezza;}//ritorna la larghezza del campo
        int Campo::get_altezza(){return altezza;}//ritorna l'altezza del campo

         void Campo::del_tan (int x, int y){ //cancella la tanica di benziona con estremo sinistro in alto (x,y)
            m[y][x] = ' ';
            m[y][x+1] = ' ';
            gotoxy(x, y);
            cout << "  ";
            m[y+1][x] = ' ';
            m[y+1][x+1] = ' ';
            gotoxy(x, y + 1);
            cout << "  ";
        }

        void Campo::del_ost(int x, int y){//cancella l ostacolo con estremo sinistro in alto (x,y)
            int i = 1;
            m[y][x] = ' ';
            gotoxy(x, y);
            cout << "  ";
            while (m[y][x+i] != '|')
            {
                m[y][x+i]=' ';
                gotoxy(x+i, y);
                cout << " ";
                i++;
            }
            m[y][x+i] = ' ';
            gotoxy(x+i, y);
            cout << " ";
        }

        void Campo::ins_tan(int x){//inserisco una tanica nel campo con (x,1) come coordinate dell' angolo sinisro in alto
           m[1][x] = '+';
           m[1][x+1] = '+';
           m[2][x] = '+';
           m[2][x+1] = '+';
        }

        void Campo::del_car(int x, int y ){//rimuovo la macchina dal campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[y][x] = ' ';
            m[y+2][x] = ' ';
            m[y+2][x+2] = ' ';
            m[y][x+2] = ' ';
            m[y+1][x+1] = ' ';
            m[y][x+1] = ' ';
            m[y+2][x+1] = ' ';
            gotoxy(x, y);
            cout << "   ";
            gotoxy(x, y+1);
            cout << "   ";
            gotoxy(x, y+2);
            cout << "   ";
        }

        void Campo::ins_ost(int x, int len){//inserisco un ostacolo di lunghezza l nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[1][x] = '|';
            m[1][x + len - 1] = '|';

            for (int i = 1; i < len - 1; i++)
                m[1][x+i] = '*';
        }

        void Campo::ins_car(int x){//inserisco la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[1][x] = '0';
            m[1][x+1] = '-';
            m[1][x+2] = '0';
            m[2][x+1] = 'H';
            m[3][x] = '0';
            m[3][x+1] = '-';
            m[3][x+2] = '0';
        }

        void Campo::ins_enemy_car(int x){//inserisco la macchina nemica nel campo con (x,y) come coordinate dell' angolo sinisro in alto
            m[1][x] = '0';
            m[1][x+1] = '-';
            m[1][x+2] = '0';
            m[2][x+1] = '@';
            m[3][x] = '0';
            m[3][x+1] = '-';
            m[3][x+2] = '0';
        }

        int Campo::control_collision( Livello level, int x, int y){
            int tmp = 0;
            int xTrue = x, yTrue = y;

            /*caso in cui prendo la barriera    :
                                                x
                                                :                   */
            if ( m[y][x] == ':' )
                    tmp = tmp + level.get_p_ost();

            /*caso in cui prendo inizio/o fine ostacolo (si divide in altri 2 casi)  x***|   |***x                  */
            if ( m[y][x] == '|' ){
                //caso 1: m[y][x] è gia' l'angolo sx dell'ostacolo, non devo far nulla
                //caso 2: m[y][x] è l'angolo dx dell'ostacolo, devo risalire al sinistro
                if( m[y][x-1] == '*' ){
                    x--;//decremento di 1 la x perche' altrimenti m[y][x]=|
                    while( m[y][x] != '|' ){x--;} //decremento finche' non trovo l'angolo sx dell'ostacolo
                }
                del_ost(x, y);
                tmp = tmp + level.get_p_ost();
            }

            /*caso in cui prendiamo l'ostacolo al centro    |**x**|             */
            x = xTrue;
            y = yTrue;
            if( m[y][x] == '*' ){
                while( m[y][x] != '|' ){x--;} //decremento x fino a quando non mi ritrovo nell'angolo sx dell'ostacolo
                del_ost(x, y);
                tmp = tmp + level.get_p_ost();
            }

            /*casi in cui prendiamo le taniche   ++  ++  +x  x+
                                                 +x  x+  ++  ++   */
            x = xTrue;
            y = yTrue;
            if ( m[y][x] == '+' ){
                if(m[y-1][x] == '+' ){y--;} //se sono sulla riga piu' in basso incremento (=alzo) la y
                if(m[y][x-1] == '+' && m[y][x] == '+' ){x--;} //se sono sull'angolo in alto dx decremento di 1 la x
                del_tan(x, y);
                tmp = tmp + level.get_p_tan();
            }

            /*casi in cui prendiamo le macchine    @     @     @     x    x-0   0-x
                                                  0-x   0x0   x-0   0-0    @     @         */
            x = xTrue;
            y = yTrue;
            if (m[y][x] == '0'){
                if(m[y][x-1] == '-'){ //caso in cui sono su una ruota dx
                    if(m[y+2][x] == '0'){x = x - 2;}//ruota dx in alto
                    else{//ruota dx in basso
                        x = x - 2;
                        y = y - 2;}
                }else{ //caso in cui sono sulla ruota a sx
                    if(m[y+2][x]!='0') //ruota sx in basso
                        y = y - 2;
                    // altrimenti sono gia' sulla ruota sx in alto
                }
                del_car(x, y);
                tmp = tmp + level.get_p_car();
            }

            return tmp;
        }

        int Campo::control_collision_car( Livello level, int x, int y){
            int tmp = 0;
            tmp+= control_collision(level, x, y);
            tmp+= control_collision(level, x, y+1);
            tmp+= control_collision(level, x, y+2);
            tmp+= control_collision(level, x+2, y);
            tmp+= control_collision(level, x+2, y+2);
            tmp+= control_collision(level, x+1, y);
            tmp+= control_collision(level, x+1, y+1);
            tmp+= control_collision(level, x+1, y+2);
            return tmp;
        }

        int Campo::move_car_dx(Macchina* car, Livello level){
         /*controllo cosa è successo con la macchina spostata di una posizione a dx con il metodo control_collision_cas che :
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una macchina nemica-> ritorna il valore della macchina ovvero level.get_p_car()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */



            //cancello la macchina dallo schermo per poi farla ricomparire spostata
            car->canc_car();

            //sposto la macchina a dx
            car->inc_x();
            int tmp = control_collision_car(level, car->get_posx(), car->get_posy());

            //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo
            if ( larghezza-3 == car->get_posx() )
                car->set_coo(larghezza-5, car->get_posy());

            //ristampo la macchina spostata a dx di rosa
            setColor('p');
            car->stampa_car();

            return tmp;
        }

        int Campo::move_car_sx(Macchina* car, Livello level){
            /*controllo cosa è successo con la macchina spostata di una posizione a sx:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

            //cancello la macchina dallo schermo per poi farla ricomparire spostata
            car->canc_car();

            //sposto la macchina a dx
            car->dec_x();
            int tmp = control_collision_car(level, car->get_posx(), car->get_posy());

            //in caso di urto con la barriera "contengo" la macchina per non farla uscire dal campo
            if ( 0 == car->get_posx() )
                car->set_coo(2, car->get_posy());

            //ristampo la macchina spostata a sx di rosa
            setColor('p');
            car->stampa_car();

            return tmp;
        }


        int Campo::move_car_wx(Macchina* car, Livello level){
            /*controllo cosa è successo con la macchina ferma:
                -se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0
                -se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()
                -se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()
                -se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan() */

            int tmp = control_collision_car(level, car->get_posx(), car->get_posy());

            //ristampo la macchina di rosa
            setColor('p');
            car->stampa_car();

            return tmp;
        }

        void Campo::agg_entita(){
            /*  in base ad un numero randomico che può essere 0, 1 , 2 scelgo che entità aggiungere",
                se=0 nuova tanica,
                se essa=1 nuovo ostacolo di lunghezza "len",
                se essa=2 nuova macchina nemica
                in ogni caso la posizione di partenza sara' m[1][x]
            */

            int x = 2 + rand()% (larghezza - 3);    //la posizione puo' andare nel range [2,99], perche' a m[:][1] e m[:][100] abbiamo i bordi del campo
            int length_ost = 3 + rand()% 5;              //calcolo una lunghezza per l'ostacolo che pu� andare da 3 ad 8

            //attraverso un numero random scelgo se creare una tanica o un ostacolo
            int type_obj = rand()% 3;

            if(type_obj == 0){ //nuova tanica
                if ( x >= larghezza - 3 ) {x = x - 4;} //se la nuova entità andrebbe a finore sul bordo destro la sposto
                ins_tan(x);
            }

           if(type_obj == 1){ //nuovo ostacolo
                if( x > (larghezza - length_ost - 1) ) {x = x - length_ost - 2;} //se la nuova entità andrebbe a finore sul bordo destro la sposto
                ins_ost(x, length_ost);
            }

           if(type_obj == 2){ //nuova macchina nemica
                if( x > larghezza - 4 ) {x = x - 5;} //se la nuova entità andrebbe a finore sul bordo destro la sposto
                ins_enemy_car(x);
            }
        }


