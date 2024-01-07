CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio6.3 esegui

esegui:
	./esercizio6.3

esercizio6.3: esercizio6.3.cpp assert.h funzioneBase.h solutore.h bisezione.h
	#
	g++ esercizio6.3.cpp ../format.cc -o $@ $(CXXFLAGS)

clean:
	rm -r esercizio6.3
