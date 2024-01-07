CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio1.3.o funzioni.o esercizio1.3 esegui

esercizio1.3: esercizio1.3.o funzioni.o
	g++ esercizio1.3.o funzioni.o -o $@ $(CXXFLAGS)

esercizio1.3.o: esercizio1.3.cpp funzioni.h
	g++ -c esercizio1.3.cpp -o $@ $(CXXFLAGS)

funzioni.o: funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o $@ $(CXXFLAGS)

esegui:
	./esercizio1.3 10 ../data.dat

clean:
	rm -r	*.o esercizio1.3 output.dat