CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio7.1 esegui

esegui:
	./esercizio7.1

esercizio7.1: esercizio7.1.cpp integrale.h assert.h
	#
	g++ esercizio7.1.cpp ../format.cc -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio7.1 esercizio7.1.png