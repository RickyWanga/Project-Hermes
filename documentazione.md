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