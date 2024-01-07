#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "funzioni.h"
#include "vettore.h"

using namespace std;

int main(int argc, char **argv) {

	// test
	test_stat_func<double>();
	
	// controllo utente
	if (argc < 3) {
		cerr << "Uso del programma: " << argv[0] << "<n_data> <filename> " << endl;
		return -1;
	}

	// inizializzazione variabili
	Vettore <double>v(atoi(argv[1]));
	char *filename {argv[2]};

	// 1. Legge i dati dal file
	letfile<double>(v, filename);
	// 2. Calcola la media e la varianza
	double media {fmedia<double>(v)};
	double varianza {fvarianza<double>(v, media)};
	
	// 3. Calcola la mediana: copia il vettore di partenza…
	Vettore <double>vc {v};

	// …poi riordina gli elementi…
	ordinavect(vc);

	// …e infine calcola la mediana
	double mediana {fmediana<double>(vc)};

	// 4. Visualizza i dati ordinati
	stampa <double>(media, varianza, mediana);
	
	// 5. Scrive l'array ordinato in un file
	std::ofstream outputFile("output.dat");
	stampa(vc, outputFile);

	return 0;
}