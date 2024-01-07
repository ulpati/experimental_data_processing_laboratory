CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio8.0 esegui

esegui:
	./esercizio8.0

esercizio8.0: esercizio8.0.cpp opvect.h assert.h
	g++ esercizio8.0.cpp ../format.cc -o $@ $(CXXFLAGS)

clean:
	rm -r esercizio8.0
