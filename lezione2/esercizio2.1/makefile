CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio2.1.o funzioni.o vettore.o esercizio2.1 esegui

esegui:
	./esercizio2.1 10 ../data.dat

esercizio2.1: esercizio2.1.o funzioni.o vettore.o
	g++ esercizio2.1.o funzioni.o vettore.o -o $@ $(CXXFLAGS)

esercizio2.1.o: esercizio2.1.cpp funzioni.h vettore.h
	g++ -c esercizio2.1.cpp -o $@ $(CXXFLAGS)

funzioni.o: funzioni.cpp funzioni.h vettore.h
	g++ -c funzioni.cpp -o $@ $(CXXFLAGS)

vettore.o: vettore.cpp vettore.h
	g++ -c vettore.cpp -o $@ $(CXXFLAGS)

clean:
	rm -r	*.o esercizio2.1 output.dat