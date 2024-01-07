#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

// test
bool are_close(double calculated, double expected, double epsilon = 1e-7) {
	return fabs(calculated - expected) < epsilon;
}

void test_stat_func(void);

// punto 1
void letfile(size_t n, double *d, const char filename[]);

// punto 2
double fmedia(size_t n, double *d);
double fvarianza(size_t n, double *d, double media);

// punto 3
void copiavect(size_t n, double *d, double *dc);
void ordinavect(size_t n, double *dc);
double fmediana(size_t n, double *dc);

// punto 4
void stampav(double media, double varianza, double mediana);

// punto 5
void stampaf(size_t n, double *dc, ofstream &f);

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
	stampav(media, varianza, mediana);

	// 5. Scrive l'array ordinato in un file
	ofstream outputFile("output.dat");
	stampaf(ndata, datasetcopy, outputFile);

	delete[] dataset;
	delete[] datasetcopy;
	
	return 0;
	}

	// test
	void test_stat_func(void) {
		double mydata[] = {1, 2, 3, 4};

		assert(are_close(fmedia(4, mydata), 2.5));
		cerr << "test media ok" << endl;
		assert(are_close(fvarianza(4, mydata, 2.5), 1.25));
		cerr << "test varianza ok" << endl;
		assert(are_close(fmediana(4, mydata), 2.5));
		cerr << "test mediana n pari ok" << endl;
		assert(are_close(fmediana(3, mydata), 2));
		cerr << "test mediana n dispari ok" << endl;
	}

	// punto 1
	void letfile(size_t n, double *d, const char filename[]) {
		ifstream f;
		f.open(filename);
		for (size_t i{0}; i < n; i++) {
			f >> d[i];
		}

		assert(f && "Errore apertura file!\n");		

		f.close();
		}

	// punto 2
	double fmedia(size_t n, double *d) {
		double sommam {0};
		for(size_t i{0}; i < n; i++) {
			sommam = sommam + d[i];
		}
	return sommam / n;
	}

	double fvarianza(size_t n, double *d, double media) {
		double sommav {0};
		for(size_t i{0}; i < n; i++) {
			sommav = sommav + pow(d[i] - media, 2);
		}
		return sommav / n;
	}

	// punto 3
	void copiavect(size_t n, double *d, double *dc) {
		for(size_t i{0}; i < n; i++) {
			dc[i] = d[i];
		}
	}

	void ordinavect(size_t n, double *dc) {
		int imin {0};
		double min {0};
		for(size_t j{0}; j < n-1; j++) {
			imin = j;
			min = dc[imin];
			for(size_t i{j+1}; i < n; i++) {
				if(dc[i] < min) {
					min = dc[i];
					imin = i;
				}
			}
			
			double temp {dc[j]};
			dc[j] = dc[imin];
			dc[imin] = temp;
		}
	}

	double fmediana(size_t n, double *dc) {
		if (n%2 == 0) {
			return (dc[n/2 - 1] + dc[n/2]) / 2;
		} else {
			return dc[n/2];
		}
	}

	// punto 4
	void stampav(double media, double varianza, double mediana) {
		cout << "Media = " << media << endl;
		cout << "Varianza = " << varianza << endl;
		cout << "Mediana = " << mediana << endl;
	}
	// punto 5
	void stampaf(size_t n, double *dc, ofstream &f) {
		for(size_t i{0}; i < n; i++) {
			f << dc[i] << endl;
		}
	f.close();
	}