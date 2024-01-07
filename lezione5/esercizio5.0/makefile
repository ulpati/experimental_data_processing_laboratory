CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio5.0.o esercizio5.0 esegui

esegui:
	./esercizio5.0 5 4 3

esercizio5.0: esercizio5.0.o assert.o posizione.o
	#
	g++ esercizio5.0.o assert.o posizione.o ../format.cc -o $@ $(CXXFLAGS)

esercizio5.0.o: esercizio5.0.cpp assert.h posizione.h
	g++ -c esercizio5.0.cpp -o $@ $(CXXFLAGS)

assert.o: assert.cpp assert.h posizione.h
	g++ -c assert.cpp -o $@ $(CXXFLAGS)

posizione.o: posizione.cpp posizione.h
	g++ -c posizione.cpp -o $@ $(CXXFLAGS)

clean:
	rm -r	*.o esercizio5.0