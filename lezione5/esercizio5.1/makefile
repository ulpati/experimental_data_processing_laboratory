CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio5.1.o esercizio5.1 esegui

esegui:
	./esercizio5.1

esercizio5.1: esercizio5.1.o particella.o elettrone.o
	#
	g++ esercizio5.1.o particella.o elettrone.o ../format.cc -o $@ $(CXXFLAGS)

esercizio5.1.o: esercizio5.1.cpp particella.h elettrone.h
	g++ -c esercizio5.1.cpp -o $@ $(CXXFLAGS)

particella.o: particella.cpp particella.h
	g++ -c particella.cpp -o $@ $(CXXFLAGS)

elettrone.o: elettrone.cpp elettrone.h
	g++ -c elettrone.cpp -o $@ $(CXXFLAGS)

clean:
	rm -r	*.o esercizio5.1