CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio6.1 esegui

esegui:
	./esercizio6.1

esercizio6.1: esercizio6.1.cpp funzioneBase.h parabola.h
	g++ esercizio6.1.cpp -o $@ $(CXXFLAGS)

clean:
	rm -r	esercizio6.1