CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio8.1 esegui

esegui:
	./esercizio8.1 0.1

esercizio8.1: esercizio8.1.cpp equazioneDifferenzialeBase.h opvect.h assert.h
	g++ esercizio8.1.cpp ../format.cc -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio8.1