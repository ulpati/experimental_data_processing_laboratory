# Esercizio 10.0 - Generatore di numeri casuali

Scrivere un programma che produca quattro istogrammi contenenti ciascuno 10000 numeri pseudo-casuali estratti da:

* una distribuzione uniforme tra 5 e 10.
* una distribuzione esponenziale tra 0 e +∞ con costante $k=1$.
* una distribuzione gaussiana centrata in 1 e larghezza 1 con il metodo di Box-Muller.
* una distribuzione gaussiana centrata in 1 e larghezza 1 con il metodo accept-reject.

# Esercizio 10.2 - Calcolo di integrali con metodi MonteCarlo

#.  Calcolare 10000 volte il valore dell'integrale di $\sin(x)$ su $[0, \pi]$ utilizzando il metodo della media a 100 punti e fare un grafico (istogramma) della distribuzione dei valori ottenuti.

#.  Estendere il punto precedente calcolando 10000 volte il valore dell'integrale di $\sin(x)$ su $[0, \pi]$ utilizzando il metodo della media a $N$ punti, con $N$ pari a 100, 500, 1000, 5000, 10000 punti. Per ogni valore di $N$ produrre il grafico della distribuzione dei 10000 valori ottenuti.
#.  Stimare l'errore sul calcolo dell'integrale a 100, 500, 1000, 5000, 10000 punti come deviazione standard dei 10000 valori calcolati per ogni $N$.
#. Si ripeta lo stesso lavoro con il metodo hit-or-miss.

Infine ho ottimizzato i due metodi e ho comparato il risulato con i nuovi istogrammi.