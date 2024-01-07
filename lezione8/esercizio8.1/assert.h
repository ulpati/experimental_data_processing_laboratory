#pragma once

#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <cassert>

#include "opvect.h"
#include "equazioneDifferenzialeBase.h"

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

bool is_close(double a, double b, double epsilon = 1e-8) {
	return std::fabs(a - b) < epsilon;
}

void test_eulero() {
	Eulero eulero;
	OscillatoreArmonico oscarm{1.};
	const double h{0.1};
	double t {0.};
	const double startt {0.};
	const double lastt{70.};
	unsigned int npassi{(unsigned int)(lastt / h + 0.5)};
	std::vector<double> x {0.,1.};
	
	for (unsigned int i{0}; i < npassi; i++) {
		x = eulero.Passo(startt,t,x,h,oscarm);
		t = t + h;
	}

	assert(is_close(x[0], 19.773746013860173));
	assert(is_close(x[1], 25.848774751522960));

	std::cerr << "test eulero ok" << std::endl;
}