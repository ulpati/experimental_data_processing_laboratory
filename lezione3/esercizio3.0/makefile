CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio3.0 esegui

esegui:
	./esercizio3.0 10 ../data.dat

esercizio3.0: esercizio3.0.cpp funzioni.h vettore.h
	g++ -o $@ esercizio3.0.cpp $(CXXFLAGS)

clean:
	rm -r esercizio3.0 output.dat