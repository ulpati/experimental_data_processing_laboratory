#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;


int main(int argc, char **argv) {

	// controllo utente
	if (argc < 3) {
  		cerr << "Uso del programma: " << argv[0] << "<n_data> <filename> " << endl;
    	return -1;
  	}

	// inizializzazione variabili
	size_t ndata {size_t(atoi(argv[1]))};
  	double *dataset {new double[ndata]};
  	char *filename {argv[2]};
  	ifstream inputFile(filename);
  	ofstream outputFile("output.dat");

	// 1. Legge i dati dal file
  	for (size_t i{0}; i < ndata; i++) {
    		inputFile >> dataset[i];
  	}

	assert(inputFile && "Errore apertura file!\n");

  	inputFile.close();

  	// 2. Calcola la media e la varianza
  	double sommam {0};
 	for(size_t i{0}; i < ndata; i++) {
    		sommam = sommam + dataset[i];
 	}
 	
	double media {sommam / ndata};
  
  	double sommav {0};
  	for (size_t i{0}; i < ndata; i++) {
    		sommav = sommav + pow(dataset[i] - media, 2);
 	}
  
  	double varianza {sommav / ndata};

  	// 3. Calcola la mediana: copia il vettore di partenza…
  	double *datasetcopy {new double[ndata]};
  	for (size_t i{0}; i < ndata; i++) {
   		datasetcopy[i] = dataset[i];
  	}
  	
	// …poi riordina gli elementi…
  	int imin {0};
  	double min {0};
  	for (size_t j{0}; j < ndata-1; j++) {
   		imin = j;
    		min = datasetcopy[imin];
    		for (size_t i{j+1}; i < ndata; i++) {
      			if (datasetcopy[i] < min) {
        			min = datasetcopy[i];
        			imin = i;
      			}
    		}
    		double temp {datasetcopy[j]};
    		datasetcopy[j] = datasetcopy[imin];
    		datasetcopy[imin] = temp;
  	}

    	// …e infine calcola la mediana
    	double mediana {0};
   	if (ndata%2 == 0) {
      		mediana = (datasetcopy[ndata/2 - 1] + datasetcopy[ndata/2]) / 2;
    	} else {
      		mediana = datasetcopy[ndata/2];
    	}
    
	// 4. Visualizza i dati ordinati
	cout << "Media = " << media << endl;
	cout << "Varianza = " << varianza << endl;
	cout << "Mediana = " << mediana << endl;

    	// 5. Scrive l'array ordinato in un file
    	for (size_t i{0}; i < ndata; i++) {
      		outputFile << datasetcopy[i] << endl;
    	}
    	outputFile.close();

	delete[] dataset;
	delete[] datasetcopy;
	
	return 0;
}