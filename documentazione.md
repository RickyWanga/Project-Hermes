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
Nel main vediamo la funzione che ci permette di nascondere il cursore, la chiamata di srand(..) per poter creare le nuove entità in modo randomico, la funzione che stampa sullo schermo il "caricamento del gioco"
(aggiunta puramente estetica), la funzione per stampare il menù **'stampa_menu()'** che presenta 3 opzioni 'INIZIA IL GIOCO', 'INFORMAZIONI' ed 'ESCI' nel quale si può navigare assraverso i comandi ‘w’ 
per andare su e ‘s’ per andare giù (una volta scorso tutto il menù la freccia tornerà alla prima opzione).

Scelta la prima opzione partirà il gioco vero e proprio attraverso la chiamata della funzione start_game().
Scelta la seconda opzione verranno stampate tutte le informazioni attraverso la chiamata della funzione stampa_info().
Scelta la terza opzione il programma terminerà.

- **start_game()**: funzione in cui prima istanziamo le variabili e classi necessarie per il funzionamento del gioco, poi le usiamo per muoverci, aggiornare i punti, 
	stampare a schermo le informazioni necessarie etc.
	In questa fase la lettura dei comandi 'a' e 'd'  avviene attraverso due funzioni presenti in conio.h ovvero khbit() e getch() che ci permettono rispettivamente
	di sapere su un tasto è stato premuto (è presente qualcosa nel buffer) e di salvare il valore di questo tasto in una variabile (ovvero 'cmd').
	Una volta salvato il tasto premuto in questa variabile possiamo muoverci di conseguenza (a destra o a sinistra) e in caso non corrispondesse a nessuno dei comandi
	possibili lasciamo andare la macchinina avanti.  
	
	Il controllo delle possibili collisoni lo fa già un metodo all'interno della classe 'Campo' (andare a vederla per maggiori dettagli) che ritorna il valore dell'entità urtata
	da andare a sommare al puteggio corrente.
	Salveremo questo valore in una variabile chiamata 'control_value' che poi useremo per l'aggiornamento del tabellone e del livello.

	Il gioco è potenzialmente infinito, ciò significa che continuerà finchè il giocatore non perderà (ovvero il suo punteggio scenderà sotto 0) o premerà il tasto 'ESC' per
	uscire (in entrambi i casi verrà visualizzata la schermata del 'GAMEOVER' con le statistiche di gioco). 
	Ogni 100 punti si sale di livello e viene stampato un riquadro che ci informa dell' UPLEVEL e del DOWNLEVEL in caso invece si scenda di 100 punti.
	Ad ogni UPLEVEL abbiamo un incremento della difficoltà implementato attraverso l' aumento di tutti i parametri del gioco e viceversa ad ogni DOWNLEVEL il gioco diventerà più facile.
	E' importante ricordare che in caso si ritorni a giocare lo stesso livello il grado di difficoltà sarà lo stesso quindi i parametri saranno gli stessi.
	
	In caso di uscita dal gioco (perdendo o premendo 'ESC') si chiamerà il metodo '**gameover(..)**' della classe Campo che stamperà su schermo quanti secondi abbiamo giocato e le statistiche
	di gioco ovvero tutti i momenti in cui siamo saliti o scesi di livello, precedentemente salvati in una lista nella classe Tabellone.
	

- **stampa_info()**: funzione che stampa tutte le informazioni necessarie, ovvero le regole del gioco, la legenda delle entità e i nomi degli autori del gioco.

<a name="Campo"></a>
## campo.cpp
Classe contenente la matrice sulla quale si incentra l'intero gioco, infatti attraverso tutti i metodi elencati di seguito si implementa la sua gestione. 
Possiamo infatti far scorrere l' intera matrice e quindi far scorrere tutte le entità in essa salvate (taniche, ostacoli, macchine nemiche), crearne di nuove, inserirle nel nostro campo ed eliminarle quando opportuno. 
Questa classe è a tutti gli effetti il cuore del gioco perchè permette di spostare la macchinina del giocatore all'interno del campo e di controllare le possibili collisioni.

La classe contiene le seguenti funzioni pubbliche:

 - **Campo(int h, int l)** : Costruttore che setta il campo da gioco vuoto con larghezza "l" e altezza "h"
 - **~Campo()** : distruttore della classe che libera lo spazio dedicato alla matrice
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
                <li> 0 se quella posizione nella matrice non corrisponde a nulla, quindi se in (x,y) ho il campo vuoto</li>
                <li> ritorna il valore dell'entità a cui appartiene il carattere nella posizione (x,y) e la elimina sia dalla matrice che dallo schermo</li>
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
- **m** : matrice sulla quale salveremo le entità
- **bordo** : carattere che definisce il bordo del campo

<a name="Entità"></a>
## Entità.cpp
La classe Entità attraverso il contruttore inizializza una nuova entità con le coordinat epassate come parametro ed implementa alcune funzioni base, 
come '**get_posx()**', '**get_posy()**' e '**set_coo(..)**' che potranno essere usufruite dalle classi figlie, nel nostro caso da Macchina.

La classe contiene le seguenti funzioni pubbliche:

- **Entita(int x, int y)** : costruttore della classe che gli assegna come posizione (x,y)
- **get_posx()** : ritorna posizione x
- **get_posy()** : ritorna posizione y
- **set_coo(int x, int y)** : imposta le coordinate dell'entità a position.X=x e position.Y=y

Gli attributi protected sono : 

- **position** : coordinate x e y dell'angolo sinistro in alto della mia entità

<a name="Macchina"></a>
## Macchina.cpp
La classe Macchina è una sottoclasse (detta anche classe figlia) di Entità infatti in quanto tale essa richiama il costrutttore di Entità e ne usa i metodi ereditati.
Essa implementa sia il movimento della macchinina del giocatore all' interno della matrice di Campo attraverso i metodi '**inc_x()**' e '**dec_x()**', 
sia all' interno dello schermo attraverso le funzioni '**canc_car()**' e '**stampa_car()**' che permettono di far scomparire e riapparire la macchinina.

La classe contiene le seguenti funzioni pubbliche:

- **Macchina(int x, int y)** : costruttore che setta la macchina nella posizione (x,y)
- **inc_x()** : incremento di uno la position.X
- **dec_x()** : decremento di uno la position.X
- **stampa_car()** : stampo la macchina sullo schermo con angolo sinistro in alto in posizione "position"
- **canc_car()** : cancello la macchina dallo schermo con angolo sinistro in alto in posizione "position"

<a name="Livello"></a>
## Livello.cpp
La classe Livello implementa la generazione infinita dei livelli e la loro gestione attraverso uplevel() e downlevel(). 
Contiene anche tutti i getter dei sui attributi quindi dei parametri che decretano la difficoltà del livello corrente e
ed una funzione che durante la partita stampa su schermo tutte le informazioni necessarie. 
Il gioco salirà di livello e quindi di difficoltà ogni 100 punti, infatti nell funzione start_game() all'interno del main
si controlla il punteggio e se necessario si chiamano i metodi '**uplevel()**' e '**downlevel()**'. 

La classe contiene le seguenti funzioni pubbliche:

- **Livello()** : costruttore che inizializza la classe livello con tutti i parametri del livello 1
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
La classe Tabellone dopo aver inizializzato tutto al suo valore iniziale (tempo e punteggio pari a 0 e puntatore della lista pari a NULL) si occupa della 
gestione del tempo e del punteggio, stampando inoltre a lato del campo da gioco da quanti secondi stiamo giocando e lo score raggiunto attraverso il metodo '**stampa_tab(..)**'. 
Il metodo chiamato dalla funzione start_game() sarà '**aggiorna(..)**' che si occuperà di incrementare il tempo e di aggiornare il punteggio (aggingendogli il
parametro 'score' ) e di stampare le informazioni su schermo chiamando '**stampa_tab(..)**'.

Sono presenti inoltre i getter di tutti gli attributi e due metodi per la gestione della lista delle statisctiche ovvero l'inserimento in
coda '**t_insert(..)**' e la stampa '**stampa_lista(..)**'.

La classe contiene le seguenti funzioni pubbliche:

- **Tabellone()** : costruttore che setta tutti gli attributi della classe al valore iniziale
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
Libreria di funzioni generali usate sia dalle classi che dal main per renderne più agevole la gestione.

La classe contiene le seguenti funzioni pubbliche:

- **gotoxy(int x, int y)** : funzione che ci permette di muoverci agevolmente nello schermo
- **ShowConsoleCursor(bool Show)** :  funzone per nascondere il cursore
- **print_uplevel(int larghezza, int lev)** : stampa il riquadro UPLEVEL a lato del campo da gioco
- **print_downlevel(int larghezza, int lev)** : stampa il riquadro DOWNLEVEL a lato del campo da gioco
- **canc_upEdown_level(int larghezza, int altezza)** : cancella il riquadro di aumento/dimuzione livello
- **setColor(char color)** : setta il colore del carattere da stampare
