CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio1.2.o funzioni.o esercizio1.2 esegui

esercizio1.2: esercizio1.2.o funzioni.o
	g++ esercizio1.2.o funzioni.o -o $@ $(CXXFLAGS)

esercizio1.2.o: esercizio1.2.cpp funzioni.h
	g++ -c esercizio1.2.cpp -o $@ $(CXXFLAGS)

funzioni.o: funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o $@ $(CXXFLAGS)

esegui:
	./esercizio1.2 10 ../data.dat

clean:
	rm -r	*.o esercizio1.2 output.dat