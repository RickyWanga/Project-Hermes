## Table of contents
1. [ Main.cpp ](#main)
2. [ Campo.cpp ](#Campo)
3. [ Livello.cpp ](#Livello)
4. [ Macchina.cpp ](#Macchina)
5. [ Ostacolo.cpp ](#Ostacolo)
6. [ Tanica.cpp ](#Tanica)
7. [ Tabellone.cpp ](#Tabellone)
7. [ Otherfunctions.cpp ](#Otherfunctions)


<a name="main"></a>
## Main.cpp
Scrivere informazione riguardanti il main.cpp

<a name="Campo"></a>
## campo.cpp
Classe contenente la matrice sulla quale si incentra l'intero gioco, infatti attraverso tutti i metodi elencati di seguito si implementa la sua gestione.
Possiamo infatti far scorrere l' intera matrice e quindi far scorrere tutte le entità in essa salvate (taniche, ostacoli, macchine nemiche), crearne di nuove, inserirle nel nostro campo ed eliminarle quando opportuno.
Questa classe è a tutti gli effetti il cuore del gioco perchè permette di spostare la macchinina del giocatore all'interno del campo e di controllare le possibili collisioni.

La classe contiene le seguenti funzioni pubbliche:

 - **Campo(int h, int l)** : Costruttore che setta il campo da gioco vuoto con larghezza "l" e altezza "h"
 - **~Campo()** : distruttore della classe
 - **stampa()** : stampa il campo da gioco vuoto
 - **scroll()** : sposta tutti gli elementi della matrice di una riga più in basso e ne implementa lo scorrimento anche sullo schermo stesso
 - **gameover(tabellone tab)** : stampa "game over" al centro dello schermo stampando anche le statistiche di gioco
 - **get_larghezza()** : ritorna la larghezza del campo
 - **get_altezza()** : ritorna l' altezza del campo
 - **del_tan(int x, int y)** : cancella la tanica di benzina che ha l' angolo in alto a sinistra in posizione (x,y)
 - **del_ost(int x, int y)** : cancella l ostacolo che ha l' angolo in alto a sinistra in posizione (x,y)
 - **del_car(int x, int y )** : cancello la macchina che ha l' angolo in alto a sinistra in posizione (x,y)
 - **ins_tan(int x)** : inserisco una tanica avente come coordinate dell' angolo sinistro in alto (x,y) nella matrice 
 - **ins_ost(int x, int len)** : inserisco un ostacolo di lunghezza "len" avente come coordinate dell' angolo sinistro in alto (x,y) nella matrice 
 - **ins_enemy_car(int x)** : inserisco una macchina nemica avente come coordinate dell' angolo sinistro in alto (x,y) nella matrice 
 - **control_collision(Livello level, int x, int y)** : metodo che data una posizione (x,y) restituisce:\
            <ul>
                <li>- 0 se quella posizione nella matrice non corrisponde a nulla, quindi se in (x,y) ho il campo vuoto</li>
                <li>- ritorna il valore dell'entità a cui appartiene il carattere nella posizione (x,y) e la elimina sia dalla matrice che dallo schermo</li>
            </ul>
- **control_collision_car( Livello level, int x, int y)** : metodo che richiama il precedente, ovvero control_collision(..), su tutto il contorno della macchinina del giocatore, ne controlla quindi le collisioni nel campo da gioco 
- **move_car_dx(Macchina* car, Livello level)** : controllo cosa è successo dopo aver spostato la macchina di una posizione a dx e la ristampo nella nuova posizione. Inoltre:\
        <ul>
            <li>se non urto niente, ne' i lati del campo da gioco, ne' diverse entità-> ritorna 0</li>
            <li>se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()</li>
            <li>se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()</li>
            <li>se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()</li>
            <li>se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan()</li>
        </ul>
- **move_car_sx(Macchina* car, Livello level)** : controllo cosa è successo dopo aver spostato la macchina di una posizione a sx e la ristampo nella nuova posizione. Inoltre:\
        <ul>
            <li>se non urto niente, ne' i lati del campo da gioco, ne' diverse entità-> ritorna 0</li>
            <li>se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()</li>
            <li>se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()</li>
            <li>se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()</li>
            <li>se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan()</li>
        </ul>
- **move_car_wx(Macchina* car, Livello level)** : controllo cosa succede non muovendo la macchina (andando solo avanti). Inoltre:\
        <ul>
            <li>se non urto niente, ne' i lati del campo da gioco, ne' diverse entità-> ritorna 0</li>
            <li>se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()</li>
            <li>se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()</li>
            <li>se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()</li>
            <li>se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan()</li>
        </ul>
- **agg_entita()** : in base ad un numero randomico che può essere 0, 1 o 2 scelgo che entità aggiungere":
        <ul>
            <li>se=0 nuova tanica</li>
            <li>se essa=1 nuovo ostacolo di lunghezza "len"</li>    
            <li>se essa=2 nuova macchina nemica</li>
            <li>in ogni caso la posizione di partenza sarà in cima al campo</li>
        </ul>

Gli attributi protected sono : 

- **larghezza** : numero di colonne della matrice del campo da gioco
- **altezza** : numero di righe della matrice del campo da gioco
- **m[HMAX][GMAX]** : matrice sulla quale salveremo le entità
- **bordo** : carattere che definisce il bordo del campo

<a name="Entità"></a>
## Entità.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Entita(int x, int y)** : costruttore della classe che gli assegna come posizione (x,y)
- **~Entita()** : distruttore della classe
- **get_posx()** : ritorna posizione x
- **get_posy()** : ritorna posizione y
- **set_coo(int x, int y)** : imposta le coordinate dell'entità a position.X=x e position.Y=y

Gli attributi protected sono : 

- **position** : coordinate x e y dell'angolo sinistro in alto della mia entità

<a name="Macchina"></a>
## Macchina.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Macchina(int x, int y)** : costruttore che setta la macchina nella posizione (x,y)
- **~Macchina()** : distruttore della classe
- **inc_x()** : incremento di uno la position.X
- **dec_x()** : decremento di uno la position.X
- **stampa_car()** : stampo la macchina sullo schermo con angolo sinistro in alto in posizione "position"
- **canc_car()** : cancello la macchina dallo schermo con angolo sinistro in alto in posizione "position"

<a name="Livello"></a>
## Livello.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Livello()** : costruttore che inizializza la classe livello con tutti i parametri del livello 1
- **~Livello()** : distruttore della classe
- **uplevel()** : aumenta il livello e tutti i parametri (quindi aumenta la difficoltà)
- **downlevel()** : diminuisce il livello e diminuisce tutti i parametri (quindi diminuisce la difficoltà)
- **get_intervallo()** : ritorna il valore di "intervallo"
- **get_level()** : ritorna il numero del livello attuale
- **get_vel()** : ritorna la velocità attuale 
- **get_p_ost()** : ritorna valore ostacolo
- **get_p_tan()** : ritorna valore tanica
- **get_p_bar()** : ritorna valore barriera
- **get_p_car()** : ritorna valore macchina
- **info_lev(int x)** : stampa tutte le informazioni relative al livello a video, sia il numero del livello che tutti i suoi parametri

Gli attributi protected sono : 

- **vel** : contiene il valore della velocità della macchina al livello corrente
- **num_livello** : contiene il valore del livello corrente
- **intervallo** : contiene il valore dell'intervallo ogni quale deve essere creata una nuova entità
- **p_ost** : quanti punti vale prendere l'ostacolo (valore in negativo)
- **p_tan** : quanti punti vale prendere la tanica (valore in positivo)
- **p_bar** : quanti punti vale prendere la barriera (valore in negativo)
- **p_car** : quanti punti vale prendere un'altrea car (valore in negativo)
- **levelBlocked** : indica il numero del livello dal quale l'intervallo è bloccato, ovvero non aumenterà più
- **velBlocked** : indica il numero del livello dal quale la velocità è bloccata, ovvero non aumenterà più

<a name="Tabellone"></a>
## Tabellone.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Tabellone()** : costruttore che setta tutti gli attributi della classe al valore iniziale
- **~Tabellone()** : distruttore della classe
- **get_tempo()** : ritorna i secondi giocati fino ad ora
- **get_punt()** : ritorna il punteggio al quale sono arrivato fino ad ora
- **get_list()** : ritorna la lista dei UPLEVEL & DOWNLEVEL
- **stampa_tab(int x)** : stampa tabellone dalla colonna x in poi
- **aggiorna(int score, int x)** : incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone dalla colonna x
- **t_insert(int value,int livello)** : inserisce un nuovo nodo nella lista con valori "value" e "livello"
- **stampa_lista(int x,int y)** : stampa la lista dei UPLEVEL & DOWNLEVEL, ovvero le statistiche di gioco

Gli attributi protected sono : 

- **tempo** : contatore secondi di gioco
- **punteggio** : contatore punteggio
- **head** : puntatore alla testa della lista dei UPLEVEL & DOWNLEVEL

<a name="Otherfunctions"></a>
## Otherfunctions.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **gotoxy(int x, int y)** : funzione che ci permette di muoverci agevolmente nello schermo
- **ShowConsoleCursor(bool Show)** : 
- **print_uplevel(int larghezza, int lev)** : stampa il riquadro UPLEVEL
- **print_downlevel(int larghezza, int lev)** : stampa il riquadro DOWNLEVEL
- **canc_upEdown_level(int larghezza, int altezza)** : cancella il riquadro di aumento/dimuzione livello
- **setColor(char color)** : setta il colore del carattere da stampare

Le costanti globali sono : 

- **GMAX** : massime colonne della matrice del campo da gioco
- **HMAX** : massime righe della matrice del campo da gioco