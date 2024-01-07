CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio3.2 esegui

esegui:
	./esercizio3.2 100000 ../data.dat

esercizio3.2: esercizio3.2.cpp funzioni.h
	g++ -o $@ esercizio3.2.cpp $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r esercizio3.2 output.dat
