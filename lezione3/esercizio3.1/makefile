CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio3.1 esegui

esegui:
	./esercizio3.1 100000 ../data.dat

esercizio3.1: esercizio3.1.cpp funzioni.h
	g++ -o  $@ esercizio3.1.cpp $(CXXFLAGS)

clean:
	rm -r esercizio3.1 output.dat