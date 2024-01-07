CXXFLAGS = -std=c++11 -g -Wall --pedantic

all_in_ordine: esercizio6.0.o esercizio6.0 esegui

esegui:
	./esercizio6.0

esercizio6.0: esercizio6.0.o particella.o elettrone.o
	#
	g++ esercizio6.0.o particella.o elettrone.o ../format.cc -o $@ $(CXXFLAGS)

esercizio6.0.o: esercizio6.0.cpp particella.h elettrone.h
	g++ -c esercizio6.0.cpp -o $@ $(CXXFLAGS)

particella.o: particella.cpp particella.h
	g++ -c particella.cpp -o $@ $(CXXFLAGS)

elettrone.o: elettrone.cpp elettrone.h
	g++ -c elettrone.cpp -o $@ $(CXXFLAGS)

clean:
	rm -r	*.o esercizio6.0