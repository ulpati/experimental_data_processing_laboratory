CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio10.2 esegui

esegui:
	./esercizio10.2

esercizio10.2:  esercizio10.2.cpp RandomGen.h assert.h integrale.h
	#
	g++ esercizio10.2.cpp ../format.cc -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio10.2