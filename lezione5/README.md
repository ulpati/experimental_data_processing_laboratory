# Esercizio 5.0 - Creazione della classe Posizione

Implementare una classe `Posizione` che descriva un punto nello spazio
      seguendo queste indicazioni:

#.  Come data membri privati usare la terna di coordinate cartesiane.
#.  Definire un costruttore di default che crei un punto di coordinate (0,0,0).
#.  Definire un costruttore che abbia come argomento una terna di numeri `double` corrispondenti alle coordinate del punto.
#.  Definire metodi per restituire le coordinate del punto in sistemi di coordinate cartesiane, sferiche e cilindriche.
#.  Definire un metodo che calcoli la distanza da un altro punto.

Verificare il funzionamento della classe creando un programmino che legga da riga di comando le coordinate cartesiane di un punto e ne stampi le coordinate in un sistema di coordinate sferiche e cilindriche.

# Esercizio 5.1 - Creazione della classe Particella ed Elettrone

Incominciamo a definire due classi che ci permetteranno di rappresentare le sorgenti del campo (elettrico in questo caso).

-   Costruiamo una classe `Particella` caratterizzata dall'avere una massa ed una carica, quindi dotata dei seguenti metodi:

    #.  Un construttore avente come argomenti massa e carica.
    
    #.  Dei metodi di accesso ai valori di massa e carica.
    
    #.  Un metodo per stampare tali valori. 
    
-   Siccome vogliamo che questa classe sia la classe base di altre classi, dichiareremo i data membri come `protected`.

-   Costruiamo, attraverso il meccanismo di ereditarietà, una classe derivata `Elettrone` che, essendo una `Particella` di massa e carica note (i cui valori sono riportati su [wikipedia](http://it.wikipedia.org/wiki/Elettrone)), ha il solo costruttore di default, che inizializza correttamente i data membri. Modifichiamo il metodo di stampa in modo che indichi che si tratta di un elettrone.

Verifichiamo che le nuovi classi e l'ereditarietà funzioni correttamente:

#.  Istanziamo dinamicamente un oggetto per ogni classe.
#.  Verifichiamo che su tutti questi operano i metodi accessori di massa e carica di `Particella`, ma il metodo di stampa delle classi derivate. 

# Esercizio 5.2 - Creazione delle classi `CampoVettoriale` e `PuntoMateriale`

Per risolvere problemi relativi all'elettrostatica o alla gravità proviamo ad effettuare una modellizzazione basata su due elementi principali: una rappresentazione del campo vettoriale e una rappresentazione delle sorgenti dei campi vettoriali.

Definiremo quindi una classe `CampoVettoriale`: sono molti i casi in Fisica in cui un vettore è collegato ad un punto dello spazio. Ad esempio una forza ha un punto di applicazione, o i vettori del campo elettrico e campo gravitazionale hanno un valore che varia da punto a punto dello spazio.

Questo esercizio richiede di costruire una classe `CampoVettoriale`, che erediti dalla classe `Posizione` e che aggiunga:

#.  le tre componenti di un vettore alla posizione;

#.  i metodi per accedere e/o modificare il vettore;

#.  costruttori: in particolare, il costruttore `CampoVettoriale(const Posizione&)` che crei un vettore nullo nella posizione assegnata;

#.  un metodo `double Modulo() const` che restituisca la lunghezza del vettore;

#.  overloading di `operator+` e `operator+=` in modo da poter facilmente sommare campi. 

# Esercizio 5.3 - Calcolo del campo elettrico generato da un dipolo

A questo punto possiamo utilizzare tutti gli ingredienti realizzati sopra per affrontare un interessante problema di elettrostatica ovvero lo studio del campo elettrico generato da un dipolo. Per fare questo sviluppiamo un codice che costuisca un dipolo costituito da un elettrone e un protone posizionati ad una distanza $\delta = 10^{-10}\,\text{m}$ e determini:

#.  il valore del campo elettrico di dipolo prodotto in un punto $P$ .
#.  disegni l'andamento del modulo del campo elettrico lungo l'asse del dipolo per una distanza da 100 a 1000 volte $\delta$.