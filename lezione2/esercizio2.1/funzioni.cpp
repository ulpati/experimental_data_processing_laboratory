#include "funzioni.h"

// test
bool are_close(double calculated, double expected, double epsilon = 1e-7) {
	return fabs(calculated - expected) < epsilon;
}

void test_stat_func(void) {
	// vettore pari
	Vettore vp(4);
		
	for(size_t i{0}; i < 4; i++) {
		vp.SetComponent(i, i+1);
	}

	// vettore dispari
	Vettore vd(3);

	for(size_t i{0}; i < 3; i++) {
		vd.SetComponent(i, i+1);
	}

	assert(are_close(fmedia(vp), 2.5));
	std::cerr << "test media ok" << std::endl;
	assert(are_close(fvarianza(vp, 2.5), 1.25));
	std::cerr << "test varianza ok" << std::endl;
	assert(are_close(fmediana(vp), 2.5));
	std::cerr << "test mediana n pari ok" << std::endl;
	assert(are_close(fmediana(vd), 2));
	std::cerr << "test mediana n dispari ok" << std::endl;
}

// punto 1
void letfile(Vettore& v, const char filename[]) {
	std::ifstream f;
	double data {0};
	f.open(filename);
	for (size_t i{0}; i < v.GetN(); i++) {
		f >> data;
		v.SetComponent(i, data);
	}
	
	assert(f && "Errore apertura file!\n");

	f.close();
}

// punto 2
double fmedia(const Vettore& v) {
	double sommam {0};
	for(size_t i{0}; i < v.GetN(); i++) {
		sommam = sommam + v.GetComponent(i);
	}
	return sommam / v.GetN();
}

double fvarianza(const Vettore& v, double media) {
	double sommav {0};
	for(size_t i{0}; i < v.GetN(); i++) {
		sommav = sommav + pow(v.GetComponent(i) - media, 2);
	}
	return sommav / v.GetN();
}

// punto 3
void ordinavect(Vettore& v) {
	int imin {0};
	double min {0};
	for(size_t j{0}; j < v.GetN()-1; j++) {
		imin = j;
		min = v.GetComponent(imin);
		for(size_t i{j+1}; i < v.GetN(); i++) {
			if(v.GetComponent(i) < min) {
				min = v.GetComponent(i);
				imin = i;
			}
		}

		double temp {v.GetComponent(j)};
		v.SetComponent(j, v.GetComponent(imin));
		v.SetComponent(imin, temp);
	}
}

double fmediana(const Vettore& v) {
	if (v.GetN()%2 == 0) {
		return (v.GetComponent(v.GetN()/2 - 1) + v.GetComponent(v.GetN()/2)) / 2;
	} else {
		return v.GetComponent(v.GetN()/2);
	}
}

// punto 4
void stampa(double media, double varianza, double mediana) {
	std::cout << "Media = " << media << std::endl;
	std::cout << "Varianza = " << varianza << std::endl;
	std::cout << "Mediana = " << mediana << std::endl;
}

// punto 5
void stampa(const Vettore& v, std::ofstream &f) {
	for(size_t i{0}; i < v.GetN(); i++) {
		f << v.GetComponent(i) << std::endl;
	}
	
	f.close();
}