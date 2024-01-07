#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "vettore.h"
#include "funzioni.h"

using namespace std;

int main(int argc, char **argv) {

	// test
	test_stat_func();

	// controllo utente
	if (argc < 3) {
		cerr << "Uso del programma: " << argv[0] << "<n_data> <filename> " << endl;
		return -1;
	}

	// inizializzazione variabili
	Vettore v(atoi(argv[1]));
	char *filename {argv[2]};

	// 1. Legge i dati dal file
	letfile(v, filename);

	// 2. Calcola la media e la varianza
	double media {fmedia(v)};
	double varianza {fvarianza(v, media)};
	
	// 3. Calcola la mediana: copia il vettore di partenza…
	Vettore vc {v};

	// …poi riordina gli elementi…
	ordinavect(vc);

	// …e infine calcola la mediana
	double mediana {fmediana(vc)};

	// 4. Visualizza i dati ordinati
	stampa(media, varianza, mediana);

	// 5. Scrive l'array ordinato in un file
	std::ofstream outputFile("output.dat");
	stampa(vc, outputFile);

	return 0;
}