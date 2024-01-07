# Esercizio 1.0 - Primo codice per analisi

Proviamo a scrivere un unico codice che legga dati da file, li immagazzini in un array dinamico, calcoli la media, la varianza e la mediana dei dati raccolti. Scriviamo su un file di output i dati riordinati in ordine crescente. Il numero di elementi da caricare e il nome del file in cui trovare i dati sono passati da tastiera nel momento in cui il programma viene eseguito.

# Esercizio 1.1 - Codice di analisi con funzioni

Vogliamo ora riorganizzare il codice precedente per renderlo più modulare e facilmente riutilizzabile. Per capirci meglio: il calcolo della media è una operazione generale che può essere immaginata come un blocco di codice che accetta in input un array di dati e una dimensione e restituisce un valore (la media, appunto). Se in uno stesso codice principale dobbiamo calcolare più volte la media di array di dati diversi, non vogliamo ripetere più volte il frammento di codice relativo; lo stesso vale per la lettura di un set di dati da un file o per il calcolo della mediana. Il codice dovrebbe avere quindi una struttura del tipo:

-   Dichiarazione di tutte le funzioni che verranno utilizzate.
-   Programma vero e proprio `int main() {...}` in cui le funzioni vengono utilizzate.
-   Al termine del programma principale l'implementazione di tutte le funzioni dichiarate.

# Esercizio 1.2 - Codice di analisi con funzioni e Makefile

In questo esercizio terminiamo il processo di riorganizzazione dell'esercizio 1.0. Procederemo in questo modo:

-   Spostiamo tutte le dichiarazioni di variabili che abbiamo messo in testa al programma in un file separato `funzioni.h`.
-   Spostiamo tutte le implementazioni delle funzioni in coda al programma in un file separato `funzioni.cpp`.
-   Ricordiamoci di includere il file `funzioni.h` sia in `main.cpp` sia in `funzioni.cpp` tramite il solito `#include "funzioni.h"`
-   Compiliamo separatamente `main.cpp` e `funzioni.cpp` utilizzando un `Makefile`

# Esercizio 1.3 - Overloading di funzione

Aggiungete alla vostra libreria di funzioni una funzione `void Print(const double *, int)` che permetta di scrivere gli elementi di un array a video. Questo è possibile grazie all'*overloading* (funzioni con stesso nome, ma con argomenti differenti).