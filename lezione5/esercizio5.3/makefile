CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio5.3.o esercizio5.3 esegui

esegui:
	./esercizio5.3 -2 3 4

esercizio5.3: esercizio5.3.o puntoMateriale.o campoVettoriale.o posizione.o particella.o assert.o
	#
	g++ esercizio5.3.o puntoMateriale.o campoVettoriale.o posizione.o particella.o assert.o ../format.cc -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

esercizio5.3.o: esercizio5.3.cpp puntoMateriale.h campoVettoriale.h particella.h posizione.h
	g++ -c esercizio5.3.cpp -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

puntoMateriale.o: puntoMateriale.cpp puntoMateriale.h
	g++ -c puntoMateriale.cpp -o $@ $(CXXFLAGS)

particella.o: particella.cpp particella.h
	g++ -c particella.cpp -o $@ $(CXXFLAGS)

posizione.o: posizione.cpp posizione.h
	g++ -c posizione.cpp -o $@ $(CXXFLAGS)

campoVettoriale.o: campoVettoriale.cpp campoVettoriale.h
	g++ -c campoVettoriale.cpp -o $@ $(CXXFLAGS)

assert.o: assert.cpp assert.h
	g++ -c assert.cpp -o $@ $(CXXFLAGS);

clean:
	rm -r	*.o esercizio5.3 esercizio5.3.png