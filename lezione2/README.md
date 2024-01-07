# Esercizio 2.0 - Creazione della classe Vettore

In questo esercizio proviamo ad implementare una classe che abbia come data membri privati un intero (dimensione del vettore) ed un puntatore a `double` (puntatore alla zona di memoria dove sono immagazzinati i dati).

La classe dovrà poi implementare:

-   Un costruttore di default, che assegni valori nulli alla lunghezza del vettore ed al puntatore.
-   Un costruttore che abbia come argomento un intero: questo deve creare un vettore di lunghezza uguale al valore dell'intero e tutte le componenti nulle (usando un `new` per allocare la memoria necessaria).
-   Un distruttore: deve chiaramente deallocare con `delete[]` la zona di memoria allocata con new.
-   Dei metodi per inserire e leggere i valori della componenti: questi metodi devono controllare che l'indice delle componenti richieste sia compatibile con la lunghezza del vettore.

La classe `vettore` costruita sopra non è però ancora completa, anzi può essere addirittura pericolosa! In particolare vogliamo:

1.  Aggiungere la possibilità di costruire un `Vettore` a partire da un `Vettore` esistente (*costruttore di copia*)

2.  Aggiungere la possibilità di eguagliare due oggetti di tipo `vettore` (*operatore di assegnazione*)

3.  Aggiungere un operatore di accesso rapido alle componenti (`[]`).

# Esercizio 2.1 - Codice di analisi dati utilizzando la classe `Vettore`

Proviamo ora a riscrivere il codice della prima lezione utilizzando un contenitore di dati più raffinato: la classe `Vettore` ci permetterà di riempire il contenitore dati controllando per esempio che non stiamo sforando la dimensione allocata. La classe `Vettore` inoltre mantiene al suo interno anche la sua dimensione (nel campo `m_N`): se dobbiamo calcolare la media degli elementi di un `Vettore` **non dobbiamo più passare la dimensione come argomento esterno**! Per svolgere questo esercizio dobbiamo:

-   modificare tutte le funzioni in `funzioni.h` e `funzioni.cpp` in modo che lavorino con oggetti di tipo `Vettore` invece che con semplici array del C.
-   modificare il `main` in modo che utilizzi la nuova classe `Vettore` e le nuove funzioni.
-   modificare il `Makefile`