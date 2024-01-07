# Esercizio 8.0 - Algebra vettoriale

Come prima cosa, proviamo a dotare il tipo `std::array` della STL di tutte le funzionalità algebriche che ci possono essere utili, definendo opportunamente gli operatori `+`, `*`, `/`, `+=`. Dal momento che non possiamo modificare gli header files e i files di implementazione della classe `std::array`, implementiamo questi operatori come funzioni libere in un header file apposito da includere quando necessario. 

# Esercizio 8.1 - Risoluzione equazione differenziale tramite metodo di Eulero

Nel primo esercizio implementeremo un codice per la risoluzione numerica dell'equazione differenziale che descrive il moto di un oscillatore armonico tramite il metodo di Eulero. Gli obiettivi principali di questo esercizio sono due:

1.  Studiare l'andamento della posizione in funzione del tempo `t` (per `t` che va da 0 a 70 secondi) per un fissato passo di integrazione `h` (si potrebbe costruire un grafico, per esempio) e confrontare l'errore commesso con la soluzione esatta.

2.  Studiare l'andamento dell'errore che si commette utilizzando il metodo di Eulero quando confrontiamo la soluzione approssimata con la soluzione esatta nell'istante t = 70 s in funzione del passo di integrazione `h` in un intervallo compreso tra 0.1 e 0.001.

Per testare il metodo, risolviamo l'equazione differenziale:

$$
\frac{\mathrm{d}}{\mathrm{d}t} \begin{pmatrix}x\\v\end{pmatrix} =
\begin{pmatrix}v\\-\omega_0^2 x\end{pmatrix},\quad x(0) = 0, \quad v(0) = 1\,\text{m/s}, \quad \omega_0 = 1\,\text{s}^{-1},
$$

mettendo in grafico il valore della $x$ in funzione del tempo $t$ ed eventualmente anche il suo errore rispetto alla soluzione esatta del problema, che è $x(t) = \sin (t)$. Si consiglia di svolgere l'integrazione per un certo numero di periodi, in modo da vedere se l'ampiezza di oscillazione rimane costante. Integrare fino a $t = 70\,\text{s}$ permette di vedere circa 10 periodi.

# Esercizio 8.2 - Risoluzione equazione differenziale tramite Runge-Kutta

Ripetere l'esercizio 8.1 con il metodo di risoluzione di equazioni differenziali di Runge-Kutta (del quarto ordine) e confrontare quindi in condizioni analoghe ($t$ massimo e $h$) la stabilità dei due metodi.

# Esercizio 8.3 - Moto del pendolo

In questo esercizio proveremo ad implementare la risoluzione dell'equazione del moto del pendolo: per prima cosa possiamo provare a fare un grafico dell'andamento dell'ampiezza dell'oscillazione in funzione del tempo. La cosa più interessante che possiamo studiare con questo codice è l'andamento del periodo di oscillazione in funzione dell'ampiezza di oscillazione: in questo modo possiamo verificare che per angoli grandi le oscillazioni non sono più isocrone. La struttura logica dell'esercizio dovrebbe essere la seguente:

1.  Portare il sistema in una condizione iniziale (θ₀, 0);

2.  Far evolvere il sistema usando il metodo di Eulero o di Runge-Kutta con passo di integrazione $h$ opportuno;

3.  Calcolare il periodo di oscillazione del pendolo;

4.  Riportare il sistema ad una condizione iniziale con ampiezza θ₀ variata e ripetere la sequenza di operazioni

Si suggerisce di far variare θ₀ tra 0.1 e 3 radianti, in passi di 0.1 radianti.

# Esercizio 8.4 - Oscillazione forzate e risonanza

Implementare la risoluzione dell'equazione di un oscillatore armonico smorzato con forzante. Fare quindi un grafico della soluzione stazionaria in funzione della frequenza dell'oscillatore, ricostruendo la curva di risonanza. La struttura logica dell'esercizio dovrebbe essere la seguente:

-   Costruiamo un oscillatore armonico forzato con smorzante con una pulsazione propria ω₀=10 rad/s e una costante α=1/30 s.

-   Impostiamo un valore della pulsazione della forzante ω (si consiglia di esplorare un intervallo per ω tra 9 rad/s e 11 rad/s in passi da 0.05 rad/s).

-   Mettiamo il sistema nella sua condizione iniziale $x=0$ e $v_x=0$.

-   Facciamo evolvere il sistema usando il metodo di Runge-Kutta con passo di integrazione h opportuno fino all'esaurirsi del transiente.

-   Calcoliamo l'ampiezza dell'oscillazione.

-   Modifichiamo il valore della pulsazione della forzante ω e riportiamo il sistema alle condizioni iniziali $x=0$ e $v_x=0$, ripetendo poi la sequenza di operazioni