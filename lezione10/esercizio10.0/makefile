CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio10.0 esegui

esegui:
	./esercizio10.0

esercizio10.0:  esercizio10.0.cpp RandomGen.h assert.h
	g++ esercizio10.0.cpp -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio10.0