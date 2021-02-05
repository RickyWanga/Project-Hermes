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