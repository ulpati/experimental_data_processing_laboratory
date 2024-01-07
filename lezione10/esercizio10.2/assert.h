#pragma once

#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>
#include "integrale.h"
#include "RandomGen.h"
#include "errori.h"

bool are_close(double calculated, double expected, double epsilon){
    return fabs(calculated - expected) < epsilon;
}

void test_random_numbers() {

	RandomGen myGen{1};
	std::vector<double> v_unif {0.47291105054318905, 0.7385413474403322, 0.008484064601361752, 0.40976652735844254, 0.10108725726604462};
	for(size_t k{}; k < v_unif.size(); k++) {
		assert(are_close(myGen.Unif(0., 1.), v_unif[k],15));
	}
	std::cout << "test uniforme ok" << std::endl;

	myGen.SetSeed(1);
	std::vector<double> v_exp {0.6403859601352556, 1.3414791243855002, 0.008520259140710315, 0.5272371040158115, 0.10656930958385337};
	for(size_t k{}; k < v_exp.size(); k++) {
		assert(are_close(myGen.Exp(1), v_exp[k],15));
	}
	std::cout << "test esponenziale ok" << std::endl;
	
	myGen.SetSeed(1);
	std::vector<double> v_bm {1.9185906933235062, 1.8898847197814346, 1.9682233298032183, 2.960947466486181, 1.9538792463229713};
	for(size_t k{}; k < v_bm.size(); k++) {
		assert(are_close(myGen.Gaus(2, 1), v_bm[k],15));
	}
	std::cout << "test box-muller ok" << std::endl;

	myGen.SetSeed(1);
	std::vector<double> v_ar {1.7291105054318905, 2.4952592495828867, 2.009022830054164, 0.6520544346421957, 1.318840131163597};
	for(size_t k{}; k < v_ar.size(); k++) {
		assert(are_close(myGen.GausAR(2, 1), v_ar[k],15));
	}
	std::cout << "test ar ok\n" << std::endl;
}

void test_integrale(){
	
	// MIDPOINT
	assert(are_close(midpoint(std::sin, 0, M_PI, 10),   2.0082484079079745, 1e-16 )); //16 cfr dec
    	assert(are_close(midpoint(std::sin, 0, M_PI, 100),  2.000082249070986, 1e-15)); //15 cfr dec
    	assert(are_close(midpoint(std::sin, M_PI, 0, 10),  -2.0082484079079745, 1e-16)); //16 cfr dec
    	assert(are_close(midpoint(std::sin, 0, 1, 10),      0.45988929071851814, 1e-17)); //17 cfr dec
    	assert(are_close(midpoint(std::sin, 1, 2, 30),      0.9564934239032155, 2e-16)); //16-> errore(1.11e-16) > 1e-16!

	// per controllare se funziona anche nel semipiano negativo e con entrambi i piani
	assert(are_close(midpoint(std::sin, -M_PI, 0, 100),  -2.000082249070986, 1e-15)); //15 cfr dec 
	assert(are_close(midpoint(std::sin, 0, -1, 10),      0.45988929071851814, 1e-17)); //17 cfr dec
	assert(are_close(midpoint(std::sin, 0, -M_PI, 100),  2.000082249070986, 1e-15)); //15 cfr dec
	assert(are_close(midpoint(std::sin, -M_PI, 1, 10),  -1.55136616452649823, 1e-17)); //17 cfr dec

	std::cerr << "Tutti i test midpoint passati con successo" << std::endl;

	//SIMPSON
	assert(are_close(simpson(std::sin, 0, M_PI, 10),   2.0001095173150043, 1e-16 )); //16 cfr dec
	assert(are_close(simpson(std::sin, 0, M_PI, 100),  2.000000010824504, 1e-15)); //15 cfr dec
	assert(are_close(simpson(std::sin, 0, 1, 10),      0.45969794982382056, 1e-17)); //17 cfr dec
	assert(are_close(simpson(std::sin, 1, 2, 30),      0.9564491489761575, 1e-16)); //16 cfr dec

	std::cerr << "Tutti i test simpson passati con successo" << std::endl;

	// TRAPEZOIDI
	unsigned int steps[] = {10, 30, 100};
	assert(are_close(trapezoidi(std::sin, 0, M_PI, steps[0]), 1.9835235375094546, 1e-16 )); //16 cfr dec
	assert(are_close(trapezoidi(std::sin, 0, 1, steps[0]), 0.45931454885797635, 1e-17)); //17 cfr dec
	assert(are_close(trapezoidi(std::sin, 1, 2, steps[1]), 0.956360580669458, 1e-15)); //15 cfr dec
	assert(are_close(trapezoidi(std::sin, 0, M_PI, steps[2]), 1.9998355038874436, 1e-16)); //16 cfr dec

	std::cerr << "Tutti i test trapezoidi passati con successo" << std::endl;

	// INTEGRALE MEDIA
	RandomGen myGen{1};
	assert(are_close(intmean(sin, 0, M_PI, 100, myGen), 1.8715046084621125, 1e-12));
	std::cout << "test integrale (metodo media) ok" << std::endl;

	// INTEGRALE HIT OR MISS
	myGen.SetSeed(1);
	assert(are_close(inthm(sin, 0, M_PI, 1, 100, myGen), 1.9477874452256718, 1e-12));
	std::cout << "test integrale (metodo hit-or-miss) ok" << std::endl;	

}