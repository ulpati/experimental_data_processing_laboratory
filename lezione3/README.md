# Esercizio 3.0 - Evoluzione della classe Vettore in una classe template

Proviamo a rendere la classe `Vettore` della lezione scorsa una classe `template`, in modo che possa in linea di principio immagazzinare oggetti di un tipo generico `T`. Notate che quando usiamo classi o funzioni template non applichiamo la separazione tra header file (`.h`) e file di implementazione (`.cpp`), ma codifichiamo tutto dentro l'*header file*. Questo perché non sarebbe possibile per il compilatore compilare separatamente un set di funzioni o una classe senza sapere i tipi esatti con cui verranno utilizzati.

# Esercizio 3.1 - Codice di analisi dati utilizzando la classe std::vector

Vediamo come possiamo ora fare uso di un contenitore “ufficiale” del c++, la classe `vector`. Questo particolare contenitore non è altro che una classe `template` sulla falsariga della nostra `Vettore`. La particolarità di questa classe sta nel fatto che la sua dimensione può non essere nota a priori: la costruzione del vettore può avvenire “aggiungendo in coda” con `push_back(x)` gli elementi `x` man mano che si rendono disponibili. Vedremo nel seguito alcuni esempi; è possibile trovare più materiale in [questa referenza](http://www.cplusplus.com/reference/vector/vector/).

# Esercizio 3.2 - Analisi dati con vector e visualizzazione dei dati

Proviamo ora ad aggiungere all'esercizio precedente la possibilità di visualizzare i dati letti da file.

Un modo semplice per visualizzare graficamente la distribuzione di un set di dati è quello di usare un istogramma (`TH1F`) di ROOT. Le classi di ROOT sono molto comode da usare, perché possiamo facilmente utilizzarle in un codice C++. Per fare questo dobbiamo ricordarci di:

-   Includere l'header file (`.h`) di ogni oggetto di ROOT che pensiamo di utilizzare (`TApplication`, `TH1F`, `TGraph`, `TCanvas`).
-   Modificare il `Makefile` in modo che sia in grado da solo di trovare il path degli header files necessari (`$INCS`) e le librerie precompilate da linkare (`$LIBS`).