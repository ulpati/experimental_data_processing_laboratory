#include <iostream>
#include <cstdlib>

#include "posizione.h"
#include "../fmtlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char **argv) {

	// test
	test_coordinate();

	// controllo utente
	if (argc != 4) {
		cerr << "Uso del programma: " << argv[0] << " <x> <y> <z> " << endl;
		return -1;
	}

	// inizializzazione variabili
	double x {atof(argv[1])};
	double y {atof(argv[2])};
	double z {atof(argv[3])};

	Posizione P(x,y,z);

	// stampa
	fmt::print("Coordinate cartesiane: [x = {}, y = {}, z = {}]\n", P.getX(), P.getY(), P.getZ());
  	fmt::print("Coordinate cilindriche: [Rho = {}, Phi = {}, z = {}]\n", P.getRho(), P.getPhi(), P.getZ());
  	fmt::print("Coordinate sferiche: [R = {}, Phi = {}, Theta¸ = {}]\n", P.getR(), P.getPhi(), P.getTheta());

	return 0;
}