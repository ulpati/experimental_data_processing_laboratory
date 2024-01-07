CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio1.0 esegui

esercizio1.0: esercizio1.0.cpp
	g++ esercizio1.0.cpp -o $@ $(CXXFLAGS)

esegui:
	./esercizio1.0 10 ../data.dat

clean:
	rm -r esercizio1.0 output.dat