#include "funzioni.h"

// test
bool are_close(double calculated, double expected, double epsilon = 1e-7) {
	return fabs(calculated - expected) < epsilon;
}

void test_stat_func(void) {
	double mydata[] = {1, 2, 3, 4};

	assert(are_close(fmedia(4, mydata), 2.5));
	std::cerr << "test media ok" << std::endl;
	assert(are_close(fvarianza(4, mydata, 2.5), 1.25));
	std::cerr << "test varianza ok" << std::endl;
	assert(are_close(fmediana(4, mydata), 2.5));
	std::cerr << "test mediana n pari ok" << std::endl;
	assert(are_close(fmediana(3, mydata), 2));
	std::cerr << "test mediana n dispari ok" << std::endl;
}

// punto 1
void letfile(size_t n, double *d, const char filename[]) {
	std::ifstream f;
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
void stampa(double media, double varianza, double mediana) {
	std::cout << "Media = " << media << std::endl;
	std::cout << "Varianza = " << varianza << std::endl;
	std::cout << "Mediana = " << mediana << std::endl;
}

// punto 5
void stampa(size_t n, double *dc, std::ofstream &f) {
	for(size_t i {0}; i < n; i++) {
		f << dc[i] << std::endl;
	}

	f.close();
}