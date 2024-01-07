#include "assert.h"

// test
bool are_close(double calculated, double expected, double epsilon = 1e-7) {
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