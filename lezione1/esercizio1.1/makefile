CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio1.1 esegui

esercizio1.1: esercizio1.1.cpp
	g++ esercizio1.1.cpp -o $@ $(CXXFLAGS)

esegui:
	./esercizio1.1 10 ../data.dat

clean:
	rm -r esercizio1.1 output.dat