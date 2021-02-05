<a name="main"></a>
## Main.cpp
Scrivere informazione riguardanti il main.cpp

<a name="Campo"></a>
## campo.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

 - **Campo(int h, int l)** : Costruttore che setta il campo da gioco vuoto con larghezza "GMAX" e altezza "HMAX"
 - **~Campo()** : distruttore dell Classe
 - **stampa()** : stampa il campo da gioco da capo
 - **scroll()** : sposta tutti gli elementi della matrice di uno in basso
 - **gameover(tabellone tab)** : stampa "game over" al centro
 - **get_larghezza()** : ritorna la larghezza del campo
 - **get_altezza()** : ritorna l' altezza del campo
 - **del_tan(int x, int y)** : cancella la tanica di benzina che inizia dall'angolo in alto a sinistra in posizione (x,y)
 - **del_ost(int x, int y)** : cancella l ostacolo con estremo sinistro in alto (x,y)
 - **del_car(int x, int y )** : cancello la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
 - **ins_tan(int x)** : inserisco una tanica nel campo con (x,y) come coordinate dell' angolo sinisro in alto
 - **ins_ost(int x, int len)** : inserisco un ostacolo di lunghezza "len" nel campo con (x,y) come coordinate dell' angolo sinisro in alto
 - **ins_car(int x)** : inserisco la macchina nel campo con (x,y) come coordinate dell' angolo sinisro in alto
 - **ins_enemy_car(int x)** : inserisco la macchina nemica nel campo con (x,y) come coordinate dell' angolo sinisro in alto
 - **control_collision(Livello level, int x, int y)** : funzione che data la posizione (x,y) della macchina ti restituisce:\
                <ul>
                <li>- 0 non ho sbattuto da nessuna parte</li>
                <li>- ritorna il valore di cosa ho beccato</li>
                </ul>
- **control_collision_car( Livello level, int x, int y)** : 
- **move_car_dx(Macchina* car, Livello level)** : controllo cosa è successo con la macchina spostata di una posizione a dx :\
        <ul>
            <li>se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0</li>
            <li>se utro la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()</li>
            <li>se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()</li>
            <li>se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()</li>
            <li>se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan()</li>
        </ul>
- **move_car_sx(Macchina* car, Livello level)** : controllo cosa è successo con la macchina spostata di una posizione a sx:\
        <ul>
          <li>se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0</li>
          <li>se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()</li>
          <li>se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()</li>
          <li>se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()</li>
          <li>se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan()</li>  
        </ul>
- **move_car_wx(Macchina* car, Livello level)** : controllo cosa è successo con la macchina che va solo avanti:
        <ul>
            <li>se non urto niente, ne' i lati del campo da gioco, ne' ostacoli vari-> ritorna 0</li>
            <li>se urto la barriera-> ritorna il valore della barriera ovvero level.get_p_bar()</li>
            <li>se urto un ostacolo-> ritorna il valore dell'ostacolo ovvero level.get_p_ost()</li>
            <li>se urto una macchina nemica-> ritorna il valore della macchina nemica ovvero level.get_p_car()</li>
            <li>se urto una tanica bonus-> ritorna il valore della tanica bonus ovvero level.get_p_tan()</li>
        </ul>
- **agg_entita()** : in base ad un numero randomico che può essere 0, 1 , 2 scelgo che entità aggiungere":
        <ul>
                <li>se=0 nuova tanica</li>
                <li>se essa=1 nuovo ostacolo di lunghezza "len"</li>    
                <li>se essa=2 nuova macchina nemica</li>
                <li>in ogni caso la posizione di partenza sarà m[1][x]</li>
        </ul>

<a name="Entità"></a>
## Entità.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Entita(int x, int y, int width, int height)** : costruttore, creo nuova istanza e gli assegn come posizione (x,y) e lunghezza ed altezza passata
- **~Entita()** : distruttore della classe
- **get_posx()** : ritorna posizione x
- **get_posy()** : ritorna posizione y
- **set_coo(int x, int y)** : imposta le coordinate dell'entità a position.X=x e position.Y=y

<a name="Livello"></a>
## Livello.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Livello()** : inizializza un'istanza della classe livello con num_livello=1
- **~Livello()** : distruttore della Classe
- **uplevel()** : aumenta di un livello quindi aumenta la difficoltà
- **downlevel()** : diminuisce di un livello quindi diminuisce la difficoltà
- **get_intervallo()** : ritorna il valore di "intervallo"
- **get_level()** : ritorna il numero del livello attuale
- **get_vel()** : ritorna la velocità attuale
- **get_p_ost()** : ritorna valore ostacolo
- **get_p_tan()** : ritorna valore tanica
- **get_p_bar()** : ritorna valore barriera
- **get_p_car()** : ritorna valore macchina
- **info_lev(int x)** : 

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

<a name="Ostacolo"></a>
## Ostacolo.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Ostacolo(int x, int y, int larghezza)** : //Costruttore della classe Ostacolo che setta l'ostacolo nella posizione (x, y) 
- **~Ostacolo()** : distruttore della classe

<a name="Tanica"></a>
## Tanica.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Tanica(int x, int y)** : costruttore della classe Tanica che setta la tanica nella posizione (x, y)
- **~Tanica()** : distruttore della classe

<a name="Tabellone"></a>
## Tabellone.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **Tabellone()** : costruttore della classe
- **~Tabellone()** : distruttore della classe
- **set_tempo(int time)** : modifico la variabile tempo sostituendola con temp
- **inc_punt(int score)** : aumento il punteggio del valore "score" che può essere anche negativo
- **inc_tempo()** : aumento di uno il contatore dei secondi
- **get_tempo()** : ritorna il secondo di gioco al quale sono arrivato fino ad ora
- **get_punt()** : ritorna il punteggio al quale sono arrivato fino ad ora
- **get_list()** : ritorna la lista dei punteggi
- **stampa_tab(int x)** : stampa tabellone
- **aggiorna(int score, int x)** : incrementa il punteggio di "score", aumenta il tempo di uno e stampa tabellone
- **t_insert(int value,int livello)** : inserisce i valori value e livello nella lista
- **stampa_lista(int x,int y)** : stampa la lista

<a name="Tabellone"></a>
## Tabellone.cpp
Descrizione del funzionamento della Classe

La classe contiene le seguenti funzioni pubbliche:

- **gotoxy(int x, int y)** : 
- **ShowConsoleCursor(bool Show)** : 
- **caricamento()** : stampa la barra di caricamento
- **stampa_info()** : stampa le informazioni relative alle regole e istruzioni di gioco
- **stampa_menu()** : stampa il menu principale
- **print_uplevel(int larghezza, int lev)** : stampa la notifica di aumento di livello
- **print_downlevel(int larghezza, int lev)** : stampa la notifica di diminuzione di livello
- **anc_upEdown_level(int larghezza, int altezza)** : cancella la notifica di aumento/dimuzione livello
- **setColor(char color)** : setta il colore del carattere da stampare