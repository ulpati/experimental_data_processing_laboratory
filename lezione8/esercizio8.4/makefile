CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio8.4 esegui

esegui:
	./esercizio8.4 10. 1./30. 7

esercizio8.4: esercizio8.4.cpp ampiezza.h funzioniPendoloForzato.h opvect.h
	g++ esercizio8.4.cpp ../format.cc -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio8.4
