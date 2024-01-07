CXXFLAGS = -std=c++11 -g -Wall --pedantic
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all_in_ordine: esercizio11.0 esegui

esegui:
	./esercizio11.0

esercizio11.0: esercizio11.0.o esperimentoPrisma.o 
	g++ esercizio11.0.o esperimentoPrisma.o -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

esercizio11.0.o: esercizio11.0.cpp assert.h histo.h RandomGen.h
	g++ -c esercizio11.0.cpp -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

esperimentoPrisma.o: esperimentoPrisma.cpp esperimentoPrisma.h
	g++ -c esperimentoPrisma.cpp -o $@ $(CXXFLAGS) ${LIBS} ${INCS}

clean:
	rm -r	*.o esercizio11.0