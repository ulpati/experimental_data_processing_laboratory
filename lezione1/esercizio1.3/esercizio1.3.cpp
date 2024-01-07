#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

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
	size_t ndata {size_t(atoi(argv[1]))};
	double *dataset {new double[ndata]};
	char *filename {argv[2]};

	// 1. Legge i dati dal file
	letfile(ndata, dataset, filename);

	// 2. Calcola la media e la varianza
	double media {fmedia(ndata, dataset)};
	double varianza {fvarianza(ndata, dataset, media)};
	
	// 3. Calcola la mediana: copia il vettore di partenza…
	double *datasetcopy {new double[ndata]};
	copiavect(ndata, dataset, datasetcopy);

	// …poi riordina gli elementi…
	ordinavect(ndata, datasetcopy);

	// …e infine calcola la mediana
	double mediana {fmediana(ndata, datasetcopy)};

	// 4. Visualizza i dati ordinati
	stampa(media, varianza, mediana);

	// 5. Scrive l'array ordinato in un file
	ofstream outputFile("output.dat");
	stampa(ndata, datasetcopy, outputFile);

	delete[] dataset;
	delete[] datasetcopy;
	
	return 0;
}