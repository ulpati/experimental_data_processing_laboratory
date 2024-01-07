CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio6.2 esegui

esegui:
	./esercizio6.2

esercizio6.2: esercizio6.2.cpp assert.h funzioneBase.h solutore.h parabola.h bisezione.h
	#
	g++ esercizio6.2.cpp ../format.cc -o $@ $(CXXFLAGS)

clean:
	rm -r esercizio6.2
