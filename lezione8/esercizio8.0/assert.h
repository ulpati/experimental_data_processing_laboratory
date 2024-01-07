#include "opvect.h"
#include <cassert>

void test_opvect() {

	// inizializzazione vettori
	std::vector<double> a {1, 2, 3};
	std::vector<double> b {4, 5, 6};
	double c {2};

	// operazioni
	std::vector<double> somma {5, 7, 9};
	std::vector<double> differenza {-3, -3, -3};
	double prodscalare {32};
	std::vector<double> prodscalvect {2, 4, 6};
	std::vector<double> divisione {0.5, 1, 1.5};

	// test
	assert(a+b == somma);
	std::cerr << "test somma ok" << std::endl;
	assert(a-b == differenza);
	std::cerr << "test differenza ok" << std::endl;
	assert(a*b == prodscalare);
	std::cerr << "test prodotto scalare ok" << std::endl;
	assert(c*a == prodscalvect);
	std::cerr << "test prodotto tra scalare e vettore ok" << std::endl;
	assert(a*c == prodscalvect);
	std::cerr << "test prodotto tra vettore e scalare ok" << std::endl;
	assert(a/c == divisione);
	std::cerr << "test divisione tra vettore e scalare ok" << std::endl;
}