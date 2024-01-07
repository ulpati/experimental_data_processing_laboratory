# Esercizio 7.0 - Integrazione con il metodo *midpoint* a numero di passi fissato

Implementare un codice per il calcolo della funzione $\sin(x)$ su $[0, \pi]$ con il metodo midpoint.

1. Per prima cosa, costruiamo un programma di test che calcoli l'integrale utilizzando un numero di intervalli fissato.

2. Per controllare la precisione ottenuta con un numero di passi fissato proviamo a stampare una tabella con la differenza tra il risultato numerico ed il valore esatto (ottenuto analiticamente) in funzione del numero di passi (o della lunghezza del passo $h$). In aggiunta alla tabella si può rappresentare l'andamento dell'errore in funzione della lunghezza del passo $h$ con un grafico, usando [gplot++](https://github.com/ziotom78/gplotpp) oppure un `TGraph` di ROOT.

# Esercizio 7.1 - Integrazione alla Simpson

Implementare l'integrazione con il metodo di Simpson con un numero di passi fissato. Si può utilizzare lo stesso schema dell'esercizio precedente costruendo una classe derivata `Simpson`. Come nell'Esercizio 7.0, stampare una tabella (o costruire un grafico) con la precisione raggiunta in funzione del numero di passi.

# Esercizio 7.2 - Integrazione con la formula dei trapezi con precisione fissata

Concludiamo l'esercitazione implementando l'integrazione della funzione $\sin x$ su $[0, \pi]$ con il metodo dei trapezi. In quest'ultimo esercizio proviamo a riflettere sull'uso di un algoritmo di integrazione numerica a precisione fissata invece che a numero di passi fissato. Negli esercizi precedenti il calcolo a numero di passi fissato non ci da alcuna indicazione sulla qualità del risultato: integrare con 10 passi è sufficiente? L'idea che vogliamo sviluppare è che l'utente fornisca una precisione desiderata e l'algoritmo sia in grado di aumentare automaticamente il numero di passi fino a raggiungere la precisione richiesta sul valore dell'integrale. L'algoritmo dato il valore della precisione dovrà raddoppiare il numero di passi finché l'errore (stimato runtime) non diventa inferiore alla precisione impostata. Infine confrontiamo attraverso un grafico i tre metodi sviluppati durante questa esercitazione.