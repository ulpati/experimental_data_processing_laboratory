#include "assert.h"

#include <iostream>
#include <cassert>
#include <cmath>

// test
bool are_close(double calculated, double expected, double epsilon = 1e-4) {
	return fabs(calculated - expected) < epsilon;
}

void test_coordinate(void) {
	
	Posizione p{1, 2, 3};

	assert(are_close(p.getX(), 1.0));
	std::cerr << "test getX ok" << std::endl;
	assert(are_close(p.getY(), 2.0));
	std::cerr << "test getY ok" << std::endl;
	assert(are_close(p.getZ(), 3.0));
	std::cerr << "test getZ ok" << std::endl;

	assert(are_close(p.getR(), 3.7416573867739));
	std::cerr << "test getR ok" << std::endl;
	assert(are_close(p.getPhi(), 1.1071487177941));
	std::cerr << "test getPhi ok" << std::endl;
	assert(are_close(p.getTheta(), 0.64052231267943));
	std::cerr << "test getTheta ok" << std::endl;
	
	assert(are_close(p.getRho(), 2.2360679774998));
	std::cerr << "test getRho ok" << std::endl;
}

void test_legge_coulomb(void) {

	PuntoMateriale particella{1.0, 5e-7, 5, 3, -2};
	Posizione p{-2, 4, 1};
	CampoVettoriale V {particella.CampoElettrico(p)};

	assert(are_close(V.getFx(), -69.41150052142065));
	std::cerr << "test getFx ok" << std::endl;
	assert(are_close(V.getFy(), 9.915928645917235));
	std::cerr << "test getFy ok" << std::endl;
	assert(are_close(V.getFz(), 29.747785937751708));
	std::cerr << "test getFz ok" << std::endl;
}