CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio8.3 esegui

esegui:
	./esercizio8.3 2. 9.81

esercizio8.3: esercizio8.3.cpp equazioneDifferenzialeBase.h opvect.h assert.h periodoPendolo.h
	g++ esercizio8.3.cpp ../format.cc -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio8.3