# Esercizio 6.0 - Metodi virtuali

Prima di incominciare con la lezione vera e propria, proviamo a riflettere sul significato del polimorfismo attraverso l'uso del qualificatore `virtual`. Consideriamo le classi `Particella` e la sua derivata `Elettrone` costruite nella lezione 5.

# Esercizio 6.1 - Classe astratta FunzioneBase

In questo esercizio scriviamo un set di classi per modellizzare una generica funzione di una variabile:

#.  Definire la classe astratta FunzioneBase, che implementi un metodo `double Eval(double x) const` che modellizza l'effetto di applicare $f$ in $x$.

#.  Implementare una classe derivata `Parabola` che descriva una funzione del tipo $f(x) = a x^2 + b x + c$ (chiaramente questa classe dovrà avere i data membri per i parameteri $a$, $b$ e $c$, ed i metodi per definirli e accederci).

#.  Verificare il funzionamento della classe `Parabola` costruendo un programmino che, dati i parametri di una parabola, ne stampi il valore della $y$ nel vertice $x_v = -b / 2a$.

# Esercizio 6.2 - Metodo della bisezione

Passiamo ora alla codifica della parte relativa agli algoritmi di ricerca degli zeri di una funzione: proviamo a scrivere un programma che calcoli gli zeri della funzione
$
f(x) = 3x^2 + 5x - 2.
$

Per calcolare gli zeri, implementeremo una classe astratta `Solutore` ed una classe concreta che realizza il metodo della bisezione visto a lezione. Si richiede obbligatoriamente che il programma stampi l'ascissa dello zero con un numero di cifre significative corrispondente alla precisione immessa.

# Esercizio 6.3 - Equazioni non risolubili analiticamente

In problemi di meccanica quantistica che verranno studiati nel prossimo anno, ci si può imbattere in equazioni del tipo:
$
x = \tan x.
$

È facile rendersi conto che tale equazione ha una soluzione in ciascuno degli intervalli $(n\pi, n\pi + \pi/2)$ con $n = 1, 2, 3\ldots$. Calcolare con una precisione di almeno $10^{-6}$ i valori delle soluzioni per $n = 1\ldots 20$.

**Suggerimento**: riscrivere l'equazione come $\sin x - x \cos x = 0$

# Esercizio 6.4 - Ricerca di zeri di una funzione senza uso del polimorfismo

Si provi ad implementare un algoritmo di ricerca degli zeri di una funzione senza utilizzare il polimorfismo. Si potrebbe codificare il metodo della bisezione in una funzione che accetti in input una `std::function`, e modellizzare la funzione di cui si vuole cercare lo zero con una funzione lambda.